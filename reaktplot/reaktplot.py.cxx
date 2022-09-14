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

// pybind11 includes
#include <reaktplot/pybind11.hxx>

void exportArray(py::module& m);
void exportConstants(py::module& m);
void exportDefault(py::module& m);
void exportEnums(py::module& m);
void exportFigure(py::module& m);
void exportMacros(py::module& m);
void exportPlotly(py::module& m);
void exportScatter(py::module& m);
void exportUtils(py::module& m);

PYBIND11_MODULE(reaktplot4py, m)
{
    exportArray(m);
    exportConstants(m);
    exportDefault(m);
    exportEnums(m);
    exportFigure(m);
    exportMacros(m);
    exportPlotly(m);
    exportScatter(m);
    exportUtils(m);
}
