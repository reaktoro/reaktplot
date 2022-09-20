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

// reaktplot includes
#include <reaktplot/Default.hpp>
#include <reaktplot/Macros.hpp>
#include <reaktplot/Scatter.hpp>
#include <reaktplot/Specs.hpp>

namespace reaktplot {

/// Used to create, show, and save figures using plotly.
class RKP_EXPORT Figure : public Pythonic
{
private:
    py::object fig;
    py::dict layout;
    py::dict xaxis;
    py::dict yaxis;

public:
    /// Construct a default Figure object.
    Figure();

    /// Draw a line in the figure.
    template<typename X, typename Y>
    auto drawLine(X const& x, Y const& y, std::string const& name, LineSpecs const& line = {}) -> void
    {
        draw(Scatter(x, y, name).line(line));
    }

    /// Draw a line with markers in the figure.
    template<typename X, typename Y>
    auto drawLineWithMarkers(X const& x, Y const& y, std::string const& name, LineSpecs const& line = {}, MarkerSpecs const& marker = {}) -> void
    {
        draw(Scatter(x, y, name).mode("lines+markers").line(line).marker(marker));
    }

    /// Draw markers in the figure.
    template<typename X, typename Y>
    auto drawMarkers(X const& x, Y const& y, std::string const& name, MarkerSpecs const& marker = {}) -> void
    {
        draw(Scatter(x, y, name).mode("markers").marker(marker));
    }

    /// Draw a scatter trace to the figure.
    auto draw(Scatter const& scatter) -> void
    {
        fig.attr("add_trace")(scatter.dict());
    }

    /// Show the figure.
    auto show() const -> void;

    /// Save the figure to a PNG, JPEG, WEBP, SVG, PDF, EPS, or HTML file.
    /// @param file The name of the file with extension `.png`, `.jpeg`, 'jpg', `.webp`, `.svg`, `.pdf`, `.eps`, or `.html`.
    auto save(std::string const& file, int width=DEFAULT_FIGURE_WIDTH, int height=DEFAULT_FIGURE_HEIGHT, double scale=DEFAULT_FIGURE_SCALE) const -> void;

    //=================================================================================================================
    //
    // ALIASES AND METHODS THAT INCREASE CONVENIENCE AND INTUITIVENESS
    //
    //=================================================================================================================

    /// @copydoc Figure::titleText
    auto title(std::string const& value) { return titleText(value); }

    /// @copydoc Figure::legendTitleText
    auto legendTitle(std::string const& value) { return legendTitleText(value); }

    /// @copydoc Figure::xaxisTitleText
    auto xaxisTitle(std::string const& value) { return xaxisTitleText(value); }

    /// @copydoc Figure::yaxisTitleText
    auto yaxisTitle(std::string const& value) { return yaxisTitleText(value); }

    /// Sets the axis type to a linear scale.
    auto xaxisScaleLinear() -> Figure& { return xaxisType("linear"); }

    /// Sets the axis type to a logarithm scale.
    auto xaxisScaleLog() -> Figure& { return xaxisType("log"); }

    /// Sets the axis type to date.
    auto xaxisTypeDate() -> Figure& { return xaxisType("date"); }

    /// Sets the axis type to a linear scale.
    auto yaxisScaleLinear() -> Figure& { return yaxisType("linear"); }

    /// Sets the axis type to a logarithm scale.
    auto yaxisScaleLog() -> Figure& { return yaxisType("log"); }

    /// Sets the axis type to date.
    auto yaxisTypeDate() -> Figure& { return yaxisType("date"); }

    //=================================================================================================================
    //
    // METHODS THAT CUSTOMIZE THE LAYOUT OF THE FIGURE
    //
    //=================================================================================================================

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto titleSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.
    /// @param value a dict containing one or more of the keys listed below.
    // auto titleFontSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto titleFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto titleFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto titleFontSize(int value) -> Figure&;

    /// Sets the padding of the title. Each padding value only applies when the corresponding `xanchor`/`yanchor` value is set accordingly. E.g. for left padding to take effect, `xanchor` must be set to "left". The same rule applies if `xanchor`/`yanchor` is determined automatically. Padding is muted if the respective anchor value is "middle"/"center".
    /// @param value a dict containing one or more of the keys listed below.
    // auto titlePaddingSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// The amount of padding (in px) along the bottom of the component. (default: 0)
    /// @param value number
    auto titlePaddingBottom(int value) -> Figure&;

    /// The amount of padding (in px) on the left side of the component. (default: 0)
    /// @param value number
    auto titlePaddingLeft(int value) -> Figure&;

    /// The amount of padding (in px) on the right side of the component. (default: 0)
    /// @param value number
    auto titlePaddingRight(int value) -> Figure&;

    /// The amount of padding (in px) along the top of the component. (default: 0)
    /// @param value number
    auto titlePaddingTop(int value) -> Figure&;

    /// Sets the plot's title. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.
    /// @param value string
    auto titleText(std::string const& value) -> Figure&;

    /// Sets the x position with respect to `xref` in normalized coordinates from "0" (left) to "1" (right). (Default: d.5)
    /// @param value number between or equal to 0 and 1
    auto titleX(double value) -> Figure&;

    /// Sets the title's horizontal alignment with respect to its x position. "left" means that the title starts at x, "right" means that the title ends at x and "center" means that the title's center is at x. "auto" divides `xref` by three and calculates the `xanchor` value automatically based on the value of `x`. (Default: "duto")
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" )
    auto titleXanchor(std::string const& value) -> Figure&;

    /// Sets the container `x` refers to. "container" spans the entire `width` of the plot. "paper" refers to the width of the plotting area only. (Default: "dontainer")
    /// @param value enumerated , one of ( "container" | "paper" )
    auto titleXref(std::string const& value) -> Figure&;

    /// Sets the y position with respect to `yref` in normalized coordinates from "0" (bottom) to "1" (top). "auto" places the baseline of the title onto the vertical center of the top margin. (Default: "duto")
    /// @param value number between or equal to 0 and 1
    auto titleY(double value) -> Figure&;

    /// Sets the title's vertical alignment with respect to its y position. "top" means that the title's cap line is at y, "bottom" means that the title's baseline is at y and "middle" means that the title's midline is at y. "auto" divides `yref` by three and calculates the `yanchor` value automatically based on the value of `y`. (Default: "duto")
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" )
    auto titleYanchor(std::string const& value) -> Figure&;

    /// Sets the container `y` refers to. "container" spans the entire `height` of the plot. "paper" refers to the height of the plotting area only. (Default: "dontainer")
    /// @param value enumerated , one of ( "container" | "paper" )
    auto titleYref(std::string const& value) -> Figure&;

