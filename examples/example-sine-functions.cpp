// reaktplot - a modern C++ scientific plotting library powered by gnuplot
// https://github.com/reaktplot/reaktplot
//
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
//
// Copyright (c) 2022-2023 Allan Leal
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// reaktplot includes
#include <reaktplot/reaktplot.hpp>
using namespace reaktplot;

// int main(int argc, char const *argv[])
// {
//     std::valarray<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
//     std::valarray<double> sinx = {1.0, 4.0, 9.0, 16.0, 25.0};
//     std::valarray<double> cosx = {2.0, 8.0, 18.0, 32.0, 50.0};


//     Figure fig;
//     fig.addScatter(x, sinx, "sin(x)");
//     fig.addScatter(x, cosx, "cos(x)");
//     fig.title_text("Trigonometric Functions");
//     fig.xaxis_title_text("Temperature [K]");
//     fig.yaxis_title_text("Value [J]");
//     fig.show();
//     return 0;
// }

int main(int argc, char** argv)
{
    // Create a vector with values from 0 to pi divived into 200 uniform intervals for the x-axis
    Array x = linspace(0.0, PI, 200);

    // Create a Figure object
    Figure fig;

    // Set the x and y titles
    fig.xaxisTitleText("x");
    fig.yaxisTitleText("y");

    // Set the x and y ranges
    // figure.xrange(0.0, PI);
    // figure.yrange(0.0, 1.0);

    // // Set the legend to be on the bottom along the horizontal
    // figure.legend()
    //     .atOutsideBottom()
    //     .displayHorizontal()
    //     .displayExpandWidthBy(2);

    // Plot sin(i*x) from i = 1 to i = 6
    fig.addScatter(x, Array(std::sin(1.0 * x)), "sin(x)");
    fig.addScatter(x, Array(std::sin(2.0 * x)), "sin(2x)");
    fig.addScatter(x, Array(std::sin(3.0 * x)), "sin(3x)");
    fig.addScatter(x, Array(std::sin(4.0 * x)), "sin(4x)");
    fig.addScatter(x, Array(std::sin(5.0 * x)), "sin(5x)");
    fig.addScatter(x, Array(std::sin(6.0 * x)), "sin(6x)");

    // Show the figure
    fig.show();

    // // Save the figure to a PDF file
    // canvas.save("example-sine-functions.pdf");
}
