#pragma once

// C++ includes
#include <string>

// pybind11 includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

// reaktplot includes
#include <reaktplot/Scatter.hpp>

namespace reaktplot {

/// Used to create, show, and save figures using plotly.
class Figure
{
public:
    /// Construct a default Figure object.
    Figure();

    /// Add a scatter trace to the figure.
    template<typename X, typename Y>
    auto addScatter(X const& x, Y const& y, std::string const& name) -> void
    {
        add(Scatter(x, y, name));
    }

    /// Add a scatter trace to the figure.
    template<typename X>
    auto addScatter(X const& x, Array const& y, std::string const& name) -> void
    {
        add(Scatter(x, y, name));
    }

    /// Add a scatter trace to the figure.
    auto add(Scatter const& scatter) -> void
    {
        using namespace py::literals;
        fig.attr("add_trace")(scatter.dict());
    }

    /// Show the figure.
    auto show() const -> void;

    //=================================================================================================================
    //
    // METHODS THAT CUSTOMIZE THE LAYOUT OF THE FIGURE
    //
    //=================================================================================================================

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto title(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.
    /// @param value dict containing one or more of the keys listed below.
    // auto title_font(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto title_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto title_font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto title_font_size(int value) -> Figure&;

    /// Sets the padding of the title. Each padding value only applies when the corresponding `xanchor`/`yanchor` value is set accordingly. E.g. for left padding to take effect, `xanchor` must be set to "left". The same rule applies if `xanchor`/`yanchor` is determined automatically. Padding is muted if the respective anchor value is "middle"/"center".
    /// @param value dict containing one or more of the keys listed below.
    // auto title_pad(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// The amount of padding (in px) along the bottom of the component. (default: 0)
    /// @param value number
    auto title_pad_b(int value) -> Figure&;

    /// The amount of padding (in px) on the left side of the component. (default: 0)
    /// @param value number
    auto title_pad_l(int value) -> Figure&;

    /// The amount of padding (in px) on the right side of the component. (default: 0)
    /// @param value number
    auto title_pad_r(int value) -> Figure&;

    /// The amount of padding (in px) along the top of the component. (default: 0)
    /// @param value number
    auto title_pad_t(int value) -> Figure&;

    /// Sets the plot's title. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.
    /// @param value string
    auto title_text(std::string const& value) -> Figure&;

    /// Sets the x position with respect to `xref` in normalized coordinates from "0" (left) to "1" (right). (Default: d.5)
    /// @param value number between or equal to 0 and 1
    auto title_x(double value) -> Figure&;

    /// Sets the title's horizontal alignment with respect to its x position. "left" means that the title starts at x, "right" means that the title ends at x and "center" means that the title's center is at x. "auto" divides `xref` by three and calculates the `xanchor` value automatically based on the value of `x`. (Default: "duto")
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" )
    auto title_xanchor(std::string const& value) -> Figure&;

    /// Sets the container `x` refers to. "container" spans the entire `width` of the plot. "paper" refers to the width of the plotting area only. (Default: "dontainer")
    /// @param value enumerated , one of ( "container" | "paper" )
    auto title_xref(std::string const& value) -> Figure&;

    /// Sets the y position with respect to `yref` in normalized coordinates from "0" (bottom) to "1" (top). "auto" places the baseline of the title onto the vertical center of the top margin. (Default: "duto")
    /// @param value number between or equal to 0 and 1
    auto title_y(double value) -> Figure&;

    /// Sets the title's vertical alignment with respect to its y position. "top" means that the title's cap line is at y, "bottom" means that the title's baseline is at y and "middle" means that the title's midline is at y. "auto" divides `yref` by three and calculates the `yanchor` value automatically based on the value of `y`. (Default: "duto")
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" )
    auto title_yanchor(std::string const& value) -> Figure&;

    /// Sets the container `y` refers to. "container" spans the entire `height` of the plot. "paper" refers to the height of the plotting area only. (Default: "dontainer")
    /// @param value enumerated , one of ( "container" | "paper" )
    auto title_yref(std::string const& value) -> Figure&;

    /// Determines whether or not a legend is drawn. Default is `True` if there is a trace to show and any of these: a) Two or more traces would by default be shown in the legend. b) One pie trace is shown in the legend. c) One trace is explicitly given with `showlegend: True`.
    /// @param value boolean
    auto showlegend(bool value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto legend(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the legend background color. Defaults to `layout.paper_bgcolor`.
    /// @param value color
    auto legend_bgcolor(std::string const& value) -> Figure&;

    /// Sets the color of the border enclosing the legend. (Default: "#d44")
    /// @param value color
    auto legend_bordercolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the border enclosing the legend. (default: 0)
    /// @param value number greater than or equal to 0
    auto legend_borderwidth(int value) -> Figure&;

    /// Sets the font used to text the legend items.
    /// @param value dict containing one or more of the keys listed below.
    // auto legend_font(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto legend_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto legend_font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto legend_font_size(int value) -> Figure&;

    /// Determines the behavior on legend group item click. "toggleitem" toggles the visibility of the individual item clicked on the graph. "togglegroup" toggles the visibility of all items in the same legendgroup as the item clicked on the graph. (Default: "dogglegroup")
    /// @param value enumerated , one of ( "toggleitem" | "togglegroup" )
    auto legend_groupclick(std::string const& value) -> Figure&;

    /// Sets the font for group titles in legend. Defaults to `legend.font` with its size increased about 10%.
    /// @param value dict containing one or more of the keys listed below.
    // auto legend_grouptitlefont(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto legend_grouptitlefont_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto legend_grouptitlefont_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto legend_grouptitlefont_size(int value) -> Figure&;

    /// Determines the behavior on legend item click. "toggle" toggles the visibility of the item clicked on the graph. "toggleothers" makes the clicked item the sole visible item on the graph. "False" disables legend item click interactions. (Default: "doggle")
    /// @param value enumerated , one of ( "toggle" | "toggleothers" | False )
    auto legend_itemclick(std::string const& value) -> Figure&;

    /// Determines the behavior on legend item double-click. "toggle" toggles the visibility of the item clicked on the graph. "toggleothers" makes the clicked item the sole visible item on the graph. "False" disables legend item double-click interactions. (Default: "doggleothers")
    /// @param value enumerated , one of ( "toggle" | "toggleothers" | False )
    auto legend_itemdoubleclick(std::string const& value) -> Figure&;

    /// Determines if the legend items symbols scale with their corresponding "trace" attributes or remain "constant" independent of the symbol size on the graph. (Default: "drace")
    /// @param value enumerated , one of ( "trace" | "constant" )
    auto legend_itemsizing(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the legend item symbols (the part other than the title.text). (default: 30)
    /// @param value number greater than or equal to 30
    auto legend_itemwidth(int value) -> Figure&;

    /// Sets the orientation of the legend. (Default: "d")
    /// @param value enumerated , one of ( "v" | "h" )
    auto legend_orientation(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto legend_title(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets this legend's title font. Defaults to `legend.font` with its size increased about 20%.
    /// @param value dict containing one or more of the keys listed below.
    // auto legend_title_font(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto legend_title_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto legend_title_font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto legend_title_font_size(int value) -> Figure&;

    /// Determines the location of legend's title with respect to the legend items. Defaulted to "top" with `orientation` is "h". Defaulted to "left" with `orientation` is "v". The "top left" options could be used to expand legend area in both x and y sides.
    /// @param value enumerated , one of ( "top" | "left" | "top left" )
    auto legend_title_side(std::string const& value) -> Figure&;

    /// Sets the title of the legend. (default: "")
    /// @param value string
    auto legend_title_text(std::string const& value) -> Figure&;

    /// Sets the amount of vertical space (in px) between legend groups. (default: 10)
    /// @param value number greater than or equal to 0
    auto legend_tracegroupgap(int value) -> Figure&;

    /// Determines the order at which the legend items are displayed. If "normal", the items are displayed top-to-bottom in the same order as the input data. If "reversed", the items are displayed in the opposite order as "normal". If "grouped", the items are displayed in groups (when a trace `legendgroup` is provided). if "grouped+reversed", the items are displayed in the opposite order as "grouped".
    /// @param value flaglist string. Any combination of "reversed", "grouped" joined with a "+" OR "normal". Examples: "reversed", "grouped", "reversed+grouped", "normal"
    auto legend_traceorder(std::string const& value) -> Figure&;

    /// Controls persistence of legend-driven changes in trace and pie label visibility. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto legend_uirevision(std::string const& value) -> Figure&;

    /// Sets the vertical alignment of the symbols with respect to their associated text. (Default: "diddle")
    /// @param value enumerated , one of ( "top" | "middle" | "bottom" )
    auto legend_valign(std::string const& value) -> Figure&;

    /// Sets the x position (in normalized coordinates) of the legend. Defaults to "1.02" for vertical legends and defaults to "0" for horizontal legends.
    /// @param value number between or equal to -2 and 3
    auto legend_x(double value) -> Figure&;

    /// Sets the legend's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the legend. Value "auto" anchors legends to the right for `x` values greater than or equal to 2/3, anchors legends to the left for `x` values less than or equal to 1/3 and anchors legends with respect to their center otherwise. (Default: "deft")
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" )
    auto legend_xanchor(std::string const& value) -> Figure&;

    /// Sets the y position (in normalized coordinates) of the legend. Defaults to "1" for vertical legends, defaults to "-0.1" for horizontal legends on graphs w/o range sliders and defaults to "1.1" for horizontal legends on graph with one or multiple range sliders.
    /// @param value number between or equal to -2 and 3
    auto legend_y(double value) -> Figure&;

    /// Sets the legend's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the legend. Value "auto" anchors legends at their bottom for `y` values less than or equal to 1/3, anchors legends to at their top for `y` values greater than or equal to 2/3 and anchors legends with respect to their middle otherwise.
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" )
    auto legend_yanchor(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto margin(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Turns on/off margin expansion computations. Legends, colorbars, updatemenus, sliders, axis rangeselector and rangeslider are allowed to push the margins by defaults. (default: True)
    /// @param value boolean
    auto margin_autoexpand(bool value) -> Figure&;

    /// Sets the bottom margin (in px). (default: 80)
    /// @param value number greater than or equal to 0
    auto margin_b(int value) -> Figure&;

    /// Sets the left margin (in px). (default: 80)
    /// @param value number greater than or equal to 0
    auto margin_l(int value) -> Figure&;

    /// Sets the amount of padding (in px) between the plotting area and the axis lines (default: 0)
    /// @param value number greater than or equal to 0
    auto margin_pad(int value) -> Figure&;

    /// Sets the right margin (in px). (default: 80)
    /// @param value number greater than or equal to 0
    auto margin_r(int value) -> Figure&;

    /// Sets the top margin (in px). (default: 100)
    /// @param value number greater than or equal to 0
    auto margin_t(int value) -> Figure&;

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
    /// @param value dict containing one or more of the keys listed below.
    // auto font(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman". (Default: ""Open Sans", verdana, arial, sans-derif")
    /// @param value string
    auto font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto font_size(int value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto uniformtext(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the minimum text size between traces of the same type. (default: 0)
    /// @param value number greater than or equal to 0
    auto uniformtext_minsize(int value) -> Figure&;

    /// Determines how the font size for various text elements are uniformed between each trace type. If the computed text sizes were smaller than the minimum size defined by `uniformtext.minsize` using "hide" option hides the text; and using "show" option shows the text without further downscaling. Please note that if the size defined by `minsize` is greater than the font size defined by trace, then the `minsize` is used.
    /// @param value enumerated , one of ( False | "hide" | "show" )
    auto uniformtext_mode(std::string const& value) -> Figure&;

    /// Sets the decimal and thousand separators. For example, ". " puts a '.' before decimals and a space between thousands. In English locales, dflt is ".," but other locales may alter this default.
    /// @param value string
    auto separators(std::string const& value) -> Figure&;

    /// Sets the background color of the paper where the graph is drawn. (Default: "#dff")
    /// @param value color
    auto paper_bgcolor(std::string const& value) -> Figure&;

    /// Sets the background color of the plotting area in-between x and y axes. (Default: "#dff")
    /// @param value color
    auto plot_bgcolor(std::string const& value) -> Figure&;

    /// Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. This is the default value; however it could be overridden for individual axes. (Default: "convert dypes")
    /// @param value enumerated , one of ( "convert types" | "strict" )
    auto autotypenumbers(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto colorscale(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the default diverging colorscale. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(5,10,172)], [0.35, rgb(106,137,247)], [0.5, rgb(190,190,190)], [0.6, rgb(220,170,132)], [0.7, rgb(230,145,90)], [1, rgb(178,10,28d], ])
    /// @param value colorscale
    auto colorscale_diverging(std::string const& value) -> Figure&;

    /// Sets the default sequential colorscale for positive values. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(220,220,220)], [0.2, rgb(245,195,157)], [0.4, rgb(245,160,105)], [1, rgb(178,10,28d], ])
    /// @param value colorscale
    auto colorscale_sequential(std::string const& value) -> Figure&;

    /// Sets the default sequential colorscale for negative values. Note that `autocolorscale` must be True for this attribute to work. (Default: [[0, rgb(5,10,172)], [0.35, rgb(40,60,190)], [0.5, rgb(70,100,245)], [0.6, rgb(90,120,245)], [0.7, rgb(106,137,247)], [1, rgb(220,220,220d], ])
    /// @param value colorscale
    auto colorscale_sequentialminus(std::string const& value) -> Figure&;

    /// Sets the default trace colors. (Default: [#1f77b4, #ff7f0e, #2ca02c, #d62728, #9467bd, #8c564b, #e377c2, #7f7f7f, #bcbd22, #d7becf])
    /// @param value colorlist
    auto colorway(std::vector<std::string> const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto modebar(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the color of the active or hovered on icons in the modebar.
    /// @param value color
    auto modebar_activecolor(std::string const& value) -> Figure&;

    /// Determines which predefined modebar buttons to add. Please note that these buttons will only be shown if they are compatible with all trace types used in a graph. Similar to `config.modeBarButtonsToAdd` option. This may include "v1hovermode", "hoverclosest", "hovercompare", "togglehover", "togglespikelines", "drawline", "drawopenpath", "drawclosedpath", "drawcircle", "drawrect", "eraseshape". (default: "")
    /// @param value string or array of strings
    auto modebar_add(std::string const& value) -> Figure&;

    /// Sets the background color of the modebar.
    /// @param value color
    auto modebar_bgcolor(std::string const& value) -> Figure&;

    /// Sets the color of the icons in the modebar.
    /// @param value color
    auto modebar_color(std::string const& value) -> Figure&;

    /// Sets the orientation of the modebar. (Default: "d")
    /// @param value enumerated , one of ( "v" | "h" )
    auto modebar_orientation(std::string const& value) -> Figure&;

    /// Determines which predefined modebar buttons to remove. Similar to `config.modeBarButtonsToRemove` option. This may include "autoScale2d", "autoscale", "editInChartStudio", "editinchartstudio", "hoverCompareCartesian", "hovercompare", "lasso", "lasso2d", "orbitRotation", "orbitrotation", "pan", "pan2d", "pan3d", "reset", "resetCameraDefault3d", "resetCameraLastSave3d", "resetGeo", "resetSankeyGroup", "resetScale2d", "resetViewMapbox", "resetViews", "resetcameradefault", "resetcameralastsave", "resetsankeygroup", "resetscale", "resetview", "resetviews", "select", "select2d", "sendDataToCloud", "senddatatocloud", "tableRotation", "tablerotation", "toImage", "toggleHover", "toggleSpikelines", "togglehover", "togglespikelines", "toimage", "zoom", "zoom2d", "zoom3d", "zoomIn2d", "zoomInGeo", "zoomInMapbox", "zoomOut2d", "zoomOutGeo", "zoomOutMapbox", "zoomin", "zoomout". (default: "")
    /// @param value string or array of strings
    auto modebar_remove(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes related to the modebar, including `hovermode`, `dragmode`, and `showspikes` at both the root level and inside subplots. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto modebar_uirevision(std::string const& value) -> Figure&;

    /// Determines the mode of hover interactions. If "closest", a single hoverlabel will appear for the "closest" point within the `hoverdistance`. If "x" (or "y"), multiple hoverlabels will appear for multiple points at the "closest" x- (or y-) coordinate within the `hoverdistance`, with the caveat that no more than one hoverlabel will appear per trace. If "x unified" (or "y unified"), a single hoverlabel will appear multiple points at the closest x- (or y-) coordinate within the `hoverdistance` with the caveat that no more than one hoverlabel will appear per trace. In this mode, spikelines are enabled by default perpendicular to the specified axis. If False, hover interactions are disabled. (Default: "dlosest")
    /// @param value enumerated , one of ( "x" | "y" | "closest" | False | "x unified" | "y unified" )
    auto hovermode(std::string const& value) -> Figure&;

    /// Examples: "event", "select", "event+select", "none"
    /// @param value flaglist string. Any combination of "event", "select" joined with a "+" OR "none".
    auto clickmode(std::string const& value) -> Figure&;

    /// Determines the mode of drag interactions. "select" and "lasso" apply only to scatter traces with markers or text. "orbit" and "turntable" apply only to 3D scenes. (Default: "doom")
    /// @param value enumerated , one of ( "zoom" | "pan" | "select" | "lasso" | "drawclosedpath" | "drawopenpath" | "drawline" | "drawrect" | "drawcircle" | "orbit" | "turntable" | False )
    auto dragmode(std::string const& value) -> Figure&;

    /// When `dragmode` is set to "select", this limits the selection of the drag to horizontal, vertical or diagonal. "h" only allows horizontal selection, "v" only vertical, "d" only diagonal and "any" sets no limit. (Default: "dny")
    /// @param value enumerated , one of ( "h" | "v" | "d" | "any" )
    auto selectdirection(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto activeselection(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the color filling the active selection' interior. (Default: "rgba(0,0,0,d)")
    /// @param value color
    auto activeselection_fillcolor(std::string const& value) -> Figure&;

    /// Sets the opacity of the active selection. (Default: d.5)
    /// @param value number between or equal to 0 and 1
    auto activeselection_opacity(double value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto newselection(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto newselection_line(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the line color. By default uses either dark grey or white to increase contrast with background color.
    /// @param value color
    auto newselection_line_color(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dot")
    /// @param value string
    auto newselection_line_dash(std::string const& value) -> Figure&;

    /// Sets the line width (in px). (default: 1)
    /// @param value number greater than or equal to 1
    auto newselection_line_width(int value) -> Figure&;

    /// Describes how a new selection is created. If `immediate`, a new selection is created after first mouse up. If `gradual`, a new selection is not created after first mouse. By adding to and subtracting from the initial selection, this option allows declaring extra outlines of the selection. (Default: "dmmediate")
    /// @param value enumerated , one of ( "immediate" | "gradual" )
    auto newselection_mode(std::string const& value) -> Figure&;

    /// Sets the default distance (in pixels) to look for data to add hover labels (-1 means no cutoff, 0 means no looking for data). This is only a real distance for hovering on point-like objects, like scatter points. For area-like objects (bars, scatter fills, etc) hovering is on inside the area and off outside, but these objects will not supersede hover on point-like objects in case of conflict. (default: 20)
    /// @param value integer greater than or equal to -1
    auto hoverdistance(std::string const& value) -> Figure&;

    /// Sets the default distance (in pixels) to look for data to draw spikelines to (-1 means no cutoff, 0 means no looking for data). As with hoverdistance, distance does not apply to area-like objects. In addition, some objects can be hovered on but will not generate spikelines, such as scatter fills. (Default: d1)
    /// @param value integer greater than or equal to -1
    auto spikedistance(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto hoverlabel(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the horizontal alignment of the text content within hover label box. Has an effect only if the hover label text spans more two or more lines (Default: "duto")
    /// @param value enumerated , one of ( "left" | "right" | "auto" )
    auto hoverlabel_align(std::string const& value) -> Figure&;

    /// Sets the background color of all hover labels on graph
    /// @param value color
    auto hoverlabel_bgcolor(std::string const& value) -> Figure&;

    /// Sets the border color of all hover labels on graph.
    /// @param value color
    auto hoverlabel_bordercolor(std::string const& value) -> Figure&;

    /// Sets the default hover label font used by all traces on the graph.
    /// @param value dict containing one or more of the keys listed below.
    // auto hoverlabel_font(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto hoverlabel_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman". (Default: "Arial, sans-derif")
    /// @param value string
    auto hoverlabel_font_family(std::string const& value) -> Figure&;

    /// grouptitlefont (default: 13)
    /// @param value number greater than or equal to 1
    auto hoverlabel_font_size(int value) -> Figure&;

    /// Sets the font for group titles in hover (unified modes). Defaults to `hoverlabel.font`.
    /// @param value dict containing one or more of the keys listed below.
    // auto hoverlabel_grouptitlefont(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Missing documentation!
    /// @param value color
    auto hoverlabel_grouptitlefont_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto hoverlabel_grouptitlefont_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto hoverlabel_grouptitlefont_size(int value) -> Figure&;

    /// Sets the default length (in number of characters) of the trace name in the hover labels for all traces. -1 shows the whole name regardless of length. 0-3 shows the first 0-3 characters, and an integer >3 will show the whole name if it is less than that many characters, but if it is longer, will truncate to `namelength - 3` characters and add an ellipsis. (default: 15)
    /// @param value integer greater than or equal to -1
    auto hoverlabel_namelength(std::string const& value) -> Figure&;

    /// Sets transition options used during Plotly.react updates.
    /// @param value dict containing one or more of the keys listed below.
    // auto transition(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// The duration of the transition, in milliseconds. If equal to zero, updates are synchronous. (default: 500)
    /// @param value number greater than or equal to 0
    auto transition_duration(int value) -> Figure&;

    /// The easing function used for the transition (Default: "cubic-in-dut")
    /// @param value enumerated , one of ( "linear" | "quad" | "cubic" | "sin" | "exp" | "circle" | "elastic" | "back" | "bounce" | "linear-in" | "quad-in" | "cubic-in" | "sin-in" | "exp-in" | "circle-in" | "elastic-in" | "back-in" | "bounce-in" | "linear-out" | "quad-out" | "cubic-out" | "sin-out" | "exp-out" | "circle-out" | "elastic-out" | "back-out" | "bounce-out" | "linear-in-out" | "quad-in-out" | "cubic-in-out" | "sin-in-out" | "exp-in-out" | "circle-in-out" | "elastic-in-out" | "back-in-out" | "bounce-in-out" )
    auto transition_easing(std::string const& value) -> Figure&;

    /// Determines whether the figure's layout or traces smoothly transitions during updates that make both traces and layout change. (Default: "layout dirst")
    /// @param value enumerated , one of ( "layout first" | "traces first" )
    auto transition_ordering(std::string const& value) -> Figure&;

    /// If provided, a changed value tells `Plotly.react` that one or more data arrays has changed. This way you can modify arrays in-place rather than making a complete new copy for an incremental change. If NOT provided, `Plotly.react` assumes that data arrays are being treated as immutable, thus any data array with a different identity from its predecessor contains new data.
    /// @param value number or categorical coordinate string
    auto datarevision(std::string const& value) -> Figure&;

    /// Used to allow user interactions with the plot to persist after `Plotly.react` calls that are unaware of these interactions. If `uirevision` is omitted, or if it is given and it changed from the previous `Plotly.react` call, the exact new figure is used. If `uirevision` is truthy and did NOT change, any attribute that has been affected by user interactions and did not receive a different value in the new figure will keep the interaction value. `layout.uirevision` attribute serves as the default for `uirevision` attributes in various sub-containers. For finer control you can set these sub-attributes directly. For example, if your app separately controls the data on the x and y axes you might set `xaxis.uirevision="time"` and `yaxis.uirevision="cost"`. Then if only the y data is changed, you can update `yaxis.uirevision="quantity"` and the y axis range will reset but the x axis range will retain any user-driven zoom.
    /// @param value number or categorical coordinate string
    auto uirevision(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in `editable: True` configuration, other than trace names and axis titles. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto editrevision(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in selected points from all traces.
    /// @param value number or categorical coordinate string
    auto selectionrevision(std::string const& value) -> Figure&;

    /// Default attributes to be applied to the plot. Templates can be created from existing plots using `Plotly.makeTemplate`, or created manually. They should be objects with format: `{layout: layoutTemplate, data: {[type]: [traceTemplate, ...]}, ...}` `layoutTemplate` and `traceTemplate` are objects matching the attribute structure of `layout` and a data trace. Trace templates are applied cyclically to traces of each type. Container arrays (eg `annotations`) have special handling: An object ending in `defaults` (eg `annotationdefaults`) is applied to each array item. But if an item has a `templateitemname` key we look in the template array for an item with matching `name` and apply that instead. If no matching `name` is found we mark the item invisible. Any named template item not referenced is appended to the end of the array, so you can use this for a watermark annotation or a logo image, for example. To omit one of these items on the plot, make an item with matching `templateitemname` and `visible: False`.
    /// @param value number or categorical coordinate string
    // auto template(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Assigns extra meta information that can be used in various `text` attributes. Attributes such as the graph, axis and colorbar `title.text`, annotation `text` `trace.name` in legend items, `rangeselector`, `updatemenus` and `sliders` `label` text all support `meta`. One can access `meta` fields using template strings: `%{meta[i]}` where `i` is the index of the `meta` item in question. `meta` can also be an object for example `{key: value}` which can be accessed %{meta[key]}.
    /// @param value number or categorical coordinate string
    auto meta(std::string const& value) -> Figure&;

    /// Placeholder for exporting automargin-impacting values namely `margin.t`, `margin.b`, `margin.l` and `margin.r` in "full-json" mode.
    /// @param value number or categorical coordinate string
    auto computed(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto grid(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// The number of columns in the grid. If you provide a 2D `subplots` array, the length of its longest row is used as the default. If you give an `xaxes` array, its length is used as the default. But it's also possible to have a different length, if you want to leave a row at the end for non-cartesian subplots.
    /// @param value integer greater than or equal to 1
    auto grid_columns(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto grid_domain(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the horizontal domain of this grid subplot (in plot fraction). The first and last cells end exactly at the domain edges, with no grout around the edges. (Default: [0, d])
    /// @param value list
    auto grid_domain_x(std::string const& value) -> Figure&;

    /// Sets the vertical domain of this grid subplot (in plot fraction). The first and last cells end exactly at the domain edges, with no grout around the edges. (Default: [0, d])
    /// @param value list
    auto grid_domain_y(std::string const& value) -> Figure&;

    /// If no `subplots`, `xaxes`, or `yaxes` are given but we do have `rows` and `columns`, we can generate defaults using consecutive axis IDs, in two ways: "coupled" gives one x axis per column and one y axis per row. "independent" uses a new xy pair for each cell, left-to-right across each row then iterating rows according to `roworder`. (Default: "doupled")
    /// @param value enumerated , one of ( "independent" | "coupled" )
    auto grid_pattern(std::string const& value) -> Figure&;

    /// Is the first row the top or the bottom? Note that columns are always enumerated from left to right. (Default: "top to dottom")
    /// @param value enumerated , one of ( "top to bottom" | "bottom to top" )
    auto grid_roworder(std::string const& value) -> Figure&;

    /// The number of rows in the grid. If you provide a 2D `subplots` array or a `yaxes` array, its length is used as the default. But it's also possible to have a different length, if you want to leave a row at the end for non-cartesian subplots.
    /// @param value integer greater than or equal to 1
    auto grid_rows(std::string const& value) -> Figure&;

    /// Used for freeform grids, where some axes may be shared across subplots but others are not. Each entry should be a cartesian subplot id, like "xy" or "x3y2", or "" to leave that cell empty. You may reuse x axes within the same column, and y axes within the same row. Non-cartesian subplots and traces that support `domain` can place themselves in this grid separately using the `gridcell` attribute.
    /// @param value list
    auto grid_subplots(std::string const& value) -> Figure&;

    /// Used with `yaxes` when the x and y axes are shared across columns and rows. Each entry should be an x axis id like "x", "x2", etc., or "" to not put an x axis in that column. Entries other than "" must be unique. Ignored if `subplots` is present. If missing but `yaxes` is present, will generate consecutive IDs.
    /// @param value list
    auto grid_xaxes(std::string const& value) -> Figure&;

    /// Horizontal space between grid cells, expressed as a fraction of the total width available to one cell. Defaults to 0.1 for coupled-axes grids and 0.2 for independent grids.
    /// @param value number between or equal to 0 and 1
    auto grid_xgap(double value) -> Figure&;

    /// Sets where the x axis labels and titles go. "bottom" means the very bottom of the grid. "bottom plot" is the lowest plot that each x axis is used in. "top" and "top plot" are similar. (Default: "bottom dlot")
    /// @param value enumerated , one of ( "bottom" | "bottom plot" | "top plot" | "top" )
    auto grid_xside(std::string const& value) -> Figure&;

    /// Used with `yaxes` when the x and y axes are shared across columns and rows. Each entry should be an y axis id like "y", "y2", etc., or "" to not put a y axis in that row. Entries other than "" must be unique. Ignored if `subplots` is present. If missing but `xaxes` is present, will generate consecutive IDs.
    /// @param value list
    auto grid_yaxes(std::string const& value) -> Figure&;

    /// Vertical space between grid cells, expressed as a fraction of the total height available to one cell. Defaults to 0.1 for coupled-axes grids and 0.3 for independent grids.
    /// @param value number between or equal to 0 and 1
    auto grid_ygap(double value) -> Figure&;

    /// Sets where the y axis labels and titles go. "left" means the very left edge of the grid. "left plot" is the leftmost plot that each y axis is used in. "right" and "right plot" are similar. (Default: "left dlot")
    /// @param value enumerated , one of ( "left" | "left plot" | "right plot" | "right" )
    auto grid_yside(std::string const& value) -> Figure&;

    /// Sets the default calendar system to use for interpreting and displaying dates throughout the plot. (Default: "dregorian")
    /// @param value enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" )
    auto calendar(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto newshape(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// When `dragmode` is set to "drawrect", "drawline" or "drawcircle" this limits the drag to be horizontal, vertical or diagonal. Using "diagonal" there is no limit e.g. in drawing lines in any direction. "ortho" limits the draw to be either horizontal or vertical. "horizontal" allows horizontal extend. "vertical" allows vertical extend. (Default: "diagonal")
    /// @param value enumerated , one of ( "ortho" | "horizontal" | "vertical" | "diagonal" )
    auto newshape_drawdirection(std::string const& value) -> Figure&;

    /// Sets the color filling new shapes' interior. Please note that if using a fillcolor with alpha greater than half, drag inside the active shape starts moving the shape underneath, otherwise a new shape could be started over. (Default: "rgba(0,0,0,d)")
    /// @param value color
    auto newshape_fillcolor(std::string const& value) -> Figure&;

    /// Determines the path's interior. For more info please visit https://developer.mozilla.org/en-US/docs/Web/SVG/Attribute/fill-rule (Default: "dvenodd")
    /// @param value enumerated , one of ( "evenodd" | "nonzero" )
    auto newshape_fillrule(std::string const& value) -> Figure&;

    /// Specifies whether new shapes are drawn below or above traces. (Default: "dbove")
    /// @param value enumerated , one of ( "below" | "above" )
    auto newshape_layer(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto newshape_line(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the line color. By default uses either dark grey or white to increase contrast with background color.
    /// @param value color
    auto newshape_line_color(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dolid")
    /// @param value string
    auto newshape_line_dash(std::string const& value) -> Figure&;

    /// Sets the line width (in px). (default: 4)
    /// @param value number greater than or equal to 0
    auto newshape_line_width(int value) -> Figure&;

    /// Sets the opacity of new shapes. (default: 1)
    /// @param value number between or equal to 0 and 1
    auto newshape_opacity(double value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto activeshape(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the color filling the active shape' interior. (Default: "rgb(255,0,d55)")
    /// @param value color
    auto activeshape_fillcolor(std::string const& value) -> Figure&;

    /// Sets the opacity of the active shape. (Default: d.5)
    /// @param value number between or equal to 0 and 1
    auto activeshape_opacity(double value) -> Figure&;

    /// Missing documentation!
    /// @param value list of dict where each dict has one or more of the keys listed below.
    auto selections(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value dict containing one or more of the keys listed below.
    // auto selections_line(std::string const& value) -> Figure&; // All methods that set a dictionary currently not implemented!

    /// Sets the line color.
    /// @param value color
    auto selections_line_color(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px"). (Default: "dot")
    /// @param value string
    auto selections_line_dash(std::string const& value) -> Figure&;

    /// Sets the line width (in px). (default: 1)
    /// @param value number greater than or equal to 1
    auto selections_line_width(int value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto selections_name(std::string const& value) -> Figure&;

    /// Sets the opacity of the selection. (Default: d.7)
    /// @param value number between or equal to 0 and 1
    auto selections_opacity(double value) -> Figure&;

    /// For `type` "path" - a valid SVG path similar to `shapes.path` in data coordinates. Allowed segments are: M, L and Z.
    /// @param value string
    auto selections_path(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto selections_templateitemname(std::string const& value) -> Figure&;

    /// Specifies the selection type to be drawn. If "rect", a rectangle is drawn linking (`x0`,`y0`), (`x1`,`y0`), (`x1`,`y1`) and (`x0`,`y1`). If "path", draw a custom SVG path using `path`.
    /// @param value enumerated , one of ( "rect" | "path" )
    auto selections_type(std::string const& value) -> Figure&;

    /// Sets the selection's starting x position.
    /// @param value number or categorical coordinate string
    auto selections_x0(std::string const& value) -> Figure&;

    /// Sets the selection's end x position.
    /// @param value number or categorical coordinate string
    auto selections_x1(std::string const& value) -> Figure&;

    /// Sets the selection's x coordinate axis. If set to a x axis id (e.g. "x" or "x2"), the `x` position refers to a x coordinate. If set to "paper", the `x` position refers to the distance from the left of the plotting area in normalized coordinates where "0" ("1") corresponds to the left (right). If set to a x axis ID followed by "domain" (separated by a space), the position behaves like for "paper", but refers to the distance in fractions of the domain length from the left of the domain of that axis: e.g., "x2 domain" refers to the domain of the second x axis and a x position of 0.5 refers to the point between the left and the right of the domain of the second x axis.
    /// @param value enumerated , one of ( "paper" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto selections_xref(std::string const& value) -> Figure&;

    /// Sets the selection's starting y position.
    /// @param value number or categorical coordinate string
    auto selections_y0(std::string const& value) -> Figure&;

    /// Sets the selection's end y position.
    /// @param value number or categorical coordinate string
    auto selections_y1(std::string const& value) -> Figure&;

    /// Sets the selection's x coordinate axis. If set to a y axis id (e.g. "y" or "y2"), the `y` position refers to a y coordinate. If set to "paper", the `y` position refers to the distance from the bottom of the plotting area in normalized coordinates where "0" ("1") corresponds to the bottom (top). If set to a y axis ID followed by "domain" (separated by a space), the position behaves like for "paper", but refers to the distance in fractions of the domain length from the bottom of the domain of that axis: e.g., "y2 domain" refers to the domain of the second y axis and a y position of 0.5 refers to the point between the bottom and the top of the domain of the second y axis.
    /// @param value enumerated , one of ( "paper" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto selections_yref(std::string const& value) -> Figure&;

    /// Determines whether or not a text link citing the data source is placed at the bottom-right cored of the figure. Has only an effect only on graphs that have been generated via forked graphs from the Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise).
    /// @param value boolean
    auto hidesources(bool value) -> Figure&;

    /// If `True`, the pie slice colors (whether given by `piecolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto extendpiecolors(bool value) -> Figure&;

    /// hiddenlabels is the funnelarea & pie chart analog of visible:'legendonly' but it can contain many labels, and can simultaneously hide slices from several pies/funnelarea charts
    /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    auto hiddenlabels(std::string const& value) -> Figure&;

    /// Sets the default pie slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendpiecolors`.
    /// @param value colorlist
    auto piecolorway(std::vector<std::string> const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between boxes of adjacent location coordinates. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto boxgap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between boxes of the same location coordinate. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto boxgroupgap(double value) -> Figure&;

    /// Determines how boxes at the same location coordinate are displayed on the graph. If "group", the boxes are plotted next to one another centered around the shared location. If "overlay", the boxes are plotted over one another, you might need to set "opacity" to see them multiple boxes. Has no effect on traces that have "width" set. (Default: "dverlay")
    /// @param value enumerated , one of ( "group" | "overlay" )
    auto boxmode(std::string const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between violins of adjacent location coordinates. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto violingap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between violins of the same location coordinate. Has no effect on traces that have "width" set. (Default: d.3)
    /// @param value number between or equal to 0 and 1
    auto violingroupgap(double value) -> Figure&;

    /// Determines how violins at the same location coordinate are displayed on the graph. If "group", the violins are plotted next to one another centered around the shared location. If "overlay", the violins are plotted over one another, you might need to set "opacity" to see them multiple violins. Has no effect on traces that have "width" set. (Default: "dverlay")
    /// @param value enumerated , one of ( "group" | "overlay" )
    auto violinmode(std::string const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)
    /// @param value number between or equal to 0 and 1
    auto bargroupgap(double value) -> Figure&;

    /// Determines how bars at the same location coordinate are displayed on the graph. With "stack", the bars are stacked on top of one another With "relative", the bars are stacked on top of one another, with negative values below the axis, positive values above With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "droup")
    /// @param value enumerated , one of ( "stack" | "group" | "overlay" | "relative" )
    auto barmode(std::string const& value) -> Figure&;

    /// Sets the normalization for bar traces on the graph. With "fraction", the value of each bar is divided by the sum of all values at that location coordinate. "percent" is the same but multiplied by 100 to show percentages. (default: "")
    /// @param value enumerated , one of ( "" | "fraction" | "percent" )
    auto barnorm(std::string const& value) -> Figure&;

    /// Sets the gap between bars of adjacent location coordinates. Values are unitless, they represent fractions of the minimum difference in bar positions in the data. (Default: 0.1)
    /// @param value number between or equal to 0 and 1
    auto bargap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of adjacent location coordinates.
    /// @param value number between or equal to 0 and 1
    auto waterfallgap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)
    /// @param value number between or equal to 0 and 1
    auto waterfallgroupgap(double value) -> Figure&;

    /// Determines how bars at the same location coordinate are displayed on the graph. With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "droup")
    /// @param value enumerated , one of ( "group" | "overlay" )
    auto waterfallmode(std::string const& value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of adjacent location coordinates.
    /// @param value number between or equal to 0 and 1
    auto funnelgap(double value) -> Figure&;

    /// Sets the gap (in plot fraction) between bars of the same location coordinate. (default: 0)
    /// @param value number between or equal to 0 and 1
    auto funnelgroupgap(double value) -> Figure&;

    /// Determines how bars at the same location coordinate are displayed on the graph. With "stack", the bars are stacked on top of one another With "group", the bars are plotted next to one another centered around the shared location. With "overlay", the bars are plotted over one another, you might need to an "opacity" to see multiple bars. (Default: "dtack")
    /// @param value enumerated , one of ( "stack" | "group" | "overlay" )
    auto funnelmode(std::string const& value) -> Figure&;

    /// If `True`, the funnelarea slice colors (whether given by `funnelareacolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto extendfunnelareacolors(bool value) -> Figure&;

    /// Sets the default funnelarea slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendfunnelareacolors`.
    /// @param value colorlist
    auto funnelareacolorway(std::vector<std::string> const& value) -> Figure&;

    /// If `True`, the sunburst slice colors (whether given by `sunburstcolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto extendsunburstcolors(bool value) -> Figure&;

    /// Sets the default sunburst slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendsunburstcolors`.
    /// @param value colorlist
    auto sunburstcolorway(std::vector<std::string> const& value) -> Figure&;

    /// If `True`, the treemap slice colors (whether given by `treemapcolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto extendtreemapcolors(bool value) -> Figure&;

    /// Sets the default treemap slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendtreemapcolors`.
    /// @param value colorlist
    auto treemapcolorway(std::vector<std::string> const& value) -> Figure&;

    /// If `True`, the icicle slice colors (whether given by `iciclecolorway` or inherited from `colorway`) will be extended to three times its original length by first repeating every color 20% lighter then each color 20% darker. This is intended to reduce the likelihood of reusing the same color when you have many slices, but you can set `False` to disable. Colors provided in the trace, using `marker.colors`, are never extended. (default: True)
    /// @param value boolean
    auto extendiciclecolors(bool value) -> Figure&;

    /// Sets the default icicle slice colors. Defaults to the main `colorway` used for trace colors. If you specify a new list here it can still be extended with lighter and darker colors, see `extendiciclecolors`.
    /// @param value colorlist
    auto iciclecolorway(std::vector<std::string> const& value) -> Figure&;

    //=================================================================================================================
    //
    // METHODS THAT CUSTOMIZE THE X-AXIS LAYOUT OF THE FIGURE
    //
    //=================================================================================================================

    /// If set to an opposite-letter axis id (e.g. `x2`, `y`), this axis is bound to the corresponding opposite-letter axis. If set to "free", this axis' position is determined by `position`.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxis_anchor(std::string const& value) -> Figure&;

    /// Determines whether long tick labels automatically grow the figure margins.
    /// @param value flaglist string. Any combination of "height", "width", "left", "right", "top", "bottom" joined with a "+" OR True or False. Examples: "height", "width", "height+width", "height+width+left", "True"
    auto xaxis_automargin(std::string const& value) -> Figure&;

    /// Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode` for more info. If `range` is provided, then `autorange` is set to "False".
    /// @param value enumerated , one of ( True | False | "reversed" ) (default: True)
    auto xaxis_autorange(std::string const& value) -> Figure&;

    /// Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. Defaults to layout.autotypenumbers.
    /// @param value enumerated , one of ( "convert types" | "strict" ) (default: "convert types")
    auto xaxis_autotypenumbers(std::string const& value) -> Figure&;

    /// Sets the calendar system to use for `range` and `tick0` if this is a date axis. This does not set the calendar for interpreting data on this axis, that's specified in the trace or via the global `layout.calendar`
    /// @param value enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" ) (default: "gregorian")
    auto xaxis_calendar(std::string const& value) -> Figure&;

    // /// Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to "array". Used with `categoryorder`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxis_categoryarray(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Specifies the ordering logic for the case of categorical variables. By default, plotly uses "trace", which specifies the order that is present in the data supplied. Set `categoryorder` to "category ascending" or "category descending" if order should be determined by the alphanumerical order of the category names. Set `categoryorder` to "array" to derive the ordering from the attribute `categoryarray`. If a category is not found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the "trace" mode. The unspecified categories will follow the categories in `categoryarray`. Set `categoryorder` to "total ascending" or "total descending" if order should be determined by the numerical order of the values. Similarly, the order can be determined by the min, max, sum, mean or median of all the values.
    /// @param value enumerated , one of ( "trace" | "category ascending" | "category descending" | "array" | "total ascending" | "total descending" | "min ascending" | "min descending" | "max ascending" | "max descending" | "sum ascending" | "sum descending" | "mean ascending" | "mean descending" | "median ascending" | "median descending" ) (default: "trace")
    auto xaxis_categoryorder(std::string const& value) -> Figure&;

    /// Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid color is lightened by blending this with the plot background Individual pieces can override this.
    /// @param value color (default: "#444")
    auto xaxis_color(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines how that happens: by increasing the "range", or by decreasing the "domain". Default is "domain" for axes containing image traces, "range" otherwise.
    /// @param value enumerated , one of ( "range" | "domain" )
    auto xaxis_constrain(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines which direction we push the originally specified plot area. Options are "left", "center" (default), and "right" for x axes, and "top", "middle" (default), and "bottom" for y axes.
    /// @param value enumerated , one of ( "left" | "center" | "right" | "top" | "middle" | "bottom" )
    auto xaxis_constraintoward(std::string const& value) -> Figure&;

    /// Sets the color of the dividers Only has an effect on "multicategory" axes.
    /// @param value color (default: "#444")
    auto xaxis_dividercolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the dividers Only has an effect on "multicategory" axes.
    /// @param value number (default: 1)
    auto xaxis_dividerwidth(int value) -> Figure&;

    // /// Sets the domain of this axis (in plot fraction).
    // /// @param value list (default: [0, 1])
    // auto xaxis_domain(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto xaxis_dtick(std::string const& value) -> Figure&;

    /// Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If "none", it appears as 1,000,000,000. If "e", 1e+9. If "E", 1E+9. If "power", 1x10^9 (with 9 in a super script). If "SI", 1G. If "B", 1B.
    /// @param value enumerated , one of ( "none" | "e" | "E" | "power" | "SI" | "B" ) (default: "B")
    auto xaxis_exponentformat(std::string const& value) -> Figure&;

    /// Determines whether or not this axis is zoom-able. If True, then zoom is disabled.
    /// @param value boolean
    auto xaxis_fixedrange(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto xaxis_gridcolor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto xaxis_griddash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxis_gridwidth(int value) -> Figure&;

    /// Sets the hover text formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto xaxis_hoverformat(std::string const& value) -> Figure&;

    /// Sets the layer on which this axis is displayed. If "above traces", this axis is displayed above all the subplot's traces If "below traces", this axis is displayed below all the subplot's traces, but above the grid lines. Useful when used together with scatter-like traces with `cliponaxis` set to "False" to show markers and/or text nodes above this axis.
    /// @param value enumerated , one of ( "above traces" | "below traces" ) (default: "above traces")
    auto xaxis_layer(std::string const& value) -> Figure&;

    /// Sets the axis line color.
    /// @param value color (default: "#444")
    auto xaxis_linecolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the axis line.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxis_linewidth(int value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis will match the range of the corresponding axis in data-coordinates space. Moreover, matching axes share auto-range values, category lists and histogram auto-bins. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden. Moreover, note that matching axes must have the same `type`.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxis_matches(std::string const& value) -> Figure&;

    /// Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is "SI" or "B".
    /// @param value number greater than or equal to 0 (default: 3)
    auto xaxis_minexponent(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_minor(std::string const& value) -> Figure&;

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto xaxis_minor_dtick(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto xaxis_minor_gridcolor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto xaxis_minor_griddash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0
    auto xaxis_minor_gridwidth(int value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 5)
    auto xaxis_minor_nticks(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto xaxis_minor_showgrid(std::string const& value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto xaxis_minor_tick0(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto xaxis_minor_tickcolor(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0
    auto xaxis_minor_ticklen(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto xaxis_minor_tickmode(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto xaxis_minor_ticks(std::string const& value) -> Figure&;

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxis_minor_tickvals(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0
    auto xaxis_minor_tickwidth(int value) -> Figure&;

    /// Determines if the axis lines or/and ticks are mirrored to the opposite side of the plotting area. If "True", the axis lines are mirrored. If "ticks", the axis lines and ticks are mirrored. If "False", mirroring is disable. If "all", axis lines are mirrored on all shared-axes subplots. If "allticks", axis lines and ticks are mirrored on all shared-axes subplots.
    /// @param value enumerated , one of ( True | "ticks" | False | "all" | "allticks" )
    auto xaxis_mirror(std::string const& value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 0)
    auto xaxis_nticks(std::string const& value) -> Figure&;

    /// If set a same-letter axis id, this axis is overlaid on top of the corresponding same-letter axis, with traces and axes visible for both axes. If "False", this axis does not overlay any same-letter axes. In this case, for axes with overlapping domains only the highest-numbered axis will be visible.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxis_overlaying(std::string const& value) -> Figure&;

    /// Sets the position of this axis in the plotting space (in normalized coordinates). Only has an effect if `anchor` is set to "free".
    /// @param value number between or equal to 0 and 1 (default: 0)
    auto xaxis_position(int value) -> Figure&;

    // /// Sets the range of this axis. If the axis `type` is "log", then you must take the log of your desired range (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    // /// @param value list
    // auto xaxis_range(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto xaxis_rangebreaks(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the lower and upper bounds of this axis rangebreak. Can be used with `pattern`.
    // /// @param value list
    // auto xaxis_rangebreaks_bounds(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the size of each `values` item. The default is one day in milliseconds.
    /// @param value number greater than or equal to 0 (default: 86400000)
    auto xaxis_rangebreaks_dvalue(int value) -> Figure&;

    /// Determines whether this axis rangebreak is enabled or disabled. Please note that `rangebreaks` only work for "date" axis type.
    /// @param value boolean (default: True)
    auto xaxis_rangebreaks_enabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto xaxis_rangebreaks_name(std::string const& value) -> Figure&;

    /// Determines a pattern on the time line that generates breaks. If "day of week" - days of the week in English e.g. 'Sunday' or `sun` (matching is case-insensitive and considers only the first three characters), as well as Sunday-based integers between 0 and 6. If "hour" - hour (24-hour clock) as decimal numbers between 0 and 24. for more info. Examples: - { pattern: 'day of week', bounds: [6, 1] } or simply { bounds: ['sat', 'mon'] } breaks from Saturday to Monday (i.e. skips the weekends). - { pattern: 'hour', bounds: [17, 8] } breaks from 5pm to 8am (i.e. skips non-work hours).
    /// @param value enumerated , one of ( "day of week" | "hour" | "" )
    auto xaxis_rangebreaks_pattern(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto xaxis_rangebreaks_templateitemname(std::string const& value) -> Figure&;

    // /// Sets the coordinate values corresponding to the rangebreaks. An alternative to `bounds`. Use `dvalue` to set the size of the values along the axis.
    // /// @param value list
    // auto xaxis_rangebreaks_values(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// If "normal", the range is computed in relation to the extrema of the input data. If "tozero"`, the range extends to 0, regardless of the input data If "nonnegative", the range is non-negative, regardless of the input data. Applies only to linear axes.
    /// @param value enumerated , one of ( "normal" | "tozero" | "nonnegative" ) (default: "normal")
    auto xaxis_rangemode(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_rangeselector(std::string const& value) -> Figure&;

    /// Sets the background color of the active range selector button.
    /// @param value color
    auto xaxis_rangeselector_activecolor(std::string const& value) -> Figure&;

    /// Sets the background color of the range selector buttons.
    /// @param value color (default: "#eee")
    auto xaxis_rangeselector_bgcolor(std::string const& value) -> Figure&;

    /// Sets the color of the border enclosing the range selector.
    /// @param value color (default: "#444")
    auto xaxis_rangeselector_bordercolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the border enclosing the range selector.
    /// @param value number greater than or equal to 0 (default: 0)
    auto xaxis_rangeselector_borderwidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto xaxis_rangeselector_buttons(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the number of steps to take to update the range. Use with `step` to specify the update interval.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxis_rangeselector_count(int value) -> Figure&;

    /// Sets the text label to appear on the button.
    /// @param value string
    auto xaxis_rangeselector_label(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto xaxis_rangeselector_name(std::string const& value) -> Figure&;

    /// The unit of measurement that the `count` value will set the range by.
    /// @param value enumerated , one of ( "month" | "year" | "day" | "hour" | "minute" | "second" | "all" ) (default: "month")
    auto xaxis_rangeselector_step(std::string const& value) -> Figure&;

    /// Sets the range update mode. If "backward", the range update shifts the start of range back "count" times "step" milliseconds. If "todate", the range update shifts the start of range back to the first timestamp from "count" times "step" milliseconds back. For example, with `step` set to "year" and `count` set to "1" the range update shifts the start of the range back to January 01 of the current year. Month and year "todate" are currently available only for the built-in (Gregorian) calendar.
    /// @param value enumerated , one of ( "backward" | "todate" ) (default: "backward")
    auto xaxis_rangeselector_stepmode(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto xaxis_rangeselector_templateitemname(std::string const& value) -> Figure&;

    // /// Sets the font of the range selector button text.
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_rangeselector_font(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto xaxis_rangeselector_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto xaxis_rangeselector_font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto xaxis_rangeselector_font_size(int value) -> Figure&;

    /// Determines whether or not this range selector is visible. Note that range selectors are only available for x axes of `type` set to or auto-typed to "date".
    /// @param value boolean (default: True)
    auto xaxis_rangeselector_visible(std::string const& value) -> Figure&;

    /// Sets the x position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto xaxis_rangeselector_x(int value) -> Figure&;

    /// Sets the range selector's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the range selector.
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" ) (default: "left")
    auto xaxis_rangeselector_xanchor(std::string const& value) -> Figure&;

    /// Sets the y position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto xaxis_rangeselector_y(int value) -> Figure&;

    /// Sets the range selector's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the range selector.
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" ) (default: "bottom")
    auto xaxis_rangeselector_yanchor(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_rangeslider(std::string const& value) -> Figure&;

    /// Determines whether or not the range slider range is computed in relation to the input data. If `range` is provided, then `autorange` is set to "False".
    /// @param value boolean (default: True)
    auto xaxis_rangeslider_autorange(std::string const& value) -> Figure&;

    /// Sets the background color of the range slider.
    /// @param value color (default: "#fff")
    auto xaxis_rangeslider_bgcolor(std::string const& value) -> Figure&;

    /// Sets the border color of the range slider.
    /// @param value color (default: "#444")
    auto xaxis_rangeslider_bordercolor(std::string const& value) -> Figure&;

    /// Sets the border width of the range slider.
    /// @param value integer greater than or equal to 0 (default: 0)
    auto xaxis_rangeslider_borderwidth(std::string const& value) -> Figure&;

    // /// Sets the range of the range slider. If not set, defaults to the full xaxis range. If the axis `type` is "log", then you must take the log of your desired range. If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    // /// @param value list
    // auto xaxis_rangeslider_range(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// The height of the range slider as a fraction of the total plot area height.
    /// @param value number between or equal to 0 and 1 (default: 0.15)
    auto xaxis_rangeslider_thickness(int value) -> Figure&;

    /// Determines whether or not the range slider will be visible. If visible, perpendicular axes will be set to `fixedrange`
    /// @param value boolean (default: True)
    auto xaxis_rangeslider_visible(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_rangeslider_yaxis(std::string const& value) -> Figure&;

    // /// Sets the range of this axis for the rangeslider.
    // /// @param value list
    // auto xaxis_rangeslider_yaxis_range(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Determines whether or not the range of this axis in the rangeslider use the same value than in the main plot when zooming in/out. If "auto", the autorange will be used. If "fixed", the `range` is used. If "match", the current range of the corresponding y-axis on the main subplot is used.
    /// @param value enumerated , one of ( "auto" | "fixed" | "match" ) (default: "match")
    auto xaxis_rangeslider_yaxis_rangemode(std::string const& value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis changes together with the range of the corresponding axis such that the scale of pixels per unit is in a constant ratio. Both axes are still zoomable, but when you zoom one, the other will zoom the same amount, keeping a fixed midpoint. `constrain` and `constraintoward` determine how we enforce the constraint. You can chain these, ie `yaxis: {scaleanchor: "x"}, xaxis2: {scaleanchor: "y"}` but you can only link axes of the same `type`. The linked axis can have the opposite letter (to constrain the aspect ratio) or the same letter (to match scales across subplots). Loops (`yaxis: {scaleanchor: "x"}, xaxis: {scaleanchor: "y"}` or longer) are redundant and the last constraint encountered will be ignored to avoid possible inconsistent constraints via `scaleratio`. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto xaxis_scaleanchor(std::string const& value) -> Figure&;

    /// If this axis is linked to another by `scaleanchor`, this determines the pixel to unit scale ratio. For example, if this value is 10, then every unit on this axis spans 10 times the number of pixels as a unit on the linked axis. Use this for example to create an elevation profile where the vertical scale is exaggerated a fixed amount with respect to the horizontal.
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxis_scaleratio(int value) -> Figure&;

    /// If "True", even 4-digit integers are separated
    /// @param value boolean
    auto xaxis_separatethousands(std::string const& value) -> Figure&;

    /// Determines whether or not a dividers are drawn between the category levels of this axis. Only has an effect on "multicategory" axes.
    /// @param value boolean (default: True)
    auto xaxis_showdividers(std::string const& value) -> Figure&;

    /// If "all", all exponents are shown besides their significands. If "first", only the exponent of the first tick is shown. If "last", only the exponent of the last tick is shown. If "none", no exponents appear.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto xaxis_showexponent(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto xaxis_showgrid(std::string const& value) -> Figure&;

    /// Determines whether or not a line bounding this axis is drawn.
    /// @param value boolean
    auto xaxis_showline(std::string const& value) -> Figure&;

    /// Determines whether or not spikes (aka droplines) are drawn for this axis. Note: This only takes affect when hovermode = closest
    /// @param value boolean
    auto xaxis_showspikes(std::string const& value) -> Figure&;

    /// Determines whether or not the tick labels are drawn.
    /// @param value boolean (default: True)
    auto xaxis_showticklabels(std::string const& value) -> Figure&;

    /// If "all", all tick labels are displayed with a prefix. If "first", only the first tick is displayed with a prefix. If "last", only the last tick is displayed with a suffix. If "none", tick prefixes are hidden.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto xaxis_showtickprefix(std::string const& value) -> Figure&;

    /// Same as `showtickprefix` but for tick suffixes.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto xaxis_showticksuffix(std::string const& value) -> Figure&;

    /// Determines whether a x (y) axis is positioned at the "bottom" ("left") or "top" ("right") of the plotting area.
    /// @param value enumerated , one of ( "top" | "bottom" | "left" | "right" )
    auto xaxis_side(std::string const& value) -> Figure&;

    /// Sets the spike color. If undefined, will use the series color
    /// @param value color
    auto xaxis_spikecolor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "dash")
    auto xaxis_spikedash(std::string const& value) -> Figure&;

    /// Determines the drawing mode for the spike line If "toaxis", the line is drawn from the data point to the axis the series is plotted on. If "across", the line is drawn across the entire plot area, and supercedes "toaxis". If "marker", then a marker dot is drawn on the axis the series is plotted on
    /// @param value flaglist string. Any combination of "toaxis", "across", "marker" joined with a "+". Examples: "toaxis", "across", "toaxis+across", "toaxis+across+marker" (default: "toaxis")
    auto xaxis_spikemode(std::string const& value) -> Figure&;

    /// Determines whether spikelines are stuck to the cursor or to the closest datapoints.
    /// @param value enumerated , one of ( "data" | "cursor" | "hovered data" ) (default: "hovered data")
    auto xaxis_spikesnap(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 3)
    auto xaxis_spikethickness(int value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto xaxis_tick0(std::string const& value) -> Figure&;

    /// Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the tick labels vertically.
    /// @param value angle (default: "auto")
    auto xaxis_tickangle(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto xaxis_tickcolor(std::string const& value) -> Figure&;

    // /// Sets the tick font.
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_tickfont(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto xaxis_tickfont_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto xaxis_tickfont_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto xaxis_tickfont_size(int value) -> Figure&;

    /// Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto xaxis_tickformat(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto xaxis_tickformatstops(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// range ["min", "max"], where "min", "max" - dtick values which describe some zoom level, it is possible to omit "min" or "max" value by passing "null"
    // /// @param value list
    // auto xaxis_tickformatstops_dtickrange(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Determines whether or not this stop is used. If `False`, this stop is ignored even within its `dtickrange`.
    /// @param value boolean (default: True)
    auto xaxis_tickformatstops_enabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto xaxis_tickformatstops_name(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto xaxis_tickformatstops_templateitemname(std::string const& value) -> Figure&;

    /// string - dtickformat for described zoom level, the same as "tickformat"
    /// @param value string (default: "")
    auto xaxis_tickformatstops_value(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to their corresponding ticks and grid lines. Only has an effect for axes of `type` "date" When set to "period", tick labels are drawn in the middle of the period between ticks.
    /// @param value enumerated , one of ( "instant" | "period" ) (default: "instant")
    auto xaxis_ticklabelmode(std::string const& value) -> Figure&;

    /// Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The default value for inside tick labels is "hide past domain". Otherwise on "category" and "multicategory" axes the default is "allow". In other cases the default is "hide past div".
    /// @param value enumerated , one of ( "allow" | "hide past div" | "hide past domain" )
    auto xaxis_ticklabeloverflow(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to the axis Please note that top or bottom has no effect on x axes or when `ticklabelmode` is set to "period". Similarly left or right has no effect on y axes or when `ticklabelmode` is set to "period". Has no effect on "multicategory" axes or when `tickson` is set to "boundaries". When used on axes linked by `matches` or `scaleanchor`, no extra padding for inside labels would be added by autorange, so that the scales could match.
    /// @param value enumerated , one of ( "outside" | "inside" | "outside top" | "inside top" | "outside left" | "inside left" | "outside right" | "inside right" | "outside bottom" | "inside bottom" ) (default: "outside")
    auto xaxis_ticklabelposition(std::string const& value) -> Figure&;

    /// Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` "log" or "multicategory", or when `tickmode` is "array".
    /// @param value integer greater than or equal to 1 (default: 1)
    auto xaxis_ticklabelstep(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0 (default: 5)
    auto xaxis_ticklen(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto xaxis_tickmode(std::string const& value) -> Figure&;

    /// Sets a tick label prefix.
    /// @param value string (default: "")
    auto xaxis_tickprefix(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto xaxis_ticks(std::string const& value) -> Figure&;

    /// Determines where ticks and grid lines are drawn with respect to their corresponding tick labels. Only has an effect for axes of `type` "category" or "multicategory". When set to "boundaries", ticks and grid lines are drawn half a category to the left/bottom of labels.
    /// @param value enumerated , one of ( "labels" | "boundaries" ) (default: "labels")
    auto xaxis_tickson(std::string const& value) -> Figure&;

    /// Sets a tick label suffix.
    /// @param value string (default: "")
    auto xaxis_ticksuffix(std::string const& value) -> Figure&;

    // /// Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to "array". Used with `tickvals`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxis_ticktext(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto xaxis_tickvals(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0 (default: 1)
    auto xaxis_tickwidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_title(std::string const& value) -> Figure&;

    // /// Sets this axis' title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.
    // /// @param value dict containing one or more of the keys listed below.
    // auto xaxis_title_font(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto xaxis_title_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto xaxis_title_font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto xaxis_title_font_size(int value) -> Figure&;

    /// Sets the standoff distance (in px) between the axis labels and the title text The default value is a function of the axis tick labels, the title `font.size` and the axis `linewidth`. Note that the axis title position is always constrained within the margins, so the actual standoff distance is always less than the set or default value. By setting `standoff` and turning on `automargin`, plotly.js will push the margins to fit the axis title at given standoff distance.
    /// @param value number greater than or equal to 0
    auto xaxis_title_standoff(int value) -> Figure&;

    /// Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.
    /// @param value string
    auto xaxis_title_text(std::string const& value) -> Figure&;

    /// Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the traces that referenced the axis in question.
    /// @param value enumerated , one of ( "-" | "linear" | "log" | "date" | "category" | "multicategory" ) (default: "-")
    auto xaxis_type(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in axis `range`, `autorange`, and `title` if in `editable: True` configuration. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto xaxis_uirevision(std::string const& value) -> Figure&;

    /// A single toggle to hide the axis while preserving interaction like dragging. Default is True when a cheater plot is present on the axis, otherwise False
    /// @param value boolean
    auto xaxis_visible(std::string const& value) -> Figure&;

    /// Determines whether or not a line is drawn at along the 0 value of this axis. If "True", the zero line is drawn on top of the grid lines.
    /// @param value boolean
    auto xaxis_zeroline(std::string const& value) -> Figure&;

    /// Sets the line color of the zero line.
    /// @param value color (default: "#444")
    auto xaxis_zerolinecolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 1)
    auto xaxis_zerolinewidth(int value) -> Figure&;

    //=================================================================================================================
    //
    // METHODS THAT CUSTOMIZE THE Y-AXIS LAYOUT OF THE FIGURE
    //
    //=================================================================================================================

    /// If set to an opposite-letter axis id (e.g. `x2`, `y`), this axis is bound to the corresponding opposite-letter axis. If set to "free", this axis' position is determined by `position`.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxis_anchor(std::string const& value) -> Figure&;

    /// Determines whether long tick labels automatically grow the figure margins.
    /// @param value flaglist string. Any combination of "height", "width", "left", "right", "top", "bottom" joined with a "+" OR True or False. Examples: "height", "width", "height+width", "height+width+left", "True"
    auto yaxis_automargin(std::string const& value) -> Figure&;

    /// Determines whether or not the range of this axis is computed in relation to the input data. See `rangemode` for more info. If `range` is provided, then `autorange` is set to "False".
    /// @param value enumerated , one of ( True | False | "reversed" ) (default: True)
    auto yaxis_autorange(std::string const& value) -> Figure&;

    /// Using "strict" a numeric string in trace data is not converted to a number. Using "convert types" a numeric string in trace data may be treated as a number during automatic axis `type` detection. Defaults to layout.autotypenumbers.
    /// @param value enumerated , one of ( "convert types" | "strict" ) (default: "convert types")
    auto yaxis_autotypenumbers(std::string const& value) -> Figure&;

    /// Sets the calendar system to use for `range` and `tick0` if this is a date axis. This does not set the calendar for interpreting data on this axis, that's specified in the trace or via the global `layout.calendar`
    /// @param value enumerated , one of ( "chinese" | "coptic" | "discworld" | "ethiopian" | "gregorian" | "hebrew" | "islamic" | "jalali" | "julian" | "mayan" | "nanakshahi" | "nepali" | "persian" | "taiwan" | "thai" | "ummalqura" ) (default: "gregorian")
    auto yaxis_calendar(std::string const& value) -> Figure&;

    // /// Sets the order in which categories on this axis appear. Only has an effect if `categoryorder` is set to "array". Used with `categoryorder`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxis_categoryarray(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Specifies the ordering logic for the case of categorical variables. By default, plotly uses "trace", which specifies the order that is present in the data supplied. Set `categoryorder` to "category ascending" or "category descending" if order should be determined by the alphanumerical order of the category names. Set `categoryorder` to "array" to derive the ordering from the attribute `categoryarray`. If a category is not found in the `categoryarray` array, the sorting behavior for that attribute will be identical to the "trace" mode. The unspecified categories will follow the categories in `categoryarray`. Set `categoryorder` to "total ascending" or "total descending" if order should be determined by the numerical order of the values. Similarly, the order can be determined by the min, max, sum, mean or median of all the values.
    /// @param value enumerated , one of ( "trace" | "category ascending" | "category descending" | "array" | "total ascending" | "total descending" | "min ascending" | "min descending" | "max ascending" | "max descending" | "sum ascending" | "sum descending" | "mean ascending" | "mean descending" | "median ascending" | "median descending" ) (default: "trace")
    auto yaxis_categoryorder(std::string const& value) -> Figure&;

    /// Sets default for all colors associated with this axis all at once: line, font, tick, and grid colors. Grid color is lightened by blending this with the plot background Individual pieces can override this.
    /// @param value color (default: "#444")
    auto yaxis_color(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines how that happens: by increasing the "range", or by decreasing the "domain". Default is "domain" for axes containing image traces, "range" otherwise.
    /// @param value enumerated , one of ( "range" | "domain" )
    auto yaxis_constrain(std::string const& value) -> Figure&;

    /// If this axis needs to be compressed (either due to its own `scaleanchor` and `scaleratio` or those of the other axis), determines which direction we push the originally specified plot area. Options are "left", "center" (default), and "right" for x axes, and "top", "middle" (default), and "bottom" for y axes.
    /// @param value enumerated , one of ( "left" | "center" | "right" | "top" | "middle" | "bottom" )
    auto yaxis_constraintoward(std::string const& value) -> Figure&;

    /// Sets the color of the dividers Only has an effect on "multicategory" axes.
    /// @param value color (default: "#444")
    auto yaxis_dividercolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the dividers Only has an effect on "multicategory" axes.
    /// @param value number (default: 1)
    auto yaxis_dividerwidth(int value) -> Figure&;

    // /// Sets the domain of this axis (in plot fraction).
    // /// @param value list (default: [0, 1])
    // auto yaxis_domain(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto yaxis_dtick(std::string const& value) -> Figure&;

    /// Determines a formatting rule for the tick exponents. For example, consider the number 1,000,000,000. If "none", it appears as 1,000,000,000. If "e", 1e+9. If "E", 1E+9. If "power", 1x10^9 (with 9 in a super script). If "SI", 1G. If "B", 1B.
    /// @param value enumerated , one of ( "none" | "e" | "E" | "power" | "SI" | "B" ) (default: "B")
    auto yaxis_exponentformat(std::string const& value) -> Figure&;

    /// Determines whether or not this axis is zoom-able. If True, then zoom is disabled.
    /// @param value boolean
    auto yaxis_fixedrange(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto yaxis_gridcolor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto yaxis_griddash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxis_gridwidth(int value) -> Figure&;

    /// Sets the hover text formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto yaxis_hoverformat(std::string const& value) -> Figure&;

    /// Sets the layer on which this axis is displayed. If "above traces", this axis is displayed above all the subplot's traces If "below traces", this axis is displayed below all the subplot's traces, but above the grid lines. Useful when used together with scatter-like traces with `cliponaxis` set to "False" to show markers and/or text nodes above this axis.
    /// @param value enumerated , one of ( "above traces" | "below traces" ) (default: "above traces")
    auto yaxis_layer(std::string const& value) -> Figure&;

    /// Sets the axis line color.
    /// @param value color (default: "#444")
    auto yaxis_linecolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the axis line.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxis_linewidth(int value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis will match the range of the corresponding axis in data-coordinates space. Moreover, matching axes share auto-range values, category lists and histogram auto-bins. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden. Moreover, note that matching axes must have the same `type`.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxis_matches(std::string const& value) -> Figure&;

    /// Hide SI prefix for 10^n if |n| is below this number. This only has an effect when `tickformat` is "SI" or "B".
    /// @param value number greater than or equal to 0 (default: 3)
    auto yaxis_minexponent(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_minor(std::string const& value) -> Figure&;

    /// Sets the step in-between ticks on this axis. Use with `tick0`. Must be a positive number, or special strings available to "log" and "date" axes. If the axis `type` is "log", then ticks are set every 10^(n"dtick) where n is the tick number. For example, to set a tick mark at 1, 10, 100, 1000, ... set dtick to 1. To set tick marks at 1, 100, 10000, ... set dtick to 2. To set tick marks at 1, 5, 25, 125, 625, 3125, ... set dtick to log_10(5), or 0.69897000433. "log" has several special values; "L<f>", where `f` is a positive number, gives ticks linearly spaced in value (but not position). For example `tick0` = 0.1, `dtick` = "L0.5" will put ticks at 0.1, 0.6, 1.1, 1.6 etc. To show powers of 10 plus small digits between, use "D1" (all digits) or "D2" (only 2 and 5). `tick0` is ignored for "D1" and "D2". If the axis `type` is "date", then you must convert the time to milliseconds. For example, to set the interval between ticks to one day, set `dtick` to 86400000.0. "date" also has special values "M<n>" gives ticks spaced by a number of months. `n` must be a positive integer. To set ticks on the 15th of every third month, set `tick0` to "2000-01-15" and `dtick` to "M3". To set ticks every 4 years, set `dtick` to "M48"
    /// @param value number or categorical coordinate string
    auto yaxis_minor_dtick(std::string const& value) -> Figure&;

    /// Sets the color of the grid lines.
    /// @param value color (default: "#eee")
    auto yaxis_minor_gridcolor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "solid")
    auto yaxis_minor_griddash(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the grid lines.
    /// @param value number greater than or equal to 0
    auto yaxis_minor_gridwidth(int value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 5)
    auto yaxis_minor_nticks(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto yaxis_minor_showgrid(std::string const& value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto yaxis_minor_tick0(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto yaxis_minor_tickcolor(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0
    auto yaxis_minor_ticklen(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto yaxis_minor_tickmode(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto yaxis_minor_ticks(std::string const& value) -> Figure&;

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxis_minor_tickvals(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0
    auto yaxis_minor_tickwidth(int value) -> Figure&;

    /// Determines if the axis lines or/and ticks are mirrored to the opposite side of the plotting area. If "True", the axis lines are mirrored. If "ticks", the axis lines and ticks are mirrored. If "False", mirroring is disable. If "all", axis lines are mirrored on all shared-axes subplots. If "allticks", axis lines and ticks are mirrored on all shared-axes subplots.
    /// @param value enumerated , one of ( True | "ticks" | False | "all" | "allticks" )
    auto yaxis_mirror(std::string const& value) -> Figure&;

    /// Specifies the maximum number of ticks for the particular axis. The actual number of ticks will be chosen automatically to be less than or equal to `nticks`. Has an effect only if `tickmode` is set to "auto".
    /// @param value integer greater than or equal to 0 (default: 0)
    auto yaxis_nticks(std::string const& value) -> Figure&;

    /// If set a same-letter axis id, this axis is overlaid on top of the corresponding same-letter axis, with traces and axes visible for both axes. If "False", this axis does not overlay any same-letter axes. In this case, for axes with overlapping domains only the highest-numbered axis will be visible.
    /// @param value enumerated , one of ( "free" | "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxis_overlaying(std::string const& value) -> Figure&;

    /// Sets the position of this axis in the plotting space (in normalized coordinates). Only has an effect if `anchor` is set to "free".
    /// @param value number between or equal to 0 and 1 (default: 0)
    auto yaxis_position(int value) -> Figure&;

    // /// Sets the range of this axis. If the axis `type` is "log", then you must take the log of your desired range (e.g. to set the range from 1 to 100, set the range from 0 to 2). If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    // /// @param value list
    // auto yaxis_range(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto yaxis_rangebreaks(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the lower and upper bounds of this axis rangebreak. Can be used with `pattern`.
    // /// @param value list
    // auto yaxis_rangebreaks_bounds(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the size of each `values` item. The default is one day in milliseconds.
    /// @param value number greater than or equal to 0 (default: 86400000)
    auto yaxis_rangebreaks_dvalue(int value) -> Figure&;

    /// Determines whether this axis rangebreak is enabled or disabled. Please note that `rangebreaks` only work for "date" axis type.
    /// @param value boolean (default: True)
    auto yaxis_rangebreaks_enabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto yaxis_rangebreaks_name(std::string const& value) -> Figure&;

    /// Determines a pattern on the time line that generates breaks. If "day of week" - days of the week in English e.g. 'Sunday' or `sun` (matching is case-insensitive and considers only the first three characters), as well as Sunday-based integers between 0 and 6. If "hour" - hour (24-hour clock) as decimal numbers between 0 and 24. for more info. Examples: - { pattern: 'day of week', bounds: [6, 1] } or simply { bounds: ['sat', 'mon'] } breaks from Saturday to Monday (i.e. skips the weekends). - { pattern: 'hour', bounds: [17, 8] } breaks from 5pm to 8am (i.e. skips non-work hours).
    /// @param value enumerated , one of ( "day of week" | "hour" | "" )
    auto yaxis_rangebreaks_pattern(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto yaxis_rangebreaks_templateitemname(std::string const& value) -> Figure&;

    // /// Sets the coordinate values corresponding to the rangebreaks. An alternative to `bounds`. Use `dvalue` to set the size of the values along the axis.
    // /// @param value list
    // auto yaxis_rangebreaks_values(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// If "normal", the range is computed in relation to the extrema of the input data. If "tozero"`, the range extends to 0, regardless of the input data If "nonnegative", the range is non-negative, regardless of the input data. Applies only to linear axes.
    /// @param value enumerated , one of ( "normal" | "tozero" | "nonnegative" ) (default: "normal")
    auto yaxis_rangemode(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_rangeselector(std::string const& value) -> Figure&;

    /// Sets the background color of the active range selector button.
    /// @param value color
    auto yaxis_rangeselector_activecolor(std::string const& value) -> Figure&;

    /// Sets the background color of the range selector buttons.
    /// @param value color (default: "#eee")
    auto yaxis_rangeselector_bgcolor(std::string const& value) -> Figure&;

    /// Sets the color of the border enclosing the range selector.
    /// @param value color (default: "#444")
    auto yaxis_rangeselector_bordercolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the border enclosing the range selector.
    /// @param value number greater than or equal to 0 (default: 0)
    auto yaxis_rangeselector_borderwidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto yaxis_rangeselector_buttons(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the number of steps to take to update the range. Use with `step` to specify the update interval.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxis_rangeselector_count(int value) -> Figure&;

    /// Sets the text label to appear on the button.
    /// @param value string
    auto yaxis_rangeselector_label(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto yaxis_rangeselector_name(std::string const& value) -> Figure&;

    /// The unit of measurement that the `count` value will set the range by.
    /// @param value enumerated , one of ( "month" | "year" | "day" | "hour" | "minute" | "second" | "all" ) (default: "month")
    auto yaxis_rangeselector_step(std::string const& value) -> Figure&;

    /// Sets the range update mode. If "backward", the range update shifts the start of range back "count" times "step" milliseconds. If "todate", the range update shifts the start of range back to the first timestamp from "count" times "step" milliseconds back. For example, with `step` set to "year" and `count` set to "1" the range update shifts the start of the range back to January 01 of the current year. Month and year "todate" are currently available only for the built-in (Gregorian) calendar.
    /// @param value enumerated , one of ( "backward" | "todate" ) (default: "backward")
    auto yaxis_rangeselector_stepmode(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto yaxis_rangeselector_templateitemname(std::string const& value) -> Figure&;

    // /// Sets the font of the range selector button text.
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_rangeselector_font(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto yaxis_rangeselector_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto yaxis_rangeselector_font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto yaxis_rangeselector_font_size(int value) -> Figure&;

    /// Determines whether or not this range selector is visible. Note that range selectors are only available for x axes of `type` set to or auto-typed to "date".
    /// @param value boolean (default: True)
    auto yaxis_rangeselector_visible(std::string const& value) -> Figure&;

    /// Sets the x position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto yaxis_rangeselector_x(int value) -> Figure&;

    /// Sets the range selector's horizontal position anchor. This anchor binds the `x` position to the "left", "center" or "right" of the range selector.
    /// @param value enumerated , one of ( "auto" | "left" | "center" | "right" ) (default: "left")
    auto yaxis_rangeselector_xanchor(std::string const& value) -> Figure&;

    /// Sets the y position (in normalized coordinates) of the range selector.
    /// @param value number between or equal to -2 and 3
    auto yaxis_rangeselector_y(int value) -> Figure&;

    /// Sets the range selector's vertical position anchor This anchor binds the `y` position to the "top", "middle" or "bottom" of the range selector.
    /// @param value enumerated , one of ( "auto" | "top" | "middle" | "bottom" ) (default: "bottom")
    auto yaxis_rangeselector_yanchor(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_rangeslider(std::string const& value) -> Figure&;

    /// Determines whether or not the range slider range is computed in relation to the input data. If `range` is provided, then `autorange` is set to "False".
    /// @param value boolean (default: True)
    auto yaxis_rangeslider_autorange(std::string const& value) -> Figure&;

    /// Sets the background color of the range slider.
    /// @param value color (default: "#fff")
    auto yaxis_rangeslider_bgcolor(std::string const& value) -> Figure&;

    /// Sets the border color of the range slider.
    /// @param value color (default: "#444")
    auto yaxis_rangeslider_bordercolor(std::string const& value) -> Figure&;

    /// Sets the border width of the range slider.
    /// @param value integer greater than or equal to 0 (default: 0)
    auto yaxis_rangeslider_borderwidth(std::string const& value) -> Figure&;

    // /// Sets the range of the range slider. If not set, defaults to the full yaxis range. If the axis `type` is "log", then you must take the log of your desired range. If the axis `type` is "date", it should be date strings, like date data, though Date objects and unix milliseconds will be accepted and converted to strings. If the axis `type` is "category", it should be numbers, using the scale where each category is assigned a serial number from zero in the order it appears.
    // /// @param value list
    // auto yaxis_rangeslider_range(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// The height of the range slider as a fraction of the total plot area height.
    /// @param value number between or equal to 0 and 1 (default: 0.15)
    auto yaxis_rangeslider_thickness(int value) -> Figure&;

    /// Determines whether or not the range slider will be visible. If visible, perpendicular axes will be set to `fixedrange`
    /// @param value boolean (default: True)
    auto yaxis_rangeslider_visible(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_rangeslider_yaxis(std::string const& value) -> Figure&;

    // /// Sets the range of this axis for the rangeslider.
    // /// @param value list
    // auto yaxis_rangeslider_yaxis_range(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Determines whether or not the range of this axis in the rangeslider use the same value than in the main plot when zooming in/out. If "auto", the autorange will be used. If "fixed", the `range` is used. If "match", the current range of the corresponding y-axis on the main subplot is used.
    /// @param value enumerated , one of ( "auto" | "fixed" | "match" ) (default: "match")
    auto yaxis_rangeslider_yaxis_rangemode(std::string const& value) -> Figure&;

    /// If set to another axis id (e.g. `x2`, `y`), the range of this axis changes together with the range of the corresponding axis such that the scale of pixels per unit is in a constant ratio. Both axes are still zoomable, but when you zoom one, the other will zoom the same amount, keeping a fixed midpoint. `constrain` and `constraintoward` determine how we enforce the constraint. You can chain these, ie `yaxis: {scaleanchor: "x"}, yaxis2: {scaleanchor: "y"}` but you can only link axes of the same `type`. The linked axis can have the opposite letter (to constrain the aspect ratio) or the same letter (to match scales across subplots). Loops (`yaxis: {scaleanchor: "x"}, yaxis: {scaleanchor: "y"}` or longer) are redundant and the last constraint encountered will be ignored to avoid possible inconsistent constraints via `scaleratio`. Note that setting axes simultaneously in both a `scaleanchor` and a `matches` constraint is currently forbidden.
    /// @param value enumerated , one of ( "/^x([2-9]|[1-9][0-9]+)?( domain)?$/" | "/^y([2-9]|[1-9][0-9]+)?( domain)?$/" )
    auto yaxis_scaleanchor(std::string const& value) -> Figure&;

    /// If this axis is linked to another by `scaleanchor`, this determines the pixel to unit scale ratio. For example, if this value is 10, then every unit on this axis spans 10 times the number of pixels as a unit on the linked axis. Use this for example to create an elevation profile where the vertical scale is exaggerated a fixed amount with respect to the horizontal.
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxis_scaleratio(int value) -> Figure&;

    /// If "True", even 4-digit integers are separated
    /// @param value boolean
    auto yaxis_separatethousands(std::string const& value) -> Figure&;

    /// Determines whether or not a dividers are drawn between the category levels of this axis. Only has an effect on "multicategory" axes.
    /// @param value boolean (default: True)
    auto yaxis_showdividers(std::string const& value) -> Figure&;

    /// If "all", all exponents are shown besides their significands. If "first", only the exponent of the first tick is shown. If "last", only the exponent of the last tick is shown. If "none", no exponents appear.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto yaxis_showexponent(std::string const& value) -> Figure&;

    /// Determines whether or not grid lines are drawn. If "True", the grid lines are drawn at every tick mark.
    /// @param value boolean
    auto yaxis_showgrid(std::string const& value) -> Figure&;

    /// Determines whether or not a line bounding this axis is drawn.
    /// @param value boolean
    auto yaxis_showline(std::string const& value) -> Figure&;

    /// Determines whether or not spikes (aka droplines) are drawn for this axis. Note: This only takes affect when hovermode = closest
    /// @param value boolean
    auto yaxis_showspikes(std::string const& value) -> Figure&;

    /// Determines whether or not the tick labels are drawn.
    /// @param value boolean (default: True)
    auto yaxis_showticklabels(std::string const& value) -> Figure&;

    /// If "all", all tick labels are displayed with a prefix. If "first", only the first tick is displayed with a prefix. If "last", only the last tick is displayed with a suffix. If "none", tick prefixes are hidden.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto yaxis_showtickprefix(std::string const& value) -> Figure&;

    /// Same as `showtickprefix` but for tick suffixes.
    /// @param value enumerated , one of ( "all" | "first" | "last" | "none" ) (default: "all")
    auto yaxis_showticksuffix(std::string const& value) -> Figure&;

    /// Determines whether a x (y) axis is positioned at the "bottom" ("left") or "top" ("right") of the plotting area.
    /// @param value enumerated , one of ( "top" | "bottom" | "left" | "right" )
    auto yaxis_side(std::string const& value) -> Figure&;

    /// Sets the spike color. If undefined, will use the series color
    /// @param value color
    auto yaxis_spikecolor(std::string const& value) -> Figure&;

    /// Sets the dash style of lines. Set to a dash type string ("solid", "dot", "dash", "longdash", "dashdot", or "longdashdot") or a dash length list in px (eg "5px,10px,2px,2px").
    /// @param value string (default: "dash")
    auto yaxis_spikedash(std::string const& value) -> Figure&;

    /// Determines the drawing mode for the spike line If "toaxis", the line is drawn from the data point to the axis the series is plotted on. If "across", the line is drawn across the entire plot area, and supercedes "toaxis". If "marker", then a marker dot is drawn on the axis the series is plotted on
    /// @param value flaglist string. Any combination of "toaxis", "across", "marker" joined with a "+". Examples: "toaxis", "across", "toaxis+across", "toaxis+across+marker" (default: "toaxis")
    auto yaxis_spikemode(std::string const& value) -> Figure&;

    /// Determines whether spikelines are stuck to the cursor or to the closest datapoints.
    /// @param value enumerated , one of ( "data" | "cursor" | "hovered data" ) (default: "hovered data")
    auto yaxis_spikesnap(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 3)
    auto yaxis_spikethickness(int value) -> Figure&;

    /// Sets the placement of the first tick on this axis. Use with `dtick`. If the axis `type` is "log", then you must take the log of your starting tick (e.g. to set the starting tick to 100, set the `tick0` to 2) except when `dtick`="L<f>" (see `dtick` for more info). If the axis `type` is "date", it should be a date string, like date data. If the axis `type` is "category", it should be a number, using the scale where each category is assigned a serial number from zero in the order it appears.
    /// @param value number or categorical coordinate string
    auto yaxis_tick0(std::string const& value) -> Figure&;

    /// Sets the angle of the tick labels with respect to the horizontal. For example, a `tickangle` of -90 draws the tick labels vertically.
    /// @param value angle (default: "auto")
    auto yaxis_tickangle(std::string const& value) -> Figure&;

    /// Sets the tick color.
    /// @param value color (default: "#444")
    auto yaxis_tickcolor(std::string const& value) -> Figure&;

    // /// Sets the tick font.
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_tickfont(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto yaxis_tickfont_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto yaxis_tickfont_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto yaxis_tickfont_size(int value) -> Figure&;

    /// Sets the tick label formatting rule using d3 formatting mini-languages which are very similar to those in Python. For numbers, see: https://github.com/d3/d3-format/tree/v1.4.5#d3-format. And for dates see: https://github.com/d3/d3-time-format/tree/v2.2.3#locale_format. We add two items to d3's date formatter: "%h" for half of the year as a decimal number as well as "%{n}f" for fractional seconds with n digits. For example, "2016-10-13 09:15:23.456" with tickformat "%H~%M~%S.%2f" would display "09~15~23.46"
    /// @param value string (default: "")
    auto yaxis_tickformat(std::string const& value) -> Figure&;

    // /// Missing documentation!
    // /// @param value list of dict where each dict has one or more of the keys listed below.
    // auto yaxis_tickformatstops(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// range ["min", "max"], where "min", "max" - dtick values which describe some zoom level, it is possible to omit "min" or "max" value by passing "null"
    // /// @param value list
    // auto yaxis_tickformatstops_dtickrange(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Determines whether or not this stop is used. If `False`, this stop is ignored even within its `dtickrange`.
    /// @param value boolean (default: True)
    auto yaxis_tickformatstops_enabled(std::string const& value) -> Figure&;

    /// When used in a template, named items are created in the output figure in addition to any items the figure already has in this array. You can modify these items in the output figure by making your own item with `templateitemname` matching this `name` alongside your modifications (including `visible: False` or `enabled: False` to hide it). Has no effect outside of a template.
    /// @param value string
    auto yaxis_tickformatstops_name(std::string const& value) -> Figure&;

    /// Used to refer to a named item in this array in the template. Named items from the template will be created even without a matching item in the input figure, but you can modify one by making an item with `templateitemname` matching its `name`, alongside your modifications (including `visible: False` or `enabled: False` to hide it). If there is no template or no matching item, this item will be hidden unless you explicitly show it with `visible: True`.
    /// @param value string
    auto yaxis_tickformatstops_templateitemname(std::string const& value) -> Figure&;

    /// string - dtickformat for described zoom level, the same as "tickformat"
    /// @param value string (default: "")
    auto yaxis_tickformatstops_value(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to their corresponding ticks and grid lines. Only has an effect for axes of `type` "date" When set to "period", tick labels are drawn in the middle of the period between ticks.
    /// @param value enumerated , one of ( "instant" | "period" ) (default: "instant")
    auto yaxis_ticklabelmode(std::string const& value) -> Figure&;

    /// Determines how we handle tick labels that would overflow either the graph div or the domain of the axis. The default value for inside tick labels is "hide past domain". Otherwise on "category" and "multicategory" axes the default is "allow". In other cases the default is "hide past div".
    /// @param value enumerated , one of ( "allow" | "hide past div" | "hide past domain" )
    auto yaxis_ticklabeloverflow(std::string const& value) -> Figure&;

    /// Determines where tick labels are drawn with respect to the axis Please note that top or bottom has no effect on x axes or when `ticklabelmode` is set to "period". Similarly left or right has no effect on y axes or when `ticklabelmode` is set to "period". Has no effect on "multicategory" axes or when `tickson` is set to "boundaries". When used on axes linked by `matches` or `scaleanchor`, no extra padding for inside labels would be added by autorange, so that the scales could match.
    /// @param value enumerated , one of ( "outside" | "inside" | "outside top" | "inside top" | "outside left" | "inside left" | "outside right" | "inside right" | "outside bottom" | "inside bottom" ) (default: "outside")
    auto yaxis_ticklabelposition(std::string const& value) -> Figure&;

    /// Sets the spacing between tick labels as compared to the spacing between ticks. A value of 1 (default) means each tick gets a label. A value of 2 means shows every 2nd label. A larger value n means only every nth tick is labeled. `tick0` determines which labels are shown. Not implemented for axes with `type` "log" or "multicategory", or when `tickmode` is "array".
    /// @param value integer greater than or equal to 1 (default: 1)
    auto yaxis_ticklabelstep(std::string const& value) -> Figure&;

    /// Sets the tick length (in px).
    /// @param value number greater than or equal to 0 (default: 5)
    auto yaxis_ticklen(int value) -> Figure&;

    /// Sets the tick mode for this axis. If "auto", the number of ticks is set via `nticks`. If "linear", the placement of the ticks is determined by a starting position `tick0` and a tick step `dtick` ("linear" is the default value if `tick0` and `dtick` are provided). If "array", the placement of the ticks is set via `tickvals` and the tick text is `ticktext`. ("array" is the default value if `tickvals` is provided).
    /// @param value enumerated , one of ( "auto" | "linear" | "array" )
    auto yaxis_tickmode(std::string const& value) -> Figure&;

    /// Sets a tick label prefix.
    /// @param value string (default: "")
    auto yaxis_tickprefix(std::string const& value) -> Figure&;

    /// Determines whether ticks are drawn or not. If "", this axis' ticks are not drawn. If "outside" ("inside"), this axis' are drawn outside (inside) the axis lines.
    /// @param value enumerated , one of ( "outside" | "inside" | "" )
    auto yaxis_ticks(std::string const& value) -> Figure&;

    /// Determines where ticks and grid lines are drawn with respect to their corresponding tick labels. Only has an effect for axes of `type` "category" or "multicategory". When set to "boundaries", ticks and grid lines are drawn half a category to the left/bottom of labels.
    /// @param value enumerated , one of ( "labels" | "boundaries" ) (default: "labels")
    auto yaxis_tickson(std::string const& value) -> Figure&;

    /// Sets a tick label suffix.
    /// @param value string (default: "")
    auto yaxis_ticksuffix(std::string const& value) -> Figure&;

    // /// Sets the text displayed at the ticks position via `tickvals`. Only has an effect if `tickmode` is set to "array". Used with `tickvals`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxis_ticktext(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    // /// Sets the values at which ticks on this axis appear. Only has an effect if `tickmode` is set to "array". Used with `ticktext`.
    // /// @param value list, numpy array, or Pandas series of numbers, strings, or datetimes.
    // auto yaxis_tickvals(std::string const& value) -> Figure&; // All methods that set a list currently not implemented!

    /// Sets the tick width (in px).
    /// @param value number greater than or equal to 0 (default: 1)
    auto yaxis_tickwidth(int value) -> Figure&;

    // /// Missing documentation!
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_title(std::string const& value) -> Figure&;

    // /// Sets this axis' title font. Note that the title's font used to be customized by the now deprecated `titlefont` attribute.
    // /// @param value dict containing one or more of the keys listed below.
    // auto yaxis_title_font(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value color
    auto yaxis_title_font_color(std::string const& value) -> Figure&;

    /// HTML font family - the typeface that will be applied by the web browser. The web browser will only be able to apply a font if it is available on the system which it operates. Provide multiple font families, separated by commas, to indicate the preference in which to apply fonts if they aren't available on the system. The Chart Studio Cloud (at https://chart-studio.plotly.com or on-premise) generates images on a server, where only a select number of fonts are installed and supported. These include "Arial", "Balto", "Courier New", "Droid Sans",, "Droid Serif", "Droid Sans Mono", "Gravitas One", "Old Standard TT", "Open Sans", "Overpass", "PT Sans Narrow", "Raleway", "Times New Roman".
    /// @param value string
    auto yaxis_title_font_family(std::string const& value) -> Figure&;

    /// Missing documentation!
    /// @param value number greater than or equal to 1
    auto yaxis_title_font_size(int value) -> Figure&;

    /// Sets the standoff distance (in px) between the axis labels and the title text The default value is a function of the axis tick labels, the title `font.size` and the axis `linewidth`. Note that the axis title position is always constrained within the margins, so the actual standoff distance is always less than the set or default value. By setting `standoff` and turning on `automargin`, plotly.js will push the margins to fit the axis title at given standoff distance.
    /// @param value number greater than or equal to 0
    auto yaxis_title_standoff(int value) -> Figure&;

    /// Sets the title of this axis. Note that before the existence of `title.text`, the title's contents used to be defined as the `title` attribute itself. This behavior has been deprecated.
    /// @param value string
    auto yaxis_title_text(std::string const& value) -> Figure&;

    /// Sets the axis type. By default, plotly attempts to determined the axis type by looking into the data of the traces that referenced the axis in question.
    /// @param value enumerated , one of ( "-" | "linear" | "log" | "date" | "category" | "multicategory" ) (default: "-")
    auto yaxis_type(std::string const& value) -> Figure&;

    /// Controls persistence of user-driven changes in axis `range`, `autorange`, and `title` if in `editable: True` configuration. Defaults to `layout.uirevision`.
    /// @param value number or categorical coordinate string
    auto yaxis_uirevision(std::string const& value) -> Figure&;

    /// A single toggle to hide the axis while preserving interaction like dragging. Default is True when a cheater plot is present on the axis, otherwise False
    /// @param value boolean
    auto yaxis_visible(std::string const& value) -> Figure&;

    /// Determines whether or not a line is drawn at along the 0 value of this axis. If "True", the zero line is drawn on top of the grid lines.
    /// @param value boolean
    auto yaxis_zeroline(std::string const& value) -> Figure&;

    /// Sets the line color of the zero line.
    /// @param value color (default: "#444")
    auto yaxis_zerolinecolor(std::string const& value) -> Figure&;

    /// Sets the width (in px) of the zero line.
    /// @param value number (default: 1)
    auto yaxis_zerolinewidth(int value) -> Figure&;

private:
    py::object fig;
    py::dict layout;
    py::dict xaxis;
    py::dict yaxis;
};

} // namespace reaktplot