    /// Determines whether or not a legend is drawn. Default is `True` if there is a trace to show and any of these: a) Two or more traces would by default be shown in the legend. b) One pie trace is shown in the legend. c) One trace is explicitly given with `showlegend: True`.
    /// @param value boolean
    auto legendShow(bool value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto legendSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the legend background color. Defaults to `layout.paper_bgcolor`.
    /// @param value color
    auto legendBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the color of the border enclosing the legend. (Default: "#d44")
    /// @param value color
    auto legendBorderColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the border enclosing the legend. (default: 0)
    /// @param value number greater than or equal to 0
    auto legendBorderWidth(int value) -> Figure&;

    /// Sets the font used to text the legend items.
    /// @param value a dict containing one or more of the keys listed below.
    // auto legendFontSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto legendFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto legendFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto legendFontSize(int value) -> Figure&;

    /// Determines the behavior on legend group item click. "toggleitem" toggles the visibility of the individual item clicked on the graph. "togglegroup" toggles the visibility of all items in the same legendgroup as the item clicked on the graph. (Default: "dogglegroup")
    /// @param value enumerated , one of ( "toggleitem" | "togglegroup" )
    auto legendGroupClick(std::string const& value) -> Figure&;

    /// Sets the font for group titles in legend. Defaults to `legend.font` with its size increased about 10%.
    /// @param value a dict containing one or more of the keys listed below.
    // auto legendGroupTitleFontSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto legendGroupTitleFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto legendGroupTitleFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto legendGroupTitleFontSize(int value) -> Figure&;

    /// Determines the behavior on legend item click. "toggle" toggles the visibility of the item clicked on the graph. "toggleothers" makes the clicked item the sole visible item on the graph. "False" disables legend item click interactions. (Default: "doggle")
    /// @param value enumerated , one of ( "toggle" | "toggleothers" | False )
    auto legendItemClick(std::string const& value) -> Figure&;

    /// Determines the behavior on legend item double-click. "toggle" toggles the visibility of the item clicked on the graph. "toggleothers" makes the clicked item the sole visible item on the graph. "False" disables legend item double-click interactions. (Default: "doggleothers")
    /// @param value enumerated , one of ( "toggle" | "toggleothers" | False )
    auto legendItemDoubleClick(std::string const& value) -> Figure&;

    /// Determines if the legend items symbols scale with their corresponding "trace" attributes or remain "constant" independent of the symbol size on the graph. (Default: "drace")
    /// @param value enumerated , one of ( "trace" | "constant" )
    auto legendItemSizing(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the legend item symbols (the part other than the title.text). (default: 30)
    /// @param value number greater than or equal to 30
    auto legendItemWidth(int value) -> Figure&;

    /// Sets the orientation of the legend. (Default: "d")
    /// @param value enumerated , one of ( "v" | "h" )
    auto legendOrientation(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto legendTitleSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets this legend's title font. Defaults to `legend.font` with its size increased about 20%.
    /// @param value a dict containing one or more of the keys listed below.
    // auto legendTitleFontSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto legendTitleFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto legendTitleFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto legendTitleFontSize(int value) -> Figure&;

    /// Determines the location of legend's title with respect to the legend items. Defaulted to "top" with `orientation` is "h". Defaulted to "left" with `orientation` is "v". The "top left" options could be used to expand legend area in both x and y sides.
    /// @param value enumerated , one of ( "top" | "left" | "top left" )
    auto legendTitleSide(std::string const& value) -> Figure&;

    /// Sets the title of the legend. (default: "")
    /// @param value string
    auto legendTitleText(std::string const& value) -> Figure&;

    /// Sets the amount of vertical space (in px) between legend groups. (default: 10)
    /// @param value number greater than or equal to 0
    auto legendTraceGroupGap(int value) -> Figure&;

    /// Determines the order at which the legend items are displayed. If "normal", the items are displayed top-to-bottom in the same order as the input data. If "reversed", the items are displayed in the opposite order as "normal". If "grouped", the items are displayed in groups (when a trace `legendgroup` is provided). if "grouped+reversed", the items are displayed in the opposite order as "grouped".
    /// @param value flaglist string. Any combination of "reversed", "grouped" joined with a "+" OR "normal". Examples: "reversed", "grouped", "reversed+grouped", "normal"
    auto legendTraceOrder(std::string const& value) -> Figure&;

    /// Controls persistence of legend-driven changes in trace and pie label visibility. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto legendUirevision(std::string const& value) -> Figure&;

    /// Sets the vertical alignment of the symbols with respect to their associated text. (Default: "diddle")
    /// @param value enumerated , one of ( "top" | "middle" | "bottom" )
    auto legendValign(std::string const& value) -> Figure&;

    /// Sets the x position (in normalized coordinates) of the legend. Defaults to "1.02" for vertical legends and defaults to "0" for horizontal legends.
    /// @param value number between or equal to -2 and 3
    auto legendX(double value) -> Figure&;

    /// Sets the legend's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the legend. Value "auto" anchors legends to the right for `x` values greater than or equal to 2/3, anchors legends to the left for `x` values less than or equal to 1/3 and anchors legends with respect to their center otherwise. (Default: "deft")
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" )
    auto legendXanchor(std::string const& value) -> Figure&;

    /// Sets the y position (in normalized coordinates) of the legend. Defaults to "1" for vertical legends, defaults to "-0.1" for horizontal legends on graphs w/o range sliders and defaults to "1.1" for horizontal legends on graph with one or multiple range sliders.
    /// @param value number between or equal to -2 and 3
    auto legendY(double value) -> Figure&;

    /// Sets the legend's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the legend. Value "auto" anchors legends at their bottom for `y` values less than or equal to 1/3, anchors legends to at their top for `y` values greater than or equal to 2/3 and anchors legends with respect to their middle otherwise.
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" )
    auto legendYanchor(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto marginSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Turns on/off margin expansion computations. Legends, colorbars, updatemenus, sliders, axis rangeselector and rangeslider are allowed to push the margins by defaults. (default: True)
    /// @param value boolean
    auto marginAutoExpand(bool value) -> Figure&;

    /// Sets the bottom margin (in px). (default: 80)
    /// @param value number greater than or equal to 0
    auto marginBottom(int value) -> Figure&;

    /// Sets the left margin (in px). (default: 80)
    /// @param value number greater than or equal to 0
    auto marginLeft(int value) -> Figure&;

    /// Sets the amount of padding (in px) between the plotting area and the axis lines (default: 0)
    /// @param value number greater than or equal to 0
    auto marginPadding(int value) -> Figure&;

    /// Sets the right margin (in px). (default: 80)
    /// @param value number greater than or equal to 0
    auto marginRight(int value) -> Figure&;

    /// Sets the top margin (in px). (default: 100)
    /// @param value number greater than or equal to 0
    auto marginTop(int value) -> Figure&;

    /// Determines whether or not a layout width or height that has been left undefined by the user is initialized on each relayout. Note that, regardless of this attribute, an undefined layout width or height is always initialized on the first call to plot.
    /// @param value boolean
    auto autosize(bool value) -> Figure&;

    /// Sets the plot's width (in px). (default: 700)
    /// @param value number greater than or equal to 10
    auto width(int value) -> Figure&;

    /// Sets the plot's height (in px). (default: 450)
    /// @param value number greater than or equal to 10
    auto height(int value) -> Figure&;

    /// Sets the global font. Note that fonts used in traces and other layout components inherit from the global font.
    /// @param value a dict containing one or more of the keys listed below.
    // auto fontSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto fontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman". (Default: ""Open Sans", verdana, arial, sans-derif")
    /// @param value string
    auto fontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto fontSize(int value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto uniformTextSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the minimum text size between traces of the same type. (default: 0)
    /// @param value number greater than or equal to 0
    auto uniformTextMinSize(int value) -> Figure&;

    /// Determines how the font size for various text elements are uniformed between each trace type. If the computed text sizes were smaller than the minimum size defined by `uniformtext.minsize` using "hide" option hides the text; and using "show" option shows the text without further downscaling. Please note that if the size defined by `minsize` is greater than the font size defined by trace, then the `minsize` is used.
    /// @param value enumerated , one of ( False | "hide" | "show" )
    auto uniformTextMode(std::string const& value) -> Figure&;

    /// Sets the decimal and thousand separators. For example, ". " puts a '.' before decimals and a space between thousands. In English locales, dflt is ".," but other locales may alter this default.
    /// @param value string
    auto separators(std::string const& value) -> Figure&;

    /// Sets the background color of the paper where the graph is drawn. (Default: "#dff")
    /// @param value color
    auto paperBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the background color of the plotting area in-between x and y axes. (Default: "#dff")
    /// @param value color
    auto plotBackgroundColor(std::string const& value) -> Figure&;

    /// Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. This is the default value; however it could be overridden for individual axes. (Default: "convert dypes")
    /// @param value enumerated , one of ( "convert types" | "strict" )
    auto autoTypeNumbers(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto colorScaleSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the default diverging colorscale. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(5,10,172)], [0.35, rgb(106,137,247)], [0.5, rgb(190,190,190)], [0.6, rgb(220,170,132)], [0.7, rgb(230,145,90)], [1, rgb(178,10,28d], ])
    /// @param value colorscale
    auto colorScaleDiverging(std::string const& value) -> Figure&;

    /// Sets the default sequential colorscale for positive values. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(220,220,220)], [0.2, rgb(245,195,157)], [0.4, rgb(245,160,105)], [1, rgb(178,10,28d], ])
    /// @param value colorscale
    auto colorScaleSequential(std::string const& value) -> Figure&;

    /// Sets the default sequential colorscale for negative values. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(5,10,172)], [0.35, rgb(40,60,190)], [0.5, rgb(70,100,245)], [0.6, rgb(90,120,245)], [0.7, rgb(106,137,247)], [1, rgb(220,220,220d], ])
    /// @param value colorscale
    auto colorScaleSequentialminus(std::string const& value) -> Figure&;

    /// Sets the default trace colors. (Default: [#1f77b4, #ff7f0e, #2ca02c, #d62728, #9467bd, #8c564b, #e377c2, #7f7f7f, #bcbd22, #d7becf])
    /// @param value colorlist
    auto colorway(std::vector<std::string> const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto modebarSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the color of the active or hovered on icons in the modebar.
    /// @param value color
    auto modebarActiveColor(std::string const& value) -> Figure&;

    /// Determines which predefined modebar buttons to add. Please note that these buttons will only be shown if they are compatible with all trace types used in a graph. Similar to `config.modeBarButtonsToAdd` option. This may include "v1hovermode", "hoverclosest", "hovercompare", "togglehover", "togglespikelines", "drawline", "drawopenpath", "drawclosedpath", "drawcircle", "drawrect", "eraseshape". (default: "")
    /// @param value string or array of strings
    auto modebarAdd(std::string const& value) -> Figure&;

    /// Sets the background color of the modebar.
    /// @param value color
    auto modebarBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the color of the icons in the modebar.
    /// @param value color
    auto modebarColor(std::string const& value) -> Figure&;

    /// Sets the orientation of the modebar. (Default: "d")
    /// @param value enumerated , one of ( "v" | "h" )
    auto modebarOrientation(std::string const& value) -> Figure&;

    /// Determines which predefined modebar buttons to remove. Similar to `config.modeBarButtonsToRemove` option. This may include "autoScale2d", "autoscale", "editInChartStudio", "editinchartstudio", "hoverCompareCartesian", "hovercompare", "lasso", "lasso2d", "orbitRotation", "orbitrotation", "pan", "pan2d", "pan3d", "reset", "resetCameraDefault3d", "resetCameraLastSave3d", "resetGeo", "resetSankeyGroup", "resetScale2d", "resetViewMapbox", "resetViews", "resetcameradefault", "resetcameralastsave", "resetsankeygroup", "resetscale", "resetview", "resetviews", "select", "select2d", "sendDataToCloud", "senddatatocloud", "tableRotation", "tablerotation", "toImage", "toggleHover", "toggleSpikelines", "togglehover", "togglespikelines", "toimage", "zoom", "zoom2d", "zoom3d", "zoomIn2d", "zoomInGeo", "zoomInMapbox", "zoomOut2d", "zoomOutGeo", "zoomOutMapbox", "zoomin", "zoomout". (default: "")
    /// @param value string or array of strings
    auto modebarRemove(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes related to the modebar, including `hovermode`, `dragmode`, and `showspikes` at both the root level and inside subplots. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto modebarUirevision(std::string const& value) -> Figure&;

    /// Determines the mode of hover interactions. If "closest", a single hoverlabel will appear for the "closest" point within the `hoverdistance`. If "x" (or "y"), multiple hoverlabels will appear for multiple points at the "closest" x- (or y-) coordinate within the `hoverdistance`, with the caveat that no more than one hoverlabel will appear per trace. If "x unified" (or "y unified"), a single hoverlabel will appear multiple points at the closest x- (or y-) coordinate within the `hoverdistance` with the caveat that no more than one hoverlabel will appear per trace. In this mode, spikelines are enabled by default perpendicular to the specified axis. If False, hover interactions are disabled. (Default: "dlosest")
    /// @param value enumerated , one of ( "x" | "y" | "closest" | False | "x unified" | "y unified" )
    auto hoverMode(std::string const& value) -> Figure&;

    /// Examples: "event", "select", "event+select", "none"
    /// @param value flaglist string. Any combination of "event", "select" joined with a "+" OR "none".
    auto clickMode(std::string const& value) -> Figure&;

    /// Determines the mode of drag interactions. "select" and "lasso" apply only to scatter traces with markers or text. "orbit" and "turntable" apply only to 3D scenes. (Default: "doom")
    /// @param value enumerated , one of ( "zoom" | "pan" | "select" | "lasso" | "drawclosedpath" | "drawopenpath" | "drawline" | "drawrect" | "drawcircle" | "orbit" | "turntable" | False )
    auto dragMode(std::string const& value) -> Figure&;

    /// When `dragmode` is set to "select", this limits the selection of the drag to horizontal, vertical or diagonal. "h" only allows horizontal selection, "v" only vertical, "d" only diagonal and "any" sets no limit. (Default: "dny")
    /// @param value enumerated , one of ( "h" | "v" | "d" | "any" )
    auto selectDirection(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto activeSelectionSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the color filling the active selection' interior. (Default: "rgba(0,0,0,d)")
    /// @param value color
    auto activeSelectionFillColor(std::string const& value) -> Figure&;

    /// Sets the opacity of the active selection. (Default: d.5)
    /// @param value number between or equal to 0 and 1
    auto activeSelectionOpacity(double value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto newSelectionSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto newSelectionLineSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the line color. By default uses either dark grey or white to increase contrast with background color.
    /// @param value color
    auto newSelectionLineColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dot")
    /// @param value string
    auto newSelectionLineDash(std::string const& value) -> Figure&;

    /// Sets the line width (in px). (default: 1)
    /// @param value number greater than or equal to 1
    auto newSelectionLineWidth(int value) -> Figure&;

    /// Describes how a new selection is created. If `immediate`, a new selection is created after first mouse up. If `gradual`, a new selection is not created after first mouse. By adding to and subtracting from the initial selection, this option allows declaring extra outlines of the selection. (Default: "dmmediate")
    /// @param value enumerated , one of ( "immediate" | "gradual" )
    auto newSelectionMode(std::string const& value) -> Figure&;

    /// Sets the default distance (in pixels) to look for data to add hover labels (-1 means no cutoff, 0 means no looking for data). This is only a real distance for hovering on point-like objects, like scatter points. For area-like objects (bars, scatter fills, etc) hovering is on inside the area and off outside, but these objects will not supersede hover on point-like objects in case of conflict. (default: 20)
    /// @param value integer greater than or equal to -1
    auto hoverDistance(std::string const& value) -> Figure&;

    /// Sets the default distance (in pixels) to look for data to draw spikelines to (-1 means no cutoff, 0 means no looking for data). As with hoverdistance, distance does not apply to area-like objects. In addition, some objects can be hovered on but will not generate spikelines, such as scatter fills. (Default: d1)
    /// @param value integer greater than or equal to -1
    auto spikeDistance(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto hoverLabelSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the horizontal alignment of the text content within hover label box. Has an effect only if the hover label text spans more two or more lines (Default: "duto")
    /// @param value enumerated , one of ( "left" | "right" | "auto" )
    auto hoverLabelAlign(std::string const& value) -> Figure&;

    /// Sets the background color of all hover labels on graph
    /// @param value color
    auto hoverLabelBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the border color of all hover labels on graph.
    /// @param value color
    auto hoverLabelBorderColor(std::string const& value) -> Figure&;

    /// Sets the default hover label font used by all traces on the graph.
    /// @param value a dict containing one or more of the keys listed below.
    // auto hoverLabelFontSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto hoverLabelFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman". (Default: "Arial, sans-derif")
    /// @param value string
    auto hoverLabelFontFamily(std::string const& value) -> Figure&;

    /// grouptitlefont (default: 13)
    /// @param value number greater than or equal to 1
    auto hoverLabelFontSize(int value) -> Figure&;

    /// Sets the font for group titles in hover (unified modes). Defaults to `hoverlabel.font`.
    /// @param value a dict containing one or more of the keys listed below.
    // auto hoverLabelGroupTitleFontSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto hoverLabelGroupTitleFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto hoverLabelGroupTitleFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto hoverLabelGroupTitleFontSize(int value) -> Figure&;

    /// Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters and add an ellipsis. (default: 15)
    /// @param value integer greater than or equal to -1
    auto hoverLabelNamelength(std::string const& value) -> Figure&;

    /// Sets transition options used during Plotly.react updates.
    /// @param value a dict containing one or more of the keys listed below.
    // auto transitionSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// The duration of the transition, in milliseconds. If equal to zero, updates are synchronous. (default: 500)
    /// @param value number greater than or equal to 0
    auto transitionDuration(int value) -> Figure&;

    /// The easing function used for the transition (Default: "cubic-in-dut")
    /// @param value enumerated , one of ( "linear" | "quad" | "cubic" | "sin" | "exp" | "circle" | "elastic" | "back" | "bounce" | "linear-in" | "quad-in" | "cubic-in" | "sin-in" | "exp-in" | "circle-in" | "elastic-in" | "back-in" | "bounce-in" | "linear-out" | "quad-out" | "cubic-out" | "sin-out" | "exp-out" | "circle-out" | "elastic-out" | "back-out" | "bounce-out" | "linear-in-out" | "quad-in-out" | "cubic-in-out" | "sin-in-out" | "exp-in-out" | "circle-in-out" | "elastic-in-out" | "back-in-out" | "bounce-in-out" )
    auto transitionEasing(std::string const& value) -> Figure&;

    /// Determines whether the figure's layout or traces smoothly transitions during updates that make both traces and layout change. (Default: "layout dirst")
    /// @param value enumerated , one of ( "layout first" | "traces first" )
    auto transitionOrdering(std::string const& value) -> Figure&;

    /// If provided, a changed value tells `Plotly.react` that one or more data arrays has changed. This way you can modify arrays in-place rather than making a complete new copy for an incremental change. If NOT provided, `Plotly.react` assumes that data arrays are being treated as immutable, thus any data array with a different identity from its predecessor contains new data.
    /// @param value number or categorical coordinate string
    auto dataRevision(std::string const& value) -> Figure&;

    /// Used to allow user interactions with the plot to persist after `Plotly.react` calls that are unaware of these interactions. If `uirevision` is omitted, or if it is given and it changed from the previous `Plotly.react` call, the exact new figure is used. If `uirevision` is truthy and did NOT change, any attribute that has been affected by user interactions and did not receive a different value in the new figure will keep the interaction value. `layout.uirevision` attribute serves as the default for `uirevision` attributes in various sub-containers. For finer control you can set these sub-attributes directly. For example, if your app separately controls the data on the x and y axes you might set `xaxis.uirevision="time"` and `yaxis.uirevision="cost"`. Then if only the y data is changed, you can update `yaxis.uirevision="quantity"` and the y axis range will reset but the x axis range will retain any user-driven zoom.
    /// @param value number or categorical coordinate string
    auto uiRevision(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in `editable: True` configuration, other than trace names and axis titles. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto editRevision(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in selected points from all traces.
    /// @param value number or categorical coordinate string
    auto selectionRevision(std::string const& value) -> Figure&;

    /// Default attributes to be applied to the plot. Templates can be created from existing plots using `Plotly.makeTemplate`, or created manually. They should be objects with format: `{layout: layoutTemplate, data: {[type]: [traceTemplate, ...]}, ...}` `layoutTemplate` and `traceTemplate` are objects matching the attribute structure of `layout` and a data trace. Trace templates are applied cyclically to traces of each type. Container arrays (eg `annotations`) have special handling: An object ending in `defaults` (eg `annotationdefaults`) is applied to each array item. But if an item has a `templateitemname` key we look in the template array for an item with matching `name` and apply that instead. If no matching `name` is found we mark the item invisible. Any named template item not referenced is appended to the end of the array, so you can use this for a watermark annotation or a logo image, for example. To omit one of these items on the plot, make an item with matching `templateitemname` and `visible: False`.
    /// @param value a dict containing the customization of the figure
    // auto templateSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Assigns extra meta information that can be used in various `text` attributes. Attributes such as the graph, axis and colorbar `title.text`, annotation `text` `trace.name` in legend items, `rangeselector`, `updatemenus` and `sliders` `label` text all support `meta`. One can access `meta` fields using template strings: `%{meta[i]}` where `i` is the index of the `meta` item in question. `meta` can also be an object for example `{key: value}` which can be accessed %{meta[key]}.
    /// @param value number or categorical coordinate string
    auto meta(std::string const& value) -> Figure&;

    /// Placeholder for exporting automargin-impacting values namely `margin.t`, `margin.b`, `margin.l` and `margin.r` in "full-json" mode.
    /// @param value number or categorical coordinate string
    auto computed(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto gridSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// The number of columns in the grid. If you provide a 2D `subplots` array, the length of its longest row is used as the default. If you give an `xaxes` array, its length is used as the default. But it's also possible to have a different length, if you want to leave a row at the end for non-cartesian subplots.
    /// @param value integer greater than or equal to 1
    auto gridColumns(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto gridDomainSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the horizontal domain of this grid subplot (in plot fraction). The first and last cells end exactly at the domain edges, with no grout around the edges. (Default: [0, d])
    /// @param value list
    auto gridDomainX(std::string const& value) -> Figure&;

    /// Sets the vertical domain of this grid subplot (in plot fraction). The first and last cells end exactly at the domain edges, with no grout around the edges. (Default: [0, d])
    /// @param value list
    auto gridDomainY(std::string const& value) -> Figure&;

    /// If no `subplots`, `xaxes`, or `yaxes` are given but we do have `rows` and `columns`, we can generate defaults using consecutive axis IDs, in two ways: "coupled" gives one x axis per column and one y axis per row. "independent" uses a new xy pair for each cell, left-to-right across each row then iterating rows according to `roworder`. (Default: "doupled")
    /// @param value enumerated , one of ( "independent" | "coupled" )
    auto gridPattern(std::string const& value) -> Figure&;

    /// Is the first row the top or the bottom? Note that columns are always enumerated from left to right. (Default: "top to dottom")
    /// @param value enumerated , one of ( "top to bottom" | "bottom to top" )
    auto gridRoworder(std::string const& value) -> Figure&;

    /// The number of rows in the grid. If you provide a 2D `subplots` array or a `yaxes` array, its length is used as the default. But it's also possible to have a different length, if you want to leave a row at the end for non-cartesian subplots.
    /// @param value integer greater than or equal to 1
    auto gridRows(std::string const& value) -> Figure&;

    /// Used for freeform grids, where some axes may be shared across subplots but others are not. Each entry should be a cartesian subplot id, like "xy" or "x3y2", or "" to leave that cell empty. You may reuse x axes within the same column, and y axes within the same row. Non-cartesian subplots and traces that support `domain` can place themselves in this grid separately using the `gridcell` attribute.
    /// @param value list
    auto gridSubplots(std::string const& value) -> Figure&;

    /// Used with `yaxes` when the x and y axes are shared across columns and rows. Each entry should be an x axis id like "x", "x2", etc., or "" to not put an x axis in that column. Entries other than "" must be unique. Ignored if `subplots` is present. If missing but `yaxes` is present, will generate consecutive IDs.
    /// @param value list
    auto gridXaxes(std::string const& value) -> Figure&;

    /// Horizontal space between grid cells, expressed as a fraction of the total width available to one cell. Defaults to 0.1 for coupled-axes grids and 0.2 for independent grids.
    /// @param value number between or equal to 0 and 1
    auto gridXgap(double value) -> Figure&;

    /// Sets where the x axis labels and titles go. "bottom" means the very bottom of the grid. "bottom plot" is the lowest plot that each x axis is used in. "top" and "top plot" are similar. (Default: "bottom dlot")
    /// @param value enumerated , one of ( "bottom" | "bottom plot" | "top plot" | "top" )
    auto gridXside(std::string const& value) -> Figure&;

    /// Used with `yaxes` when the x and y axes are shared across columns and rows. Each entry should be an y axis id like "y", "y2", etc., or "" to not put a y axis in that row. Entries other than "" must be unique. Ignored if `subplots` is present. If missing but `xaxes` is present, will generate consecutive IDs.
    /// @param value list
    auto gridYaxes(std::string const& value) -> Figure&;

    /// Vertical space between grid cells, expressed as a fraction of the total height available to one cell. Defaults to 0.1 for coupled-axes grids and 0.3 for independent grids.
    /// @param value number between or equal to 0 and 1
    auto gridYgap(double value) -> Figure&;

    /// Sets where the y axis labels and titles go. "left" means the very left edge of the grid. "left plot" is the leftmost plot that each y axis is used in. "right" and "right plot" are similar. (Default: "left dlot")
    /// @param value enumerated , one of ( "left" | "left plot" | "right plot" | "right" )
    auto gridYside(std::string const& value) -> Figure&;

    /// Sets the default calendar system to use for interpreting and displaying dates throughout the plot. (Default: "dregorian")
    /// @param value enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" )
    auto calendar(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto newShapeSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// When `dragmode` is set to "drawrect", "drawline" or "drawcircle" this limits the drag to be horizontal, vertical or diagonal. Using "diagonal" there is no limit e.g. in drawing lines in any direction. "ortho" limits the draw to be either horizontal or vertical. "horizontal" allows horizontal extend. "vertical" allows vertical extend. (Default: "diagonal")
    /// @param value enumerated , one of ( "ortho" | "horizontal" | "vertical" | "diagonal" )
    auto newShapeDrawdirection(std::string const& value) -> Figure&;

    /// Sets the color filling new shapes' interior. Please note that if using a fillcolor with alpha greater than half, drag inside the active shape starts moving the shape underneath, otherwise a new shape could be started over. (Default: "rgba(0,0,0,d)")
    /// @param value color
    auto newShapeFillColor(std::string const& value) -> Figure&;

    /// Determines the path's interior. For more info please visit https://developer.mozilla.org/en-US/docs/Web/SVG/Attribute/fill-rule (Default: "dvenodd")
    /// @param value enumerated , one of ( "evenodd" | "nonzero" )
    auto newShapeFillrule(std::string const& value) -> Figure&;

    /// Specifies whether new shapes are drawn below or above traces. (Default: "dbove")
    /// @param value enumerated , one of ( "below" | "above" )
    auto newShapeLayer(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto newShapeLineSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the line color. By default uses either dark grey or white to increase contrast with background color.
    /// @param value color
    auto newShapeLineColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dolid")
    /// @param value string
    auto newShapeLineDash(std::string const& value) -> Figure&;

    /// Sets the line width (in px). (default: 4)
    /// @param value number greater than or equal to 0
    auto newShapeLineWidth(int value) -> Figure&;

    /// Sets the opacity of new shapes. (default: 1)
    /// @param value number between or equal to 0 and 1
    auto newShapeOpacity(double value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto activeShapeSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the color filling the active shape' interior. (Default: "rgb(255,0,d55)")
    /// @param value color
    auto activeShapeFillColor(std::string const& value) -> Figure&;

    /// Sets the opacity of the active shape. (Default: d.5)
    /// @param value number between or equal to 0 and 1
    auto activeShapeOpacity(double value) -> Figure&;

    /// Missing documentation!
    /// @param value list of dict where each dict has one or more of the keys listed below.
    auto selections(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value a dict containing one or more of the keys listed below.
    // auto selectionsLineSpecs(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the line color.
    /// @param value color
    auto selectionsLineColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dot")
    /// @param value string
    auto selectionsLineDash(std::string const& value) -> Figure&;

    /// Sets the line width (in px). (default: 1)
    /// @param value number greater than or equal to 1
    auto selectionsLineWidth(int value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto selectionsName(std::string const& value) -> Figure&;

    /// Sets the opacity of the selection. (Default: d.7)
    /// @param value number between or equal to 0 and 1
    auto selectionsOpacity(double value) -> Figure&;

    /// For `type` "path" - a valid SVG path similar to `shapes.path` in data coordinates. Allowed segments are: M, L and Z.
    /// @param value string
    auto selectionsPath(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto selectionsTemplateItemName(std::string const& value) -> Figure&;

    /// Specifies the selection type to be drawn. If "rect", a rectangle is drawn linking (`x0`,`y0`), (`x1`,`y0`), (`x1`,`y1`) and (`x0`,`y1`). If "path", draw a custom SVG path using `path`.
    /// @param value enumerated , one of ( "rect" | "path" )
    auto selectionsType(std::string const& value) -> Figure&;

    /// Sets the selection's starting x position.
    /// @param value number or categorical coordinate string
    auto selectionsX0(std::string const& value) -> Figure&;

    /// Sets the selection's end x position.
    /// @param value number or categorical coordinate string
    auto selectionsX1(std::string const& value) -> Figure&;

    /// Sets the selection's x coordinate axis. If set to a x axis id (e.g. "x" or "x2"), the `x` position refers to a x coordinate. If set to "paper", the `x` position refers to the distance from the left of the plotting area in normalized coordinates where "0" ("1") corresponds to the left (right). If set to a x axis ID followed by "domain" (separated by a space), the position behaves like for "paper", but refers to the distance in fractions of the domain length from the left of the domain of that axis: e.g., "x2 domain" refers to the domain of the second x axis and a x position of 0.5 refers to the point between the left and the right of the domain of the second x axis.
    /// @param value enumerated , one of ( "paper" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto selectionsXref(std::string const& value) -> Figure&;

    /// Sets the selection's starting y position.
    /// @param value number or categorical coordinate string
    auto selectionsY0(std::string const& value) -> Figure&;

    /// Sets the selection's end y position.
    /// @param value number or categorical coordinate string
    auto selectionsY1(std::string const& value) -> Figure&;

    /// Sets the selection's x coordinate axis. If set to a y axis id (e.g. "y" or "y2"), the `y` position refers to a y coordinate. If set to "paper", the `y` position refers to the distance from the bottom of the plotting area in normalized coordinates where "0" ("1") corresponds to the bottom (top). If set to a y axis ID followed by "domain" (separated by a space), the position behaves like for "paper", but refers to the distance in fractions of the domain length from the bottom of the domain of that axis: e.g., "y2 domain" refers to the domain of the second y axis and a y position of 0.5 refers to the point between the bottom and the top of the domain of the second y axis.
    /// @param value enumerated , one of ( "paper" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto selectionsYref(std::string const& value) -> Figure&;

    /// Determines whether or not a text link citing the data source is placed at the bottom-right cored of the figure. Has only an effect only on graphs that have been generated via forked graphs from the Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise).
    /// @param value boolean
    auto hideSources(bool value) -> Figure&;

    /// If `True`, the pie slice colors (whether given by `piecolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto pieExtendColors(bool value) -> Figure&;

    /// hiddenlabels is the funnelarea & pie chart analog of visible:'legendonly' but it can contain many labels, and can simultaneously hide slices from several pies/funnelarea charts
    /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    auto hiddenLabels(std::string const& value) -> Figure&;

    /// Sets the default pie slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendpiecolors`.
    /// @param value colorlist
    auto pieColorway(std::vector<std::string> const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between boxes of adjacent location coordinates. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto boxGap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between boxes of the same location coordinate. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto boxGroupGap(double value) -> Figure&;

    /// Determines how boxes at the same location coordinate are displayed on the graph. If "group", the boxes are plotted next to one another centered around the shared location. If "overlay", the boxes are plotted over one another, you might need to set "opacity" to see them multiple boxes. Has no effect on traces that have "width" set. (Default: "dverlay")
    /// @param value enumerated , one of ( "group" | "overlay" )
    auto boxMode(std::string const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between violins of adjacent location coordinates. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto violinGap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between violins of the same location coordinate. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto violinGroupGap(double value) -> Figure&;

    /// Determines how violins at the same location coordinate are displayed on the graph. If "group", the violins are plotted next to one another centered around the shared location. If "overlay", the violins are plotted over one another, you might need to set "opacity" to see them multiple violins. Has no effect on traces that have "width" set. (Default: "dverlay")
    /// @param value enumerated , one of ( "group" | "overlay" )
    auto violinMode(std::string const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)
    /// @param value number between or equal to 0 and 1
    auto barGroupGap(double value) -> Figure&;

    /// Determines how bars at the same location coordinate are displayed on the graph. With "stack", the bars are stacked on top of one another With "relative", the bars are stacked on top of one another, with negative values below the axis, positive values above With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "droup")
    /// @param value enumerated , one of ( "stack" | "group" | "overlay" | "relative" )
    auto barMode(std::string const& value) -> Figure&;

    /// Sets the normalization for bar traces on the graph. With "fraction", the value of each bar is divided by the sum of all values at that location coordinate. "percent" is the same but multiplied by 100 to show percentages. (default: "")
    /// @param value enumerated , one of ( "" | "fraction" | "percent" )
    auto barNorm(std::string const& value) -> Figure&;

    /// Sets the gap between bars of adjacent location coordinates. Values are unitless, they represent fractions of the minimum difference in bar positions in the data. (Default: 0.1)
    /// @param value number between or equal to 0 and 1
    auto barGap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of adjacent location coordinates.
    /// @param value number between or equal to 0 and 1
    auto waterfallGap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)
    /// @param value number between or equal to 0 and 1
    auto waterfallGroupGap(double value) -> Figure&;

    /// Determines how bars at the same location coordinate are displayed on the graph. With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "droup")
    /// @param value enumerated , one of ( "group" | "overlay" )
    auto waterfallMode(std::string const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of adjacent location coordinates.
    /// @param value number between or equal to 0 and 1
    auto funnelGap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)
    /// @param value number between or equal to 0 and 1
    auto funnelGroupGap(double value) -> Figure&;

    /// Determines how bars at the same location coordinate are displayed on the graph. With "stack", the bars are stacked on top of one another With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "dtack")
    /// @param value enumerated , one of ( "stack" | "group" | "overlay" )
    auto funnelMode(std::string const& value) -> Figure&;

    /// If `True`, the funnelarea slice colors (whether given by `funnelareacolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto funnelAreaExtendColors(bool value) -> Figure&;

    /// Sets the default funnelarea slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendfunnelareacolors`.
    /// @param value colorlist
    auto funnelAreaColorway(std::vector<std::string> const& value) -> Figure&;

    /// If `True`, the sunburst slice colors (whether given by `sunburstcolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto sunburstExtendColors(bool value) -> Figure&;

    /// Sets the default sunburst slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendsunburstcolors`.
    /// @param value colorlist
    auto sunburstColorway(std::vector<std::string> const& value) -> Figure&;

    /// If `True`, the treemap slice colors (whether given by `treemapcolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto treemapExtendColors(bool value) -> Figure&;

    /// Sets the default treemap slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendtreemapcolors`.
    /// @param value colorlist
    auto treemapColorway(std::vector<std::string> const& value) -> Figure&;

    /// If `True`, the icicle slice colors (whether given by `iciclecolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto icicleExtendColors(bool value) -> Figure&;

    /// Sets the default icicle slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendiciclecolors`.
    /// @param value colorlist
    auto icicleColorway(std::vector<std::string> const& value) -> Figure&;

    //=================================================================================================================
    //
    // METHODS THAT CUSTOMIZE THE X-AXIS LAYOUT OF THE FIGURE
    //
    //=================================================================================================================

    /// If set to an opposite-letter axis id (e.g. `x2`, `y`), this axis is bound to the corresponding opposite-letter axis. If set to "free", this axis' position is determined by `position`.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxisAnchor(std::string const& value) -> Figure&;

    /// Determines whether long tick labels automatically grow the figure margins.
    /// @param value flaglist string. Any combination of "height", "width", "left", "right", "top", "bottom" joined with a "+" OR True or False. Examples: "height", "width", "height+width", "height+width+left", "True"
    auto xaxisAutoMargin(std::string const& value) -> Figure&;

    /// Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode` for more info. If `range` is provided, then `autorange` is set to "False".
    /// @param value enumerated , one of ( True | False | "reversed" ) (default: True)
    auto xaxisAutoRange(std::string const& value) -> Figure&;

    /// Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. Defaults to layout.autotypenumbers.
    /// @param value enumerated , one of ( "convert types" | "strict" ) (default: "convert types")
    auto xaxisAutoTypeNumbers(std::string const& value) -> Figure&;

    /// Sets the calendar system to use for `range` and `tick0` if this is a date axis. This does not set the calendar for interpreting data on this axis, that's specified in the trace or via the global `layout.calendar`
    /// @param value enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" ) (default: "gregorian")
    auto xaxisCalendar(std::string const& value) -> Figure&;

    // /// Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to "array". Used with `categoryorder`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxisCategoryArray(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Specifies the ordering logic for the case of categorical variables. By default, plotly uses "trace", which specifies the order that is present in the data supplied. Set `categoryorder` to "category ascending" or "category descending" if order should be determined by the alphanumerical order of the category names. Set `categoryorder` to "array" to derive the ordering from the attribute `categoryarray`. If a category is not found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the "trace" mode. The unspecified categories will follow the categories in `categoryarray`. Set `categoryorder` to "total ascending" or "total descending" if order should be determined by the numerical order of the values. Similarly, the order can be determined by the min, max, sum, mean or median of all the values.
    /// @param value enumerated , one of ( "trace" | "category ascending" | "category descending" | "array" | "total ascending" | "total descending" | "min ascending" | "min descending" | "max ascending" | "max descending" | "sum ascending" | "sum descending" | "mean ascending" | "mean descending" | "median ascending" | "median descending" ) (default: "trace")
    auto xaxisCategoryOrder(std::string const& value) -> Figure&;

    /// Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid color is lightened by blending this with the plot background Individual pieces can override this.
    /// @param value color (default: "#444")
    auto xaxisColor(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines how that happens: by increasing the "range", or by decreasing the "domain". Default is "domain" for axes containing image traces, "range" otherwise.
    /// @param value enumerated , one of ( "range" | "domain" )
    auto xaxisConstrain(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines which direction we push the originally specified plot area. Options are "left", "center" (default), and "right" for x axes, and "top", "middle" (default), and "bottom" for y axes.
    /// @param value enumerated , one of ( "left" | "center" | "right" | "top" | "middle" | "bottom" )
    auto xaxisConstrainToward(std::string const& value) -> Figure&;

    /// Sets the color of the dividers Only has an effect on "multicategory" axes.
    /// @param value color (default: "#444")
    auto xaxisDividerColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the dividers Only has an effect on "multicategory" axes.
    /// @param value number (default: 1)
    auto xaxisDividerWidth(int value) -> Figure&;

    // /// Sets the domain of this axis (in plot fraction).
    // /// @param value list (default: [0, 1])
    // auto xaxisDomain(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto xaxisDtick(std::string const& value) -> Figure&;

    /// Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If "none", it appears as 1,000,000,000. If "e", 1e+9. If "E", 1E+9. If "power", 1x10^9 (with 9 in a super script). If "SI", 1G. If "B", 1B.
    /// @param value enumerated , one of ( "none" | "e" | "E" | "power" | "SI" | "B" ) (default: "B")
    auto xaxisExponentFormat(std::string const& value) -> Figure&;

    /// Determines whether or not this axis is zoom-able. If True, then zoom is disabled.
    /// @param value boolean
    auto xaxisFixedRange(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto xaxisGridColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto xaxisGridDash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxisGridWidth(int value) -> Figure&;

    /// Sets the hover text formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto xaxisHoverFormat(std::string const& value) -> Figure&;

    /// Sets the layer on which this axis is displayed. If "above traces", this axis is displayed above all the subplot's traces If "below traces", this axis is displayed below all the subplot's traces, but above the grid lines. Useful when used together with scatter-like traces with `cliponaxis` set to "False" to show markers and/or text nodes above this axis.
    /// @param value enumerated , one of ( "above traces" | "below traces" ) (default: "above traces")
    auto xaxisLayer(std::string const& value) -> Figure&;

    /// Sets the axis line color.
    /// @param value color (default: "#444")
    auto xaxisLineColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the axis line.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxisLineWidth(int value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis will match the range of the corresponding axis in data-coordinates space. Moreover, matching axes share auto-range values, category lists and histogram auto-bins. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden. Moreover, note that matching axes must have the same `type`.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxisMatches(std::string const& value) -> Figure&;

    /// Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is "SI" or "B".
    /// @param value number greater than or equal to 0 (default: 3)
    auto xaxisMinExponent(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisMinorSpecs(std::string const& value) -> Figure&;

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto xaxisMinorDtick(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto xaxisMinorGridColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto xaxisMinorGridDash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0
    auto xaxisMinorGridWidth(int value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 5)
    auto xaxisMinorNticks(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto xaxisMinorShowgrid(std::string const& value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto xaxisMinorTick0(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto xaxisMinorTickColor(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0
    auto xaxisMinorTickLength(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto xaxisMinorTickMode(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto xaxisMinorTicks(std::string const& value) -> Figure&;

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxisMinorTickValues(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0
    auto xaxisMinorTickWidth(int value) -> Figure&;

    /// Determines if the axis lines or/and ticks are mirrored to the opposite side of the plotting area. If "True", the axis lines are mirrored. If "ticks", the axis lines and ticks are mirrored. If "False", mirroring is disable. If "all", axis lines are mirrored on all shared-axes subplots. If "allticks", axis lines and ticks are mirrored on all shared-axes subplots.
    /// @param value enumerated , one of ( True | "ticks" | False | "all" | "allticks" )
    auto xaxisMirror(std::string const& value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 0)
    auto xaxisNticks(std::string const& value) -> Figure&;

    /// If set a same-letter axis id, this axis is overlaid on top of the corresponding same-letter axis, with traces and axes visible for both axes. If "False", this axis does not overlay any same-letter axes. In this case, for axes with overlapping domains only the highest-numbered axis will be visible.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxisOverlaying(std::string const& value) -> Figure&;

    /// Sets the position of this axis in the plotting space (in normalized coordinates). Only has an effect if `anchor` is set to "free".
    /// @param value number between or equal to 0 and 1 (default: 0)
    auto xaxisPosition(int value) -> Figure&;

    /// Sets the range of this axis. If the axis `type` is "log", then you must take the log of your desired range (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value list
    auto xaxisRange(double l, double r) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto xaxisRangeBreaks(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the lower and upper bounds of this axis rangebreak. Can be used with `pattern`.
    // /// @param value list
    // auto xaxisRangeBreaksBounds(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the size of each `values` item. The default is one day in milliseconds.
    /// @param value number greater than or equal to 0 (default: 86400000)
    auto xaxisRangeBreaksDvalue(int value) -> Figure&;

    /// Determines whether this axis rangebreak is enabled or disabled. Please note that `rangebreaks` only work for "date" axis type.
    /// @param value boolean (default: True)
    auto xaxisRangeBreaksEnabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto xaxisRangeBreaksName(std::string const& value) -> Figure&;

    /// Determines a pattern on the time line that generates breaks. If "day of week" - days of the week in English e.g. 'Sunday' or `sun` (matching is case-insensitive and considers only the first three characters), as well as Sunday-based integers between 0 and 6. If "hour" - hour (24-hour clock) as decimal numbers between 0 and 24. for more info. Examples: - { pattern: 'day of week', bounds: [6, 1] } or simply { bounds: ['sat', 'mon'] } breaks from Saturday to Monday (i.e. skips the weekends). - { pattern: 'hour', bounds: [17, 8] } breaks from 5pm to 8am (i.e. skips non-work hours).
    /// @param value enumerated , one of ( "day of week" | "hour" | "" )
    auto xaxisRangeBreaksPattern(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto xaxisRangeBreaksTemplateItemName(std::string const& value) -> Figure&;

    // /// Sets the coordinate values corresponding to the rangebreaks. An alternative to `bounds`. Use `dvalue` to set the size of the values along the axis.
    // /// @param value list
    // auto xaxisRangeBreaksValues(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// If "normal", the range is computed in relation to the extrema of the input data. If "tozero"`, the range extends to 0, regardless of the input data If "nonnegative", the range is non-negative, regardless of the input data. Applies only to linear axes.
    /// @param value enumerated , one of ( "normal" | "tozero" | "nonnegative" ) (default: "normal")
    auto xaxisRangeMode(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisRangeSelectorSpecs(std::string const& value) -> Figure&;

    /// Sets the background color of the active range selector button.
    /// @param value color
    auto xaxisRangeSelectorActiveColor(std::string const& value) -> Figure&;

    /// Sets the background color of the range selector buttons.
    /// @param value color (default: "#eee")
    auto xaxisRangeSelectorBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the color of the border enclosing the range selector.
    /// @param value color (default: "#444")
    auto xaxisRangeSelectorBorderColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the border enclosing the range selector.
    /// @param value number greater than or equal to 0 (default: 0)
    auto xaxisRangeSelectorBorderWidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto xaxisRangeSelectorButtons(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the number of steps to take to update the range. Use with `step` to specify the update interval.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxisRangeSelectorCount(int value) -> Figure&;

    /// Sets the text label to appear on the button.
    /// @param value string
    auto xaxisRangeSelectorLabel(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto xaxisRangeSelectorName(std::string const& value) -> Figure&;

    /// The unit of measurement that the `count` value will set the range by.
    /// @param value enumerated , one of ( "month" | "year" | "day" | "hour" | "minute" | "second" | "all" ) (default: "month")
    auto xaxisRangeSelectorStep(std::string const& value) -> Figure&;

    /// Sets the range update mode. If "backward", the range update shifts the start of range back "count" times "step" milliseconds. If "todate", the range update shifts the start of range back to the first timestamp from "count" times "step" milliseconds back. For example, with `step` set to "year" and `count` set to "1" the range update shifts the start of the range back to January 01 of the current year. Month and year "todate" are currently available only for the built-in (Gregorian) calendar.
    /// @param value enumerated , one of ( "backward" | "todate" ) (default: "backward")
    auto xaxisRangeSelectorStepMode(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto xaxisRangeSelectorTemplateItemName(std::string const& value) -> Figure&;

    // /// Sets the font of the range selector button text.
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisRangeSelectorFontSpecs(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto xaxisRangeSelectorFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto xaxisRangeSelectorFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto xaxisRangeSelectorFontSize(int value) -> Figure&;

    /// Determines whether or not this range selector is visible. Note that range selectors are only available for x axes of `type` set to or auto-typed to "date".
    /// @param value boolean (default: True)
    auto xaxisRangeSelectorVisible(std::string const& value) -> Figure&;

    /// Sets the x position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto xaxisRangeSelectorX(int value) -> Figure&;

    /// Sets the range selector's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the range selector.
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" ) (default: "left")
    auto xaxisRangeSelectorXanchor(std::string const& value) -> Figure&;

    /// Sets the y position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto xaxisRangeSelectorY(int value) -> Figure&;

    /// Sets the range selector's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the range selector.
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" ) (default: "bottom")
    auto xaxisRangeSelectorYanchor(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisRangeSliderSpecs(std::string const& value) -> Figure&;

    /// Determines whether or not the range slider range is computed in relation to the input data. If `range` is provided, then `autorange` is set to "False".
    /// @param value boolean (default: True)
    auto xaxisRangeSliderAutoRange(std::string const& value) -> Figure&;

    /// Sets the background color of the range slider.
    /// @param value color (default: "#fff")
    auto xaxisRangeSliderBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the border color of the range slider.
    /// @param value color (default: "#444")
    auto xaxisRangeSliderBorderColor(std::string const& value) -> Figure&;

    /// Sets the border width of the range slider.
    /// @param value integer greater than or equal to 0 (default: 0)
    auto xaxisRangeSliderBorderWidth(std::string const& value) -> Figure&;

    // /// Sets the range of the range slider. If not set, defaults to the full xaxis range. If the axis `type` is "log", then you must take the log of your desired range. If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    // /// @param value list
    // auto xaxisRangeSliderRange(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// The height of the range slider as a fraction of the total plot area height.
    /// @param value number between or equal to 0 and 1 (default: 0.15)
    auto xaxisRangeSliderThickness(int value) -> Figure&;

    /// Determines whether or not the range slider will be visible. If visible, perpendicular axes will be set to `fixedrange`
    /// @param value boolean (default: True)
    auto xaxisRangeSliderVisible(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisRangeSliderYaxisSpecs(std::string const& value) -> Figure&;

    /// Sets the range of this axis for the rangeslider.
    /// @param value list
    auto xaxisRangeSliderYaxisRange(double l, double r) -> Figure&;

    /// Determines whether or not the range of this axis in the rangeslider use the same value than in the main plot when zooming in/out. If "auto", the autorange will be used. If "fixed", the `range` is used. If "match", the current range of the corresponding y-axis on the main subplot is used.
    /// @param value enumerated , one of ( "auto" | "fixed" | "match" ) (default: "match")
    auto xaxisRangeSliderYaxisRangeMode(std::string const& value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis changes together with the range of the corresponding axis such that the scale of pixels per unit is in a constant ratio. Both axes are still zoomable, but when you zoom one, the other will zoom the same amount, keeping a fixed midpoint. `constrain` and `constraintoward` determine how we enforce the constraint. You can chain these, ie `yaxis: {scaleanchor: "x"}, xaxis2: {scaleanchor: "y"}` but you can only link axes of the same `type`. The linked axis can have the opposite letter (to constrain the aspect ratio) or the same letter (to match scales across subplots). Loops (`yaxis: {scaleanchor: "x"}, xaxis: {scaleanchor: "y"}` or longer) are redundant and the last constraint encountered will be ignored to avoid possible inconsistent constraints via `scaleratio`. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxisScaleAnchor(std::string const& value) -> Figure&;

    /// If this axis is linked to another by `scaleanchor`, this determines the pixel to unit scale ratio. For example, if this value is 10, then every unit on this axis spans 10 times the number of pixels as a unit on the linked axis. Use this for example to create an elevation profile where the vertical scale is exaggerated a fixed amount with respect to the horizontal.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxisScaleRatio(int value) -> Figure&;

    /// If "True", even 4-digit integers are separated
    /// @param value boolean
    auto xaxisSeparateThousands(std::string const& value) -> Figure&;

    /// Determines whether or not a dividers are drawn between the category levels of this axis. Only has an effect on "multicategory" axes.
    /// @param value boolean (default: True)
    auto xaxisShowDividers(std::string const& value) -> Figure&;

    /// If "all", all exponents are shown besides their significands. If "first", only the exponent of the first tick is shown. If "last", only the exponent of the last tick is shown. If "none", no exponents appear.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto xaxisShowExponent(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto xaxisShowGrid(std::string const& value) -> Figure&;

    /// Determines whether or not a line bounding this axis is drawn.
    /// @param value boolean
    auto xaxisShowLine(std::string const& value) -> Figure&;

    /// Determines whether or not spikes (aka droplines) are drawn for this axis. Note: This only takes affect when hovermode = closest
    /// @param value boolean
    auto xaxisShowSpikes(std::string const& value) -> Figure&;

    /// Determines whether or not the tick labels are drawn.
    /// @param value boolean (default: True)
    auto xaxisShowTickLabels(std::string const& value) -> Figure&;

    /// If "all", all tick labels are displayed with a prefix. If "first", only the first tick is displayed with a prefix. If "last", only the last tick is displayed with a suffix. If "none", tick prefixes are hidden.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto xaxisShowTickPrefix(std::string const& value) -> Figure&;

    /// Same as `showtickprefix` but for tick suffixes.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto xaxisShowTickSuffix(std::string const& value) -> Figure&;

    /// Determines whether a x (y) axis is positioned at the "bottom" ("left") or "top" ("right") of the plotting area.
    /// @param value enumerated , one of ( "top" | "bottom" | "left" | "right" )
    auto xaxisSide(std::string const& value) -> Figure&;

    /// Sets the spike color. If undefined, will use the series color
    /// @param value color
    auto xaxisSpikeColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "dash")
    auto xaxisSpikeDash(std::string const& value) -> Figure&;

    /// Determines the drawing mode for the spike line If "toaxis", the line is drawn from the data point to the axis the series is plotted on. If "across", the line is drawn across the entire plot area, and supercedes "toaxis". If "marker", then a marker dot is drawn on the axis the series is plotted on
    /// @param value flaglist string. Any combination of "toaxis", "across", "marker" joined with a "+". Examples: "toaxis", "across", "toaxis+across", "toaxis+across+marker" (default: "toaxis")
    auto xaxisSpikeMode(std::string const& value) -> Figure&;

    /// Determines whether spikelines are stuck to the cursor or to the closest datapoints.
    /// @param value enumerated , one of ( "data" | "cursor" | "hovered data" ) (default: "hovered data")
    auto xaxisSpikeSnap(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 3)
    auto xaxisSpikeThickness(int value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto xaxisTick0(std::string const& value) -> Figure&;

    /// Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the tick labels vertically.
    /// @param value angle (default: "auto")
    auto xaxisTickAngle(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto xaxisTickColor(std::string const& value) -> Figure&;

    // /// Sets the tick font.
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisTickFontSpecs(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto xaxisTickFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto xaxisTickFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto xaxisTickFontSize(int value) -> Figure&;

    /// Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto xaxisTickFormat(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto xaxisTickFormatStops(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// range ["min", "max"], where "min", "max" - dtick values which describe some zoom level, it is possible to omit "min" or "max" value by passing "null"
    // /// @param value list
    // auto xaxisTickFormatStopsDtickRange(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Determines whether or not this stop is used. If `False`, this stop is ignored even within its `dtickrange`.
    /// @param value boolean (default: True)
    auto xaxisTickFormatStopsEnabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto xaxisTickFormatStopsName(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto xaxisTickFormatStopsTemplateItemName(std::string const& value) -> Figure&;

    /// string - dtickformat for described zoom level, the same as "tickformat"
    /// @param value string (default: "")
    auto xaxisTickFormatStopsValue(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to their corresponding ticks and grid lines. Only has an effect for axes of `type` "date" When set to "period", tick labels are drawn in the middle of the period between ticks.
    /// @param value enumerated , one of ( "instant" | "period" ) (default: "instant")
    auto xaxisTickLabelMode(std::string const& value) -> Figure&;

    /// Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The default value for inside tick labels is "hide past domain". Otherwise on "category" and "multicategory" axes the default is "allow". In other cases the default is "hide past div".
    /// @param value enumerated , one of ( "allow" | "hide past div" | "hide past domain" )
    auto xaxisTickLabelOverflow(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to the axis Please note that top or bottom has no effect on x axes or when `ticklabelmode` is set to "period". Similarly left or right has no effect on y axes or when `ticklabelmode` is set to "period". Has no effect on "multicategory" axes or when `tickson` is set to "boundaries". When used on axes linked by `matches` or `scaleanchor`, no extra padding for inside labels would be added by autorange, so that the scales could match.
    /// @param value enumerated , one of ( "outside" | "inside" | "outside top" | "inside top" | "outside left" | "inside left" | "outside right" | "inside right" | "outside bottom" | "inside bottom" ) (default: "outside")
    auto xaxisTickLabelPosition(std::string const& value) -> Figure&;

    /// Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` "log" or "multicategory", or when `tickmode` is "array".
    /// @param value integer greater than or equal to 1 (default: 1)
    auto xaxisTickLabelStep(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0 (default: 5)
    auto xaxisTickLength(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto xaxisTickMode(std::string const& value) -> Figure&;

    /// Sets a tick label prefix.
    /// @param value string (default: "")
    auto xaxisTickPrefix(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto xaxisTicks(std::string const& value) -> Figure&;

    /// Determines where ticks and grid lines are drawn with respect to their corresponding tick labels. Only has an effect for axes of `type` "category" or "multicategory". When set to "boundaries", ticks and grid lines are drawn half a category to the left/bottom of labels.
    /// @param value enumerated , one of ( "labels" | "boundaries" ) (default: "labels")
    auto xaxisTickson(std::string const& value) -> Figure&;

    /// Sets a tick label suffix.
    /// @param value string (default: "")
    auto xaxisTickSuffix(std::string const& value) -> Figure&;

    // /// Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to "array". Used with `tickvals`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxisTickText(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxisTickValues(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxisTickWidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisTitleSpecs(std::string const& value) -> Figure&;

    // /// Sets this axis' title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.
    // /// @param value a dict containing one or more of the keys listed below.
    // auto xaxisTitleFontSpecs(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto xaxisTitleFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto xaxisTitleFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto xaxisTitleFontSize(int value) -> Figure&;

    /// Sets the standoff distance (in px) between the axis labels and the title text The default value is a function of the axis tick labels, the title `font.size` and the axis `linewidth`. Note that the axis title position is always constrained within the margins, so the actual standoff distance is always less than the set or default value. By setting `standoff` and turning on `automargin`, plotly.js will push the margins to fit the axis title at given standoff distance.
    /// @param value number greater than or equal to 0
    auto xaxisTitleStandoff(int value) -> Figure&;

    /// Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.
    /// @param value string
    auto xaxisTitleText(std::string const& value) -> Figure&;

    /// Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the traces that referenced the axis in question.
    /// @param value enumerated , one of ( "-" | "linear" | "log" | "date" | "category" | "multicategory" ) (default: "-")
    auto xaxisType(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in axis `range`, `autorange`, and `title` if in `editable: True` configuration. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto xaxisUirevision(std::string const& value) -> Figure&;

    /// A single toggle to hide the axis while preserving interaction like dragging. Default is True when a cheater plot is present on the axis, otherwise False
    /// @param value boolean
    auto xaxisVisible(std::string const& value) -> Figure&;

    /// Determines whether or not a line is drawn at along the 0 value of this axis. If "True", the zero line is drawn on top of the grid lines.
    /// @param value boolean
    auto xaxisZeroLine(std::string const& value) -> Figure&;

    /// Sets the line color of the zero line.
    /// @param value color (default: "#444")
    auto xaxisZeroLineColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 1)
    auto xaxisZeroLineWidth(int value) -> Figure&;

    //=================================================================================================================
    //
    // METHODS THAT CUSTOMIZE THE Y-AXIS LAYOUT OF THE FIGURE
    //
    //=================================================================================================================

    /// If set to an opposite-letter axis id (e.g. `x2`, `y`), this axis is bound to the corresponding opposite-letter axis. If set to "free", this axis' position is determined by `position`.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxisAnchor(std::string const& value) -> Figure&;

    /// Determines whether long tick labels automatically grow the figure margins.
    /// @param value flaglist string. Any combination of "height", "width", "left", "right", "top", "bottom" joined with a "+" OR True or False. Examples: "height", "width", "height+width", "height+width+left", "True"
    auto yaxisAutoMargin(std::string const& value) -> Figure&;

    /// Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode` for more info. If `range` is provided, then `autorange` is set to "False".
    /// @param value enumerated , one of ( True | False | "reversed" ) (default: True)
    auto yaxisAutoRange(std::string const& value) -> Figure&;

    /// Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. Defaults to layout.autotypenumbers.
    /// @param value enumerated , one of ( "convert types" | "strict" ) (default: "convert types")
    auto yaxisAutoTypeNumbers(std::string const& value) -> Figure&;

    /// Sets the calendar system to use for `range` and `tick0` if this is a date axis. This does not set the calendar for interpreting data on this axis, that's specified in the trace or via the global `layout.calendar`
    /// @param value enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" ) (default: "gregorian")
    auto yaxisCalendar(std::string const& value) -> Figure&;

    // /// Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to "array". Used with `categoryorder`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxisCategoryArray(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Specifies the ordering logic for the case of categorical variables. By default, plotly uses "trace", which specifies the order that is present in the data supplied. Set `categoryorder` to "category ascending" or "category descending" if order should be determined by the alphanumerical order of the category names. Set `categoryorder` to "array" to derive the ordering from the attribute `categoryarray`. If a category is not found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the "trace" mode. The unspecified categories will follow the categories in `categoryarray`. Set `categoryorder` to "total ascending" or "total descending" if order should be determined by the numerical order of the values. Similarly, the order can be determined by the min, max, sum, mean or median of all the values.
    /// @param value enumerated , one of ( "trace" | "category ascending" | "category descending" | "array" | "total ascending" | "total descending" | "min ascending" | "min descending" | "max ascending" | "max descending" | "sum ascending" | "sum descending" | "mean ascending" | "mean descending" | "median ascending" | "median descending" ) (default: "trace")
    auto yaxisCategoryOrder(std::string const& value) -> Figure&;

    /// Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid color is lightened by blending this with the plot background Individual pieces can override this.
    /// @param value color (default: "#444")
    auto yaxisColor(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines how that happens: by increasing the "range", or by decreasing the "domain". Default is "domain" for axes containing image traces, "range" otherwise.
    /// @param value enumerated , one of ( "range" | "domain" )
    auto yaxisConstrain(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines which direction we push the originally specified plot area. Options are "left", "center" (default), and "right" for x axes, and "top", "middle" (default), and "bottom" for y axes.
    /// @param value enumerated , one of ( "left" | "center" | "right" | "top" | "middle" | "bottom" )
    auto yaxisConstrainToward(std::string const& value) -> Figure&;

    /// Sets the color of the dividers Only has an effect on "multicategory" axes.
    /// @param value color (default: "#444")
    auto yaxisDividerColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the dividers Only has an effect on "multicategory" axes.
    /// @param value number (default: 1)
    auto yaxisDividerWidth(int value) -> Figure&;

    // /// Sets the domain of this axis (in plot fraction).
    // /// @param value list (default: [0, 1])
    // auto yaxisDomain(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto yaxisDtick(std::string const& value) -> Figure&;

    /// Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If "none", it appears as 1,000,000,000. If "e", 1e+9. If "E", 1E+9. If "power", 1x10^9 (with 9 in a super script). If "SI", 1G. If "B", 1B.
    /// @param value enumerated , one of ( "none" | "e" | "E" | "power" | "SI" | "B" ) (default: "B")
    auto yaxisExponentFormat(std::string const& value) -> Figure&;

    /// Determines whether or not this axis is zoom-able. If True, then zoom is disabled.
    /// @param value boolean
    auto yaxisFixedRange(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto yaxisGridColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto yaxisGridDash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxisGridWidth(int value) -> Figure&;

    /// Sets the hover text formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto yaxisHoverFormat(std::string const& value) -> Figure&;

    /// Sets the layer on which this axis is displayed. If "above traces", this axis is displayed above all the subplot's traces If "below traces", this axis is displayed below all the subplot's traces, but above the grid lines. Useful when used together with scatter-like traces with `cliponaxis` set to "False" to show markers and/or text nodes above this axis.
    /// @param value enumerated , one of ( "above traces" | "below traces" ) (default: "above traces")
    auto yaxisLayer(std::string const& value) -> Figure&;

    /// Sets the axis line color.
    /// @param value color (default: "#444")
    auto yaxisLineColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the axis line.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxisLineWidth(int value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis will match the range of the corresponding axis in data-coordinates space. Moreover, matching axes share auto-range values, category lists and histogram auto-bins. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden. Moreover, note that matching axes must have the same `type`.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxisMatches(std::string const& value) -> Figure&;

    /// Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is "SI" or "B".
    /// @param value number greater than or equal to 0 (default: 3)
    auto yaxisMinExponent(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisMinorSpecs(std::string const& value) -> Figure&;

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto yaxisMinorDtick(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto yaxisMinorGridColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto yaxisMinorGridDash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0
    auto yaxisMinorGridWidth(int value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 5)
    auto yaxisMinorNticks(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto yaxisMinorShowgrid(std::string const& value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto yaxisMinorTick0(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto yaxisMinorTickColor(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0
    auto yaxisMinorTickLength(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto yaxisMinorTickMode(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto yaxisMinorTicks(std::string const& value) -> Figure&;

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxisMinorTickValues(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0
    auto yaxisMinorTickWidth(int value) -> Figure&;

    /// Determines if the axis lines or/and ticks are mirrored to the opposite side of the plotting area. If "True", the axis lines are mirrored. If "ticks", the axis lines and ticks are mirrored. If "False", mirroring is disable. If "all", axis lines are mirrored on all shared-axes subplots. If "allticks", axis lines and ticks are mirrored on all shared-axes subplots.
    /// @param value enumerated , one of ( True | "ticks" | False | "all" | "allticks" )
    auto yaxisMirror(std::string const& value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 0)
    auto yaxisNticks(std::string const& value) -> Figure&;

    /// If set a same-letter axis id, this axis is overlaid on top of the corresponding same-letter axis, with traces and axes visible for both axes. If "False", this axis does not overlay any same-letter axes. In this case, for axes with overlapping domains only the highest-numbered axis will be visible.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxisOverlaying(std::string const& value) -> Figure&;

    /// Sets the position of this axis in the plotting space (in normalized coordinates). Only has an effect if `anchor` is set to "free".
    /// @param value number between or equal to 0 and 1 (default: 0)
    auto yaxisPosition(int value) -> Figure&;

    /// Sets the range of this axis. If the axis `type` is "log", then you must take the log of your desired range (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value list
    auto yaxisRange(double l, double r) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto yaxisRangeBreaks(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the lower and upper bounds of this axis rangebreak. Can be used with `pattern`.
    // /// @param value list
    // auto yaxisRangeBreaksBounds(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the size of each `values` item. The default is one day in milliseconds.
    /// @param value number greater than or equal to 0 (default: 86400000)
    auto yaxisRangeBreaksDvalue(int value) -> Figure&;

    /// Determines whether this axis rangebreak is enabled or disabled. Please note that `rangebreaks` only work for "date" axis type.
    /// @param value boolean (default: True)
    auto yaxisRangeBreaksEnabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto yaxisRangeBreaksName(std::string const& value) -> Figure&;

    /// Determines a pattern on the time line that generates breaks. If "day of week" - days of the week in English e.g. 'Sunday' or `sun` (matching is case-insensitive and considers only the first three characters), as well as Sunday-based integers between 0 and 6. If "hour" - hour (24-hour clock) as decimal numbers between 0 and 24. for more info. Examples: - { pattern: 'day of week', bounds: [6, 1] } or simply { bounds: ['sat', 'mon'] } breaks from Saturday to Monday (i.e. skips the weekends). - { pattern: 'hour', bounds: [17, 8] } breaks from 5pm to 8am (i.e. skips non-work hours).
    /// @param value enumerated , one of ( "day of week" | "hour" | "" )
    auto yaxisRangeBreaksPattern(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto yaxisRangeBreaksTemplateItemName(std::string const& value) -> Figure&;

    // /// Sets the coordinate values corresponding to the rangebreaks. An alternative to `bounds`. Use `dvalue` to set the size of the values along the axis.
    // /// @param value list
    // auto yaxisRangeBreaksValues(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// If "normal", the range is computed in relation to the extrema of the input data. If "tozero"`, the range extends to 0, regardless of the input data If "nonnegative", the range is non-negative, regardless of the input data. Applies only to linear axes.
    /// @param value enumerated , one of ( "normal" | "tozero" | "nonnegative" ) (default: "normal")
    auto yaxisRangeMode(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisRangeSelectorSpecs(std::string const& value) -> Figure&;

    /// Sets the background color of the active range selector button.
    /// @param value color
    auto yaxisRangeSelectorActiveColor(std::string const& value) -> Figure&;

    /// Sets the background color of the range selector buttons.
    /// @param value color (default: "#eee")
    auto yaxisRangeSelectorBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the color of the border enclosing the range selector.
    /// @param value color (default: "#444")
    auto yaxisRangeSelectorBorderColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the border enclosing the range selector.
    /// @param value number greater than or equal to 0 (default: 0)
    auto yaxisRangeSelectorBorderWidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto yaxisRangeSelectorButtons(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the number of steps to take to update the range. Use with `step` to specify the update interval.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxisRangeSelectorCount(int value) -> Figure&;

    /// Sets the text label to appear on the button.
    /// @param value string
    auto yaxisRangeSelectorLabel(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto yaxisRangeSelectorName(std::string const& value) -> Figure&;

    /// The unit of measurement that the `count` value will set the range by.
    /// @param value enumerated , one of ( "month" | "year" | "day" | "hour" | "minute" | "second" | "all" ) (default: "month")
    auto yaxisRangeSelectorStep(std::string const& value) -> Figure&;

    /// Sets the range update mode. If "backward", the range update shifts the start of range back "count" times "step" milliseconds. If "todate", the range update shifts the start of range back to the first timestamp from "count" times "step" milliseconds back. For example, with `step` set to "year" and `count` set to "1" the range update shifts the start of the range back to January 01 of the current year. Month and year "todate" are currently available only for the built-in (Gregorian) calendar.
    /// @param value enumerated , one of ( "backward" | "todate" ) (default: "backward")
    auto yaxisRangeSelectorStepMode(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto yaxisRangeSelectorTemplateItemName(std::string const& value) -> Figure&;

    // /// Sets the font of the range selector button text.
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisRangeSelectorFontSpecs(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto yaxisRangeSelectorFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto yaxisRangeSelectorFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto yaxisRangeSelectorFontSize(int value) -> Figure&;

    /// Determines whether or not this range selector is visible. Note that range selectors are only available for x axes of `type` set to or auto-typed to "date".
    /// @param value boolean (default: True)
    auto yaxisRangeSelectorVisible(std::string const& value) -> Figure&;

    /// Sets the x position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto yaxisRangeSelectorX(int value) -> Figure&;

    /// Sets the range selector's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the range selector.
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" ) (default: "left")
    auto yaxisRangeSelectorXanchor(std::string const& value) -> Figure&;

    /// Sets the y position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto yaxisRangeSelectorY(int value) -> Figure&;

    /// Sets the range selector's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the range selector.
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" ) (default: "bottom")
    auto yaxisRangeSelectorYanchor(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisRangeSliderSpecs(std::string const& value) -> Figure&;

    /// Determines whether or not the range slider range is computed in relation to the input data. If `range` is provided, then `autorange` is set to "False".
    /// @param value boolean (default: True)
    auto yaxisRangeSliderAutoRange(std::string const& value) -> Figure&;

    /// Sets the background color of the range slider.
    /// @param value color (default: "#fff")
    auto yaxisRangeSliderBackgroundColor(std::string const& value) -> Figure&;

    /// Sets the border color of the range slider.
    /// @param value color (default: "#444")
    auto yaxisRangeSliderBorderColor(std::string const& value) -> Figure&;

    /// Sets the border width of the range slider.
    /// @param value integer greater than or equal to 0 (default: 0)
    auto yaxisRangeSliderBorderWidth(std::string const& value) -> Figure&;

    // /// Sets the range of the range slider. If not set, defaults to the full yaxis range. If the axis `type` is "log", then you must take the log of your desired range. If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    // /// @param value list
    // auto yaxisRangeSliderRange(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// The height of the range slider as a fraction of the total plot area height.
    /// @param value number between or equal to 0 and 1 (default: 0.15)
    auto yaxisRangeSliderThickness(int value) -> Figure&;

    /// Determines whether or not the range slider will be visible. If visible, perpendicular axes will be set to `fixedrange`
    /// @param value boolean (default: True)
    auto yaxisRangeSliderVisible(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisRangeSliderYaxisSpecs(std::string const& value) -> Figure&;

    /// Sets the range of this axis for the rangeslider.
    /// @param value list
    auto yaxisRangeSliderYaxisRange(double l, double r) -> Figure&;

    /// Determines whether or not the range of this axis in the rangeslider use the same value than in the main plot when zooming in/out. If "auto", the autorange will be used. If "fixed", the `range` is used. If "match", the current range of the corresponding y-axis on the main subplot is used.
    /// @param value enumerated , one of ( "auto" | "fixed" | "match" ) (default: "match")
    auto yaxisRangeSliderYaxisRangeMode(std::string const& value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis changes together with the range of the corresponding axis such that the scale of pixels per unit is in a constant ratio. Both axes are still zoomable, but when you zoom one, the other will zoom the same amount, keeping a fixed midpoint. `constrain` and `constraintoward` determine how we enforce the constraint. You can chain these, ie `yaxis: {scaleanchor: "x"}, yaxis2: {scaleanchor: "y"}` but you can only link axes of the same `type`. The linked axis can have the opposite letter (to constrain the aspect ratio) or the same letter (to match scales across subplots). Loops (`yaxis: {scaleanchor: "x"}, yaxis: {scaleanchor: "y"}` or longer) are redundant and the last constraint encountered will be ignored to avoid possible inconsistent constraints via `scaleratio`. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxisScaleAnchor(std::string const& value) -> Figure&;

    /// If this axis is linked to another by `scaleanchor`, this determines the pixel to unit scale ratio. For example, if this value is 10, then every unit on this axis spans 10 times the number of pixels as a unit on the linked axis. Use this for example to create an elevation profile where the vertical scale is exaggerated a fixed amount with respect to the horizontal.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxisScaleRatio(int value) -> Figure&;

    /// If "True", even 4-digit integers are separated
    /// @param value boolean
    auto yaxisSeparateThousands(std::string const& value) -> Figure&;

    /// Determines whether or not a dividers are drawn between the category levels of this axis. Only has an effect on "multicategory" axes.
    /// @param value boolean (default: True)
    auto yaxisShowDividers(std::string const& value) -> Figure&;

    /// If "all", all exponents are shown besides their significands. If "first", only the exponent of the first tick is shown. If "last", only the exponent of the last tick is shown. If "none", no exponents appear.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto yaxisShowExponent(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto yaxisShowGrid(std::string const& value) -> Figure&;

    /// Determines whether or not a line bounding this axis is drawn.
    /// @param value boolean
    auto yaxisShowLine(std::string const& value) -> Figure&;

    /// Determines whether or not spikes (aka droplines) are drawn for this axis. Note: This only takes affect when hovermode = closest
    /// @param value boolean
    auto yaxisShowSpikes(std::string const& value) -> Figure&;

    /// Determines whether or not the tick labels are drawn.
    /// @param value boolean (default: True)
    auto yaxisShowTickLabels(std::string const& value) -> Figure&;

    /// If "all", all tick labels are displayed with a prefix. If "first", only the first tick is displayed with a prefix. If "last", only the last tick is displayed with a suffix. If "none", tick prefixes are hidden.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto yaxisShowTickPrefix(std::string const& value) -> Figure&;

    /// Same as `showtickprefix` but for tick suffixes.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto yaxisShowTickSuffix(std::string const& value) -> Figure&;

    /// Determines whether a x (y) axis is positioned at the "bottom" ("left") or "top" ("right") of the plotting area.
    /// @param value enumerated , one of ( "top" | "bottom" | "left" | "right" )
    auto yaxisSide(std::string const& value) -> Figure&;

    /// Sets the spike color. If undefined, will use the series color
    /// @param value color
    auto yaxisSpikeColor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "dash")
    auto yaxisSpikeDash(std::string const& value) -> Figure&;

    /// Determines the drawing mode for the spike line If "toaxis", the line is drawn from the data point to the axis the series is plotted on. If "across", the line is drawn across the entire plot area, and supercedes "toaxis". If "marker", then a marker dot is drawn on the axis the series is plotted on
    /// @param value flaglist string. Any combination of "toaxis", "across", "marker" joined with a "+". Examples: "toaxis", "across", "toaxis+across", "toaxis+across+marker" (default: "toaxis")
    auto yaxisSpikeMode(std::string const& value) -> Figure&;

    /// Determines whether spikelines are stuck to the cursor or to the closest datapoints.
    /// @param value enumerated , one of ( "data" | "cursor" | "hovered data" ) (default: "hovered data")
    auto yaxisSpikeSnap(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 3)
    auto yaxisSpikeThickness(int value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto yaxisTick0(std::string const& value) -> Figure&;

    /// Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the tick labels vertically.
    /// @param value angle (default: "auto")
    auto yaxisTickAngle(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto yaxisTickColor(std::string const& value) -> Figure&;

    // /// Sets the tick font.
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisTickFontSpecs(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto yaxisTickFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto yaxisTickFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto yaxisTickFontSize(int value) -> Figure&;

    /// Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto yaxisTickFormat(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto yaxisTickFormatStops(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// range ["min", "max"], where "min", "max" - dtick values which describe some zoom level, it is possible to omit "min" or "max" value by passing "null"
    // /// @param value list
    // auto yaxisTickFormatStopsDtickRange(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Determines whether or not this stop is used. If `False`, this stop is ignored even within its `dtickrange`.
    /// @param value boolean (default: True)
    auto yaxisTickFormatStopsEnabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto yaxisTickFormatStopsName(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto yaxisTickFormatStopsTemplateItemName(std::string const& value) -> Figure&;

    /// string - dtickformat for described zoom level, the same as "tickformat"
    /// @param value string (default: "")
    auto yaxisTickFormatStopsValue(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to their corresponding ticks and grid lines. Only has an effect for axes of `type` "date" When set to "period", tick labels are drawn in the middle of the period between ticks.
    /// @param value enumerated , one of ( "instant" | "period" ) (default: "instant")
    auto yaxisTickLabelMode(std::string const& value) -> Figure&;

    /// Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The default value for inside tick labels is "hide past domain". Otherwise on "category" and "multicategory" axes the default is "allow". In other cases the default is "hide past div".
    /// @param value enumerated , one of ( "allow" | "hide past div" | "hide past domain" )
    auto yaxisTickLabelOverflow(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to the axis Please note that top or bottom has no effect on x axes or when `ticklabelmode` is set to "period". Similarly left or right has no effect on y axes or when `ticklabelmode` is set to "period". Has no effect on "multicategory" axes or when `tickson` is set to "boundaries". When used on axes linked by `matches` or `scaleanchor`, no extra padding for inside labels would be added by autorange, so that the scales could match.
    /// @param value enumerated , one of ( "outside" | "inside" | "outside top" | "inside top" | "outside left" | "inside left" | "outside right" | "inside right" | "outside bottom" | "inside bottom" ) (default: "outside")
    auto yaxisTickLabelPosition(std::string const& value) -> Figure&;

    /// Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` "log" or "multicategory", or when `tickmode` is "array".
    /// @param value integer greater than or equal to 1 (default: 1)
    auto yaxisTickLabelStep(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0 (default: 5)
    auto yaxisTickLength(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto yaxisTickMode(std::string const& value) -> Figure&;

    /// Sets a tick label prefix.
    /// @param value string (default: "")
    auto yaxisTickPrefix(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto yaxisTicks(std::string const& value) -> Figure&;

    /// Determines where ticks and grid lines are drawn with respect to their corresponding tick labels. Only has an effect for axes of `type` "category" or "multicategory". When set to "boundaries", ticks and grid lines are drawn half a category to the left/bottom of labels.
    /// @param value enumerated , one of ( "labels" | "boundaries" ) (default: "labels")
    auto yaxisTickson(std::string const& value) -> Figure&;

    /// Sets a tick label suffix.
    /// @param value string (default: "")
    auto yaxisTickSuffix(std::string const& value) -> Figure&;

    // /// Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to "array". Used with `tickvals`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxisTickText(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxisTickValues(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxisTickWidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisTitleSpecs(std::string const& value) -> Figure&;

    // /// Sets this axis' title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.
    // /// @param value a dict containing one or more of the keys listed below.
    // auto yaxisTitleFontSpecs(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto yaxisTitleFontColor(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto yaxisTitleFontFamily(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto yaxisTitleFontSize(int value) -> Figure&;

    /// Sets the standoff distance (in px) between the axis labels and the title text The default value is a function of the axis tick labels, the title `font.size` and the axis `linewidth`. Note that the axis title position is always constrained within the margins, so the actual standoff distance is always less than the set or default value. By setting `standoff` and turning on `automargin`, plotly.js will push the margins to fit the axis title at given standoff distance.
    /// @param value number greater than or equal to 0
    auto yaxisTitleStandoff(int value) -> Figure&;

    /// Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.
    /// @param value string
    auto yaxisTitleText(std::string const& value) -> Figure&;

    /// Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the traces that referenced the axis in question.
    /// @param value enumerated , one of ( "-" | "linear" | "log" | "date" | "category" | "multicategory" ) (default: "-")
    auto yaxisType(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in axis `range`, `autorange`, and `title` if in `editable: True` configuration. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto yaxisUirevision(std::string const& value) -> Figure&;

    /// A single toggle to hide the axis while preserving interaction like dragging. Default is True when a cheater plot is present on the axis, otherwise False
    /// @param value boolean
    auto yaxisVisible(std::string const& value) -> Figure&;

    /// Determines whether or not a line is drawn at along the 0 value of this axis. If "True", the zero line is drawn on top of the grid lines.
    /// @param value boolean
    auto yaxisZeroLine(std::string const& value) -> Figure&;

    /// Sets the line color of the zero line.
    /// @param value color (default: "#444")
    auto yaxisZeroLineColor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 1)
    auto yaxisZeroLineWidth(int value) -> Figure&;
};

} // namespace reaktplot
