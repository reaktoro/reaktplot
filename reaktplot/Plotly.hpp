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

/// Used to get plotly python modules that have been initialized once, upon its first request.
class RKP_EXPORT PlotlyModules
{
public:
    /// Return the `plotly` module guaranteed to be initialized only once.
    static auto ply() -> py::module;

    /// Return the `plotly.io` module guaranteed to be initialized only once.
    static auto pio() -> py::module;

    /// Return the `plotly.graph_objects` module guaranteed to be initialized only once.
    static auto pgo() -> py::module;
};

/// Used to get Python objects from the plotly python library.
class RKP_EXPORT Plotly
{
public:
    /// Return a Python object of class `Figure` from module `plotly.graph_objects`.
    static auto Figure() -> py::object;

    /// Return a Python object of class `Layout` from module `plotly.graph_objects`.
    static auto Layout() -> py::object;

    /// Return a Python object of class `Scatter` from module `plotly.graph_objects`.
    static auto Scatter() -> py::object;

    /// Return a Python object of class `Bar` from module `plotly.graph_objects`.
    static auto Bar() -> py::object;
};

} // namespace reaktplot
