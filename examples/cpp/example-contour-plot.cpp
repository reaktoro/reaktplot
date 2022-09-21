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
using namespace reaktplot;

int main(int argc, char** argv)
{
    using Vec = std::vector<double>;
    using Mat = std::vector<std::vector<double>>;

    auto x = Vec{ 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 };
    auto y = Vec{ 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 };
    auto z = Mat{
        { 10.00, 10.625, 12.500, 15.625, 20.000 },
        { 5.625,  6.250,  8.125, 11.250, 15.625 },
        { 2.500,  3.125,  5.000,  8.125, 12.500 },
        { 0.625,  1.250,  3.125,  6.250, 10.625 },
        { 0.000,  0.625,  2.500,  5.625, 10.000 }
    };

    Figure fig;

    fig.title("CONTOUR PLOT");

    fig.xaxisTitle("x");
    fig.yaxisTitle("y");

    fig.drawContour(x, y, z);

    fig.save("example-contour-plot.pdf");

    fig.show();
}
