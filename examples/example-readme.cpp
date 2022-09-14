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

// reaktplot includes
#include <reaktplot/reaktplot.hpp>
namespace rkp = reaktplot;

int main()
{
    rkp::Array x = rkp::linspace(0.0, rkp::PI, 200);

    rkp::Figure fig;

    fig.titleText("SINE FUNCTIONS");

    fig.xaxisTitleText("x");
    fig.yaxisTitleText("y");

    fig.addScatter(x, rkp::Array(std::sin(1.0 * x)), "sin(x)");
    fig.addScatter(x, rkp::Array(std::sin(2.0 * x)), "sin(2x)");
    fig.addScatter(x, rkp::Array(std::sin(3.0 * x)), "sin(3x)");
    fig.addScatter(x, rkp::Array(std::sin(4.0 * x)), "sin(4x)");
    fig.addScatter(x, rkp::Array(std::sin(5.0 * x)), "sin(5x)");
    fig.addScatter(x, rkp::Array(std::sin(6.0 * x)), "sin(6x)");

    fig.show();

    fig.save("example-readme.svg");
}
