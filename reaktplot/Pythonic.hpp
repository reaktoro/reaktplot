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

#pragma once

// pybind11 includes
#include <pybind11/pybind11.h>
namespace py = pybind11;

// reaktplot includes
#include <reaktplot/Macros.hpp>

namespace reaktplot {

/// Used to get Python objects from the plotly python library.
class RKP_EXPORT Pythonic
{
public:
    /// Construct a default Pythonic object initializing the Python interpreter once.
    Pythonic();

    /// Create a Python object of type `reaktplot.Figure`.
    static auto createFigure() -> py::object;

    /// Create a Python object of type `reaktplot.FontSpecs`.
    static auto createFontSpecs() -> py::object;

    /// Create a Python object of type `reaktplot.LineSpecs`.
    static auto createLineSpecs() -> py::object;

    /// Create a Python object of type `reaktplot.MarkerSpecs`.
    static auto createMarkerSpecs() -> py::object;

    /// Create a Python object of type `reaktplot.ContourSpecs`.
    static auto createContourSpecs() -> py::object;
};

} // namespace reaktplot
