# reaktplot - a modern C++ scientific plotting library powered by plotly
# https://github.com/reaktplot/reaktplot
#
# Licensed under the MIT License <http://opensource.org/licenses/MIT>.
#
# Copyright (c) 2022-2023 Allan Leal
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
# associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


from __future__ import annotations  # needed to allow Figure as type annotation below for return types


class FontSpecs:
    """Used to specify the attributes of a font for a text in a figure."""

    # Reference: https://plotly.com/python/reference/layout/#layout-title-font

    def __init__(self):
        """Constructs a default FontSpecs object"""
        self.options = dict()


    def size(self, value: int) -> FontSpecs:
        """
        Sets the size of the font (in px).

        Args:
            value (int): the size of the font (in px)
        """
        self.options["size"] = value
        return self


    def color(self, value: str) -> FontSpecs:
        """
        Sets the color of the text.

        Args:
            value (str): The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
        """
        self.options["color"] = value
        return self


    def family(self, value: str) -> FontSpecs:
        """
        Sets the font family for the text.

        Args:
            value (str): The font family value (e.g., 'Arial', 'Sans-Serif', 'Droid Sans')
        """
        self.options["family"] = value
        return self


class LineSpecs:
    """Used to specify the attributes of a line plot in a figure."""

    # Reference: https://plotly.com/python-api-reference/generated/plotly.graph_objects.scatter.marker.html#plotly.graph_objects.scatter.marker.Line

    def __init__(self):
        """Constructs a default LineSpecs object"""
        self.options = dict()


    def width(self, value: int) -> LineSpecs:
        """
        Sets the width of the line element (in px).

        Args:
            value (int): the width of the line (in px)
        """
        self.options["width"] = value
        return self


    def color(self, value: str) -> LineSpecs:
        """
        Sets the color of the line.

        Args:
            value (str): The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
        """
        self.options["color"] = value
        return self


class MarkerSpecs:
    """Used to specify the attributes of a marker plot in a figure."""

    # Reference: https://plotly.com/python-api-reference/generated/plotly.graph_objects.scatter.html#plotly.graph_objects.scatter.Marker

    def __init__(self):
        """Constructs a default MarkerSpecs object"""
        self.options = dict()


    def size(self, value: int) -> MarkerSpecs:
        """
        Sets the marker size (in px).

        The size property is a number and may be specified as:

            * An int or float in the interval [0, inf]
            * A tuple, list, or one-dimensional numpy array of the above

        Args:
            value (int): the size of the marker (in px)
        """
        self.options["size"] = value
        return self


    def symbol(self, value: str) -> MarkerSpecs:
        """
        Sets the marker symbol type.

        Args:
            value (str): the marker symbol (e.g, "circle", "diamond", "square", "circle-open")
        """
        self.options["symbol"] = value
        return self


    def color(self, value: str) -> MarkerSpecs:
        """
        Sets the color of the marker.

        Args:
            value (str): The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
        """
        self.options["color"] = value
        return self


    def line(self, value: LineSpecs) -> MarkerSpecs:
        """
        Sets the properties of the border line of the marker.

        Args:
            value (LineSpecs): the line specs of the border of the marker
        """
        self.options["line"] = value.options
        return self


    def opacity(self, value: float) -> MarkerSpecs:
        """
        Sets the marker opacity.

        Args:
            value (float): the opacity value as a float number in [0, 1]
        """
        self.options["opacity"] = value
        return self


class ContourSpecs:
    """Used to specify the attributes of a contour plot in a figure."""

    # Reference: https://plotly.com/python-api-reference/generated/plotly.graph_objects.Contour.html#plotly.graph_objects.Contour

    def __init__(self):
        """Constructs a default ContourSpecs object"""
        self.options = dict()
        self.options["contours"] = {}

        # Set Portland as the default color scale for contour plots
        self.colorscale("Portland")


    def colorscale(self, value: str) -> ContourSpecs:
        """
        Sets the colorscale of the contour plot. [Check available colorscale names](https://plotly.com/python/builtin-colorscales/).

        Args:
            value (str): the name of the colorscale
        """
        self.options["colorscale"] = value
        return self


    def coloringModeFill(self) -> ContourSpecs:
        """
        Sets the coloring mode of the contour plot to fill.
        """
        self.options["contours_coloring"] = "fill"
        return self


    def coloringModeHeatmap(self) -> ContourSpecs:
        """
        Sets the coloring mode of the contour plot to heatmap.
        """
        self.options["contours_coloring"] = "heatmap"
        return self


    def numContours(self, value: int) -> ContourSpecs:
        """
        Sets the number of contour lines in the plot.

        Args:
            value (int): the number of contour lines in the plot.
        """
        self.options["ncontours"] = value
        return self


    def showLabels(self, value = True) -> ContourSpecs:
        """
        Sets or unsets the display of labels along the contour lines.

        Args:
            value (bool): the flag indicating to show or not labels along contour lines.
        """
        self.options["contours"]["showlabels"] = value
        return self


    def showLines(self, value = True) -> ContourSpecs:
        """
        Sets or unsets the display of lines in the contour plot (has effect only for fill coloring mode!).

        Args:
            value (bool): the flag indicating to show or not lines in the contour plot.
        """
        self.options["contours"]["showlines"] = value
        return self


    def labelFont(self, value: FontSpecs) -> ContourSpecs:
        """
        Sets the font specifications for the labels on the contour lines.

        Args:
            value (FontSpecs): the font specifications for the labels
        """
        self.options["contours"]["labelfont"] = value.options
        return self


    def labelFormat(self, value: str) -> ContourSpecs:
        """
        Sets the contour label formatting rule using d3 formatting mini-languages which are very similar to those in Python. [Check these format string examples](https://github.com/d3/d3-format/tree/v1.4.5#d3-format).

        Args:
            value (str): the formatting rule (e.g., '.1f', '.2e')
        """
        self.options["contours"]["labelformat"] = value
        return self


    def line(self, value: LineSpecs) -> ContourSpecs:
        """
        Sets the attributes of the lines in the contour plot.

        Args:
            value (LineSpecs): the attributes of the contour lines.
        """
        self.options["line"] = value.options
        return self
