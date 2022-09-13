#pragma once

// C++ includes
#include <string>

// pybind11 includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

namespace reaktplot {

class Scatter
{
public:
    inline Scatter()
    {}

    template<typename X, typename Y>
    explicit Scatter(X const& x, Y const& y, std::string const& name)
    {
        options["x"] = x;
        options["y"] = y;
        options["name"] = name;
    }

    template<typename X>
    auto x(X const& values) -> Scatter&
    {
        options["x"] = values;
        return *this;
    }

    template<typename Y>
    auto y(Y const& values) -> Scatter&
    {
        options["y"] = values;
        return *this;
    }

    inline auto name(std::string const& str) -> Scatter&
    {
        options["name"] = str;
        return *this;
    }

    inline auto dict() const -> py::dict
    {
        return options;
    }

private:
    py::dict options;
};

} // namespace reaktplot
