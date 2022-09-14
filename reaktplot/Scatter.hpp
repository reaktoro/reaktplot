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
