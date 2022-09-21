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
        """Constructs a default LineSpecs object"""
        self.options = dict()


    def size(self, value: int) -> LineSpecs:
        """
        Sets the size of the font (in px).

        Args:
            value (int): the size of the font (in px)
        """
        self.options["size"] = value
        return self


    def color(self, value: str) -> LineSpecs:
        """
        Sets the color of the text.

        Args:
            value (str): The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
        """
        self.options["color"] = value
        return self


    def family(self, value: str) -> LineSpecs:
        """
        Sets the font family for the text.

        Args:
            value (str): The font family value (e.g., 'Arial', 'Sans-Serif', 'Droid Sans')
        """
        self.options["family"] = value
        return self


class LineSpecs:
    """Used to specify the attributes of a line element in a figure."""

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
    """Used to specify the attributes of a marker element in a figure."""

    # Reference: https://plotly.com/python-api-reference/generated/plotly.graph_objects.scatter.html#plotly.graph_objects.scatter.Marker

    def __init__(self):
        """Constructs a default MarkerSpecs object"""
        self.options = dict()


    def size(self, value: int):
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


    def symbol(self, value: str):
        """
        Sets the marker symbol type.

        Args:
            value (str): the marker symbol (e.g, "circle", "diamond", "square", "circle-open")
        """
        self.options["symbol"] = value
        return self


    def color(self, value: str):
        """
        Sets the color of the marker.

        Args:
            value (str): The color value (e.g., '#ff0000', 'rgb(100, 150, 200)', 'coral', 'darkblue')
        """
        self.options["color"] = value
        return self


    def line(self, value: LineSpecs):
        """
        Sets the properties of the border line of the marker.

        Args:
            value (LineSpecs): the line specs of the border of the marker
        """
        self.options["line"] = value.options
        return self


    def opacity(self, value: float):
        """
        Sets the marker opacity.

        Args:
            value (float): the opacity value as a float number in [0, 1]
        """
        self.options["opacity"] = value
