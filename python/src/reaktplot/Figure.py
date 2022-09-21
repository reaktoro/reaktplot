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

import plotly as ply
import plotly.graph_objects as pgo
import plotly.io as pio

from .Specs import FontSpecs, ContourSpecs, LineSpecs, MarkerSpecs


class Figure:
    """
    Used to create, show, and save figures using plotly.
    """

    def __init__(self):
        """Construct a default Figure object."""
        self.fig = pgo.Figure()
        self.layout = dict()
        self.xaxis = dict()
        self.yaxis = dict()


    def drawLine(self, x, y, name: str, linespecs = LineSpecs()):
        """Draw a line in the figure."""
        self.fig.add_trace(pgo.Scatter(x=x, y=y, name=name, mode="lines", line=linespecs.options))


    def drawLineWithMarkers(self, x, y, name: str, linespecs = LineSpecs(), markerspecs = MarkerSpecs()):
        """Draw a line with markers in the figure."""
        self.fig.add_trace(pgo.Scatter(x=x, y=y, name=name, mode='lines+markers', line=linespecs.options, marker=markerspecs.options))


    def drawMarkers(self, x, y, name: str, markerspecs = MarkerSpecs()):
        """Draw markers in the figure."""
        self.fig.add_trace(pgo.Scatter(x=x, y=y, name=name, mode='markers', marker=markerspecs.options))


    def drawContour(self, x, y, z, contourspecs = ContourSpecs()):
        """Draw a contour in the figure."""
        self.fig.add_contour(x=x, y=y, z=z, **contourspecs.options)


    def show(self):
        """Show the figure."""
        self.fig.update_layout(self.layout)
        self.fig.update_xaxes(self.xaxis)
        self.fig.update_yaxes(self.yaxis)
        self.fig.show()


    def save(self, file: str, width: int = 800, height: int = 500, scale: float = 1.0):
        """
        Save the figure to a PNG, JPEG, WEBP, SVG, PDF, EPS, or HTML file.

        Args:
            file (str): The name of the file with extension `.png`, `.jpeg`, 'jpg', `.webp`, `.svg`, `.pdf`, `.eps`, or `.html`.
            width (int): The width of the figure (in px). Defaults to 800.
            height (int): The height of the figure (in px). Defaults to 500.
            scale (float): The scaling factor applied to the figure. Defaults to 1.0.
        """
        self.fig.update_layout(self.layout)
        self.fig.update_xaxes(self.xaxis)
        self.fig.update_yaxes(self.yaxis)
        self.fig.write_image(file, width=width, height=height, scale=scale)


    #=================================================================================================================
    #
    # METHODS THAT CUSTOMIZE THE LAYOUT OF THE FIGURE
    #
    #=================================================================================================================


    def titleSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["title"] = value
        return self


    def titleFontSpecs(self, value: dict) -> Figure:
        """
        Sets the title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["title_font"] = value
        return self


    def titleFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.layout["title_font_color"] = value
        return self


    def titleFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.layout["title_font_family"] = value
        return self


    def titleFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["title_font_size"] = value
        return self


    def titlePaddingSpecs(self, value: dict) -> Figure:
        """
        Sets the padding of the title. Each padding value only applies when the corresponding `xanchor`/`yanchor` value is set accordingly. E.g. for left padding to take effect, `xanchor` must be set to "left". The same rule applies if `xanchor`/`yanchor` is determined automatically. Padding is muted if the respective anchor value is "middle"/"center".

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["title_pad"] = value
        return self


    def titlePaddingBottom(self, value: int) -> Figure:
        """
        The amount of padding (in px) along the bottom of the component. (default: 0)

        Args:
            value {int} -- a number
        """
        self.layout["title_pad_b"] = value
        return self


    def titlePaddingLeft(self, value: int) -> Figure:
        """
        The amount of padding (in px) on the left side of the component. (default: 0)

        Args:
            value {int} -- a number
        """
        self.layout["title_pad_l"] = value
        return self


    def titlePaddingRight(self, value: int) -> Figure:
        """
        The amount of padding (in px) on the right side of the component. (default: 0)

        Args:
            value {int} -- a number
        """
        self.layout["title_pad_r"] = value
        return self


    def titlePaddingTop(self, value: int) -> Figure:
        """
        The amount of padding (in px) along the top of the component. (default: 0)

        Args:
            value {int} -- a number
        """
        self.layout["title_pad_t"] = value
        return self


    def titleText(self, value: str) -> Figure:
        """
        Sets the plot's title. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.

        Args:
            value {str} -- a string
        """
        self.layout["title_text"] = value
        return self


    def titleX(self, value: float) -> Figure:
        """
        Sets the x position with respect to `xref` in normalized coordinates from "0" (left) to "1" (right). (Default: d.5)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["title_x"] = value
        return self


    def titleXanchor(self, value: str) -> Figure:
        """
        Sets the title's horizontal alignment with respect to its x position. "left" means that the title starts at x, "right" means that the title ends at x and "center" means that the title's center is at x. "auto" divides `xref` by three and calculates the `xanchor` value automatically based on the value of `x`. (Default: "duto")

        Args:
            value {str} -- a enumerated , one of ( "auto" | "left" | "center" | "right" )
        """
        self.layout["title_xanchor"] = value
        return self


    def titleXref(self, value: str) -> Figure:
        """
        Sets the container `x` refers to. "container" spans the entire `width` of the plot. "paper" refers to the width of the plotting area only. (Default: "dontainer")

        Args:
            value {str} -- a enumerated , one of ( "container" | "paper" )
        """
        self.layout["title_xref"] = value
        return self


    def titleY(self, value: float) -> Figure:
        """
        Sets the y position with respect to `yref` in normalized coordinates from "0" (bottom) to "1" (top). "auto" places the baseline of the title onto the vertical center of the top margin. (Default: "duto")

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["title_y"] = value
        return self


    def titleYanchor(self, value: str) -> Figure:
        """
        Sets the title's vertical alignment with respect to its y position. "top" means that the title's cap line is at y, "bottom" means that the title's baseline is at y and "middle" means that the title's midline is at y. "auto" divides `yref` by three and calculates the `yanchor` value automatically based on the value of `y`. (Default: "duto")

        Args:
            value {str} -- a enumerated , one of ( "auto" | "top" | "middle" | "bottom" )
        """
        self.layout["title_yanchor"] = value
        return self


    def titleYref(self, value: str) -> Figure:
        """
        Sets the container `y` refers to. "container" spans the entire `height` of the plot. "paper" refers to the height of the plotting area only. (Default: "dontainer")

        Args:
            value {str} -- a enumerated , one of ( "container" | "paper" )
        """
        self.layout["title_yref"] = value
        return self


    def legendShow(self, value: bool) -> Figure:
        """
        Determines whether or not a legend is drawn. Default is `True` if there is a trace to show and any of these: a) Two or more traces would by default be shown in the legend. b) One pie trace is shown in the legend. c) One trace is explicitly given with `showlegend: True`.

        Args:
            value {bool} -- a boolean
        """
        self.layout["showlegend"] = value
        return self


    def legendSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["legend"] = value
        return self


    def legendBackgroundColor(self, value: str) -> Figure:
        """
        Sets the legend background color. Defaults to `layout.paper_bgcolor`.

        Args:
            value {str} -- a color
        """
        self.layout["legend_bgcolor"] = value
        return self


    def legendBorderColor(self, value: str) -> Figure:
        """
        Sets the color of the border enclosing the legend. (Default: "#d44")

        Args:
            value {str} -- a color
        """
        self.layout["legend_bordercolor"] = value
        return self


    def legendBorderWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the border enclosing the legend. (default: 0)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["legend_borderwidth"] = value
        return self


    def legendFontSpecs(self, value: dict) -> Figure:
        """
        Sets the font used to text the legend items.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["legend_font"] = value
        return self


    def legendFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.layout["legend_font_color"] = value
        return self


    def legendFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.layout["legend_font_family"] = value
        return self


    def legendFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["legend_font_size"] = value
        return self


    def legendGroupClick(self, value: str) -> Figure:
        """
        Determines the behavior on legend group item click. "toggleitem" toggles the visibility of the individual item clicked on the graph. "togglegroup" toggles the visibility of all items in the same legendgroup as the item clicked on the graph. (Default: "dogglegroup")

        Args:
            value {str} -- a enumerated , one of ( "toggleitem" | "togglegroup" )
        """
        self.layout["legend_groupclick"] = value
        return self


    def legendGroupTitleFontSpecs(self, value: dict) -> Figure:
        """
        Sets the font for group titles in legend. Defaults to `legend.font` with its size increased about 10%.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["legend_grouptitlefont"] = value
        return self


    def legendGroupTitleFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.layout["legend_grouptitlefont_color"] = value
        return self


    def legendGroupTitleFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.layout["legend_grouptitlefont_family"] = value
        return self


    def legendGroupTitleFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["legend_grouptitlefont_size"] = value
        return self


    def legendItemClick(self, value: str) -> Figure:
        """
        Determines the behavior on legend item click. "toggle" toggles the visibility of the item clicked on the graph. "toggleothers" makes the clicked item the sole visible item on the graph. "False" disables legend item click interactions. (Default: "doggle")

        Args:
            value {str} -- a enumerated , one of ( "toggle" | "toggleothers" | False )
        """
        self.layout["legend_itemclick"] = value
        return self


    def legendItemDoubleClick(self, value: str) -> Figure:
        """
        Determines the behavior on legend item double-click. "toggle" toggles the visibility of the item clicked on the graph. "toggleothers" makes the clicked item the sole visible item on the graph. "False" disables legend item double-click interactions. (Default: "doggleothers")

        Args:
            value {str} -- a enumerated , one of ( "toggle" | "toggleothers" | False )
        """
        self.layout["legend_itemdoubleclick"] = value
        return self


    def legendItemSizing(self, value: str) -> Figure:
        """
        Determines if the legend items symbols scale with their corresponding "trace" attributes or remain "constant" independent of the symbol size on the graph. (Default: "drace")

        Args:
            value {str} -- a enumerated , one of ( "trace" | "constant" )
        """
        self.layout["legend_itemsizing"] = value
        return self


    def legendItemWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the legend item symbols (the part other than the title.text). (default: 30)

        Args:
            value {int} -- a number greater than or equal to 30
        """
        self.layout["legend_itemwidth"] = value
        return self


    def legendOrientation(self, value: str) -> Figure:
        """
        Sets the orientation of the legend. (Default: "d")

        Args:
            value {str} -- a enumerated , one of ( "v" | "h" )
        """
        self.layout["legend_orientation"] = value
        return self


    def legendTitleSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["legend_title"] = value
        return self


    def legendTitleFontSpecs(self, value: dict) -> Figure:
        """
        Sets this legend's title font. Defaults to `legend.font` with its size increased about 20%.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["legend_title_font"] = value
        return self


    def legendTitleFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.layout["legend_title_font_color"] = value
        return self


    def legendTitleFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.layout["legend_title_font_family"] = value
        return self


    def legendTitleFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["legend_title_font_size"] = value
        return self


    def legendTitleSide(self, value: str) -> Figure:
        """
        Determines the location of legend's title with respect to the legend items. Defaulted to "top" with `orientation` is "h". Defaulted to "left" with `orientation` is "v". The "top left" options could be used to expand legend area in both x and y sides.

        Args:
            value {str} -- a enumerated , one of ( "top" | "left" | "top left" )
        """
        self.layout["legend_title_side"] = value
        return self


    def legendTitleText(self, value: str) -> Figure:
        """
        Sets the title of the legend. (default: "")

        Args:
            value {str} -- a string
        """
        self.layout["legend_title_text"] = value
        return self


    def legendTraceGroupGap(self, value: int) -> Figure:
        """
        Sets the amount of vertical space (in px) between legend groups. (default: 10)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["legend_tracegroupgap"] = value
        return self


    def legendTraceOrder(self, value: str) -> Figure:
        """
        Determines the order at which the legend items are displayed. If "normal", the items are displayed top-to-bottom in the same order as the input data. If "reversed", the items are displayed in the opposite order as "normal". If "grouped", the items are displayed in groups (when a trace `legendgroup` is provided). if "grouped+reversed", the items are displayed in the opposite order as "grouped".

        Args:
            value {str} -- a flaglist string. Any combination of "reversed", "grouped" joined with a "+" OR "normal". Examples: "reversed", "grouped", "reversed+grouped", "normal"
        """
        self.layout["legend_traceorder"] = value
        return self


    def legendUirevision(self, value: str) -> Figure:
        """
        Controls persistence of legend-driven changes in trace and pie label visibility. Defaults to `layout.uirevision`.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["legend_uirevision"] = value
        return self


    def legendValign(self, value: str) -> Figure:
        """
        Sets the vertical alignment of the symbols with respect to their associated text. (Default: "diddle")

        Args:
            value {str} -- a enumerated , one of ( "top" | "middle" | "bottom" )
        """
        self.layout["legend_valign"] = value
        return self


    def legendX(self, value: float) -> Figure:
        """
        Sets the x position (in normalized coordinates) of the legend. Defaults to "1.02" for vertical legends and defaults to "0" for horizontal legends.

        Args:
            value {float} -- a number between or equal to -2 and 3
        """
        self.layout["legend_x"] = value
        return self


    def legendXanchor(self, value: str) -> Figure:
        """
        Sets the legend's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the legend. Value "auto" anchors legends to the right for `x` values greater than or equal to 2/3, anchors legends to the left for `x` values less than or equal to 1/3 and anchors legends with respect to their center otherwise. (Default: "deft")

        Args:
            value {str} -- a enumerated , one of ( "auto" | "left" | "center" | "right" )
        """
        self.layout["legend_xanchor"] = value
        return self


    def legendY(self, value: float) -> Figure:
        """
        Sets the y position (in normalized coordinates) of the legend. Defaults to "1" for vertical legends, defaults to "-0.1" for horizontal legends on graphs w/o range sliders and defaults to "1.1" for horizontal legends on graph with one or multiple range sliders.

        Args:
            value {float} -- a number between or equal to -2 and 3
        """
        self.layout["legend_y"] = value
        return self


    def legendYanchor(self, value: str) -> Figure:
        """
        Sets the legend's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the legend. Value "auto" anchors legends at their bottom for `y` values less than or equal to 1/3, anchors legends to at their top for `y` values greater than or equal to 2/3 and anchors legends with respect to their middle otherwise.

        Args:
            value {str} -- a enumerated , one of ( "auto" | "top" | "middle" | "bottom" )
        """
        self.layout["legend_yanchor"] = value
        return self


    def marginSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["margin"] = value
        return self


    def marginAutoExpand(self, value: bool) -> Figure:
        """
        Turns on/off margin expansion computations. Legends, colorbars, updatemenus, sliders, axis rangeselector and rangeslider are allowed to push the margins by defaults. (default: True)

        Args:
            value {bool} -- a boolean
        """
        self.layout["margin_autoexpand"] = value
        return self


    def marginBottom(self, value: int) -> Figure:
        """
        Sets the bottom margin (in px). (default: 80)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["margin_b"] = value
        return self


    def marginLeft(self, value: int) -> Figure:
        """
        Sets the left margin (in px). (default: 80)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["margin_l"] = value
        return self


    def marginPadding(self, value: int) -> Figure:
        """
        Sets the amount of padding (in px) between the plotting area and the axis lines (default: 0)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["margin_pad"] = value
        return self


    def marginRight(self, value: int) -> Figure:
        """
        Sets the right margin (in px). (default: 80)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["margin_r"] = value
        return self


    def marginTop(self, value: int) -> Figure:
        """
        Sets the top margin (in px). (default: 100)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["margin_t"] = value
        return self


    def autosize(self, value: bool) -> Figure:
        """
        Determines whether or not a layout width or height that has been left undefined by the user is initialized on each relayout. Note that, regardless of this attribute, an undefined layout width or height is always initialized on the first call to plot.

        Args:
            value {bool} -- a boolean
        """
        self.layout["autosize"] = value
        return self


    def width(self, value: int) -> Figure:
        """
        Sets the plot's width (in px). (default: 700)

        Args:
            value {int} -- a number greater than or equal to 10
        """
        self.layout["width"] = value
        return self


    def height(self, value: int) -> Figure:
        """
        Sets the plot's height (in px). (default: 450)

        Args:
            value {int} -- a number greater than or equal to 10
        """
        self.layout["height"] = value
        return self


    def fontSpecs(self, value: dict) -> Figure:
        """
        Sets the global font. Note that fonts used in traces and other layout components inherit from the global font.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["font"] = value
        return self


    def fontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.layout["font_color"] = value
        return self


    def fontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman". (Default: ""Open Sans", verdana, arial, sans-derif")

        Args:
            value {str} -- a string
        """
        self.layout["font_family"] = value
        return self


    def fontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["font_size"] = value
        return self


    def uniformTextSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["uniformtext"] = value
        return self


    def uniformTextMinSize(self, value: int) -> Figure:
        """
        Sets the minimum text size between traces of the same type. (default: 0)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["uniformtext_minsize"] = value
        return self


    def uniformTextMode(self, value: str) -> Figure:
        """
        Determines how the font size for various text elements are uniformed between each trace type. If the computed text sizes were smaller than the minimum size defined by `uniformtext.minsize` using "hide" option hides the text; and using "show" option shows the text without further downscaling. Please note that if the size defined by `minsize` is greater than the font size defined by trace, then the `minsize` is used.

        Args:
            value {str} -- a enumerated , one of ( False | "hide" | "show" )
        """
        self.layout["uniformtext_mode"] = value
        return self


    def separators(self, value: str) -> Figure:
        """
        Sets the decimal and thousand separators. For example, ". " puts a '.' before decimals and a space between thousands. In English locales, dflt is ".," but other locales may alter this default.

        Args:
            value {str} -- a string
        """
        self.layout["separators"] = value
        return self


    def paperBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of the paper where the graph is drawn. (Default: "#dff")

        Args:
            value {str} -- a color
        """
        self.layout["paper_bgcolor"] = value
        return self


    def plotBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of the plotting area in-between x and y axes. (Default: "#dff")

        Args:
            value {str} -- a color
        """
        self.layout["plot_bgcolor"] = value
        return self


    def autoTypeNumbers(self, value: str) -> Figure:
        """
        Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. This is the default value; however it could be overridden for individual axes. (Default: "convert dypes")

        Args:
            value {str} -- a enumerated , one of ( "convert types" | "strict" )
        """
        self.layout["autotypenumbers"] = value
        return self


    def colorScaleSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["colorscale"] = value
        return self


    def colorScaleDiverging(self, value: str) -> Figure:
        """
        Sets the default diverging colorscale. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(5,10,172)], [0.35, rgb(106,137,247)], [0.5, rgb(190,190,190)], [0.6, rgb(220,170,132)], [0.7, rgb(230,145,90)], [1, rgb(178,10,28d], ])

        Args:
            value {str} -- a colorscale
        """
        self.layout["colorscale_diverging"] = value
        return self


    def colorScaleSequential(self, value: str) -> Figure:
        """
        Sets the default sequential colorscale for positive values. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(220,220,220)], [0.2, rgb(245,195,157)], [0.4, rgb(245,160,105)], [1, rgb(178,10,28d], ])

        Args:
            value {str} -- a colorscale
        """
        self.layout["colorscale_sequential"] = value
        return self


    def colorScaleSequentialminus(self, value: str) -> Figure:
        """
        Sets the default sequential colorscale for negative values. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(5,10,172)], [0.35, rgb(40,60,190)], [0.5, rgb(70,100,245)], [0.6, rgb(90,120,245)], [0.7, rgb(106,137,247)], [1, rgb(220,220,220d], ])

        Args:
            value {str} -- a colorscale
        """
        self.layout["colorscale_sequentialminus"] = value
        return self


    def colorway(self, value: list) -> Figure:
        """
        Sets the default trace colors. (Default: [#1f77b4, #ff7f0e, #2ca02c, #d62728, #9467bd, #8c564b, #e377c2, #7f7f7f, #bcbd22, #d7becf])

        Args:
            value {list} -- a colorlist
        """
        self.layout["colorway"] = value
        return self


    def modebarSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["modebar"] = value
        return self


    def modebarActiveColor(self, value: str) -> Figure:
        """
        Sets the color of the active or hovered on icons in the modebar.

        Args:
            value {str} -- a color
        """
        self.layout["modebar_activecolor"] = value
        return self


    def modebarAdd(self, value: str) -> Figure:
        """
        Determines which predefined modebar buttons to add. Please note that these buttons will only be shown if they are compatible with all trace types used in a graph. Similar to `config.modeBarButtonsToAdd` option. This may include "v1hovermode", "hoverclosest", "hovercompare", "togglehover", "togglespikelines", "drawline", "drawopenpath", "drawclosedpath", "drawcircle", "drawrect", "eraseshape". (default: "")

        Args:
            value {str} -- a string or array of strings
        """
        self.layout["modebar_add"] = value
        return self


    def modebarBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of the modebar.

        Args:
            value {str} -- a color
        """
        self.layout["modebar_bgcolor"] = value
        return self


    def modebarColor(self, value: str) -> Figure:
        """
        Sets the color of the icons in the modebar.

        Args:
            value {str} -- a color
        """
        self.layout["modebar_color"] = value
        return self


    def modebarOrientation(self, value: str) -> Figure:
        """
        Sets the orientation of the modebar. (Default: "d")

        Args:
            value {str} -- a enumerated , one of ( "v" | "h" )
        """
        self.layout["modebar_orientation"] = value
        return self


    def modebarRemove(self, value: str) -> Figure:
        """
        Determines which predefined modebar buttons to remove. Similar to `config.modeBarButtonsToRemove` option. This may include "autoScale2d", "autoscale", "editInChartStudio", "editinchartstudio", "hoverCompareCartesian", "hovercompare", "lasso", "lasso2d", "orbitRotation", "orbitrotation", "pan", "pan2d", "pan3d", "reset", "resetCameraDefault3d", "resetCameraLastSave3d", "resetGeo", "resetSankeyGroup", "resetScale2d", "resetViewMapbox", "resetViews", "resetcameradefault", "resetcameralastsave", "resetsankeygroup", "resetscale", "resetview", "resetviews", "select", "select2d", "sendDataToCloud", "senddatatocloud", "tableRotation", "tablerotation", "toImage", "toggleHover", "toggleSpikelines", "togglehover", "togglespikelines", "toimage", "zoom", "zoom2d", "zoom3d", "zoomIn2d", "zoomInGeo", "zoomInMapbox", "zoomOut2d", "zoomOutGeo", "zoomOutMapbox", "zoomin", "zoomout". (default: "")

        Args:
            value {str} -- a string or array of strings
        """
        self.layout["modebar_remove"] = value
        return self


    def modebarUirevision(self, value: str) -> Figure:
        """
        Controls persistence of user-driven changes related to the modebar, including `hovermode`, `dragmode`, and `showspikes` at both the root level and inside subplots. Defaults to `layout.uirevision`.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["modebar_uirevision"] = value
        return self


    def hoverMode(self, value: str) -> Figure:
        """
        Determines the mode of hover interactions. If "closest", a single hoverlabel will appear for the "closest" point within the `hoverdistance`. If "x" (or "y"), multiple hoverlabels will appear for multiple points at the "closest" x- (or y-) coordinate within the `hoverdistance`, with the caveat that no more than one hoverlabel will appear per trace. If "x unified" (or "y unified"), a single hoverlabel will appear multiple points at the closest x- (or y-) coordinate within the `hoverdistance` with the caveat that no more than one hoverlabel will appear per trace. In this mode, spikelines are enabled by default perpendicular to the specified axis. If False, hover interactions are disabled. (Default: "dlosest")

        Args:
            value {str} -- a enumerated , one of ( "x" | "y" | "closest" | False | "x unified" | "y unified" )
        """
        self.layout["hovermode"] = value
        return self


    def clickMode(self, value: str) -> Figure:
        """
        Examples: "event", "select", "event+select", "none"

        Args:
            value {str} -- a flaglist string. Any combination of "event", "select" joined with a "+" OR "none".
        """
        self.layout["clickmode"] = value
        return self


    def dragMode(self, value: str) -> Figure:
        """
        Determines the mode of drag interactions. "select" and "lasso" apply only to scatter traces with markers or text. "orbit" and "turntable" apply only to 3D scenes. (Default: "doom")

        Args:
            value {str} -- a enumerated , one of ( "zoom" | "pan" | "select" | "lasso" | "drawclosedpath" | "drawopenpath" | "drawline" | "drawrect" | "drawcircle" | "orbit" | "turntable" | False )
        """
        self.layout["dragmode"] = value
        return self


    def selectDirection(self, value: str) -> Figure:
        """
        When `dragmode` is set to "select", this limits the selection of the drag to horizontal, vertical or diagonal. "h" only allows horizontal selection, "v" only vertical, "d" only diagonal and "any" sets no limit. (Default: "dny")

        Args:
            value {str} -- a enumerated , one of ( "h" | "v" | "d" | "any" )
        """
        self.layout["selectdirection"] = value
        return self


    def activeSelectionSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["activeselection"] = value
        return self


    def activeSelectionFillColor(self, value: str) -> Figure:
        """
        Sets the color filling the active selection' interior. (Default: "rgba(0,0,0,d)")

        Args:
            value {str} -- a color
        """
        self.layout["activeselection_fillcolor"] = value
        return self


    def activeSelectionOpacity(self, value: float) -> Figure:
        """
        Sets the opacity of the active selection. (Default: d.5)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["activeselection_opacity"] = value
        return self


    def newSelectionSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["newselection"] = value
        return self


    def newSelectionLineSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["newselection_line"] = value
        return self


    def newSelectionLineColor(self, value: str) -> Figure:
        """
        Sets the line color. By default uses either dark grey or white to increase contrast with background color.

        Args:
            value {str} -- a color
        """
        self.layout["newselection_line_color"] = value
        return self


    def newSelectionLineDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dot")

        Args:
            value {str} -- a string
        """
        self.layout["newselection_line_dash"] = value
        return self


    def newSelectionLineWidth(self, value: int) -> Figure:
        """
        Sets the line width (in px). (default: 1)

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["newselection_line_width"] = value
        return self


    def newSelectionMode(self, value: str) -> Figure:
        """
        Describes how a new selection is created. If `immediate`, a new selection is created after first mouse up. If `gradual`, a new selection is not created after first mouse. By adding to and subtracting from the initial selection, this option allows declaring extra outlines of the selection. (Default: "dmmediate")

        Args:
            value {str} -- a enumerated , one of ( "immediate" | "gradual" )
        """
        self.layout["newselection_mode"] = value
        return self


    def hoverDistance(self, value: str) -> Figure:
        """
        Sets the default distance (in pixels) to look for data to add hover labels (-1 means no cutoff, 0 means no looking for data). This is only a real distance for hovering on point-like objects, like scatter points. For area-like objects (bars, scatter fills, etc) hovering is on inside the area and off outside, but these objects will not supersede hover on point-like objects in case of conflict. (default: 20)

        Args:
            value {str} -- a integer greater than or equal to -1
        """
        self.layout["hoverdistance"] = value
        return self


    def spikeDistance(self, value: str) -> Figure:
        """
        Sets the default distance (in pixels) to look for data to draw spikelines to (-1 means no cutoff, 0 means no looking for data). As with hoverdistance, distance does not apply to area-like objects. In addition, some objects can be hovered on but will not generate spikelines, such as scatter fills. (Default: d1)

        Args:
            value {str} -- a integer greater than or equal to -1
        """
        self.layout["spikedistance"] = value
        return self


    def hoverLabelSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["hoverlabel"] = value
        return self


    def hoverLabelAlign(self, value: str) -> Figure:
        """
        Sets the horizontal alignment of the text content within hover label box. Has an effect only if the hover label text spans more two or more lines (Default: "duto")

        Args:
            value {str} -- a enumerated , one of ( "left" | "right" | "auto" )
        """
        self.layout["hoverlabel_align"] = value
        return self


    def hoverLabelBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of all hover labels on graph

        Args:
            value {str} -- a color
        """
        self.layout["hoverlabel_bgcolor"] = value
        return self


    def hoverLabelBorderColor(self, value: str) -> Figure:
        """
        Sets the border color of all hover labels on graph.

        Args:
            value {str} -- a color
        """
        self.layout["hoverlabel_bordercolor"] = value
        return self


    def hoverLabelFontSpecs(self, value: dict) -> Figure:
        """
        Sets the default hover label font used by all traces on the graph.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["hoverlabel_font"] = value
        return self


    def hoverLabelFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.layout["hoverlabel_font_color"] = value
        return self


    def hoverLabelFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman". (Default: "Arial, sans-derif")

        Args:
            value {str} -- a string
        """
        self.layout["hoverlabel_font_family"] = value
        return self


    def hoverLabelFontSize(self, value: int) -> Figure:
        """
        grouptitlefont (default: 13)

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["hoverlabel_font_size"] = value
        return self


    def hoverLabelGroupTitleFontSpecs(self, value: dict) -> Figure:
        """
        Sets the font for group titles in hover (unified modes). Defaults to `hoverlabel.font`.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["hoverlabel_grouptitlefont"] = value
        return self


    def hoverLabelGroupTitleFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.layout["hoverlabel_grouptitlefont_color"] = value
        return self


    def hoverLabelGroupTitleFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.layout["hoverlabel_grouptitlefont_family"] = value
        return self


    def hoverLabelGroupTitleFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["hoverlabel_grouptitlefont_size"] = value
        return self


    def hoverLabelNamelength(self, value: str) -> Figure:
        """
        Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters and add an ellipsis. (default: 15)

        Args:
            value {str} -- a integer greater than or equal to -1
        """
        self.layout["hoverlabel_namelength"] = value
        return self


    def transitionSpecs(self, value: dict) -> Figure:
        """
        Sets transition options used during Plotly.react updates.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["transition"] = value
        return self


    def transitionDuration(self, value: int) -> Figure:
        """
        The duration of the transition, in milliseconds. If equal to zero, updates are synchronous. (default: 500)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["transition_duration"] = value
        return self


    def transitionEasing(self, value: str) -> Figure:
        """
        The easing function used for the transition (Default: "cubic-in-dut")

        Args:
            value {str} -- a enumerated , one of ( "linear" | "quad" | "cubic" | "sin" | "exp" | "circle" | "elastic" | "back" | "bounce" | "linear-in" | "quad-in" | "cubic-in" | "sin-in" | "exp-in" | "circle-in" | "elastic-in" | "back-in" | "bounce-in" | "linear-out" | "quad-out" | "cubic-out" | "sin-out" | "exp-out" | "circle-out" | "elastic-out" | "back-out" | "bounce-out" | "linear-in-out" | "quad-in-out" | "cubic-in-out" | "sin-in-out" | "exp-in-out" | "circle-in-out" | "elastic-in-out" | "back-in-out" | "bounce-in-out" )
        """
        self.layout["transition_easing"] = value
        return self


    def transitionOrdering(self, value: str) -> Figure:
        """
        Determines whether the figure's layout or traces smoothly transitions during updates that make both traces and layout change. (Default: "layout dirst")

        Args:
            value {str} -- a enumerated , one of ( "layout first" | "traces first" )
        """
        self.layout["transition_ordering"] = value
        return self


    def dataRevision(self, value: str) -> Figure:
        """
        If provided, a changed value tells `Plotly.react` that one or more data arrays has changed. This way you can modify arrays in-place rather than making a complete new copy for an incremental change. If NOT provided, `Plotly.react` assumes that data arrays are being treated as immutable, thus any data array with a different identity from its predecessor contains new data.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["datarevision"] = value
        return self


    def uiRevision(self, value: str) -> Figure:
        """
        Used to allow user interactions with the plot to persist after `Plotly.react` calls that are unaware of these interactions. If `uirevision` is omitted, or if it is given and it changed from the previous `Plotly.react` call, the exact new figure is used. If `uirevision` is truthy and did NOT change, any attribute that has been affected by user interactions and did not receive a different value in the new figure will keep the interaction value. `layout.uirevision` attribute serves as the default for `uirevision` attributes in various sub-containers. For finer control you can set these sub-attributes directly. For example, if your app separately controls the data on the x and y axes you might set `xaxis.uirevision="time"` and `yaxis.uirevision="cost"`. Then if only the y data is changed, you can update `yaxis.uirevision="quantity"` and the y axis range will reset but the x axis range will retain any user-driven zoom.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["uirevision"] = value
        return self


    def editRevision(self, value: str) -> Figure:
        """
        Controls persistence of user-driven changes in `editable: True` configuration, other than trace names and axis titles. Defaults to `layout.uirevision`.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["editrevision"] = value
        return self


    def selectionRevision(self, value: str) -> Figure:
        """
        Controls persistence of user-driven changes in selected points from all traces.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["selectionrevision"] = value
        return self


    def templateSpecs(self, value: dict) -> Figure:
        """
        Default attributes to be applied to the plot. Templates can be created from existing plots using `Plotly.makeTemplate`, or created manually. They should be objects with format: `{layout: layoutTemplate, data: {[type]: [traceTemplate, ...]}, ...}` `layoutTemplate` and `traceTemplate` are objects matching the attribute structure of `layout` and a data trace. Trace templates are applied cyclically to traces of each type. Container arrays (eg `annotations`) have special handling: An object ending in `defaults` (eg `annotationdefaults`) is applied to each array item. But if an item has a `templateitemname` key we look in the template array for an item with matching `name` and apply that instead. If no matching `name` is found we mark the item invisible. Any named template item not referenced is appended to the end of the array, so you can use this for a watermark annotation or a logo image, for example. To omit one of these items on the plot, make an item with matching `templateitemname` and `visible: False`.

        Args:
            value {dict} -- dict containing the customization of the figure
        """
        self.layout["template"] = value
        return self


    def meta(self, value: str) -> Figure:
        """
        Assigns extra meta information that can be used in various `text` attributes. Attributes such as the graph, axis and colorbar `title.text`, annotation `text` `trace.name` in legend items, `rangeselector`, `updatemenus` and `sliders` `label` text all support `meta`. One can access `meta` fields using template strings: `%{meta[i]}` where `i` is the index of the `meta` item in question. `meta` can also be an object for example `{key: value}` which can be accessed %{meta[key]}.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["meta"] = value
        return self


    def computed(self, value: str) -> Figure:
        """
        Placeholder for exporting automargin-impacting values namely `margin.t`, `margin.b`, `margin.l` and `margin.r` in "full-json" mode.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["computed"] = value
        return self


    def gridSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["grid"] = value
        return self


    def gridColumns(self, value: str) -> Figure:
        """
        The number of columns in the grid. If you provide a 2D `subplots` array, the length of its longest row is used as the default. If you give an `xaxes` array, its length is used as the default. But it's also possible to have a different length, if you want to leave a row at the end for non-cartesian subplots.

        Args:
            value {str} -- a integer greater than or equal to 1
        """
        self.layout["grid_columns"] = value
        return self


    def gridDomainSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["grid_domain"] = value
        return self


    def gridDomainX(self, value: str) -> Figure:
        """
        Sets the horizontal domain of this grid subplot (in plot fraction). The first and last cells end exactly at the domain edges, with no grout around the edges. (Default: [0, d])

        Args:
            value {str} -- a list
        """
        self.layout["grid_domain_x"] = value
        return self


    def gridDomainY(self, value: str) -> Figure:
        """
        Sets the vertical domain of this grid subplot (in plot fraction). The first and last cells end exactly at the domain edges, with no grout around the edges. (Default: [0, d])

        Args:
            value {str} -- a list
        """
        self.layout["grid_domain_y"] = value
        return self


    def gridPattern(self, value: str) -> Figure:
        """
        If no `subplots`, `xaxes`, or `yaxes` are given but we do have `rows` and `columns`, we can generate defaults using consecutive axis IDs, in two ways: "coupled" gives one x axis per column and one y axis per row. "independent" uses a new xy pair for each cell, left-to-right across each row then iterating rows according to `roworder`. (Default: "doupled")

        Args:
            value {str} -- a enumerated , one of ( "independent" | "coupled" )
        """
        self.layout["grid_pattern"] = value
        return self


    def gridRoworder(self, value: str) -> Figure:
        """
        Is the first row the top or the bottom? Note that columns are always enumerated from left to right. (Default: "top to dottom")

        Args:
            value {str} -- a enumerated , one of ( "top to bottom" | "bottom to top" )
        """
        self.layout["grid_roworder"] = value
        return self


    def gridRows(self, value: str) -> Figure:
        """
        The number of rows in the grid. If you provide a 2D `subplots` array or a `yaxes` array, its length is used as the default. But it's also possible to have a different length, if you want to leave a row at the end for non-cartesian subplots.

        Args:
            value {str} -- a integer greater than or equal to 1
        """
        self.layout["grid_rows"] = value
        return self


    def gridSubplots(self, value: str) -> Figure:
        """
        Used for freeform grids, where some axes may be shared across subplots but others are not. Each entry should be a cartesian subplot id, like "xy" or "x3y2", or "" to leave that cell empty. You may reuse x axes within the same column, and y axes within the same row. Non-cartesian subplots and traces that support `domain` can place themselves in this grid separately using the `gridcell` attribute.

        Args:
            value {str} -- a list
        """
        self.layout["grid_subplots"] = value
        return self


    def gridXaxes(self, value: str) -> Figure:
        """
        Used with `yaxes` when the x and y axes are shared across columns and rows. Each entry should be an x axis id like "x", "x2", etc., or "" to not put an x axis in that column. Entries other than "" must be unique. Ignored if `subplots` is present. If missing but `yaxes` is present, will generate consecutive IDs.

        Args:
            value {str} -- a list
        """
        self.layout["grid_xaxes"] = value
        return self


    def gridXgap(self, value: float) -> Figure:
        """
        Horizontal space between grid cells, expressed as a fraction of the total width available to one cell. Defaults to 0.1 for coupled-axes grids and 0.2 for independent grids.

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["grid_xgap"] = value
        return self


    def gridXside(self, value: str) -> Figure:
        """
        Sets where the x axis labels and titles go. "bottom" means the very bottom of the grid. "bottom plot" is the lowest plot that each x axis is used in. "top" and "top plot" are similar. (Default: "bottom dlot")

        Args:
            value {str} -- a enumerated , one of ( "bottom" | "bottom plot" | "top plot" | "top" )
        """
        self.layout["grid_xside"] = value
        return self


    def gridYaxes(self, value: str) -> Figure:
        """
        Used with `yaxes` when the x and y axes are shared across columns and rows. Each entry should be an y axis id like "y", "y2", etc., or "" to not put a y axis in that row. Entries other than "" must be unique. Ignored if `subplots` is present. If missing but `xaxes` is present, will generate consecutive IDs.

        Args:
            value {str} -- a list
        """
        self.layout["grid_yaxes"] = value
        return self


    def gridYgap(self, value: float) -> Figure:
        """
        Vertical space between grid cells, expressed as a fraction of the total height available to one cell. Defaults to 0.1 for coupled-axes grids and 0.3 for independent grids.

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["grid_ygap"] = value
        return self


    def gridYside(self, value: str) -> Figure:
        """
        Sets where the y axis labels and titles go. "left" means the very left edge of the grid. "left plot" is the leftmost plot that each y axis is used in. "right" and "right plot" are similar. (Default: "left dlot")

        Args:
            value {str} -- a enumerated , one of ( "left" | "left plot" | "right plot" | "right" )
        """
        self.layout["grid_yside"] = value
        return self


    def calendar(self, value: str) -> Figure:
        """
        Sets the default calendar system to use for interpreting and displaying dates throughout the plot. (Default: "dregorian")

        Args:
            value {str} -- a enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" )
        """
        self.layout["calendar"] = value
        return self


    def newShapeSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["newshape"] = value
        return self


    def newShapeDrawdirection(self, value: str) -> Figure:
        """
        When `dragmode` is set to "drawrect", "drawline" or "drawcircle" this limits the drag to be horizontal, vertical or diagonal. Using "diagonal" there is no limit e.g. in drawing lines in any direction. "ortho" limits the draw to be either horizontal or vertical. "horizontal" allows horizontal extend. "vertical" allows vertical extend. (Default: "diagonal")

        Args:
            value {str} -- a enumerated , one of ( "ortho" | "horizontal" | "vertical" | "diagonal" )
        """
        self.layout["newshape_drawdirection"] = value
        return self


    def newShapeFillColor(self, value: str) -> Figure:
        """
        Sets the color filling new shapes' interior. Please note that if using a fillcolor with alpha greater than half, drag inside the active shape starts moving the shape underneath, otherwise a new shape could be started over. (Default: "rgba(0,0,0,d)")

        Args:
            value {str} -- a color
        """
        self.layout["newshape_fillcolor"] = value
        return self


    def newShapeFillrule(self, value: str) -> Figure:
        """
        Determines the path's interior. For more info please visit https://developer.mozilla.org/en-US/docs/Web/SVG/Attribute/fill-rule (Default: "dvenodd")

        Args:
            value {str} -- a enumerated , one of ( "evenodd" | "nonzero" )
        """
        self.layout["newshape_fillrule"] = value
        return self


    def newShapeLayer(self, value: str) -> Figure:
        """
        Specifies whether new shapes are drawn below or above traces. (Default: "dbove")

        Args:
            value {str} -- a enumerated , one of ( "below" | "above" )
        """
        self.layout["newshape_layer"] = value
        return self


    def newShapeLineSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["newshape_line"] = value
        return self


    def newShapeLineColor(self, value: str) -> Figure:
        """
        Sets the line color. By default uses either dark grey or white to increase contrast with background color.

        Args:
            value {str} -- a color
        """
        self.layout["newshape_line_color"] = value
        return self


    def newShapeLineDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dolid")

        Args:
            value {str} -- a string
        """
        self.layout["newshape_line_dash"] = value
        return self


    def newShapeLineWidth(self, value: int) -> Figure:
        """
        Sets the line width (in px). (default: 4)

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.layout["newshape_line_width"] = value
        return self


    def newShapeOpacity(self, value: float) -> Figure:
        """
        Sets the opacity of new shapes. (default: 1)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["newshape_opacity"] = value
        return self


    def activeShapeSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["activeshape"] = value
        return self


    def activeShapeFillColor(self, value: str) -> Figure:
        """
        Sets the color filling the active shape' interior. (Default: "rgb(255,0,d55)")

        Args:
            value {str} -- a color
        """
        self.layout["activeshape_fillcolor"] = value
        return self


    def activeShapeOpacity(self, value: float) -> Figure:
        """
        Sets the opacity of the active shape. (Default: d.5)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["activeshape_opacity"] = value
        return self


    def selections(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a list of dict where each dict has one or more of the keys listed below.
        """
        self.layout["selections"] = value
        return self


    def selectionsLineSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.layout["selections_line"] = value
        return self


    def selectionsLineColor(self, value: str) -> Figure:
        """
        Sets the line color.

        Args:
            value {str} -- a color
        """
        self.layout["selections_line_color"] = value
        return self


    def selectionsLineDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dot")

        Args:
            value {str} -- a string
        """
        self.layout["selections_line_dash"] = value
        return self


    def selectionsLineWidth(self, value: int) -> Figure:
        """
        Sets the line width (in px). (default: 1)

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.layout["selections_line_width"] = value
        return self


    def selectionsName(self, value: str) -> Figure:
        """
        When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.

        Args:
            value {str} -- a string
        """
        self.layout["selections_name"] = value
        return self


    def selectionsOpacity(self, value: float) -> Figure:
        """
        Sets the opacity of the selection. (Default: d.7)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["selections_opacity"] = value
        return self


    def selectionsPath(self, value: str) -> Figure:
        """
        For `type` "path" - a valid SVG path similar to `shapes.path` in data coordinates. Allowed segments are: M, L and Z.

        Args:
            value {str} -- a string
        """
        self.layout["selections_path"] = value
        return self


    def selectionsTemplateItemName(self, value: str) -> Figure:
        """
        Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.

        Args:
            value {str} -- a string
        """
        self.layout["selections_templateitemname"] = value
        return self


    def selectionsType(self, value: str) -> Figure:
        """
        Specifies the selection type to be drawn. If "rect", a rectangle is drawn linking (`x0`,`y0`), (`x1`,`y0`), (`x1`,`y1`) and (`x0`,`y1`). If "path", draw a custom SVG path using `path`.

        Args:
            value {str} -- a enumerated , one of ( "rect" | "path" )
        """
        self.layout["selections_type"] = value
        return self


    def selectionsX0(self, value: str) -> Figure:
        """
        Sets the selection's starting x position.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["selections_x0"] = value
        return self


    def selectionsX1(self, value: str) -> Figure:
        """
        Sets the selection's end x position.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["selections_x1"] = value
        return self


    def selectionsXref(self, value: str) -> Figure:
        """
        Sets the selection's x coordinate axis. If set to a x axis id (e.g. "x" or "x2"), the `x` position refers to a x coordinate. If set to "paper", the `x` position refers to the distance from the left of the plotting area in normalized coordinates where "0" ("1") corresponds to the left (right). If set to a x axis ID followed by "domain" (separated by a space), the position behaves like for "paper", but refers to the distance in fractions of the domain length from the left of the domain of that axis: e.g., "x2 domain" refers to the domain of the second x axis and a x position of 0.5 refers to the point between the left and the right of the domain of the second x axis.

        Args:
            value {str} -- a enumerated , one of ( "paper" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.layout["selections_xref"] = value
        return self


    def selectionsY0(self, value: str) -> Figure:
        """
        Sets the selection's starting y position.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["selections_y0"] = value
        return self


    def selectionsY1(self, value: str) -> Figure:
        """
        Sets the selection's end y position.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.layout["selections_y1"] = value
        return self


    def selectionsYref(self, value: str) -> Figure:
        """
        Sets the selection's x coordinate axis. If set to a y axis id (e.g. "y" or "y2"), the `y` position refers to a y coordinate. If set to "paper", the `y` position refers to the distance from the bottom of the plotting area in normalized coordinates where "0" ("1") corresponds to the bottom (top). If set to a y axis ID followed by "domain" (separated by a space), the position behaves like for "paper", but refers to the distance in fractions of the domain length from the bottom of the domain of that axis: e.g., "y2 domain" refers to the domain of the second y axis and a y position of 0.5 refers to the point between the bottom and the top of the domain of the second y axis.

        Args:
            value {str} -- a enumerated , one of ( "paper" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.layout["selections_yref"] = value
        return self


    def hideSources(self, value: bool) -> Figure:
        """
        Determines whether or not a text link citing the data source is placed at the bottom-right cored of the figure. Has only an effect only on graphs that have been generated via forked graphs from the Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise).

        Args:
            value {bool} -- a boolean
        """
        self.layout["hidesources"] = value
        return self


    def pieExtendColors(self, value: bool) -> Figure:
        """
        If `True`, the pie slice colors (whether given by `piecolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)

        Args:
            value {bool} -- a boolean
        """
        self.layout["extendpiecolors"] = value
        return self


    def hiddenLabels(self, value: str) -> Figure:
        """
        hiddenlabels is the funnelarea & pie chart analog of visible:'legendonly' but it can contain many labels, and can simultaneously hide slices from several pies/funnelarea charts

        Args:
            value {str} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.layout["hiddenlabels"] = value
        return self


    def pieColorway(self, value: list) -> Figure:
        """
        Sets the default pie slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendpiecolors`.

        Args:
            value {list} -- a colorlist
        """
        self.layout["piecolorway"] = value
        return self


    def boxGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between boxes of adjacent location coordinates. Has no effect on traces that have "width" set. (Default: d.3)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["boxgap"] = value
        return self


    def boxGroupGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between boxes of the same location coordinate. Has no effect on traces that have "width" set. (Default: d.3)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["boxgroupgap"] = value
        return self


    def boxMode(self, value: str) -> Figure:
        """
        Determines how boxes at the same location coordinate are displayed on the graph. If "group", the boxes are plotted next to one another centered around the shared location. If "overlay", the boxes are plotted over one another, you might need to set "opacity" to see them multiple boxes. Has no effect on traces that have "width" set. (Default: "dverlay")

        Args:
            value {str} -- a enumerated , one of ( "group" | "overlay" )
        """
        self.layout["boxmode"] = value
        return self


    def violinGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between violins of adjacent location coordinates. Has no effect on traces that have "width" set. (Default: d.3)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["violingap"] = value
        return self


    def violinGroupGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between violins of the same location coordinate. Has no effect on traces that have "width" set. (Default: d.3)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["violingroupgap"] = value
        return self


    def violinMode(self, value: str) -> Figure:
        """
        Determines how violins at the same location coordinate are displayed on the graph. If "group", the violins are plotted next to one another centered around the shared location. If "overlay", the violins are plotted over one another, you might need to set "opacity" to see them multiple violins. Has no effect on traces that have "width" set. (Default: "dverlay")

        Args:
            value {str} -- a enumerated , one of ( "group" | "overlay" )
        """
        self.layout["violinmode"] = value
        return self


    def barGroupGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["bargroupgap"] = value
        return self


    def barMode(self, value: str) -> Figure:
        """
        Determines how bars at the same location coordinate are displayed on the graph. With "stack", the bars are stacked on top of one another With "relative", the bars are stacked on top of one another, with negative values below the axis, positive values above With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "droup")

        Args:
            value {str} -- a enumerated , one of ( "stack" | "group" | "overlay" | "relative" )
        """
        self.layout["barmode"] = value
        return self


    def barNorm(self, value: str) -> Figure:
        """
        Sets the normalization for bar traces on the graph. With "fraction", the value of each bar is divided by the sum of all values at that location coordinate. "percent" is the same but multiplied by 100 to show percentages. (default: "")

        Args:
            value {str} -- a enumerated , one of ( "" | "fraction" | "percent" )
        """
        self.layout["barnorm"] = value
        return self


    def barGap(self, value: float) -> Figure:
        """
        Sets the gap between bars of adjacent location coordinates. Values are unitless, they represent fractions of the minimum difference in bar positions in the data. (Default: 0.1)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["bargap"] = value
        return self


    def waterfallGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between bars of adjacent location coordinates.

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["waterfallgap"] = value
        return self


    def waterfallGroupGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["waterfallgroupgap"] = value
        return self


    def waterfallMode(self, value: str) -> Figure:
        """
        Determines how bars at the same location coordinate are displayed on the graph. With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "droup")

        Args:
            value {str} -- a enumerated , one of ( "group" | "overlay" )
        """
        self.layout["waterfallmode"] = value
        return self


    def funnelGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between bars of adjacent location coordinates.

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["funnelgap"] = value
        return self


    def funnelGroupGap(self, value: float) -> Figure:
        """
        Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)

        Args:
            value {float} -- a number between or equal to 0 and 1
        """
        self.layout["funnelgroupgap"] = value
        return self


    def funnelMode(self, value: str) -> Figure:
        """
        Determines how bars at the same location coordinate are displayed on the graph. With "stack", the bars are stacked on top of one another With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "dtack")

        Args:
            value {str} -- a enumerated , one of ( "stack" | "group" | "overlay" )
        """
        self.layout["funnelmode"] = value
        return self


    def funnelAreaExtendColors(self, value: bool) -> Figure:
        """
        If `True`, the funnelarea slice colors (whether given by `funnelareacolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)

        Args:
            value {bool} -- a boolean
        """
        self.layout["extendfunnelareacolors"] = value
        return self


    def funnelAreaColorway(self, value: list) -> Figure:
        """
        Sets the default funnelarea slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendfunnelareacolors`.

        Args:
            value {list} -- a colorlist
        """
        self.layout["funnelareacolorway"] = value
        return self


    def sunburstExtendColors(self, value: bool) -> Figure:
        """
        If `True`, the sunburst slice colors (whether given by `sunburstcolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)

        Args:
            value {bool} -- a boolean
        """
        self.layout["extendsunburstcolors"] = value
        return self


    def sunburstColorway(self, value: list) -> Figure:
        """
        Sets the default sunburst slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendsunburstcolors`.

        Args:
            value {list} -- a colorlist
        """
        self.layout["sunburstcolorway"] = value
        return self


    def treemapExtendColors(self, value: bool) -> Figure:
        """
        If `True`, the treemap slice colors (whether given by `treemapcolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)

        Args:
            value {bool} -- a boolean
        """
        self.layout["extendtreemapcolors"] = value
        return self


    def treemapColorway(self, value: list) -> Figure:
        """
        Sets the default treemap slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendtreemapcolors`.

        Args:
            value {list} -- a colorlist
        """
        self.layout["treemapcolorway"] = value
        return self


    def icicleExtendColors(self, value: bool) -> Figure:
        """
        If `True`, the icicle slice colors (whether given by `iciclecolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)

        Args:
            value {bool} -- a boolean
        """
        self.layout["extendiciclecolors"] = value
        return self


    def icicleColorway(self, value: list) -> Figure:
        """
        Sets the default icicle slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendiciclecolors`.

        Args:
            value {list} -- a colorlist
        """
        self.layout["iciclecolorway"] = value
        return self

    #=================================================================================================================
    #
    # METHODS THAT CUSTOMIZE THE X-AXIS LAYOUT OF THE FIGURE
    #
    #=================================================================================================================


    def xaxisAnchor(self, value: str) -> Figure:
        """
        If set to an opposite-letter axis id (e.g. `x2`, `y`), this axis is bound to the corresponding opposite-letter axis. If set to "free", this axis' position is determined by `position`.

        Args:
            value {str} -- a enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.xaxis["anchor"] = value
        return self


    def xaxisAutoMargin(self, value: str) -> Figure:
        """
        Determines whether long tick labels automatically grow the figure margins.

        Args:
            value {str} -- a flaglist string. Any combination of "height", "width", "left", "right", "top", "bottom" joined with a "+" OR True or False. Examples: "height", "width", "height+width", "height+width+left", "True"
        """
        self.xaxis["automargin"] = value
        return self


    def xaxisAutoRange(self, value: str) -> Figure:
        """
        Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode` for more info. If `range` is provided, then `autorange` is set to "False".

        Args:
            value {str} -- a enumerated , one of ( True | False | "reversed" ) (default: True)
        """
        self.xaxis["autorange"] = value
        return self


    def xaxisAutoTypeNumbers(self, value: str) -> Figure:
        """
        Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. Defaults to layout.autotypenumbers.

        Args:
            value {str} -- a enumerated , one of ( "convert types" | "strict" ) (default: "convert types")
        """
        self.xaxis["autotypenumbers"] = value
        return self


    def xaxisCalendar(self, value: str) -> Figure:
        """
        Sets the calendar system to use for `range` and `tick0` if this is a date axis. This does not set the calendar for interpreting data on this axis, that's specified in the trace or via the global `layout.calendar`

        Args:
            value {str} -- a enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" ) (default: "gregorian")
        """
        self.xaxis["calendar"] = value
        return self


    def xaxisCategoryArray(self, value: list) -> Figure:
        """
        Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to "array". Used with `categoryorder`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.xaxis["categoryarray"] = value
        return self


    def xaxisCategoryOrder(self, value: str) -> Figure:
        """
        Specifies the ordering logic for the case of categorical variables. By default, plotly uses "trace", which specifies the order that is present in the data supplied. Set `categoryorder` to "category ascending" or "category descending" if order should be determined by the alphanumerical order of the category names. Set `categoryorder` to "array" to derive the ordering from the attribute `categoryarray`. If a category is not found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the "trace" mode. The unspecified categories will follow the categories in `categoryarray`. Set `categoryorder` to "total ascending" or "total descending" if order should be determined by the numerical order of the values. Similarly, the order can be determined by the min, max, sum, mean or median of all the values.

        Args:
            value {str} -- a enumerated , one of ( "trace" | "category ascending" | "category descending" | "array" | "total ascending" | "total descending" | "min ascending" | "min descending" | "max ascending" | "max descending" | "sum ascending" | "sum descending" | "mean ascending" | "mean descending" | "median ascending" | "median descending" ) (default: "trace")
        """
        self.xaxis["categoryorder"] = value
        return self


    def xaxisColor(self, value: str) -> Figure:
        """
        Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid color is lightened by blending this with the plot background Individual pieces can override this.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["color"] = value
        return self


    def xaxisConstrain(self, value: str) -> Figure:
        """
        If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines how that happens: by increasing the "range", or by decreasing the "domain". Default is "domain" for axes containing image traces, "range" otherwise.

        Args:
            value {str} -- a enumerated , one of ( "range" | "domain" )
        """
        self.xaxis["constrain"] = value
        return self


    def xaxisConstrainToward(self, value: str) -> Figure:
        """
        If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines which direction we push the originally specified plot area. Options are "left", "center" (default), and "right" for x axes, and "top", "middle" (default), and "bottom" for y axes.

        Args:
            value {str} -- a enumerated , one of ( "left" | "center" | "right" | "top" | "middle" | "bottom" )
        """
        self.xaxis["constraintoward"] = value
        return self


    def xaxisDividerColor(self, value: str) -> Figure:
        """
        Sets the color of the dividers Only has an effect on "multicategory" axes.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["dividercolor"] = value
        return self


    def xaxisDividerWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the dividers Only has an effect on "multicategory" axes.

        Args:
            value {int} -- a number (default: 1)
        """
        self.xaxis["dividerwidth"] = value
        return self


    def xaxisDomain(self, value: list) -> Figure:
        """
        Sets the domain of this axis (in plot fraction).

        Args:
            value {list} -- a list (default: [0, 1])
        """
        self.xaxis["domain"] = value
        return self


    def xaxisDtick(self, value: str) -> Figure:
        """
        Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.xaxis["dtick"] = value
        return self


    def xaxisExponentFormat(self, value: str) -> Figure:
        """
        Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If "none", it appears as 1,000,000,000. If "e", 1e+9. If "E", 1E+9. If "power", 1x10^9 (with 9 in a super script). If "SI", 1G. If "B", 1B.

        Args:
            value {str} -- a enumerated , one of ( "none" | "e" | "E" | "power" | "SI" | "B" ) (default: "B")
        """
        self.xaxis["exponentformat"] = value
        return self


    def xaxisFixedRange(self, value: str) -> Figure:
        """
        Determines whether or not this axis is zoom-able. If True, then zoom is disabled.

        Args:
            value {str} -- a boolean
        """
        self.xaxis["fixedrange"] = value
        return self


    def xaxisGridColor(self, value: str) -> Figure:
        """
        Sets the color of the grid lines.

        Args:
            value {str} -- a color (default: "#eee")
        """
        self.xaxis["gridcolor"] = value
        return self


    def xaxisGridDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").

        Args:
            value {str} -- a string (default: "solid")
        """
        self.xaxis["griddash"] = value
        return self


    def xaxisGridWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the grid lines.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.xaxis["gridwidth"] = value
        return self


    def xaxisHoverFormat(self, value: str) -> Figure:
        """
        Sets the hover text formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"

        Args:
            value {str} -- a string (default: "")
        """
        self.xaxis["hoverformat"] = value
        return self


    def xaxisLayer(self, value: str) -> Figure:
        """
        Sets the layer on which this axis is displayed. If "above traces", this axis is displayed above all the subplot's traces If "below traces", this axis is displayed below all the subplot's traces, but above the grid lines. Useful when used together with scatter-like traces with `cliponaxis` set to "False" to show markers and/or text nodes above this axis.

        Args:
            value {str} -- a enumerated , one of ( "above traces" | "below traces" ) (default: "above traces")
        """
        self.xaxis["layer"] = value
        return self


    def xaxisLineColor(self, value: str) -> Figure:
        """
        Sets the axis line color.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["linecolor"] = value
        return self


    def xaxisLineWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the axis line.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.xaxis["linewidth"] = value
        return self


    def xaxisMatches(self, value: str) -> Figure:
        """
        If set to another axis id (e.g. `x2`, `y`), the range of this axis will match the range of the corresponding axis in data-coordinates space. Moreover, matching axes share auto-range values, category lists and histogram auto-bins. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden. Moreover, note that matching axes must have the same `type`.

        Args:
            value {str} -- a enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.xaxis["matches"] = value
        return self


    def xaxisMinExponent(self, value: int) -> Figure:
        """
        Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is "SI" or "B".

        Args:
            value {int} -- a number greater than or equal to 0 (default: 3)
        """
        self.xaxis["minexponent"] = value
        return self


    def xaxisMinorSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["minor"] = value
        return self


    def xaxisMinorDtick(self, value: str) -> Figure:
        """
        Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.xaxis["minor_dtick"] = value
        return self


    def xaxisMinorGridColor(self, value: str) -> Figure:
        """
        Sets the color of the grid lines.

        Args:
            value {str} -- a color (default: "#eee")
        """
        self.xaxis["minor_gridcolor"] = value
        return self


    def xaxisMinorGridDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").

        Args:
            value {str} -- a string (default: "solid")
        """
        self.xaxis["minor_griddash"] = value
        return self


    def xaxisMinorGridWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the grid lines.

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.xaxis["minor_gridwidth"] = value
        return self


    def xaxisMinorNticks(self, value: str) -> Figure:
        """
        Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".

        Args:
            value {str} -- a integer greater than or equal to 0 (default: 5)
        """
        self.xaxis["minor_nticks"] = value
        return self


    def xaxisMinorShowgrid(self, value: str) -> Figure:
        """
        Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.

        Args:
            value {str} -- a boolean
        """
        self.xaxis["minor_showgrid"] = value
        return self


    def xaxisMinorTick0(self, value: str) -> Figure:
        """
        Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.xaxis["minor_tick0"] = value
        return self


    def xaxisMinorTickColor(self, value: str) -> Figure:
        """
        Sets the tick color.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["minor_tickcolor"] = value
        return self


    def xaxisMinorTickLength(self, value: int) -> Figure:
        """
        Sets the tick length (in px).

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.xaxis["minor_ticklen"] = value
        return self


    def xaxisMinorTickMode(self, value: str) -> Figure:
        """
        Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).

        Args:
            value {str} -- a enumerated , one of ( "auto" | "linear" | "array" )
        """
        self.xaxis["minor_tickmode"] = value
        return self


    def xaxisMinorTicks(self, value: str) -> Figure:
        """
        Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.

        Args:
            value {str} -- a enumerated , one of ( "outside" | "inside" | "" )
        """
        self.xaxis["minor_ticks"] = value
        return self


    def xaxisMinorTickValues(self, value: list) -> Figure:
        """
        Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.xaxis["minor_tickvals"] = value
        return self


    def xaxisMinorTickWidth(self, value: int) -> Figure:
        """
        Sets the tick width (in px).

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.xaxis["minor_tickwidth"] = value
        return self


    def xaxisMirror(self, value: str) -> Figure:
        """
        Determines if the axis lines or/and ticks are mirrored to the opposite side of the plotting area. If "True", the axis lines are mirrored. If "ticks", the axis lines and ticks are mirrored. If "False", mirroring is disable. If "all", axis lines are mirrored on all shared-axes subplots. If "allticks", axis lines and ticks are mirrored on all shared-axes subplots.

        Args:
            value {str} -- a enumerated , one of ( True | "ticks" | False | "all" | "allticks" )
        """
        self.xaxis["mirror"] = value
        return self


    def xaxisNticks(self, value: str) -> Figure:
        """
        Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".

        Args:
            value {str} -- a integer greater than or equal to 0 (default: 0)
        """
        self.xaxis["nticks"] = value
        return self


    def xaxisOverlaying(self, value: str) -> Figure:
        """
        If set a same-letter axis id, this axis is overlaid on top of the corresponding same-letter axis, with traces and axes visible for both axes. If "False", this axis does not overlay any same-letter axes. In this case, for axes with overlapping domains only the highest-numbered axis will be visible.

        Args:
            value {str} -- a enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.xaxis["overlaying"] = value
        return self


    def xaxisPosition(self, value: int) -> Figure:
        """
        Sets the position of this axis in the plotting space (in normalized coordinates). Only has an effect if `anchor` is set to "free".

        Args:
            value {int} -- a number between or equal to 0 and 1 (default: 0)
        """
        self.xaxis["position"] = value
        return self


    def xaxisRange(l: float, r: float) -> Figure:
        """
        Sets the range of this axis. If the axis `type` is "log", then you must take the log of your desired range (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {float} -- a list
        """
        self.xaxis["range"] = [l, r]
        return self


    def xaxisRangeBreaks(self, value: list) -> Figure:
        """
        Missing documentation!

        Args:
            value {list} -- a list of dict where each dict has one or more of the keys listed below.
        """
        self.xaxis["rangebreaks"] = value
        return self


    def xaxisRangeBreaksBounds(self, value: list) -> Figure:
        """
        Sets the lower and upper bounds of this axis rangebreak. Can be used with `pattern`.

        Args:
            value {list} -- a list
        """
        self.xaxis["rangebreaks_bounds"] = value
        return self


    def xaxisRangeBreaksDvalue(self, value: int) -> Figure:
        """
        Sets the size of each `values` item. The default is one day in milliseconds.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 86400000)
        """
        self.xaxis["rangebreaks_dvalue"] = value
        return self


    def xaxisRangeBreaksEnabled(self, value: str) -> Figure:
        """
        Determines whether this axis rangebreak is enabled or disabled. Please note that `rangebreaks` only work for "date" axis type.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.xaxis["rangebreaks_enabled"] = value
        return self


    def xaxisRangeBreaksName(self, value: str) -> Figure:
        """
        When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.

        Args:
            value {str} -- a string
        """
        self.xaxis["rangebreaks_name"] = value
        return self


    def xaxisRangeBreaksPattern(self, value: str) -> Figure:
        """
        Determines a pattern on the time line that generates breaks. If "day of week" - days of the week in English e.g. 'Sunday' or `sun` (matching is case-insensitive and considers only the first three characters), as well as Sunday-based integers between 0 and 6. If "hour" - hour (24-hour clock) as decimal numbers between 0 and 24. for more info. Examples: - { pattern: 'day of week', bounds: [6, 1] } or simply { bounds: ['sat', 'mon'] } breaks from Saturday to Monday (i.e. skips the weekends). - { pattern: 'hour', bounds: [17, 8] } breaks from 5pm to 8am (i.e. skips non-work hours).

        Args:
            value {str} -- a enumerated , one of ( "day of week" | "hour" | "" )
        """
        self.xaxis["rangebreaks_pattern"] = value
        return self


    def xaxisRangeBreaksTemplateItemName(self, value: str) -> Figure:
        """
        Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.

        Args:
            value {str} -- a string
        """
        self.xaxis["rangebreaks_templateitemname"] = value
        return self


    def xaxisRangeBreaksValues(self, value: list) -> Figure:
        """
        Sets the coordinate values corresponding to the rangebreaks. An alternative to `bounds`. Use `dvalue` to set the size of the values along the axis.

        Args:
            value {list} -- a list
        """
        self.xaxis["rangebreaks_values"] = value
        return self


    def xaxisRangeMode(self, value: str) -> Figure:
        """
        If "normal", the range is computed in relation to the extrema of the input data. If "tozero"`, the range extends to 0, regardless of the input data If "nonnegative", the range is non-negative, regardless of the input data. Applies only to linear axes.

        Args:
            value {str} -- a enumerated , one of ( "normal" | "tozero" | "nonnegative" ) (default: "normal")
        """
        self.xaxis["rangemode"] = value
        return self


    def xaxisRangeSelectorSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["rangeselector"] = value
        return self


    def xaxisRangeSelectorActiveColor(self, value: str) -> Figure:
        """
        Sets the background color of the active range selector button.

        Args:
            value {str} -- a color
        """
        self.xaxis["rangeselector_activecolor"] = value
        return self


    def xaxisRangeSelectorBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of the range selector buttons.

        Args:
            value {str} -- a color (default: "#eee")
        """
        self.xaxis["rangeselector_bgcolor"] = value
        return self


    def xaxisRangeSelectorBorderColor(self, value: str) -> Figure:
        """
        Sets the color of the border enclosing the range selector.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["rangeselector_bordercolor"] = value
        return self


    def xaxisRangeSelectorBorderWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the border enclosing the range selector.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 0)
        """
        self.xaxis["rangeselector_borderwidth"] = value
        return self


    def xaxisRangeSelectorButtons(self, value: list) -> Figure:
        """
        Missing documentation!

        Args:
            value {list} -- a list of dict where each dict has one or more of the keys listed below.
        """
        self.xaxis["rangeselector_buttons"] = value
        return self


    def xaxisRangeSelectorCount(self, value: int) -> Figure:
        """
        Sets the number of steps to take to update the range. Use with `step` to specify the update interval.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.xaxis["rangeselector_count"] = value
        return self


    def xaxisRangeSelectorLabel(self, value: str) -> Figure:
        """
        Sets the text label to appear on the button.

        Args:
            value {str} -- a string
        """
        self.xaxis["rangeselector_label"] = value
        return self


    def xaxisRangeSelectorName(self, value: str) -> Figure:
        """
        When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.

        Args:
            value {str} -- a string
        """
        self.xaxis["rangeselector_name"] = value
        return self


    def xaxisRangeSelectorStep(self, value: str) -> Figure:
        """
        The unit of measurement that the `count` value will set the range by.

        Args:
            value {str} -- a enumerated , one of ( "month" | "year" | "day" | "hour" | "minute" | "second" | "all" ) (default: "month")
        """
        self.xaxis["rangeselector_step"] = value
        return self


    def xaxisRangeSelectorStepMode(self, value: str) -> Figure:
        """
        Sets the range update mode. If "backward", the range update shifts the start of range back "count" times "step" milliseconds. If "todate", the range update shifts the start of range back to the first timestamp from "count" times "step" milliseconds back. For example, with `step` set to "year" and `count` set to "1" the range update shifts the start of the range back to January 01 of the current year. Month and year "todate" are currently available only for the built-in (Gregorian) calendar.

        Args:
            value {str} -- a enumerated , one of ( "backward" | "todate" ) (default: "backward")
        """
        self.xaxis["rangeselector_stepmode"] = value
        return self


    def xaxisRangeSelectorTemplateItemName(self, value: str) -> Figure:
        """
        Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.

        Args:
            value {str} -- a string
        """
        self.xaxis["rangeselector_templateitemname"] = value
        return self


    def xaxisRangeSelectorFontSpecs(self, value: dict) -> Figure:
        """
        Sets the font of the range selector button text.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["rangeselector_font"] = value
        return self


    def xaxisRangeSelectorFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.xaxis["rangeselector_font_color"] = value
        return self


    def xaxisRangeSelectorFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.xaxis["rangeselector_font_family"] = value
        return self


    def xaxisRangeSelectorFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.xaxis["rangeselector_font_size"] = value
        return self


    def xaxisRangeSelectorVisible(self, value: str) -> Figure:
        """
        Determines whether or not this range selector is visible. Note that range selectors are only available for x axes of `type` set to or auto-typed to "date".

        Args:
            value {str} -- a boolean (default: True)
        """
        self.xaxis["rangeselector_visible"] = value
        return self


    def xaxisRangeSelectorX(self, value: int) -> Figure:
        """
        Sets the x position (in normalized coordinates) of the range selector.

        Args:
            value {int} -- a number between or equal to -2 and 3
        """
        self.xaxis["rangeselector_x"] = value
        return self


    def xaxisRangeSelectorXanchor(self, value: str) -> Figure:
        """
        Sets the range selector's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the range selector.

        Args:
            value {str} -- a enumerated , one of ( "auto" | "left" | "center" | "right" ) (default: "left")
        """
        self.xaxis["rangeselector_xanchor"] = value
        return self


    def xaxisRangeSelectorY(self, value: int) -> Figure:
        """
        Sets the y position (in normalized coordinates) of the range selector.

        Args:
            value {int} -- a number between or equal to -2 and 3
        """
        self.xaxis["rangeselector_y"] = value
        return self


    def xaxisRangeSelectorYanchor(self, value: str) -> Figure:
        """
        Sets the range selector's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the range selector.

        Args:
            value {str} -- a enumerated , one of ( "auto" | "top" | "middle" | "bottom" ) (default: "bottom")
        """
        self.xaxis["rangeselector_yanchor"] = value
        return self


    def xaxisRangeSliderSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["rangeslider"] = value
        return self


    def xaxisRangeSliderAutoRange(self, value: str) -> Figure:
        """
        Determines whether or not the range slider range is computed in relation to the input data. If `range` is provided, then `autorange` is set to "False".

        Args:
            value {str} -- a boolean (default: True)
        """
        self.xaxis["rangeslider_autorange"] = value
        return self


    def xaxisRangeSliderBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of the range slider.

        Args:
            value {str} -- a color (default: "#fff")
        """
        self.xaxis["rangeslider_bgcolor"] = value
        return self


    def xaxisRangeSliderBorderColor(self, value: str) -> Figure:
        """
        Sets the border color of the range slider.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["rangeslider_bordercolor"] = value
        return self


    def xaxisRangeSliderBorderWidth(self, value: str) -> Figure:
        """
        Sets the border width of the range slider.

        Args:
            value {str} -- a integer greater than or equal to 0 (default: 0)
        """
        self.xaxis["rangeslider_borderwidth"] = value
        return self


    def xaxisRangeSliderRange(self, value: list) -> Figure:
        """
        Sets the range of the range slider. If not set, defaults to the full xaxis range. If the axis `type` is "log", then you must take the log of your desired range. If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {list} -- a list
        """
        self.xaxis["rangeslider_range"] = value
        return self


    def xaxisRangeSliderThickness(self, value: int) -> Figure:
        """
        The height of the range slider as a fraction of the total plot area height.

        Args:
            value {int} -- a number between or equal to 0 and 1 (default: 0.15)
        """
        self.xaxis["rangeslider_thickness"] = value
        return self


    def xaxisRangeSliderVisible(self, value: str) -> Figure:
        """
        Determines whether or not the range slider will be visible. If visible, perpendicular axes will be set to `fixedrange`

        Args:
            value {str} -- a boolean (default: True)
        """
        self.xaxis["rangeslider_visible"] = value
        return self


    def xaxisRangeSliderYaxisSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["rangeslider_yaxis"] = value
        return self


    def xaxisRangeSliderYaxisRange(l: float, r: float) -> Figure:
        """
        Sets the range of this axis for the rangeslider.

        Args:
            value {float} -- a list
        """
        self.xaxis["rangeslider_yaxis_range"] = [l, r]
        return self


    def xaxisRangeSliderYaxisRangeMode(self, value: str) -> Figure:
        """
        Determines whether or not the range of this axis in the rangeslider use the same value than in the main plot when zooming in/out. If "auto", the autorange will be used. If "fixed", the `range` is used. If "match", the current range of the corresponding y-axis on the main subplot is used.

        Args:
            value {str} -- a enumerated , one of ( "auto" | "fixed" | "match" ) (default: "match")
        """
        self.xaxis["rangeslider_yaxis_rangemode"] = value
        return self


    def xaxisScaleAnchor(self, value: str) -> Figure:
        """
        If set to another axis id (e.g. `x2`, `y`), the range of this axis changes together with the range of the corresponding axis such that the scale of pixels per unit is in a constant ratio. Both axes are still zoomable, but when you zoom one, the other will zoom the same amount, keeping a fixed midpoint. `constrain` and `constraintoward` determine how we enforce the constraint. You can chain these, ie `yaxis: {scaleanchor: "x"}, xaxis2: {scaleanchor: "y"}` but you can only link axes of the same `type`. The linked axis can have the opposite letter (to constrain the aspect ratio) or the same letter (to match scales across subplots). Loops (`yaxis: {scaleanchor: "x"}, xaxis: {scaleanchor: "y"}` or longer) are redundant and the last constraint encountered will be ignored to avoid possible inconsistent constraints via `scaleratio`. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden.

        Args:
            value {str} -- a enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.xaxis["scaleanchor"] = value
        return self


    def xaxisScaleRatio(self, value: int) -> Figure:
        """
        If this axis is linked to another by `scaleanchor`, this determines the pixel to unit scale ratio. For example, if this value is 10, then every unit on this axis spans 10 times the number of pixels as a unit on the linked axis. Use this for example to create an elevation profile where the vertical scale is exaggerated a fixed amount with respect to the horizontal.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.xaxis["scaleratio"] = value
        return self


    def xaxisSeparateThousands(self, value: str) -> Figure:
        """
        If "True", even 4-digit integers are separated

        Args:
            value {str} -- a boolean
        """
        self.xaxis["separatethousands"] = value
        return self


    def xaxisShowDividers(self, value: str) -> Figure:
        """
        Determines whether or not a dividers are drawn between the category levels of this axis. Only has an effect on "multicategory" axes.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.xaxis["showdividers"] = value
        return self


    def xaxisShowExponent(self, value: str) -> Figure:
        """
        If "all", all exponents are shown besides their significands. If "first", only the exponent of the first tick is shown. If "last", only the exponent of the last tick is shown. If "none", no exponents appear.

        Args:
            value {str} -- a enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
        """
        self.xaxis["showexponent"] = value
        return self


    def xaxisShowGrid(self, value: str) -> Figure:
        """
        Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.

        Args:
            value {str} -- a boolean
        """
        self.xaxis["showgrid"] = value
        return self


    def xaxisShowLine(self, value: str) -> Figure:
        """
        Determines whether or not a line bounding this axis is drawn.

        Args:
            value {str} -- a boolean
        """
        self.xaxis["showline"] = value
        return self


    def xaxisShowSpikes(self, value: str) -> Figure:
        """
        Determines whether or not spikes (aka droplines) are drawn for this axis. Note: This only takes affect when hovermode = closest

        Args:
            value {str} -- a boolean
        """
        self.xaxis["showspikes"] = value
        return self


    def xaxisShowTickLabels(self, value: str) -> Figure:
        """
        Determines whether or not the tick labels are drawn.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.xaxis["showticklabels"] = value
        return self


    def xaxisShowTickPrefix(self, value: str) -> Figure:
        """
        If "all", all tick labels are displayed with a prefix. If "first", only the first tick is displayed with a prefix. If "last", only the last tick is displayed with a suffix. If "none", tick prefixes are hidden.

        Args:
            value {str} -- a enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
        """
        self.xaxis["showtickprefix"] = value
        return self


    def xaxisShowTickSuffix(self, value: str) -> Figure:
        """
        Same as `showtickprefix` but for tick suffixes.

        Args:
            value {str} -- a enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
        """
        self.xaxis["showticksuffix"] = value
        return self


    def xaxisSide(self, value: str) -> Figure:
        """
        Determines whether a x (y) axis is positioned at the "bottom" ("left") or "top" ("right") of the plotting area.

        Args:
            value {str} -- a enumerated , one of ( "top" | "bottom" | "left" | "right" )
        """
        self.xaxis["side"] = value
        return self


    def xaxisSpikeColor(self, value: str) -> Figure:
        """
        Sets the spike color. If undefined, will use the series color

        Args:
            value {str} -- a color
        """
        self.xaxis["spikecolor"] = value
        return self


    def xaxisSpikeDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").

        Args:
            value {str} -- a string (default: "dash")
        """
        self.xaxis["spikedash"] = value
        return self


    def xaxisSpikeMode(self, value: str) -> Figure:
        """
        Determines the drawing mode for the spike line If "toaxis", the line is drawn from the data point to the axis the series is plotted on. If "across", the line is drawn across the entire plot area, and supercedes "toaxis". If "marker", then a marker dot is drawn on the axis the series is plotted on

        Args:
            value {str} -- a flaglist string. Any combination of "toaxis", "across", "marker" joined with a "+". Examples: "toaxis", "across", "toaxis+across", "toaxis+across+marker" (default: "toaxis")
        """
        self.xaxis["spikemode"] = value
        return self


    def xaxisSpikeSnap(self, value: str) -> Figure:
        """
        Determines whether spikelines are stuck to the cursor or to the closest datapoints.

        Args:
            value {str} -- a enumerated , one of ( "data" | "cursor" | "hovered data" ) (default: "hovered data")
        """
        self.xaxis["spikesnap"] = value
        return self


    def xaxisSpikeThickness(self, value: int) -> Figure:
        """
        Sets the width (in px) of the zero line.

        Args:
            value {int} -- a number (default: 3)
        """
        self.xaxis["spikethickness"] = value
        return self


    def xaxisTick0(self, value: str) -> Figure:
        """
        Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.xaxis["tick0"] = value
        return self


    def xaxisTickAngle(self, value: str) -> Figure:
        """
        Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the tick labels vertically.

        Args:
            value {str} -- a angle (default: "auto")
        """
        self.xaxis["tickangle"] = value
        return self


    def xaxisTickColor(self, value: str) -> Figure:
        """
        Sets the tick color.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["tickcolor"] = value
        return self


    def xaxisTickFontSpecs(self, value: dict) -> Figure:
        """
        Sets the tick font.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["tickfont"] = value
        return self


    def xaxisTickFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.xaxis["tickfont_color"] = value
        return self


    def xaxisTickFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.xaxis["tickfont_family"] = value
        return self


    def xaxisTickFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.xaxis["tickfont_size"] = value
        return self


    def xaxisTickFormat(self, value: str) -> Figure:
        """
        Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"

        Args:
            value {str} -- a string (default: "")
        """
        self.xaxis["tickformat"] = value
        return self


    def xaxisTickFormatStops(self, value: list) -> Figure:
        """
        Missing documentation!

        Args:
            value {list} -- a list of dict where each dict has one or more of the keys listed below.
        """
        self.xaxis["tickformatstops"] = value
        return self


    def xaxisTickFormatStopsDtickRange(self, value: list) -> Figure:
        """
        range ["min", "max"], where "min", "max" - dtick values which describe some zoom level, it is possible to omit "min" or "max" value by passing "null"

        Args:
            value {list} -- a list
        """
        self.xaxis["tickformatstops_dtickrange"] = value
        return self


    def xaxisTickFormatStopsEnabled(self, value: str) -> Figure:
        """
        Determines whether or not this stop is used. If `False`, this stop is ignored even within its `dtickrange`.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.xaxis["tickformatstops_enabled"] = value
        return self


    def xaxisTickFormatStopsName(self, value: str) -> Figure:
        """
        When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.

        Args:
            value {str} -- a string
        """
        self.xaxis["tickformatstops_name"] = value
        return self


    def xaxisTickFormatStopsTemplateItemName(self, value: str) -> Figure:
        """
        Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.

        Args:
            value {str} -- a string
        """
        self.xaxis["tickformatstops_templateitemname"] = value
        return self


    def xaxisTickFormatStopsValue(self, value: str) -> Figure:
        """
        string - dtickformat for described zoom level, the same as "tickformat"

        Args:
            value {str} -- a string (default: "")
        """
        self.xaxis["tickformatstops_value"] = value
        return self


    def xaxisTickLabelMode(self, value: str) -> Figure:
        """
        Determines where tick labels are drawn with respect to their corresponding ticks and grid lines. Only has an effect for axes of `type` "date" When set to "period", tick labels are drawn in the middle of the period between ticks.

        Args:
            value {str} -- a enumerated , one of ( "instant" | "period" ) (default: "instant")
        """
        self.xaxis["ticklabelmode"] = value
        return self


    def xaxisTickLabelOverflow(self, value: str) -> Figure:
        """
        Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The default value for inside tick labels is "hide past domain". Otherwise on "category" and "multicategory" axes the default is "allow". In other cases the default is "hide past div".

        Args:
            value {str} -- a enumerated , one of ( "allow" | "hide past div" | "hide past domain" )
        """
        self.xaxis["ticklabeloverflow"] = value
        return self


    def xaxisTickLabelPosition(self, value: str) -> Figure:
        """
        Determines where tick labels are drawn with respect to the axis Please note that top or bottom has no effect on x axes or when `ticklabelmode` is set to "period". Similarly left or right has no effect on y axes or when `ticklabelmode` is set to "period". Has no effect on "multicategory" axes or when `tickson` is set to "boundaries". When used on axes linked by `matches` or `scaleanchor`, no extra padding for inside labels would be added by autorange, so that the scales could match.

        Args:
            value {str} -- a enumerated , one of ( "outside" | "inside" | "outside top" | "inside top" | "outside left" | "inside left" | "outside right" | "inside right" | "outside bottom" | "inside bottom" ) (default: "outside")
        """
        self.xaxis["ticklabelposition"] = value
        return self


    def xaxisTickLabelStep(self, value: str) -> Figure:
        """
        Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` "log" or "multicategory", or when `tickmode` is "array".

        Args:
            value {str} -- a integer greater than or equal to 1 (default: 1)
        """
        self.xaxis["ticklabelstep"] = value
        return self


    def xaxisTickLength(self, value: int) -> Figure:
        """
        Sets the tick length (in px).

        Args:
            value {int} -- a number greater than or equal to 0 (default: 5)
        """
        self.xaxis["ticklen"] = value
        return self


    def xaxisTickMode(self, value: str) -> Figure:
        """
        Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).

        Args:
            value {str} -- a enumerated , one of ( "auto" | "linear" | "array" )
        """
        self.xaxis["tickmode"] = value
        return self


    def xaxisTickPrefix(self, value: str) -> Figure:
        """
        Sets a tick label prefix.

        Args:
            value {str} -- a string (default: "")
        """
        self.xaxis["tickprefix"] = value
        return self


    def xaxisTicks(self, value: str) -> Figure:
        """
        Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.

        Args:
            value {str} -- a enumerated , one of ( "outside" | "inside" | "" )
        """
        self.xaxis["ticks"] = value
        return self


    def xaxisTickson(self, value: str) -> Figure:
        """
        Determines where ticks and grid lines are drawn with respect to their corresponding tick labels. Only has an effect for axes of `type` "category" or "multicategory". When set to "boundaries", ticks and grid lines are drawn half a category to the left/bottom of labels.

        Args:
            value {str} -- a enumerated , one of ( "labels" | "boundaries" ) (default: "labels")
        """
        self.xaxis["tickson"] = value
        return self


    def xaxisTickSuffix(self, value: str) -> Figure:
        """
        Sets a tick label suffix.

        Args:
            value {str} -- a string (default: "")
        """
        self.xaxis["ticksuffix"] = value
        return self


    def xaxisTickText(self, value: list) -> Figure:
        """
        Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to "array". Used with `tickvals`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.xaxis["ticktext"] = value
        return self


    def xaxisTickValues(self, value: list) -> Figure:
        """
        Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.xaxis["tickvals"] = value
        return self


    def xaxisTickWidth(self, value: int) -> Figure:
        """
        Sets the tick width (in px).

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.xaxis["tickwidth"] = value
        return self


    def xaxisTitleSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["title"] = value
        return self


    def xaxisTitleFontSpecs(self, value: dict) -> Figure:
        """
        Sets this axis' title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.xaxis["title_font"] = value
        return self


    def xaxisTitleFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.xaxis["title_font_color"] = value
        return self


    def xaxisTitleFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.xaxis["title_font_family"] = value
        return self


    def xaxisTitleFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.xaxis["title_font_size"] = value
        return self


    def xaxisTitleStandoff(self, value: int) -> Figure:
        """
        Sets the standoff distance (in px) between the axis labels and the title text The default value is a function of the axis tick labels, the title `font.size` and the axis `linewidth`. Note that the axis title position is always constrained within the margins, so the actual standoff distance is always less than the set or default value. By setting `standoff` and turning on `automargin`, plotly.js will push the margins to fit the axis title at given standoff distance.

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.xaxis["title_standoff"] = value
        return self


    def xaxisTitleText(self, value: str) -> Figure:
        """
        Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.

        Args:
            value {str} -- a string
        """
        self.xaxis["title_text"] = value
        return self


    def xaxisType(self, value: str) -> Figure:
        """
        Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the traces that referenced the axis in question.

        Args:
            value {str} -- a enumerated , one of ( "-" | "linear" | "log" | "date" | "category" | "multicategory" ) (default: "-")
        """
        self.xaxis["type"] = value
        return self


    def xaxisUirevision(self, value: str) -> Figure:
        """
        Controls persistence of user-driven changes in axis `range`, `autorange`, and `title` if in `editable: True` configuration. Defaults to `layout.uirevision`.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.xaxis["uirevision"] = value
        return self


    def xaxisVisible(self, value: str) -> Figure:
        """
        A single toggle to hide the axis while preserving interaction like dragging. Default is True when a cheater plot is present on the axis, otherwise False

        Args:
            value {str} -- a boolean
        """
        self.xaxis["visible"] = value
        return self


    def xaxisZeroLine(self, value: str) -> Figure:
        """
        Determines whether or not a line is drawn at along the 0 value of this axis. If "True", the zero line is drawn on top of the grid lines.

        Args:
            value {str} -- a boolean
        """
        self.xaxis["zeroline"] = value
        return self


    def xaxisZeroLineColor(self, value: str) -> Figure:
        """
        Sets the line color of the zero line.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.xaxis["zerolinecolor"] = value
        return self


    def xaxisZeroLineWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the zero line.

        Args:
            value {int} -- a number (default: 1)
        """
        self.xaxis["zerolinewidth"] = value
        return self

    #=================================================================================================================
    #
    # METHODS THAT CUSTOMIZE THE Y-AXIS LAYOUT OF THE FIGURE
    #
    #=================================================================================================================


    def yaxisAnchor(self, value: str) -> Figure:
        """
        If set to an opposite-letter axis id (e.g. `x2`, `y`), this axis is bound to the corresponding opposite-letter axis. If set to "free", this axis' position is determined by `position`.

        Args:
            value {str} -- a enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.yaxis["anchor"] = value
        return self


    def yaxisAutoMargin(self, value: str) -> Figure:
        """
        Determines whether long tick labels automatically grow the figure margins.

        Args:
            value {str} -- a flaglist string. Any combination of "height", "width", "left", "right", "top", "bottom" joined with a "+" OR True or False. Examples: "height", "width", "height+width", "height+width+left", "True"
        """
        self.yaxis["automargin"] = value
        return self


    def yaxisAutoRange(self, value: str) -> Figure:
        """
        Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode` for more info. If `range` is provided, then `autorange` is set to "False".

        Args:
            value {str} -- a enumerated , one of ( True | False | "reversed" ) (default: True)
        """
        self.yaxis["autorange"] = value
        return self


    def yaxisAutoTypeNumbers(self, value: str) -> Figure:
        """
        Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. Defaults to layout.autotypenumbers.

        Args:
            value {str} -- a enumerated , one of ( "convert types" | "strict" ) (default: "convert types")
        """
        self.yaxis["autotypenumbers"] = value
        return self


    def yaxisCalendar(self, value: str) -> Figure:
        """
        Sets the calendar system to use for `range` and `tick0` if this is a date axis. This does not set the calendar for interpreting data on this axis, that's specified in the trace or via the global `layout.calendar`

        Args:
            value {str} -- a enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" ) (default: "gregorian")
        """
        self.yaxis["calendar"] = value
        return self


    def yaxisCategoryArray(self, value: list) -> Figure:
        """
        Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to "array". Used with `categoryorder`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.yaxis["categoryarray"] = value
        return self


    def yaxisCategoryOrder(self, value: str) -> Figure:
        """
        Specifies the ordering logic for the case of categorical variables. By default, plotly uses "trace", which specifies the order that is present in the data supplied. Set `categoryorder` to "category ascending" or "category descending" if order should be determined by the alphanumerical order of the category names. Set `categoryorder` to "array" to derive the ordering from the attribute `categoryarray`. If a category is not found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the "trace" mode. The unspecified categories will follow the categories in `categoryarray`. Set `categoryorder` to "total ascending" or "total descending" if order should be determined by the numerical order of the values. Similarly, the order can be determined by the min, max, sum, mean or median of all the values.

        Args:
            value {str} -- a enumerated , one of ( "trace" | "category ascending" | "category descending" | "array" | "total ascending" | "total descending" | "min ascending" | "min descending" | "max ascending" | "max descending" | "sum ascending" | "sum descending" | "mean ascending" | "mean descending" | "median ascending" | "median descending" ) (default: "trace")
        """
        self.yaxis["categoryorder"] = value
        return self


    def yaxisColor(self, value: str) -> Figure:
        """
        Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid color is lightened by blending this with the plot background Individual pieces can override this.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["color"] = value
        return self


    def yaxisConstrain(self, value: str) -> Figure:
        """
        If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines how that happens: by increasing the "range", or by decreasing the "domain". Default is "domain" for axes containing image traces, "range" otherwise.

        Args:
            value {str} -- a enumerated , one of ( "range" | "domain" )
        """
        self.yaxis["constrain"] = value
        return self


    def yaxisConstrainToward(self, value: str) -> Figure:
        """
        If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines which direction we push the originally specified plot area. Options are "left", "center" (default), and "right" for x axes, and "top", "middle" (default), and "bottom" for y axes.

        Args:
            value {str} -- a enumerated , one of ( "left" | "center" | "right" | "top" | "middle" | "bottom" )
        """
        self.yaxis["constraintoward"] = value
        return self


    def yaxisDividerColor(self, value: str) -> Figure:
        """
        Sets the color of the dividers Only has an effect on "multicategory" axes.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["dividercolor"] = value
        return self


    def yaxisDividerWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the dividers Only has an effect on "multicategory" axes.

        Args:
            value {int} -- a number (default: 1)
        """
        self.yaxis["dividerwidth"] = value
        return self


    def yaxisDomain(self, value: list) -> Figure:
        """
        Sets the domain of this axis (in plot fraction).

        Args:
            value {list} -- a list (default: [0, 1])
        """
        self.yaxis["domain"] = value
        return self


    def yaxisDtick(self, value: str) -> Figure:
        """
        Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.yaxis["dtick"] = value
        return self


    def yaxisExponentFormat(self, value: str) -> Figure:
        """
        Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If "none", it appears as 1,000,000,000. If "e", 1e+9. If "E", 1E+9. If "power", 1x10^9 (with 9 in a super script). If "SI", 1G. If "B", 1B.

        Args:
            value {str} -- a enumerated , one of ( "none" | "e" | "E" | "power" | "SI" | "B" ) (default: "B")
        """
        self.yaxis["exponentformat"] = value
        return self


    def yaxisFixedRange(self, value: str) -> Figure:
        """
        Determines whether or not this axis is zoom-able. If True, then zoom is disabled.

        Args:
            value {str} -- a boolean
        """
        self.yaxis["fixedrange"] = value
        return self


    def yaxisGridColor(self, value: str) -> Figure:
        """
        Sets the color of the grid lines.

        Args:
            value {str} -- a color (default: "#eee")
        """
        self.yaxis["gridcolor"] = value
        return self


    def yaxisGridDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").

        Args:
            value {str} -- a string (default: "solid")
        """
        self.yaxis["griddash"] = value
        return self


    def yaxisGridWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the grid lines.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.yaxis["gridwidth"] = value
        return self


    def yaxisHoverFormat(self, value: str) -> Figure:
        """
        Sets the hover text formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"

        Args:
            value {str} -- a string (default: "")
        """
        self.yaxis["hoverformat"] = value
        return self


    def yaxisLayer(self, value: str) -> Figure:
        """
        Sets the layer on which this axis is displayed. If "above traces", this axis is displayed above all the subplot's traces If "below traces", this axis is displayed below all the subplot's traces, but above the grid lines. Useful when used together with scatter-like traces with `cliponaxis` set to "False" to show markers and/or text nodes above this axis.

        Args:
            value {str} -- a enumerated , one of ( "above traces" | "below traces" ) (default: "above traces")
        """
        self.yaxis["layer"] = value
        return self


    def yaxisLineColor(self, value: str) -> Figure:
        """
        Sets the axis line color.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["linecolor"] = value
        return self


    def yaxisLineWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the axis line.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.yaxis["linewidth"] = value
        return self


    def yaxisMatches(self, value: str) -> Figure:
        """
        If set to another axis id (e.g. `x2`, `y`), the range of this axis will match the range of the corresponding axis in data-coordinates space. Moreover, matching axes share auto-range values, category lists and histogram auto-bins. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden. Moreover, note that matching axes must have the same `type`.

        Args:
            value {str} -- a enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.yaxis["matches"] = value
        return self


    def yaxisMinExponent(self, value: int) -> Figure:
        """
        Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is "SI" or "B".

        Args:
            value {int} -- a number greater than or equal to 0 (default: 3)
        """
        self.yaxis["minexponent"] = value
        return self


    def yaxisMinorSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["minor"] = value
        return self


    def yaxisMinorDtick(self, value: str) -> Figure:
        """
        Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.yaxis["minor_dtick"] = value
        return self


    def yaxisMinorGridColor(self, value: str) -> Figure:
        """
        Sets the color of the grid lines.

        Args:
            value {str} -- a color (default: "#eee")
        """
        self.yaxis["minor_gridcolor"] = value
        return self


    def yaxisMinorGridDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").

        Args:
            value {str} -- a string (default: "solid")
        """
        self.yaxis["minor_griddash"] = value
        return self


    def yaxisMinorGridWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the grid lines.

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.yaxis["minor_gridwidth"] = value
        return self


    def yaxisMinorNticks(self, value: str) -> Figure:
        """
        Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".

        Args:
            value {str} -- a integer greater than or equal to 0 (default: 5)
        """
        self.yaxis["minor_nticks"] = value
        return self


    def yaxisMinorShowgrid(self, value: str) -> Figure:
        """
        Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.

        Args:
            value {str} -- a boolean
        """
        self.yaxis["minor_showgrid"] = value
        return self


    def yaxisMinorTick0(self, value: str) -> Figure:
        """
        Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.yaxis["minor_tick0"] = value
        return self


    def yaxisMinorTickColor(self, value: str) -> Figure:
        """
        Sets the tick color.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["minor_tickcolor"] = value
        return self


    def yaxisMinorTickLength(self, value: int) -> Figure:
        """
        Sets the tick length (in px).

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.yaxis["minor_ticklen"] = value
        return self


    def yaxisMinorTickMode(self, value: str) -> Figure:
        """
        Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).

        Args:
            value {str} -- a enumerated , one of ( "auto" | "linear" | "array" )
        """
        self.yaxis["minor_tickmode"] = value
        return self


    def yaxisMinorTicks(self, value: str) -> Figure:
        """
        Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.

        Args:
            value {str} -- a enumerated , one of ( "outside" | "inside" | "" )
        """
        self.yaxis["minor_ticks"] = value
        return self


    def yaxisMinorTickValues(self, value: list) -> Figure:
        """
        Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.yaxis["minor_tickvals"] = value
        return self


    def yaxisMinorTickWidth(self, value: int) -> Figure:
        """
        Sets the tick width (in px).

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.yaxis["minor_tickwidth"] = value
        return self


    def yaxisMirror(self, value: str) -> Figure:
        """
        Determines if the axis lines or/and ticks are mirrored to the opposite side of the plotting area. If "True", the axis lines are mirrored. If "ticks", the axis lines and ticks are mirrored. If "False", mirroring is disable. If "all", axis lines are mirrored on all shared-axes subplots. If "allticks", axis lines and ticks are mirrored on all shared-axes subplots.

        Args:
            value {str} -- a enumerated , one of ( True | "ticks" | False | "all" | "allticks" )
        """
        self.yaxis["mirror"] = value
        return self


    def yaxisNticks(self, value: str) -> Figure:
        """
        Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".

        Args:
            value {str} -- a integer greater than or equal to 0 (default: 0)
        """
        self.yaxis["nticks"] = value
        return self


    def yaxisOverlaying(self, value: str) -> Figure:
        """
        If set a same-letter axis id, this axis is overlaid on top of the corresponding same-letter axis, with traces and axes visible for both axes. If "False", this axis does not overlay any same-letter axes. In this case, for axes with overlapping domains only the highest-numbered axis will be visible.

        Args:
            value {str} -- a enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.yaxis["overlaying"] = value
        return self


    def yaxisPosition(self, value: int) -> Figure:
        """
        Sets the position of this axis in the plotting space (in normalized coordinates). Only has an effect if `anchor` is set to "free".

        Args:
            value {int} -- a number between or equal to 0 and 1 (default: 0)
        """
        self.yaxis["position"] = value
        return self


    def yaxisRange(l: float, r: float) -> Figure:
        """
        Sets the range of this axis. If the axis `type` is "log", then you must take the log of your desired range (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {float} -- a list
        """
        self.yaxis["range"] = [l, r]
        return self


    def yaxisRangeBreaks(self, value: list) -> Figure:
        """
        Missing documentation!

        Args:
            value {list} -- a list of dict where each dict has one or more of the keys listed below.
        """
        self.yaxis["rangebreaks"] = value
        return self


    def yaxisRangeBreaksBounds(self, value: list) -> Figure:
        """
        Sets the lower and upper bounds of this axis rangebreak. Can be used with `pattern`.

        Args:
            value {list} -- a list
        """
        self.yaxis["rangebreaks_bounds"] = value
        return self


    def yaxisRangeBreaksDvalue(self, value: int) -> Figure:
        """
        Sets the size of each `values` item. The default is one day in milliseconds.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 86400000)
        """
        self.yaxis["rangebreaks_dvalue"] = value
        return self


    def yaxisRangeBreaksEnabled(self, value: str) -> Figure:
        """
        Determines whether this axis rangebreak is enabled or disabled. Please note that `rangebreaks` only work for "date" axis type.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.yaxis["rangebreaks_enabled"] = value
        return self


    def yaxisRangeBreaksName(self, value: str) -> Figure:
        """
        When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.

        Args:
            value {str} -- a string
        """
        self.yaxis["rangebreaks_name"] = value
        return self


    def yaxisRangeBreaksPattern(self, value: str) -> Figure:
        """
        Determines a pattern on the time line that generates breaks. If "day of week" - days of the week in English e.g. 'Sunday' or `sun` (matching is case-insensitive and considers only the first three characters), as well as Sunday-based integers between 0 and 6. If "hour" - hour (24-hour clock) as decimal numbers between 0 and 24. for more info. Examples: - { pattern: 'day of week', bounds: [6, 1] } or simply { bounds: ['sat', 'mon'] } breaks from Saturday to Monday (i.e. skips the weekends). - { pattern: 'hour', bounds: [17, 8] } breaks from 5pm to 8am (i.e. skips non-work hours).

        Args:
            value {str} -- a enumerated , one of ( "day of week" | "hour" | "" )
        """
        self.yaxis["rangebreaks_pattern"] = value
        return self


    def yaxisRangeBreaksTemplateItemName(self, value: str) -> Figure:
        """
        Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.

        Args:
            value {str} -- a string
        """
        self.yaxis["rangebreaks_templateitemname"] = value
        return self


    def yaxisRangeBreaksValues(self, value: list) -> Figure:
        """
        Sets the coordinate values corresponding to the rangebreaks. An alternative to `bounds`. Use `dvalue` to set the size of the values along the axis.

        Args:
            value {list} -- a list
        """
        self.yaxis["rangebreaks_values"] = value
        return self


    def yaxisRangeMode(self, value: str) -> Figure:
        """
        If "normal", the range is computed in relation to the extrema of the input data. If "tozero"`, the range extends to 0, regardless of the input data If "nonnegative", the range is non-negative, regardless of the input data. Applies only to linear axes.

        Args:
            value {str} -- a enumerated , one of ( "normal" | "tozero" | "nonnegative" ) (default: "normal")
        """
        self.yaxis["rangemode"] = value
        return self


    def yaxisRangeSelectorSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["rangeselector"] = value
        return self


    def yaxisRangeSelectorActiveColor(self, value: str) -> Figure:
        """
        Sets the background color of the active range selector button.

        Args:
            value {str} -- a color
        """
        self.yaxis["rangeselector_activecolor"] = value
        return self


    def yaxisRangeSelectorBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of the range selector buttons.

        Args:
            value {str} -- a color (default: "#eee")
        """
        self.yaxis["rangeselector_bgcolor"] = value
        return self


    def yaxisRangeSelectorBorderColor(self, value: str) -> Figure:
        """
        Sets the color of the border enclosing the range selector.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["rangeselector_bordercolor"] = value
        return self


    def yaxisRangeSelectorBorderWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the border enclosing the range selector.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 0)
        """
        self.yaxis["rangeselector_borderwidth"] = value
        return self


    def yaxisRangeSelectorButtons(self, value: list) -> Figure:
        """
        Missing documentation!

        Args:
            value {list} -- a list of dict where each dict has one or more of the keys listed below.
        """
        self.yaxis["rangeselector_buttons"] = value
        return self


    def yaxisRangeSelectorCount(self, value: int) -> Figure:
        """
        Sets the number of steps to take to update the range. Use with `step` to specify the update interval.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.yaxis["rangeselector_count"] = value
        return self


    def yaxisRangeSelectorLabel(self, value: str) -> Figure:
        """
        Sets the text label to appear on the button.

        Args:
            value {str} -- a string
        """
        self.yaxis["rangeselector_label"] = value
        return self


    def yaxisRangeSelectorName(self, value: str) -> Figure:
        """
        When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.

        Args:
            value {str} -- a string
        """
        self.yaxis["rangeselector_name"] = value
        return self


    def yaxisRangeSelectorStep(self, value: str) -> Figure:
        """
        The unit of measurement that the `count` value will set the range by.

        Args:
            value {str} -- a enumerated , one of ( "month" | "year" | "day" | "hour" | "minute" | "second" | "all" ) (default: "month")
        """
        self.yaxis["rangeselector_step"] = value
        return self


    def yaxisRangeSelectorStepMode(self, value: str) -> Figure:
        """
        Sets the range update mode. If "backward", the range update shifts the start of range back "count" times "step" milliseconds. If "todate", the range update shifts the start of range back to the first timestamp from "count" times "step" milliseconds back. For example, with `step` set to "year" and `count` set to "1" the range update shifts the start of the range back to January 01 of the current year. Month and year "todate" are currently available only for the built-in (Gregorian) calendar.

        Args:
            value {str} -- a enumerated , one of ( "backward" | "todate" ) (default: "backward")
        """
        self.yaxis["rangeselector_stepmode"] = value
        return self


    def yaxisRangeSelectorTemplateItemName(self, value: str) -> Figure:
        """
        Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.

        Args:
            value {str} -- a string
        """
        self.yaxis["rangeselector_templateitemname"] = value
        return self


    def yaxisRangeSelectorFontSpecs(self, value: dict) -> Figure:
        """
        Sets the font of the range selector button text.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["rangeselector_font"] = value
        return self


    def yaxisRangeSelectorFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.yaxis["rangeselector_font_color"] = value
        return self


    def yaxisRangeSelectorFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.yaxis["rangeselector_font_family"] = value
        return self


    def yaxisRangeSelectorFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.yaxis["rangeselector_font_size"] = value
        return self


    def yaxisRangeSelectorVisible(self, value: str) -> Figure:
        """
        Determines whether or not this range selector is visible. Note that range selectors are only available for x axes of `type` set to or auto-typed to "date".

        Args:
            value {str} -- a boolean (default: True)
        """
        self.yaxis["rangeselector_visible"] = value
        return self


    def yaxisRangeSelectorX(self, value: int) -> Figure:
        """
        Sets the x position (in normalized coordinates) of the range selector.

        Args:
            value {int} -- a number between or equal to -2 and 3
        """
        self.yaxis["rangeselector_x"] = value
        return self


    def yaxisRangeSelectorXanchor(self, value: str) -> Figure:
        """
        Sets the range selector's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the range selector.

        Args:
            value {str} -- a enumerated , one of ( "auto" | "left" | "center" | "right" ) (default: "left")
        """
        self.yaxis["rangeselector_xanchor"] = value
        return self


    def yaxisRangeSelectorY(self, value: int) -> Figure:
        """
        Sets the y position (in normalized coordinates) of the range selector.

        Args:
            value {int} -- a number between or equal to -2 and 3
        """
        self.yaxis["rangeselector_y"] = value
        return self


    def yaxisRangeSelectorYanchor(self, value: str) -> Figure:
        """
        Sets the range selector's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the range selector.

        Args:
            value {str} -- a enumerated , one of ( "auto" | "top" | "middle" | "bottom" ) (default: "bottom")
        """
        self.yaxis["rangeselector_yanchor"] = value
        return self


    def yaxisRangeSliderSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["rangeslider"] = value
        return self


    def yaxisRangeSliderAutoRange(self, value: str) -> Figure:
        """
        Determines whether or not the range slider range is computed in relation to the input data. If `range` is provided, then `autorange` is set to "False".

        Args:
            value {str} -- a boolean (default: True)
        """
        self.yaxis["rangeslider_autorange"] = value
        return self


    def yaxisRangeSliderBackgroundColor(self, value: str) -> Figure:
        """
        Sets the background color of the range slider.

        Args:
            value {str} -- a color (default: "#fff")
        """
        self.yaxis["rangeslider_bgcolor"] = value
        return self


    def yaxisRangeSliderBorderColor(self, value: str) -> Figure:
        """
        Sets the border color of the range slider.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["rangeslider_bordercolor"] = value
        return self


    def yaxisRangeSliderBorderWidth(self, value: str) -> Figure:
        """
        Sets the border width of the range slider.

        Args:
            value {str} -- a integer greater than or equal to 0 (default: 0)
        """
        self.yaxis["rangeslider_borderwidth"] = value
        return self


    def yaxisRangeSliderRange(self, value: list) -> Figure:
        """
        Sets the range of the range slider. If not set, defaults to the full yaxis range. If the axis `type` is "log", then you must take the log of your desired range. If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {list} -- a list
        """
        self.yaxis["rangeslider_range"] = value
        return self


    def yaxisRangeSliderThickness(self, value: int) -> Figure:
        """
        The height of the range slider as a fraction of the total plot area height.

        Args:
            value {int} -- a number between or equal to 0 and 1 (default: 0.15)
        """
        self.yaxis["rangeslider_thickness"] = value
        return self


    def yaxisRangeSliderVisible(self, value: str) -> Figure:
        """
        Determines whether or not the range slider will be visible. If visible, perpendicular axes will be set to `fixedrange`

        Args:
            value {str} -- a boolean (default: True)
        """
        self.yaxis["rangeslider_visible"] = value
        return self


    def yaxisRangeSliderYaxisSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["rangeslider_yaxis"] = value
        return self


    def yaxisRangeSliderYaxisRange(l: float, r: float) -> Figure:
        """
        Sets the range of this axis for the rangeslider.

        Args:
            value {float} -- a list
        """
        self.yaxis["rangeslider_yaxis_range"] = [l, r]
        return self


    def yaxisRangeSliderYaxisRangeMode(self, value: str) -> Figure:
        """
        Determines whether or not the range of this axis in the rangeslider use the same value than in the main plot when zooming in/out. If "auto", the autorange will be used. If "fixed", the `range` is used. If "match", the current range of the corresponding y-axis on the main subplot is used.

        Args:
            value {str} -- a enumerated , one of ( "auto" | "fixed" | "match" ) (default: "match")
        """
        self.yaxis["rangeslider_yaxis_rangemode"] = value
        return self


    def yaxisScaleAnchor(self, value: str) -> Figure:
        """
        If set to another axis id (e.g. `x2`, `y`), the range of this axis changes together with the range of the corresponding axis such that the scale of pixels per unit is in a constant ratio. Both axes are still zoomable, but when you zoom one, the other will zoom the same amount, keeping a fixed midpoint. `constrain` and `constraintoward` determine how we enforce the constraint. You can chain these, ie `yaxis: {scaleanchor: "x"}, yaxis2: {scaleanchor: "y"}` but you can only link axes of the same `type`. The linked axis can have the opposite letter (to constrain the aspect ratio) or the same letter (to match scales across subplots). Loops (`yaxis: {scaleanchor: "x"}, yaxis: {scaleanchor: "y"}` or longer) are redundant and the last constraint encountered will be ignored to avoid possible inconsistent constraints via `scaleratio`. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden.

        Args:
            value {str} -- a enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
        """
        self.yaxis["scaleanchor"] = value
        return self


    def yaxisScaleRatio(self, value: int) -> Figure:
        """
        If this axis is linked to another by `scaleanchor`, this determines the pixel to unit scale ratio. For example, if this value is 10, then every unit on this axis spans 10 times the number of pixels as a unit on the linked axis. Use this for example to create an elevation profile where the vertical scale is exaggerated a fixed amount with respect to the horizontal.

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.yaxis["scaleratio"] = value
        return self


    def yaxisSeparateThousands(self, value: str) -> Figure:
        """
        If "True", even 4-digit integers are separated

        Args:
            value {str} -- a boolean
        """
        self.yaxis["separatethousands"] = value
        return self


    def yaxisShowDividers(self, value: str) -> Figure:
        """
        Determines whether or not a dividers are drawn between the category levels of this axis. Only has an effect on "multicategory" axes.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.yaxis["showdividers"] = value
        return self


    def yaxisShowExponent(self, value: str) -> Figure:
        """
        If "all", all exponents are shown besides their significands. If "first", only the exponent of the first tick is shown. If "last", only the exponent of the last tick is shown. If "none", no exponents appear.

        Args:
            value {str} -- a enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
        """
        self.yaxis["showexponent"] = value
        return self


    def yaxisShowGrid(self, value: str) -> Figure:
        """
        Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.

        Args:
            value {str} -- a boolean
        """
        self.yaxis["showgrid"] = value
        return self


    def yaxisShowLine(self, value: str) -> Figure:
        """
        Determines whether or not a line bounding this axis is drawn.

        Args:
            value {str} -- a boolean
        """
        self.yaxis["showline"] = value
        return self


    def yaxisShowSpikes(self, value: str) -> Figure:
        """
        Determines whether or not spikes (aka droplines) are drawn for this axis. Note: This only takes affect when hovermode = closest

        Args:
            value {str} -- a boolean
        """
        self.yaxis["showspikes"] = value
        return self


    def yaxisShowTickLabels(self, value: str) -> Figure:
        """
        Determines whether or not the tick labels are drawn.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.yaxis["showticklabels"] = value
        return self


    def yaxisShowTickPrefix(self, value: str) -> Figure:
        """
        If "all", all tick labels are displayed with a prefix. If "first", only the first tick is displayed with a prefix. If "last", only the last tick is displayed with a suffix. If "none", tick prefixes are hidden.

        Args:
            value {str} -- a enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
        """
        self.yaxis["showtickprefix"] = value
        return self


    def yaxisShowTickSuffix(self, value: str) -> Figure:
        """
        Same as `showtickprefix` but for tick suffixes.

        Args:
            value {str} -- a enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
        """
        self.yaxis["showticksuffix"] = value
        return self


    def yaxisSide(self, value: str) -> Figure:
        """
        Determines whether a x (y) axis is positioned at the "bottom" ("left") or "top" ("right") of the plotting area.

        Args:
            value {str} -- a enumerated , one of ( "top" | "bottom" | "left" | "right" )
        """
        self.yaxis["side"] = value
        return self


    def yaxisSpikeColor(self, value: str) -> Figure:
        """
        Sets the spike color. If undefined, will use the series color

        Args:
            value {str} -- a color
        """
        self.yaxis["spikecolor"] = value
        return self


    def yaxisSpikeDash(self, value: str) -> Figure:
        """
        Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").

        Args:
            value {str} -- a string (default: "dash")
        """
        self.yaxis["spikedash"] = value
        return self


    def yaxisSpikeMode(self, value: str) -> Figure:
        """
        Determines the drawing mode for the spike line If "toaxis", the line is drawn from the data point to the axis the series is plotted on. If "across", the line is drawn across the entire plot area, and supercedes "toaxis". If "marker", then a marker dot is drawn on the axis the series is plotted on

        Args:
            value {str} -- a flaglist string. Any combination of "toaxis", "across", "marker" joined with a "+". Examples: "toaxis", "across", "toaxis+across", "toaxis+across+marker" (default: "toaxis")
        """
        self.yaxis["spikemode"] = value
        return self


    def yaxisSpikeSnap(self, value: str) -> Figure:
        """
        Determines whether spikelines are stuck to the cursor or to the closest datapoints.

        Args:
            value {str} -- a enumerated , one of ( "data" | "cursor" | "hovered data" ) (default: "hovered data")
        """
        self.yaxis["spikesnap"] = value
        return self


    def yaxisSpikeThickness(self, value: int) -> Figure:
        """
        Sets the width (in px) of the zero line.

        Args:
            value {int} -- a number (default: 3)
        """
        self.yaxis["spikethickness"] = value
        return self


    def yaxisTick0(self, value: str) -> Figure:
        """
        Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.yaxis["tick0"] = value
        return self


    def yaxisTickAngle(self, value: str) -> Figure:
        """
        Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the tick labels vertically.

        Args:
            value {str} -- a angle (default: "auto")
        """
        self.yaxis["tickangle"] = value
        return self


    def yaxisTickColor(self, value: str) -> Figure:
        """
        Sets the tick color.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["tickcolor"] = value
        return self


    def yaxisTickFontSpecs(self, value: dict) -> Figure:
        """
        Sets the tick font.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["tickfont"] = value
        return self


    def yaxisTickFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.yaxis["tickfont_color"] = value
        return self


    def yaxisTickFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.yaxis["tickfont_family"] = value
        return self


    def yaxisTickFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.yaxis["tickfont_size"] = value
        return self


    def yaxisTickFormat(self, value: str) -> Figure:
        """
        Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"

        Args:
            value {str} -- a string (default: "")
        """
        self.yaxis["tickformat"] = value
        return self


    def yaxisTickFormatStops(self, value: list) -> Figure:
        """
        Missing documentation!

        Args:
            value {list} -- a list of dict where each dict has one or more of the keys listed below.
        """
        self.yaxis["tickformatstops"] = value
        return self


    def yaxisTickFormatStopsDtickRange(self, value: list) -> Figure:
        """
        range ["min", "max"], where "min", "max" - dtick values which describe some zoom level, it is possible to omit "min" or "max" value by passing "null"

        Args:
            value {list} -- a list
        """
        self.yaxis["tickformatstops_dtickrange"] = value
        return self


    def yaxisTickFormatStopsEnabled(self, value: str) -> Figure:
        """
        Determines whether or not this stop is used. If `False`, this stop is ignored even within its `dtickrange`.

        Args:
            value {str} -- a boolean (default: True)
        """
        self.yaxis["tickformatstops_enabled"] = value
        return self


    def yaxisTickFormatStopsName(self, value: str) -> Figure:
        """
        When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.

        Args:
            value {str} -- a string
        """
        self.yaxis["tickformatstops_name"] = value
        return self


    def yaxisTickFormatStopsTemplateItemName(self, value: str) -> Figure:
        """
        Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.

        Args:
            value {str} -- a string
        """
        self.yaxis["tickformatstops_templateitemname"] = value
        return self


    def yaxisTickFormatStopsValue(self, value: str) -> Figure:
        """
        string - dtickformat for described zoom level, the same as "tickformat"

        Args:
            value {str} -- a string (default: "")
        """
        self.yaxis["tickformatstops_value"] = value
        return self


    def yaxisTickLabelMode(self, value: str) -> Figure:
        """
        Determines where tick labels are drawn with respect to their corresponding ticks and grid lines. Only has an effect for axes of `type` "date" When set to "period", tick labels are drawn in the middle of the period between ticks.

        Args:
            value {str} -- a enumerated , one of ( "instant" | "period" ) (default: "instant")
        """
        self.yaxis["ticklabelmode"] = value
        return self


    def yaxisTickLabelOverflow(self, value: str) -> Figure:
        """
        Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The default value for inside tick labels is "hide past domain". Otherwise on "category" and "multicategory" axes the default is "allow". In other cases the default is "hide past div".

        Args:
            value {str} -- a enumerated , one of ( "allow" | "hide past div" | "hide past domain" )
        """
        self.yaxis["ticklabeloverflow"] = value
        return self


    def yaxisTickLabelPosition(self, value: str) -> Figure:
        """
        Determines where tick labels are drawn with respect to the axis Please note that top or bottom has no effect on x axes or when `ticklabelmode` is set to "period". Similarly left or right has no effect on y axes or when `ticklabelmode` is set to "period". Has no effect on "multicategory" axes or when `tickson` is set to "boundaries". When used on axes linked by `matches` or `scaleanchor`, no extra padding for inside labels would be added by autorange, so that the scales could match.

        Args:
            value {str} -- a enumerated , one of ( "outside" | "inside" | "outside top" | "inside top" | "outside left" | "inside left" | "outside right" | "inside right" | "outside bottom" | "inside bottom" ) (default: "outside")
        """
        self.yaxis["ticklabelposition"] = value
        return self


    def yaxisTickLabelStep(self, value: str) -> Figure:
        """
        Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` "log" or "multicategory", or when `tickmode` is "array".

        Args:
            value {str} -- a integer greater than or equal to 1 (default: 1)
        """
        self.yaxis["ticklabelstep"] = value
        return self


    def yaxisTickLength(self, value: int) -> Figure:
        """
        Sets the tick length (in px).

        Args:
            value {int} -- a number greater than or equal to 0 (default: 5)
        """
        self.yaxis["ticklen"] = value
        return self


    def yaxisTickMode(self, value: str) -> Figure:
        """
        Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).

        Args:
            value {str} -- a enumerated , one of ( "auto" | "linear" | "array" )
        """
        self.yaxis["tickmode"] = value
        return self


    def yaxisTickPrefix(self, value: str) -> Figure:
        """
        Sets a tick label prefix.

        Args:
            value {str} -- a string (default: "")
        """
        self.yaxis["tickprefix"] = value
        return self


    def yaxisTicks(self, value: str) -> Figure:
        """
        Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.

        Args:
            value {str} -- a enumerated , one of ( "outside" | "inside" | "" )
        """
        self.yaxis["ticks"] = value
        return self


    def yaxisTickson(self, value: str) -> Figure:
        """
        Determines where ticks and grid lines are drawn with respect to their corresponding tick labels. Only has an effect for axes of `type` "category" or "multicategory". When set to "boundaries", ticks and grid lines are drawn half a category to the left/bottom of labels.

        Args:
            value {str} -- a enumerated , one of ( "labels" | "boundaries" ) (default: "labels")
        """
        self.yaxis["tickson"] = value
        return self


    def yaxisTickSuffix(self, value: str) -> Figure:
        """
        Sets a tick label suffix.

        Args:
            value {str} -- a string (default: "")
        """
        self.yaxis["ticksuffix"] = value
        return self


    def yaxisTickText(self, value: list) -> Figure:
        """
        Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to "array". Used with `tickvals`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.yaxis["ticktext"] = value
        return self


    def yaxisTickValues(self, value: list) -> Figure:
        """
        Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.

        Args:
            value {list} -- a list, numpy array, or Pandas series of numbers, strings, or datetimes.
        """
        self.yaxis["tickvals"] = value
        return self


    def yaxisTickWidth(self, value: int) -> Figure:
        """
        Sets the tick width (in px).

        Args:
            value {int} -- a number greater than or equal to 0 (default: 1)
        """
        self.yaxis["tickwidth"] = value
        return self


    def yaxisTitleSpecs(self, value: dict) -> Figure:
        """
        Missing documentation!

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["title"] = value
        return self


    def yaxisTitleFontSpecs(self, value: dict) -> Figure:
        """
        Sets this axis' title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.

        Args:
            value {dict} -- a dict containing one or more of the keys listed below.
        """
        self.yaxis["title_font"] = value
        return self


    def yaxisTitleFontColor(self, value: str) -> Figure:
        """
        Missing documentation!

        Args:
            value {str} -- a color
        """
        self.yaxis["title_font_color"] = value
        return self


    def yaxisTitleFontFamily(self, value: str) -> Figure:
        """
        HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".

        Args:
            value {str} -- a string
        """
        self.yaxis["title_font_family"] = value
        return self


    def yaxisTitleFontSize(self, value: int) -> Figure:
        """
        Missing documentation!

        Args:
            value {int} -- a number greater than or equal to 1
        """
        self.yaxis["title_font_size"] = value
        return self


    def yaxisTitleStandoff(self, value: int) -> Figure:
        """
        Sets the standoff distance (in px) between the axis labels and the title text The default value is a function of the axis tick labels, the title `font.size` and the axis `linewidth`. Note that the axis title position is always constrained within the margins, so the actual standoff distance is always less than the set or default value. By setting `standoff` and turning on `automargin`, plotly.js will push the margins to fit the axis title at given standoff distance.

        Args:
            value {int} -- a number greater than or equal to 0
        """
        self.yaxis["title_standoff"] = value
        return self


    def yaxisTitleText(self, value: str) -> Figure:
        """
        Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.

        Args:
            value {str} -- a string
        """
        self.yaxis["title_text"] = value
        return self


    def yaxisType(self, value: str) -> Figure:
        """
        Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the traces that referenced the axis in question.

        Args:
            value {str} -- a enumerated , one of ( "-" | "linear" | "log" | "date" | "category" | "multicategory" ) (default: "-")
        """
        self.yaxis["type"] = value
        return self


    def yaxisUirevision(self, value: str) -> Figure:
        """
        Controls persistence of user-driven changes in axis `range`, `autorange`, and `title` if in `editable: True` configuration. Defaults to `layout.uirevision`.

        Args:
            value {str} -- a number or categorical coordinate string
        """
        self.yaxis["uirevision"] = value
        return self


    def yaxisVisible(self, value: str) -> Figure:
        """
        A single toggle to hide the axis while preserving interaction like dragging. Default is True when a cheater plot is present on the axis, otherwise False

        Args:
            value {str} -- a boolean
        """
        self.yaxis["visible"] = value
        return self


    def yaxisZeroLine(self, value: str) -> Figure:
        """
        Determines whether or not a line is drawn at along the 0 value of this axis. If "True", the zero line is drawn on top of the grid lines.

        Args:
            value {str} -- a boolean
        """
        self.yaxis["zeroline"] = value
        return self


    def yaxisZeroLineColor(self, value: str) -> Figure:
        """
        Sets the line color of the zero line.

        Args:
            value {str} -- a color (default: "#444")
        """
        self.yaxis["zerolinecolor"] = value
        return self


    def yaxisZeroLineWidth(self, value: int) -> Figure:
        """
        Sets the width (in px) of the zero line.

        Args:
            value {int} -- a number (default: 1)
        """
        self.yaxis["zerolinewidth"] = value
        return self


    #=================================================================================================================
    #
    # ALIASES AND METHODS THAT INCREASE CONVENIENCE AND INTUITIVENESS
    #
    #=================================================================================================================


    title       = titleText
    legendTitle = legendTitleText
    xaxisTitle  = xaxisTitleText
    yaxisTitle  = yaxisTitleText


    def xaxisScaleLinear(self):
        """Sets the axis type to a linear scale."""
        self.xaxisType("linear")


    def xaxisScaleLog(self):
        """Sets the axis type to a logarithm scale."""
        self.xaxisType("log")


    def xaxisTypeDate(self):
        """Sets the axis type to date."""
        self.xaxisType("date")


    def yaxisScaleLinear(self):
        """Sets the axis type to a linear scale."""
        self.yaxisType("linear")


    def yaxisScaleLog(self):
        """Sets the axis type to a logarithm scale."""
        self.yaxisType("log")


    def yaxisTypeDate(self):
        """Sets the axis type to date."""
        self.yaxisType("date")

