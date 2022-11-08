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

/// Used to specify the attributes of a font for a text in a figure.
class RKP_EXPORT FontSpecs : public Pythonic
{
private:
    /// The Python object of type `reaktplot.FontSpecs`.
    py::object obj;

public:
    /// Construct a default FontSpecs object.
    FontSpecs()
    : obj(Pythonic::createFontSpecs())
    {}

    /// Return the underlying `reakplot.FontSpecs` Python object.
    auto pyspecs() const -> py::object const& { return obj; }

    /// Sets the size of the font (in px).
    /// @param value The size of the font (in px)
    auto size(int const& value) -> FontSpecs& { obj.attr("size")(value); return *this; }

    /// Sets the color of the text.
    /// @param value The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
    auto color(std::string const& value) -> FontSpecs& { obj.attr("color")(value); return *this; }

    /// Sets the font family for the text.
    /// @param value The font family value (e.g., 'Arial', 'Sans-Serif', 'Droid Sans')
    auto family(std::string const& value) -> FontSpecs& { obj.attr("family")(value); return *this; }
};

/// Used to specify the attributes of a line plot in a figure.
class RKP_EXPORT LineSpecs : public Pythonic
{
private:
    /// The Python object of type `reaktplot.LineSpecs`.
    py::object obj;

public:
    /// Construct a default LineSpecs object.
    LineSpecs()
    : obj(Pythonic::createLineSpecs())
    {}

    /// Return the underlying `reakplot.LineSpecs` Python object.
    auto pyspecs() const -> py::object const& { return obj; }

    /// Sets the width of the line element (in px).
    /// @param value The width of the line (in px)
    auto width(int const& value) -> LineSpecs& { obj.attr("width")(value); return *this; }

    /// Sets the color of the line.
    /// @param value The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
    auto color(std::string const& value) -> LineSpecs& { obj.attr("color")(value); return *this; }
};

/// Used to specify the attributes of a marker plot in a figure.
class RKP_EXPORT MarkerSpecs : public Pythonic
{
private:
    /// The Python object of type `reaktplot.MarkerSpecs`.
    py::object obj;

public:
    /// Construct a default MarkerSpecs object.
    MarkerSpecs()
    : obj(Pythonic::createMarkerSpecs())
    {}

    /// Return the underlying `reakplot.MarkerSpecs` Python object.
    auto pyspecs() const -> py::object const& { return obj; }

    /// Sets the marker size (in px).
    /// The size property is a number and may be specified as:
    ///     * An int or float in the interval [0, inf]
    ///     * A tuple, list, or one-dimensional numpy array of the above
    /// @param value The size of the marker (in px)
    auto size(int const& value) -> MarkerSpecs& { obj.attr("size")(value); return *this; }

    /// Sets the marker symbol type.
    /// @param value The marker symbol (e.g, "circle", "diamond", "square", "circle-open")
    auto symbol(std::string const& value) -> MarkerSpecs& { obj.attr("symbol")(value); return *this; }

    /// Sets the color of the marker.
    /// @param value The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
    auto color(std::string const& value) -> MarkerSpecs& { obj.attr("color")(value); return *this; }

    /// Sets the properties of the border line of the marker.
    /// @param value The line specs of the border of the marker
    auto line(LineSpecs const& value) -> MarkerSpecs& { obj.attr("line")(value.pyspecs()); return *this; }

    /// Sets the marker opacity.
    /// @param value The opacity value as a float number in [0, 1]
    auto opacity(float const& value) -> MarkerSpecs& { obj.attr("opacity")(value); return *this; }
};

/// Used to specify the attributes of a contour plot in a figure.
class RKP_EXPORT ContourSpecs : public Pythonic
{
private:
    /// The Python object of type `reaktplot.ContourSpecs`.
    py::object obj;

public:
    /// Construct a default ContourSpecs object.
    ContourSpecs()
    : obj(Pythonic::createContourSpecs())
    {}

    /// Return the underlying `reakplot.ContourSpecs` Python object.
    auto pyspecs() const -> py::object const& { return obj; }

    /// Sets the colorscale of the contour plot. [Check available colorscale names](https://plotly.com/python/builtin-colorscales/).
    /// @param value The name of the colorscale
    auto colorscale(std::string const& value) -> ContourSpecs& { obj.attr("colorscale")(value); return *this; }

    /// Sets the coloring mode of the contour plot to fill.
    auto coloringModeFill() -> ContourSpecs& { obj.attr("coloringModeFill")(); return *this; }

    /// Sets the coloring mode of the contour plot to heatmap.
    auto coloringModeHeatmap() -> ContourSpecs& { obj.attr("coloringModeHeatmap")(); return *this; }

    /// Sets the number of contour lines in the plot.
    /// @param value The number of contour lines in the plot.
    auto numContours(int const& value) -> ContourSpecs& { obj.attr("numContours")(value); return *this; }

    /// Sets or unsets the display of labels along the contour lines.
    /// @param value The flag indicating to show or not labels along contour lines.
    auto showLabels(bool const& value) -> ContourSpecs& { obj.attr("showLabels")(value); return *this; }

    /// Sets or unsets the display of lines in the contour plot (has effect only for fill coloring mode!).
    /// @param value The flag indicating to show or not lines in the contour plot.
    auto showLines(bool const& value) -> ContourSpecs& { obj.attr("showLines")(value); return *this; }

    /// Sets the font specifications for the labels on the contour lines.
    /// @param value The font specifications for the labels
    auto labelFont(FontSpecs const& value) -> ContourSpecs& { obj.attr("labelFont")(value.pyspecs()); return *this; }

    /// Sets the contour label formatting rule using d3 formatting mini-languages which are very similar to those in Python. [Check these format string examples](https://github.com/d3/d3-format/tree/v1.4.5#d3-format).
    /// @param value The formatting rule (e.g., '.1f', '.2e')
    auto labelFormat(std::string const& value) -> ContourSpecs& { obj.attr("labelFormat")(value); return *this; }

    /// Sets the attributes of the lines in the contour plot.
    /// @param value The attributes of the contour lines.
    auto line(LineSpecs const& value) -> ContourSpecs& { obj.attr("line")(value.pyspecs()); return *this; }
};

} // namespace reaktplot
