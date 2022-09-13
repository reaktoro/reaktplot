#pragma once

#include <pybind11/pybind11.h>
namespace py = pybind11;

namespace reaktplot {

/// Used to get plotly python modules that have been initialized once, upon its first request.
class PlotlyModules
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
class Plotly
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
