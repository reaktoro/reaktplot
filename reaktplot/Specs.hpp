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
namespace py = pybind11;

// reaktplot includes
#include <reaktplot/Macros.hpp>
#include <reaktplot/Pythonic.hpp>

namespace reaktplot {

//==========//==========//==========//==========//==========//==========//==========//==========//==========//==========/
// Below are reference links to docs of plotly components used in this file:
//
// [plotly.graph_objects.scatter.Marker](https://plotly.com/python-api-reference/generated/plotly.graph_objects.scatter.html#plotly.graph_objects.scatter.Marker)
// [plotly.graph_objects.scatter.marker.Line](https://plotly.com/python-api-reference/generated/plotly.graph_objects.scatter.marker.html#plotly.graph_objects.scatter.marker.Line)
//==========//==========//==========//==========//==========//==========//==========//==========//==========//==========/

/// Used to specify the attributes of a line element in a figure.
class RKP_EXPORT LineSpecs : public Pythonic
{
private:
    /// The dictionary containing the specs of the line.
    py::dict mspecs;

public:
    /// Constructs a default LineSpecs object.
    LineSpecs() = default;

    /// Sets the width of the line element (in px).
    /// @param value The width of the line (in px)
    inline auto width(int value) -> LineSpecs&
    {
        mspecs["width"] = value;
        return *this;
    }

    /// Sets the color of the line.
    /// @param value The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
    inline auto color(std::string const& value) -> LineSpecs&
    {
        mspecs["color"] = value;
        return *this;
    }

    /// Get the underlying Python dictionary of the LineSpecs object.
    inline auto dict() const -> py::dict
    {
        return mspecs;
    }
};

/// Used to specify the attributes of a marker element in a figure.
class RKP_EXPORT MarkerSpecs : public Pythonic
{
private:
    /// The dictionary containing the specs of the marker.
    py::dict mspecs;

public:

    /// Constructs a default MarkerSpecs object.
    MarkerSpecs() = default;

    /// Sets the marker size (in px).
    /// @param value The size of the marker (in px)
    inline auto size(int value) -> MarkerSpecs&
    {
        mspecs["size"] = value;
        return *this;
    }


    /// Sets the marker symbol type.
    /// @param value The marker symbol (e.g, "circle", "diamond", "square", "circle-open")
    inline auto symbol(std::string const& value) -> MarkerSpecs&
    {
        mspecs["symbol"] = value;
        return *this;
    }


    /// Sets the color of the marker.
    /// @param value The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
    inline auto color(std::string const& value) -> MarkerSpecs&
    {
        mspecs["color"] = value;
        return *this;
    }

    /// Sets the properties of the border line of the marker.
    /// @param value The line specs of the border of the marker
    inline auto line(LineSpecs const& value) -> MarkerSpecs&
    {
        mspecs["line"] = value.dict();
        return *this;
    }

    /// Sets the marker opacity.
    /// @param value The opacity value as a float number in [0, 1]
    inline auto opacity(float const& value) -> MarkerSpecs&
    {
        mspecs["opacity"] = value;
        return *this;
    }

    /// Get the underlying Python dictionary of the MarkerSpecs object.
    inline auto dict() const -> py::dict
    {
        return mspecs;
    }
};

} // namespace reaktplot
