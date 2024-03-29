// reaktplot - a modern C++ scientific plotting library powered by plotly
// https://github.com/reaktplot/reaktplot
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
//
// Copyright (c) 2022-2023 Allan Leal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

// Catch includes
#include <catch2/catch.hpp>

// reaktplot includes
#include <reaktplot/Array.hpp>
#include <reaktplot/Figure.hpp>
using namespace reaktplot;

TEST_CASE("Testing Figure", "[Figure]")
{
    REQUIRE_NOTHROW( Figure() );

    Figure fig;

    Array x = linspace(0.0, 1.0, 10);
    Array u = x * x;
    Array v = x * x * x;
    Array w = x * x * x * x;

    fig.xaxisTitle("TESTING TITLE");

    fig.xaxisTitle("x");
    fig.yaxisTitle("y");

    fig.drawLine(x, u, "u");
    fig.drawLineWithMarkers(x, v, "v");
    fig.drawMarkers(x, w, "w");

    CHECK_NOTHROW( fig.save("fig.pdf") );

    auto colorway = fig.colorway();
    CHECK(colorway == std::vector<std::string>{"#4C78A8", "#F58518", "#E45756", "#72B7B2", "#54A24B", "#EECA3B", "#B279A2", "#FF9DA6", "#9D755D", "#BAB0AC"});

    fig.colorway({"black", "green"});

    colorway = fig.colorway();
    CHECK(colorway == std::vector<std::string>{"black", "green"});
}
