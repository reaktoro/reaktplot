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

#include "Figure.hpp"

// reaktplot includes
#include <reaktplot/Constants.hpp>
#include <reaktplot/Default.hpp>
#include <reaktplot/Plotly.hpp>

#include <iostream>

namespace reaktplot {

Figure::Figure()
: fig(Plotly::Figure())
{
}

auto Figure::show() const -> void
{
    fig.attr("update_layout")(layout);
    fig.attr("update_xaxes")(xaxis);
    fig.attr("update_yaxes")(yaxis);
    fig.attr("show")();
}

auto Figure::save(std::string const& filename, int width, int height, double scale) const -> void
{
    using namespace pybind11::literals;
    fig.attr("update_layout")(layout);
    fig.attr("update_xaxes")(xaxis);
    fig.attr("update_yaxes")(yaxis);
    fig.attr("write_image")(filename, "width"_a=width, "height"_a=height, "scale"_a=scale);
}

template<typename L, typename R>
auto createRange(L const& l, R const& r)
{
    py::list lst;
    lst.append(l);
    lst.append(r);
    return lst;
}

// auto Figure::titleSpecs(std::string const& value)                        -> Figure& { layout["title"] = value; return *this; }
// auto Figure::titleFontSpecs(std::string const& value)                    -> Figure& { layout["title_font"] = value; return *this; }
auto Figure::titleFontColor(std::string const& value)                       -> Figure& { layout["title_font_color"] = value; return *this; }
auto Figure::titleFontFamily(std::string const& value)                      -> Figure& { layout["title_font_family"] = value; return *this; }
auto Figure::titleFontSize(int value)                                       -> Figure& { layout["title_font_size"] = value; return *this; }
// auto Figure::titlePaddingSpecs(std::string const& value)                 -> Figure& { layout["title_pad"] = value; return *this; }
auto Figure::titlePaddingBottom(int value)                                  -> Figure& { layout["title_pad_b"] = value; return *this; }
auto Figure::titlePaddingLeft(int value)                                    -> Figure& { layout["title_pad_l"] = value; return *this; }
auto Figure::titlePaddingRight(int value)                                   -> Figure& { layout["title_pad_r"] = value; return *this; }
auto Figure::titlePaddingTop(int value)                                     -> Figure& { layout["title_pad_t"] = value; return *this; }
auto Figure::titleText(std::string const& value)                            -> Figure& { layout["title_text"] = value; return *this; }
auto Figure::titleX(double value)                                           -> Figure& { layout["title_x"] = value; return *this; }
auto Figure::titleXanchor(std::string const& value)                         -> Figure& { layout["title_xanchor"] = value; return *this; }
auto Figure::titleXref(std::string const& value)                            -> Figure& { layout["title_xref"] = value; return *this; }
auto Figure::titleY(double value)                                           -> Figure& { layout["title_y"] = value; return *this; }
auto Figure::titleYanchor(std::string const& value)                         -> Figure& { layout["title_yanchor"] = value; return *this; }
auto Figure::titleYref(std::string const& value)                            -> Figure& { layout["title_yref"] = value; return *this; }
auto Figure::legendShow(bool value)                                         -> Figure& { layout["showlegend"] = value; return *this; }
// auto Figure::legendSpecs(std::string const& value)                       -> Figure& { layout["legend"] = value; return *this; }
auto Figure::legendBackgroundColor(std::string const& value)                -> Figure& { layout["legend_bgcolor"] = value; return *this; }
auto Figure::legendBorderColor(std::string const& value)                    -> Figure& { layout["legend_bordercolor"] = value; return *this; }
auto Figure::legendBorderWidth(int value)                                   -> Figure& { layout["legend_borderwidth"] = value; return *this; }
// auto Figure::legendFontSpecs(std::string const& value)                   -> Figure& { layout["legend_font"] = value; return *this; }
auto Figure::legendFontColor(std::string const& value)                      -> Figure& { layout["legend_font_color"] = value; return *this; }
auto Figure::legendFontFamily(std::string const& value)                     -> Figure& { layout["legend_font_family"] = value; return *this; }
auto Figure::legendFontSize(int value)                                      -> Figure& { layout["legend_font_size"] = value; return *this; }
auto Figure::legendGroupClick(std::string const& value)                     -> Figure& { layout["legend_groupclick"] = value; return *this; }
// auto Figure::legendGroupTitleFontSpecs(std::string const& value)         -> Figure& { layout["legend_grouptitlefont"] = value; return *this; }
auto Figure::legendGroupTitleFontColor(std::string const& value)            -> Figure& { layout["legend_grouptitlefont_color"] = value; return *this; }
auto Figure::legendGroupTitleFontFamily(std::string const& value)           -> Figure& { layout["legend_grouptitlefont_family"] = value; return *this; }
auto Figure::legendGroupTitleFontSize(int value)                            -> Figure& { layout["legend_grouptitlefont_size"] = value; return *this; }
auto Figure::legendItemClick(std::string const& value)                      -> Figure& { layout["legend_itemclick"] = value; return *this; }
auto Figure::legendItemDoubleClick(std::string const& value)                -> Figure& { layout["legend_itemdoubleclick"] = value; return *this; }
auto Figure::legendItemSizing(std::string const& value)                     -> Figure& { layout["legend_itemsizing"] = value; return *this; }
auto Figure::legendItemWidth(int value)                                     -> Figure& { layout["legend_itemwidth"] = value; return *this; }
auto Figure::legendOrientation(std::string const& value)                    -> Figure& { layout["legend_orientation"] = value; return *this; }
// auto Figure::legendTitleSpecs(std::string const& value)                  -> Figure& { layout["legend_title"] = value; return *this; }
// auto Figure::legendTitleFontSpecs(std::string const& value)              -> Figure& { layout["legend_title_font"] = value; return *this; }
auto Figure::legendTitleFontColor(std::string const& value)                 -> Figure& { layout["legend_title_font_color"] = value; return *this; }
auto Figure::legendTitleFontFamily(std::string const& value)                -> Figure& { layout["legend_title_font_family"] = value; return *this; }
auto Figure::legendTitleFontSize(int value)                                 -> Figure& { layout["legend_title_font_size"] = value; return *this; }
auto Figure::legendTitleSide(std::string const& value)                      -> Figure& { layout["legend_title_side"] = value; return *this; }
auto Figure::legendTitleText(std::string const& value)                      -> Figure& { layout["legend_title_text"] = value; return *this; }
auto Figure::legendTraceGroupGap(int value)                                 -> Figure& { layout["legend_tracegroupgap"] = value; return *this; }
auto Figure::legendTraceOrder(std::string const& value)                     -> Figure& { layout["legend_traceorder"] = value; return *this; }
auto Figure::legendUirevision(std::string const& value)                     -> Figure& { layout["legend_uirevision"] = value; return *this; }
auto Figure::legendValign(std::string const& value)                         -> Figure& { layout["legend_valign"] = value; return *this; }
auto Figure::legendX(double value)                                          -> Figure& { layout["legend_x"] = value; return *this; }
auto Figure::legendXanchor(std::string const& value)                        -> Figure& { layout["legend_xanchor"] = value; return *this; }
auto Figure::legendY(double value)                                          -> Figure& { layout["legend_y"] = value; return *this; }
auto Figure::legendYanchor(std::string const& value)                        -> Figure& { layout["legend_yanchor"] = value; return *this; }
// auto Figure::marginSpecs(std::string const& value)                       -> Figure& { layout["margin"] = value; return *this; }
auto Figure::marginAutoExpand(bool value)                                   -> Figure& { layout["margin_autoexpand"] = value; return *this; }
auto Figure::marginBottom(int value)                                        -> Figure& { layout["margin_b"] = value; return *this; }
auto Figure::marginLeft(int value)                                          -> Figure& { layout["margin_l"] = value; return *this; }
auto Figure::marginPadding(int value)                                       -> Figure& { layout["margin_pad"] = value; return *this; }
auto Figure::marginRight(int value)                                         -> Figure& { layout["margin_r"] = value; return *this; }
auto Figure::marginTop(int value)                                           -> Figure& { layout["margin_t"] = value; return *this; }
auto Figure::autosize(bool value)                                           -> Figure& { layout["autosize"] = value; return *this; }
auto Figure::width(int value)                                               -> Figure& { layout["width"] = value; return *this; }
auto Figure::height(int value)                                              -> Figure& { layout["height"] = value; return *this; }
// auto Figure::fontSpecs(std::string const& value)                         -> Figure& { layout["font"] = value; return *this; }
auto Figure::fontColor(std::string const& value)                            -> Figure& { layout["font_color"] = value; return *this; }
auto Figure::fontFamily(std::string const& value)                           -> Figure& { layout["font_family"] = value; return *this; }
auto Figure::fontSize(int value)                                            -> Figure& { layout["font_size"] = value; return *this; }
// auto Figure::uniformTextSpecs(std::string const& value)                  -> Figure& { layout["uniformtext"] = value; return *this; }
auto Figure::uniformTextMinSize(int value)                                  -> Figure& { layout["uniformtext_minsize"] = value; return *this; }
auto Figure::uniformTextMode(std::string const& value)                      -> Figure& { layout["uniformtext_mode"] = value; return *this; }
auto Figure::separators(std::string const& value)                           -> Figure& { layout["separators"] = value; return *this; }
auto Figure::paperBackgroundColor(std::string const& value)                 -> Figure& { layout["paper_bgcolor"] = value; return *this; }
auto Figure::plotBackgroundColor(std::string const& value)                  -> Figure& { layout["plot_bgcolor"] = value; return *this; }
auto Figure::autoTypeNumbers(std::string const& value)                      -> Figure& { layout["autotypenumbers"] = value; return *this; }
// auto Figure::colorScaleSpecs(std::string const& value)                   -> Figure& { layout["colorscale"] = value; return *this; }
auto Figure::colorScaleDiverging(std::string const& value)                  -> Figure& { layout["colorscale_diverging"] = value; return *this; }
auto Figure::colorScaleSequential(std::string const& value)                 -> Figure& { layout["colorscale_sequential"] = value; return *this; }
auto Figure::colorScaleSequentialminus(std::string const& value)            -> Figure& { layout["colorscale_sequentialminus"] = value; return *this; }
auto Figure::colorway(std::vector<std::string> const& value)                -> Figure& { layout["colorway"] = value; return *this; }
// auto Figure::modebarSpecs(std::string const& value)                      -> Figure& { layout["modebar"] = value; return *this; }
auto Figure::modebarActiveColor(std::string const& value)                   -> Figure& { layout["modebar_activecolor"] = value; return *this; }
auto Figure::modebarAdd(std::string const& value)                           -> Figure& { layout["modebar_add"] = value; return *this; }
auto Figure::modebarBackgroundColor(std::string const& value)               -> Figure& { layout["modebar_bgcolor"] = value; return *this; }
auto Figure::modebarColor(std::string const& value)                         -> Figure& { layout["modebar_color"] = value; return *this; }
auto Figure::modebarOrientation(std::string const& value)                   -> Figure& { layout["modebar_orientation"] = value; return *this; }
auto Figure::modebarRemove(std::string const& value)                        -> Figure& { layout["modebar_remove"] = value; return *this; }
auto Figure::modebarUirevision(std::string const& value)                    -> Figure& { layout["modebar_uirevision"] = value; return *this; }
auto Figure::hoverMode(std::string const& value)                            -> Figure& { layout["hovermode"] = value; return *this; }
auto Figure::clickMode(std::string const& value)                            -> Figure& { layout["clickmode"] = value; return *this; }
auto Figure::dragMode(std::string const& value)                             -> Figure& { layout["dragmode"] = value; return *this; }
auto Figure::selectDirection(std::string const& value)                      -> Figure& { layout["selectdirection"] = value; return *this; }
// auto Figure::activeSelectionSpecs(std::string const& value)              -> Figure& { layout["activeselection"] = value; return *this; }
auto Figure::activeSelectionFillColor(std::string const& value)             -> Figure& { layout["activeselection_fillcolor"] = value; return *this; }
auto Figure::activeSelectionOpacity(double value)                           -> Figure& { layout["activeselection_opacity"] = value; return *this; }
// auto Figure::newSelectionSpecs(std::string const& value)                 -> Figure& { layout["newselection"] = value; return *this; }
// auto Figure::newSelectionLineSpecs(std::string const& value)             -> Figure& { layout["newselection_line"] = value; return *this; }
auto Figure::newSelectionLineColor(std::string const& value)                -> Figure& { layout["newselection_line_color"] = value; return *this; }
auto Figure::newSelectionLineDash(std::string const& value)                 -> Figure& { layout["newselection_line_dash"] = value; return *this; }
auto Figure::newSelectionLineWidth(int value)                               -> Figure& { layout["newselection_line_width"] = value; return *this; }
auto Figure::newSelectionMode(std::string const& value)                     -> Figure& { layout["newselection_mode"] = value; return *this; }
auto Figure::hoverDistance(std::string const& value)                        -> Figure& { layout["hoverdistance"] = value; return *this; }
auto Figure::spikeDistance(std::string const& value)                        -> Figure& { layout["spikedistance"] = value; return *this; }
// auto Figure::hoverLabelSpecs(std::string const& value)                   -> Figure& { layout["hoverlabel"] = value; return *this; }
auto Figure::hoverLabelAlign(std::string const& value)                      -> Figure& { layout["hoverlabel_align"] = value; return *this; }
auto Figure::hoverLabelBackgroundColor(std::string const& value)            -> Figure& { layout["hoverlabel_bgcolor"] = value; return *this; }
auto Figure::hoverLabelBorderColor(std::string const& value)                -> Figure& { layout["hoverlabel_bordercolor"] = value; return *this; }
// auto Figure::hoverLabelFontSpecs(std::string const& value)               -> Figure& { layout["hoverlabel_font"] = value; return *this; }
auto Figure::hoverLabelFontColor(std::string const& value)                  -> Figure& { layout["hoverlabel_font_color"] = value; return *this; }
auto Figure::hoverLabelFontFamily(std::string const& value)                 -> Figure& { layout["hoverlabel_font_family"] = value; return *this; }
auto Figure::hoverLabelFontSize(int value)                                  -> Figure& { layout["hoverlabel_font_size"] = value; return *this; }
// auto Figure::hoverLabelGroupTitleFontSpecs(std::string const& value)     -> Figure& { layout["hoverlabel_grouptitlefont"] = value; return *this; }
auto Figure::hoverLabelGroupTitleFontColor(std::string const& value)        -> Figure& { layout["hoverlabel_grouptitlefont_color"] = value; return *this; }
auto Figure::hoverLabelGroupTitleFontFamily(std::string const& value)       -> Figure& { layout["hoverlabel_grouptitlefont_family"] = value; return *this; }
auto Figure::hoverLabelGroupTitleFontSize(int value)                        -> Figure& { layout["hoverlabel_grouptitlefont_size"] = value; return *this; }
auto Figure::hoverLabelNamelength(std::string const& value)                 -> Figure& { layout["hoverlabel_namelength"] = value; return *this; }
// auto Figure::transitionSpecs(std::string const& value)                   -> Figure& { layout["transition"] = value; return *this; }
auto Figure::transitionDuration(int value)                                  -> Figure& { layout["transition_duration"] = value; return *this; }
auto Figure::transitionEasing(std::string const& value)                     -> Figure& { layout["transition_easing"] = value; return *this; }
auto Figure::transitionOrdering(std::string const& value)                   -> Figure& { layout["transition_ordering"] = value; return *this; }
auto Figure::dataRevision(std::string const& value)                         -> Figure& { layout["datarevision"] = value; return *this; }
auto Figure::uiRevision(std::string const& value)                           -> Figure& { layout["uirevision"] = value; return *this; }
auto Figure::editRevision(std::string const& value)                         -> Figure& { layout["editrevision"] = value; return *this; }
auto Figure::selectionRevision(std::string const& value)                    -> Figure& { layout["selectionrevision"] = value; return *this; }
// auto templateSpecs(std::string const& value)                             -> Figure&; { layout["template"] = value; return *this; }
auto Figure::meta(std::string const& value)                                 -> Figure& { layout["meta"] = value; return *this; }
auto Figure::computed(std::string const& value)                             -> Figure& { layout["computed"] = value; return *this; }
// auto Figure::gridSpecs(std::string const& value)                         -> Figure& { layout["grid"] = value; return *this; }
auto Figure::gridColumns(std::string const& value)                          -> Figure& { layout["grid_columns"] = value; return *this; }
// auto Figure::gridDomainSpecs(std::string const& value)                   -> Figure& { layout["grid_domain"] = value; return *this; }
auto Figure::gridDomainX(std::string const& value)                          -> Figure& { layout["grid_domain_x"] = value; return *this; }
auto Figure::gridDomainY(std::string const& value)                          -> Figure& { layout["grid_domain_y"] = value; return *this; }
auto Figure::gridPattern(std::string const& value)                          -> Figure& { layout["grid_pattern"] = value; return *this; }
auto Figure::gridRoworder(std::string const& value)                         -> Figure& { layout["grid_roworder"] = value; return *this; }
auto Figure::gridRows(std::string const& value)                             -> Figure& { layout["grid_rows"] = value; return *this; }
auto Figure::gridSubplots(std::string const& value)                         -> Figure& { layout["grid_subplots"] = value; return *this; }
auto Figure::gridXaxes(std::string const& value)                            -> Figure& { layout["grid_xaxes"] = value; return *this; }
auto Figure::gridXgap(double value)                                         -> Figure& { layout["grid_xgap"] = value; return *this; }
auto Figure::gridXside(std::string const& value)                            -> Figure& { layout["grid_xside"] = value; return *this; }
auto Figure::gridYaxes(std::string const& value)                            -> Figure& { layout["grid_yaxes"] = value; return *this; }
auto Figure::gridYgap(double value)                                         -> Figure& { layout["grid_ygap"] = value; return *this; }
auto Figure::gridYside(std::string const& value)                            -> Figure& { layout["grid_yside"] = value; return *this; }
auto Figure::calendar(std::string const& value)                             -> Figure& { layout["calendar"] = value; return *this; }
// auto Figure::newShapeSpecs(std::string const& value)                     -> Figure& { layout["newshape"] = value; return *this; }
auto Figure::newShapeDrawdirection(std::string const& value)                -> Figure& { layout["newshape_drawdirection"] = value; return *this; }
auto Figure::newShapeFillColor(std::string const& value)                    -> Figure& { layout["newshape_fillcolor"] = value; return *this; }
auto Figure::newShapeFillrule(std::string const& value)                     -> Figure& { layout["newshape_fillrule"] = value; return *this; }
auto Figure::newShapeLayer(std::string const& value)                        -> Figure& { layout["newshape_layer"] = value; return *this; }
// auto Figure::newShapeLineSpecs(std::string const& value)                 -> Figure& { layout["newshape_line"] = value; return *this; }
auto Figure::newShapeLineColor(std::string const& value)                    -> Figure& { layout["newshape_line_color"] = value; return *this; }
auto Figure::newShapeLineDash(std::string const& value)                     -> Figure& { layout["newshape_line_dash"] = value; return *this; }
auto Figure::newShapeLineWidth(int value)                                   -> Figure& { layout["newshape_line_width"] = value; return *this; }
auto Figure::newShapeOpacity(double value)                                  -> Figure& { layout["newshape_opacity"] = value; return *this; }
// auto Figure::activeShapeSpecs(std::string const& value)                  -> Figure& { layout["activeshape"] = value; return *this; }
auto Figure::activeShapeFillColor(std::string const& value)                 -> Figure& { layout["activeshape_fillcolor"] = value; return *this; }
auto Figure::activeShapeOpacity(double value)                               -> Figure& { layout["activeshape_opacity"] = value; return *this; }
auto Figure::selections(std::string const& value)                           -> Figure& { layout["selections"] = value; return *this; }
// auto Figure::selectionsLineSpecs(std::string const& value)               -> Figure& { layout["selections_line"] = value; return *this; }
auto Figure::selectionsLineColor(std::string const& value)                  -> Figure& { layout["selections_line_color"] = value; return *this; }
auto Figure::selectionsLineDash(std::string const& value)                   -> Figure& { layout["selections_line_dash"] = value; return *this; }
auto Figure::selectionsLineWidth(int value)                                 -> Figure& { layout["selections_line_width"] = value; return *this; }
auto Figure::selectionsName(std::string const& value)                       -> Figure& { layout["selections_name"] = value; return *this; }
auto Figure::selectionsOpacity(double value)                                -> Figure& { layout["selections_opacity"] = value; return *this; }
auto Figure::selectionsPath(std::string const& value)                       -> Figure& { layout["selections_path"] = value; return *this; }
auto Figure::selectionsTemplateItemName(std::string const& value)           -> Figure& { layout["selections_templateitemname"] = value; return *this; }
auto Figure::selectionsType(std::string const& value)                       -> Figure& { layout["selections_type"] = value; return *this; }
auto Figure::selectionsX0(std::string const& value)                         -> Figure& { layout["selections_x0"] = value; return *this; }
auto Figure::selectionsX1(std::string const& value)                         -> Figure& { layout["selections_x1"] = value; return *this; }
auto Figure::selectionsXref(std::string const& value)                       -> Figure& { layout["selections_xref"] = value; return *this; }
auto Figure::selectionsY0(std::string const& value)                         -> Figure& { layout["selections_y0"] = value; return *this; }
auto Figure::selectionsY1(std::string const& value)                         -> Figure& { layout["selections_y1"] = value; return *this; }
auto Figure::selectionsYref(std::string const& value)                       -> Figure& { layout["selections_yref"] = value; return *this; }
auto Figure::hideSources(bool value)                                        -> Figure& { layout["hidesources"] = value; return *this; }
auto Figure::pieExtendColors(bool value)                                    -> Figure& { layout["extendpiecolors"] = value; return *this; }
auto Figure::hiddenLabels(std::string const& value)                         -> Figure& { layout["hiddenlabels"] = value; return *this; }
auto Figure::pieColorway(std::vector<std::string> const& value)             -> Figure& { layout["piecolorway"] = value; return *this; }
auto Figure::boxGap(double value)                                           -> Figure& { layout["boxgap"] = value; return *this; }
auto Figure::boxGroupGap(double value)                                      -> Figure& { layout["boxgroupgap"] = value; return *this; }
auto Figure::boxMode(std::string const& value)                              -> Figure& { layout["boxmode"] = value; return *this; }
auto Figure::violinGap(double value)                                        -> Figure& { layout["violingap"] = value; return *this; }
auto Figure::violinGroupGap(double value)                                   -> Figure& { layout["violingroupgap"] = value; return *this; }
auto Figure::violinMode(std::string const& value)                           -> Figure& { layout["violinmode"] = value; return *this; }
auto Figure::barGroupGap(double value)                                      -> Figure& { layout["bargroupgap"] = value; return *this; }
auto Figure::barMode(std::string const& value)                              -> Figure& { layout["barmode"] = value; return *this; }
auto Figure::barNorm(std::string const& value)                              -> Figure& { layout["barnorm"] = value; return *this; }
auto Figure::barGap(double value)                                           -> Figure& { layout["bargap"] = value; return *this; }
auto Figure::waterfallGap(double value)                                     -> Figure& { layout["waterfallgap"] = value; return *this; }
auto Figure::waterfallGroupGap(double value)                                -> Figure& { layout["waterfallgroupgap"] = value; return *this; }
auto Figure::waterfallMode(std::string const& value)                        -> Figure& { layout["waterfallmode"] = value; return *this; }
auto Figure::funnelGap(double value)                                        -> Figure& { layout["funnelgap"] = value; return *this; }
auto Figure::funnelGroupGap(double value)                                   -> Figure& { layout["funnelgroupgap"] = value; return *this; }
auto Figure::funnelMode(std::string const& value)                           -> Figure& { layout["funnelmode"] = value; return *this; }
auto Figure::funnelAreaExtendColors(bool value)                             -> Figure& { layout["extendfunnelareacolors"] = value; return *this; }
auto Figure::funnelAreaColorway(std::vector<std::string> const& value)      -> Figure& { layout["funnelareacolorway"] = value; return *this; }
auto Figure::sunburstExtendColors(bool value)                               -> Figure& { layout["extendsunburstcolors"] = value; return *this; }
auto Figure::sunburstColorway(std::vector<std::string> const& value)        -> Figure& { layout["sunburstcolorway"] = value; return *this; }
auto Figure::treemapExtendColors(bool value)                                -> Figure& { layout["extendtreemapcolors"] = value; return *this; }
auto Figure::treemapColorway(std::vector<std::string> const& value)         -> Figure& { layout["treemapcolorway"] = value; return *this; }
auto Figure::icicleExtendColors(bool value)                                 -> Figure& { layout["extendiciclecolors"] = value; return *this; }
auto Figure::icicleColorway(std::vector<std::string> const& value)          -> Figure& { layout["iciclecolorway"] = value; return *this; }

//=================================================================================================================
//
// METHODS THAT CUSTOMIZE THE X-AXIS LAYOUT OF THE FIGURE
//
//=================================================================================================================

auto Figure::xaxisAnchor(std::string const& value)                          -> Figure& { xaxis["anchor"] = value; return *this; }
auto Figure::xaxisAutoMargin(std::string const& value)                      -> Figure& { xaxis["automargin"] = value; return *this; }
auto Figure::xaxisAutoRange(std::string const& value)                       -> Figure& { xaxis["autorange"] = value; return *this; }
auto Figure::xaxisAutoTypeNumbers(std::string const& value)                 -> Figure& { xaxis["autotypenumbers"] = value; return *this; }
auto Figure::xaxisCalendar(std::string const& value)                        -> Figure& { xaxis["calendar"] = value; return *this; }
// auto Figure::xaxisCategoryArray(std::string const& value)                -> Figure& { xaxis["categoryarray"] = value; return *this; }
auto Figure::xaxisCategoryOrder(std::string const& value)                   -> Figure& { xaxis["categoryorder"] = value; return *this; }
auto Figure::xaxisColor(std::string const& value)                           -> Figure& { xaxis["color"] = value; return *this; }
auto Figure::xaxisConstrain(std::string const& value)                       -> Figure& { xaxis["constrain"] = value; return *this; }
auto Figure::xaxisConstrainToward(std::string const& value)                 -> Figure& { xaxis["constraintoward"] = value; return *this; }
auto Figure::xaxisDividerColor(std::string const& value)                    -> Figure& { xaxis["dividercolor"] = value; return *this; }
auto Figure::xaxisDividerWidth(int value)                                   -> Figure& { xaxis["dividerwidth"] = value; return *this; }
// auto Figure::xaxisDomain(std::string const& value)                       -> Figure& { xaxis["domain"] = value; return *this; }
auto Figure::xaxisDtick(std::string const& value)                           -> Figure& { xaxis["dtick"] = value; return *this; }
auto Figure::xaxisExponentFormat(std::string const& value)                  -> Figure& { xaxis["exponentformat"] = value; return *this; }
auto Figure::xaxisFixedRange(std::string const& value)                      -> Figure& { xaxis["fixedrange"] = value; return *this; }
auto Figure::xaxisGridColor(std::string const& value)                       -> Figure& { xaxis["gridcolor"] = value; return *this; }
auto Figure::xaxisGridDash(std::string const& value)                        -> Figure& { xaxis["griddash"] = value; return *this; }
auto Figure::xaxisGridWidth(int value)                                      -> Figure& { xaxis["gridwidth"] = value; return *this; }
auto Figure::xaxisHoverFormat(std::string const& value)                     -> Figure& { xaxis["hoverformat"] = value; return *this; }
auto Figure::xaxisLayer(std::string const& value)                           -> Figure& { xaxis["layer"] = value; return *this; }
auto Figure::xaxisLineColor(std::string const& value)                       -> Figure& { xaxis["linecolor"] = value; return *this; }
auto Figure::xaxisLineWidth(int value)                                      -> Figure& { xaxis["linewidth"] = value; return *this; }
auto Figure::xaxisMatches(std::string const& value)                         -> Figure& { xaxis["matches"] = value; return *this; }
auto Figure::xaxisMinExponent(int value)                                    -> Figure& { xaxis["minexponent"] = value; return *this; }
// auto Figure::xaxisMinorSpecs(std::string const& value)                   -> Figure& { xaxis["minor"] = value; return *this; }
auto Figure::xaxisMinorDtick(std::string const& value)                      -> Figure& { xaxis["minor_dtick"] = value; return *this; }
auto Figure::xaxisMinorGridColor(std::string const& value)                  -> Figure& { xaxis["minor_gridcolor"] = value; return *this; }
auto Figure::xaxisMinorGridDash(std::string const& value)                   -> Figure& { xaxis["minor_griddash"] = value; return *this; }
auto Figure::xaxisMinorGridWidth(int value)                                 -> Figure& { xaxis["minor_gridwidth"] = value; return *this; }
auto Figure::xaxisMinorNticks(std::string const& value)                     -> Figure& { xaxis["minor_nticks"] = value; return *this; }
auto Figure::xaxisMinorShowgrid(std::string const& value)                   -> Figure& { xaxis["minor_showgrid"] = value; return *this; }
auto Figure::xaxisMinorTick0(std::string const& value)                      -> Figure& { xaxis["minor_tick0"] = value; return *this; }
auto Figure::xaxisMinorTickColor(std::string const& value)                  -> Figure& { xaxis["minor_tickcolor"] = value; return *this; }
auto Figure::xaxisMinorTickLength(int value)                                -> Figure& { xaxis["minor_ticklen"] = value; return *this; }
auto Figure::xaxisMinorTickMode(std::string const& value)                   -> Figure& { xaxis["minor_tickmode"] = value; return *this; }
auto Figure::xaxisMinorTicks(std::string const& value)                      -> Figure& { xaxis["minor_ticks"] = value; return *this; }
// auto Figure::xaxisMinorTickValues(std::string const& value)              -> Figure& { xaxis["minor_tickvals"] = value; return *this; }
auto Figure::xaxisMinorTickWidth(int value)                                 -> Figure& { xaxis["minor_tickwidth"] = value; return *this; }
auto Figure::xaxisMirror(std::string const& value)                          -> Figure& { xaxis["mirror"] = value; return *this; }
auto Figure::xaxisNticks(std::string const& value)                          -> Figure& { xaxis["nticks"] = value; return *this; }
auto Figure::xaxisOverlaying(std::string const& value)                      -> Figure& { xaxis["overlaying"] = value; return *this; }
auto Figure::xaxisPosition(int value)                                       -> Figure& { xaxis["position"] = value; return *this; }
auto Figure::xaxisRange(double l, double r)                                 -> Figure& { xaxis["range"] = createRange(l, r); return *this; }
// auto Figure::xaxisRangeBreaks(std::string const& value)                  -> Figure& { xaxis["rangebreaks"] = value; return *this; }
// auto Figure::xaxisRangeBreaksBounds(std::string const& value)            -> Figure& { xaxis["rangebreaks_bounds"] = value; return *this; }
auto Figure::xaxisRangeBreaksDvalue(int value)                              -> Figure& { xaxis["rangebreaks_dvalue"] = value; return *this; }
auto Figure::xaxisRangeBreaksEnabled(std::string const& value)              -> Figure& { xaxis["rangebreaks_enabled"] = value; return *this; }
auto Figure::xaxisRangeBreaksName(std::string const& value)                 -> Figure& { xaxis["rangebreaks_name"] = value; return *this; }
auto Figure::xaxisRangeBreaksPattern(std::string const& value)              -> Figure& { xaxis["rangebreaks_pattern"] = value; return *this; }
auto Figure::xaxisRangeBreaksTemplateItemName(std::string const& value)     -> Figure& { xaxis["rangebreaks_templateitemname"] = value; return *this; }
// auto Figure::xaxisRangeBreaksValues(std::string const& value)            -> Figure& { xaxis["rangebreaks_values"] = value; return *this; }
auto Figure::xaxisRangeMode(std::string const& value)                       -> Figure& { xaxis["rangemode"] = value; return *this; }
// auto Figure::xaxisRangeSelectorSpecs(std::string const& value)           -> Figure& { xaxis["rangeselector"] = value; return *this; }
auto Figure::xaxisRangeSelectorActiveColor(std::string const& value)        -> Figure& { xaxis["rangeselector_activecolor"] = value; return *this; }
auto Figure::xaxisRangeSelectorBackgroundColor(std::string const& value)    -> Figure& { xaxis["rangeselector_bgcolor"] = value; return *this; }
auto Figure::xaxisRangeSelectorBorderColor(std::string const& value)        -> Figure& { xaxis["rangeselector_bordercolor"] = value; return *this; }
auto Figure::xaxisRangeSelectorBorderWidth(int value)                       -> Figure& { xaxis["rangeselector_borderwidth"] = value; return *this; }
// auto Figure::xaxisRangeSelectorButtons(std::string const& value)         -> Figure& { xaxis["rangeselector_buttons"] = value; return *this; }
auto Figure::xaxisRangeSelectorCount(int value)                             -> Figure& { xaxis["rangeselector_count"] = value; return *this; }
auto Figure::xaxisRangeSelectorLabel(std::string const& value)              -> Figure& { xaxis["rangeselector_label"] = value; return *this; }
auto Figure::xaxisRangeSelectorName(std::string const& value)               -> Figure& { xaxis["rangeselector_name"] = value; return *this; }
auto Figure::xaxisRangeSelectorStep(std::string const& value)               -> Figure& { xaxis["rangeselector_step"] = value; return *this; }
auto Figure::xaxisRangeSelectorStepMode(std::string const& value)           -> Figure& { xaxis["rangeselector_stepmode"] = value; return *this; }
auto Figure::xaxisRangeSelectorTemplateItemName(std::string const& value)   -> Figure& { xaxis["rangeselector_templateitemname"] = value; return *this; }
// auto Figure::xaxisRangeSelectorFontSpecs(std::string const& value)       -> Figure& { xaxis["rangeselector_font"] = value; return *this; }
auto Figure::xaxisRangeSelectorFontColor(std::string const& value)          -> Figure& { xaxis["rangeselector_font_color"] = value; return *this; }
auto Figure::xaxisRangeSelectorFontFamily(std::string const& value)         -> Figure& { xaxis["rangeselector_font_family"] = value; return *this; }
auto Figure::xaxisRangeSelectorFontSize(int value)                          -> Figure& { xaxis["rangeselector_font_size"] = value; return *this; }
auto Figure::xaxisRangeSelectorVisible(std::string const& value)            -> Figure& { xaxis["rangeselector_visible"] = value; return *this; }
auto Figure::xaxisRangeSelectorX(int value)                                 -> Figure& { xaxis["rangeselector_x"] = value; return *this; }
auto Figure::xaxisRangeSelectorXanchor(std::string const& value)            -> Figure& { xaxis["rangeselector_xanchor"] = value; return *this; }
auto Figure::xaxisRangeSelectorY(int value)                                 -> Figure& { xaxis["rangeselector_y"] = value; return *this; }
auto Figure::xaxisRangeSelectorYanchor(std::string const& value)            -> Figure& { xaxis["rangeselector_yanchor"] = value; return *this; }
// auto Figure::xaxisRangeSliderSpecs(std::string const& value)             -> Figure& { xaxis["rangeslider"] = value; return *this; }
auto Figure::xaxisRangeSliderAutoRange(std::string const& value)            -> Figure& { xaxis["rangeslider_autorange"] = value; return *this; }
auto Figure::xaxisRangeSliderBackgroundColor(std::string const& value)      -> Figure& { xaxis["rangeslider_bgcolor"] = value; return *this; }
auto Figure::xaxisRangeSliderBorderColor(std::string const& value)          -> Figure& { xaxis["rangeslider_bordercolor"] = value; return *this; }
auto Figure::xaxisRangeSliderBorderWidth(std::string const& value)          -> Figure& { xaxis["rangeslider_borderwidth"] = value; return *this; }
// auto Figure::xaxisRangeSliderRange(std::string const& value)             -> Figure& { xaxis["rangeslider_range"] = value; return *this; }
auto Figure::xaxisRangeSliderThickness(int value)                           -> Figure& { xaxis["rangeslider_thickness"] = value; return *this; }
auto Figure::xaxisRangeSliderVisible(std::string const& value)              -> Figure& { xaxis["rangeslider_visible"] = value; return *this; }
// auto Figure::xaxisRangeSliderYaxisSpecs(std::string const& value)        -> Figure& { xaxis["rangeslider_yaxis"] = value; return *this; }
auto Figure::xaxisRangeSliderYaxisRange(double l, double r)                 -> Figure& { xaxis["rangeslider_yaxis_range"] = createRange(l, r); return *this; }
auto Figure::xaxisRangeSliderYaxisRangeMode(std::string const& value)       -> Figure& { xaxis["rangeslider_yaxis_rangemode"] = value; return *this; }
auto Figure::xaxisScaleAnchor(std::string const& value)                     -> Figure& { xaxis["scaleanchor"] = value; return *this; }
auto Figure::xaxisScaleRatio(int value)                                     -> Figure& { xaxis["scaleratio"] = value; return *this; }
auto Figure::xaxisSeparateThousands(std::string const& value)               -> Figure& { xaxis["separatethousands"] = value; return *this; }
auto Figure::xaxisShowDividers(std::string const& value)                    -> Figure& { xaxis["showdividers"] = value; return *this; }
auto Figure::xaxisShowExponent(std::string const& value)                    -> Figure& { xaxis["showexponent"] = value; return *this; }
auto Figure::xaxisShowGrid(std::string const& value)                        -> Figure& { xaxis["showgrid"] = value; return *this; }
auto Figure::xaxisShowLine(std::string const& value)                        -> Figure& { xaxis["showline"] = value; return *this; }
auto Figure::xaxisShowSpikes(std::string const& value)                      -> Figure& { xaxis["showspikes"] = value; return *this; }
auto Figure::xaxisShowTickLabels(std::string const& value)                  -> Figure& { xaxis["showticklabels"] = value; return *this; }
auto Figure::xaxisShowTickPrefix(std::string const& value)                  -> Figure& { xaxis["showtickprefix"] = value; return *this; }
auto Figure::xaxisShowTickSuffix(std::string const& value)                  -> Figure& { xaxis["showticksuffix"] = value; return *this; }
auto Figure::xaxisSide(std::string const& value)                            -> Figure& { xaxis["side"] = value; return *this; }
auto Figure::xaxisSpikeColor(std::string const& value)                      -> Figure& { xaxis["spikecolor"] = value; return *this; }
auto Figure::xaxisSpikeDash(std::string const& value)                       -> Figure& { xaxis["spikedash"] = value; return *this; }
auto Figure::xaxisSpikeMode(std::string const& value)                       -> Figure& { xaxis["spikemode"] = value; return *this; }
auto Figure::xaxisSpikeSnap(std::string const& value)                       -> Figure& { xaxis["spikesnap"] = value; return *this; }
auto Figure::xaxisSpikeThickness(int value)                                 -> Figure& { xaxis["spikethickness"] = value; return *this; }
auto Figure::xaxisTick0(std::string const& value)                           -> Figure& { xaxis["tick0"] = value; return *this; }
auto Figure::xaxisTickAngle(std::string const& value)                       -> Figure& { xaxis["tickangle"] = value; return *this; }
auto Figure::xaxisTickColor(std::string const& value)                       -> Figure& { xaxis["tickcolor"] = value; return *this; }
// auto Figure::xaxisTickFontSpecs(std::string const& value)                -> Figure& { xaxis["tickfont"] = value; return *this; }
auto Figure::xaxisTickFontColor(std::string const& value)                   -> Figure& { xaxis["tickfont_color"] = value; return *this; }
auto Figure::xaxisTickFontFamily(std::string const& value)                  -> Figure& { xaxis["tickfont_family"] = value; return *this; }
auto Figure::xaxisTickFontSize(int value)                                   -> Figure& { xaxis["tickfont_size"] = value; return *this; }
auto Figure::xaxisTickFormat(std::string const& value)                      -> Figure& { xaxis["tickformat"] = value; return *this; }
// auto Figure::xaxisTickFormatStops(std::string const& value)              -> Figure& { xaxis["tickformatstops"] = value; return *this; }
// auto Figure::xaxisTickFormatStopsDtickRange(std::string const& value)    -> Figure& { xaxis["tickformatstops_dtickrange"] = value; return *this; }
auto Figure::xaxisTickFormatStopsEnabled(std::string const& value)          -> Figure& { xaxis["tickformatstops_enabled"] = value; return *this; }
auto Figure::xaxisTickFormatStopsName(std::string const& value)             -> Figure& { xaxis["tickformatstops_name"] = value; return *this; }
auto Figure::xaxisTickFormatStopsTemplateItemName(std::string const& value) -> Figure& { xaxis["tickformatstops_templateitemname"] = value; return *this; }
auto Figure::xaxisTickFormatStopsValue(std::string const& value)            -> Figure& { xaxis["tickformatstops_value"] = value; return *this; }
auto Figure::xaxisTickLabelMode(std::string const& value)                   -> Figure& { xaxis["ticklabelmode"] = value; return *this; }
auto Figure::xaxisTickLabelOverflow(std::string const& value)               -> Figure& { xaxis["ticklabeloverflow"] = value; return *this; }
auto Figure::xaxisTickLabelPosition(std::string const& value)               -> Figure& { xaxis["ticklabelposition"] = value; return *this; }
auto Figure::xaxisTickLabelStep(std::string const& value)                   -> Figure& { xaxis["ticklabelstep"] = value; return *this; }
auto Figure::xaxisTickLength(int value)                                     -> Figure& { xaxis["ticklen"] = value; return *this; }
auto Figure::xaxisTickMode(std::string const& value)                        -> Figure& { xaxis["tickmode"] = value; return *this; }
auto Figure::xaxisTickPrefix(std::string const& value)                      -> Figure& { xaxis["tickprefix"] = value; return *this; }
auto Figure::xaxisTicks(std::string const& value)                           -> Figure& { xaxis["ticks"] = value; return *this; }
auto Figure::xaxisTickson(std::string const& value)                         -> Figure& { xaxis["tickson"] = value; return *this; }
auto Figure::xaxisTickSuffix(std::string const& value)                      -> Figure& { xaxis["ticksuffix"] = value; return *this; }
// auto Figure::xaxisTickText(std::string const& value)                     -> Figure& { xaxis["ticktext"] = value; return *this; }
// auto Figure::xaxisTickValues(std::string const& value)                   -> Figure& { xaxis["tickvals"] = value; return *this; }
auto Figure::xaxisTickWidth(int value)                                      -> Figure& { xaxis["tickwidth"] = value; return *this; }
// auto Figure::xaxisTitleSpecs(std::string const& value)                   -> Figure& { xaxis["title"] = value; return *this; }
// auto Figure::xaxisTitleFontSpecs(std::string const& value)               -> Figure& { xaxis["title_font"] = value; return *this; }
auto Figure::xaxisTitleFontColor(std::string const& value)                  -> Figure& { xaxis["title_font_color"] = value; return *this; }
auto Figure::xaxisTitleFontFamily(std::string const& value)                 -> Figure& { xaxis["title_font_family"] = value; return *this; }
auto Figure::xaxisTitleFontSize(int value)                                  -> Figure& { xaxis["title_font_size"] = value; return *this; }
auto Figure::xaxisTitleStandoff(int value)                                  -> Figure& { xaxis["title_standoff"] = value; return *this; }
auto Figure::xaxisTitleText(std::string const& value)                       -> Figure& { xaxis["title_text"] = value; return *this; }
auto Figure::xaxisType(std::string const& value)                            -> Figure& { xaxis["type"] = value; return *this; }
auto Figure::xaxisUirevision(std::string const& value)                      -> Figure& { xaxis["uirevision"] = value; return *this; }
auto Figure::xaxisVisible(std::string const& value)                         -> Figure& { xaxis["visible"] = value; return *this; }
auto Figure::xaxisZeroLine(std::string const& value)                        -> Figure& { xaxis["zeroline"] = value; return *this; }
auto Figure::xaxisZeroLineColor(std::string const& value)                   -> Figure& { xaxis["zerolinecolor"] = value; return *this; }
auto Figure::xaxisZeroLineWidth(int value)                                  -> Figure& { xaxis["zerolinewidth"] = value; return *this; }

//=================================================================================================================
//
// METHODS THAT CUSTOMIZE THE Y-AXIS LAYOUT OF THE FIGURE
//
//=================================================================================================================

auto Figure::yaxisAnchor(std::string const& value)                          -> Figure& { yaxis["anchor"] = value; return *this; }
auto Figure::yaxisAutoMargin(std::string const& value)                      -> Figure& { yaxis["automargin"] = value; return *this; }
auto Figure::yaxisAutoRange(std::string const& value)                       -> Figure& { yaxis["autorange"] = value; return *this; }
auto Figure::yaxisAutoTypeNumbers(std::string const& value)                 -> Figure& { yaxis["autotypenumbers"] = value; return *this; }
auto Figure::yaxisCalendar(std::string const& value)                        -> Figure& { yaxis["calendar"] = value; return *this; }
// auto Figure::yaxisCategoryArray(std::string const& value)                -> Figure& { yaxis["categoryarray"] = value; return *this; }
auto Figure::yaxisCategoryOrder(std::string const& value)                   -> Figure& { yaxis["categoryorder"] = value; return *this; }
auto Figure::yaxisColor(std::string const& value)                           -> Figure& { yaxis["color"] = value; return *this; }
auto Figure::yaxisConstrain(std::string const& value)                       -> Figure& { yaxis["constrain"] = value; return *this; }
auto Figure::yaxisConstrainToward(std::string const& value)                 -> Figure& { yaxis["constraintoward"] = value; return *this; }
auto Figure::yaxisDividerColor(std::string const& value)                    -> Figure& { yaxis["dividercolor"] = value; return *this; }
auto Figure::yaxisDividerWidth(int value)                                   -> Figure& { yaxis["dividerwidth"] = value; return *this; }
// auto Figure::yaxisDomain(std::string const& value)                       -> Figure& { yaxis["domain"] = value; return *this; }
auto Figure::yaxisDtick(std::string const& value)                           -> Figure& { yaxis["dtick"] = value; return *this; }
auto Figure::yaxisExponentFormat(std::string const& value)                  -> Figure& { yaxis["exponentformat"] = value; return *this; }
auto Figure::yaxisFixedRange(std::string const& value)                      -> Figure& { yaxis["fixedrange"] = value; return *this; }
auto Figure::yaxisGridColor(std::string const& value)                       -> Figure& { yaxis["gridcolor"] = value; return *this; }
auto Figure::yaxisGridDash(std::string const& value)                        -> Figure& { yaxis["griddash"] = value; return *this; }
auto Figure::yaxisGridWidth(int value)                                      -> Figure& { yaxis["gridwidth"] = value; return *this; }
auto Figure::yaxisHoverFormat(std::string const& value)                     -> Figure& { yaxis["hoverformat"] = value; return *this; }
auto Figure::yaxisLayer(std::string const& value)                           -> Figure& { yaxis["layer"] = value; return *this; }
auto Figure::yaxisLineColor(std::string const& value)                       -> Figure& { yaxis["linecolor"] = value; return *this; }
auto Figure::yaxisLineWidth(int value)                                      -> Figure& { yaxis["linewidth"] = value; return *this; }
auto Figure::yaxisMatches(std::string const& value)                         -> Figure& { yaxis["matches"] = value; return *this; }
auto Figure::yaxisMinExponent(int value)                                    -> Figure& { yaxis["minexponent"] = value; return *this; }
// auto Figure::yaxisMinorSpecs(std::string const& value)                   -> Figure& { yaxis["minor"] = value; return *this; }
auto Figure::yaxisMinorDtick(std::string const& value)                      -> Figure& { yaxis["minor_dtick"] = value; return *this; }
auto Figure::yaxisMinorGridColor(std::string const& value)                  -> Figure& { yaxis["minor_gridcolor"] = value; return *this; }
auto Figure::yaxisMinorGridDash(std::string const& value)                   -> Figure& { yaxis["minor_griddash"] = value; return *this; }
auto Figure::yaxisMinorGridWidth(int value)                                 -> Figure& { yaxis["minor_gridwidth"] = value; return *this; }
auto Figure::yaxisMinorNticks(std::string const& value)                     -> Figure& { yaxis["minor_nticks"] = value; return *this; }
auto Figure::yaxisMinorShowgrid(std::string const& value)                   -> Figure& { yaxis["minor_showgrid"] = value; return *this; }
auto Figure::yaxisMinorTick0(std::string const& value)                      -> Figure& { yaxis["minor_tick0"] = value; return *this; }
auto Figure::yaxisMinorTickColor(std::string const& value)                  -> Figure& { yaxis["minor_tickcolor"] = value; return *this; }
auto Figure::yaxisMinorTickLength(int value)                                -> Figure& { yaxis["minor_ticklen"] = value; return *this; }
auto Figure::yaxisMinorTickMode(std::string const& value)                   -> Figure& { yaxis["minor_tickmode"] = value; return *this; }
auto Figure::yaxisMinorTicks(std::string const& value)                      -> Figure& { yaxis["minor_ticks"] = value; return *this; }
// auto Figure::yaxisMinorTickValues(std::string const& value)              -> Figure& { yaxis["minor_tickvals"] = value; return *this; }
auto Figure::yaxisMinorTickWidth(int value)                                 -> Figure& { yaxis["minor_tickwidth"] = value; return *this; }
auto Figure::yaxisMirror(std::string const& value)                          -> Figure& { yaxis["mirror"] = value; return *this; }
auto Figure::yaxisNticks(std::string const& value)                          -> Figure& { yaxis["nticks"] = value; return *this; }
auto Figure::yaxisOverlaying(std::string const& value)                      -> Figure& { yaxis["overlaying"] = value; return *this; }
auto Figure::yaxisPosition(int value)                                       -> Figure& { yaxis["position"] = value; return *this; }
auto Figure::yaxisRange(double l, double r)                                 -> Figure& { yaxis["range"] = createRange(l, r); return *this; }
// auto Figure::yaxisRangeBreaks(std::string const& value)                  -> Figure& { yaxis["rangebreaks"] = value; return *this; }
// auto Figure::yaxisRangeBreaksBounds(std::string const& value)            -> Figure& { yaxis["rangebreaks_bounds"] = value; return *this; }
auto Figure::yaxisRangeBreaksDvalue(int value)                              -> Figure& { yaxis["rangebreaks_dvalue"] = value; return *this; }
auto Figure::yaxisRangeBreaksEnabled(std::string const& value)              -> Figure& { yaxis["rangebreaks_enabled"] = value; return *this; }
auto Figure::yaxisRangeBreaksName(std::string const& value)                 -> Figure& { yaxis["rangebreaks_name"] = value; return *this; }
auto Figure::yaxisRangeBreaksPattern(std::string const& value)              -> Figure& { yaxis["rangebreaks_pattern"] = value; return *this; }
auto Figure::yaxisRangeBreaksTemplateItemName(std::string const& value)     -> Figure& { yaxis["rangebreaks_templateitemname"] = value; return *this; }
// auto Figure::yaxisRangeBreaksValues(std::string const& value)            -> Figure& { yaxis["rangebreaks_values"] = value; return *this; }
auto Figure::yaxisRangeMode(std::string const& value)                       -> Figure& { yaxis["rangemode"] = value; return *this; }
// auto Figure::yaxisRangeSelectorSpecs(std::string const& value)           -> Figure& { yaxis["rangeselector"] = value; return *this; }
auto Figure::yaxisRangeSelectorActiveColor(std::string const& value)        -> Figure& { yaxis["rangeselector_activecolor"] = value; return *this; }
auto Figure::yaxisRangeSelectorBackgroundColor(std::string const& value)    -> Figure& { yaxis["rangeselector_bgcolor"] = value; return *this; }
auto Figure::yaxisRangeSelectorBorderColor(std::string const& value)        -> Figure& { yaxis["rangeselector_bordercolor"] = value; return *this; }
auto Figure::yaxisRangeSelectorBorderWidth(int value)                       -> Figure& { yaxis["rangeselector_borderwidth"] = value; return *this; }
// auto Figure::yaxisRangeSelectorButtons(std::string const& value)         -> Figure& { yaxis["rangeselector_buttons"] = value; return *this; }
auto Figure::yaxisRangeSelectorCount(int value)                             -> Figure& { yaxis["rangeselector_count"] = value; return *this; }
auto Figure::yaxisRangeSelectorLabel(std::string const& value)              -> Figure& { yaxis["rangeselector_label"] = value; return *this; }
auto Figure::yaxisRangeSelectorName(std::string const& value)               -> Figure& { yaxis["rangeselector_name"] = value; return *this; }
auto Figure::yaxisRangeSelectorStep(std::string const& value)               -> Figure& { yaxis["rangeselector_step"] = value; return *this; }
auto Figure::yaxisRangeSelectorStepMode(std::string const& value)           -> Figure& { yaxis["rangeselector_stepmode"] = value; return *this; }
auto Figure::yaxisRangeSelectorTemplateItemName(std::string const& value)   -> Figure& { yaxis["rangeselector_templateitemname"] = value; return *this; }
// auto Figure::yaxisRangeSelectorFontSpecs(std::string const& value)       -> Figure& { yaxis["rangeselector_font"] = value; return *this; }
auto Figure::yaxisRangeSelectorFontColor(std::string const& value)          -> Figure& { yaxis["rangeselector_font_color"] = value; return *this; }
auto Figure::yaxisRangeSelectorFontFamily(std::string const& value)         -> Figure& { yaxis["rangeselector_font_family"] = value; return *this; }
auto Figure::yaxisRangeSelectorFontSize(int value)                          -> Figure& { yaxis["rangeselector_font_size"] = value; return *this; }
auto Figure::yaxisRangeSelectorVisible(std::string const& value)            -> Figure& { yaxis["rangeselector_visible"] = value; return *this; }
auto Figure::yaxisRangeSelectorX(int value)                                 -> Figure& { yaxis["rangeselector_x"] = value; return *this; }
auto Figure::yaxisRangeSelectorXanchor(std::string const& value)            -> Figure& { yaxis["rangeselector_xanchor"] = value; return *this; }
auto Figure::yaxisRangeSelectorY(int value)                                 -> Figure& { yaxis["rangeselector_y"] = value; return *this; }
auto Figure::yaxisRangeSelectorYanchor(std::string const& value)            -> Figure& { yaxis["rangeselector_yanchor"] = value; return *this; }
// auto Figure::yaxisRangeSliderSpecs(std::string const& value)             -> Figure& { yaxis["rangeslider"] = value; return *this; }
auto Figure::yaxisRangeSliderAutoRange(std::string const& value)            -> Figure& { yaxis["rangeslider_autorange"] = value; return *this; }
auto Figure::yaxisRangeSliderBackgroundColor(std::string const& value)      -> Figure& { yaxis["rangeslider_bgcolor"] = value; return *this; }
auto Figure::yaxisRangeSliderBorderColor(std::string const& value)          -> Figure& { yaxis["rangeslider_bordercolor"] = value; return *this; }
auto Figure::yaxisRangeSliderBorderWidth(std::string const& value)          -> Figure& { yaxis["rangeslider_borderwidth"] = value; return *this; }
// auto Figure::yaxisRangeSliderRange(std::string const& value)             -> Figure& { yaxis["rangeslider_range"] = value; return *this; }
auto Figure::yaxisRangeSliderThickness(int value)                           -> Figure& { yaxis["rangeslider_thickness"] = value; return *this; }
auto Figure::yaxisRangeSliderVisible(std::string const& value)              -> Figure& { yaxis["rangeslider_visible"] = value; return *this; }
// auto Figure::yaxisRangeSliderYaxisSpecs(std::string const& value)        -> Figure& { yaxis["rangeslider_yaxis"] = value; return *this; }
auto Figure::yaxisRangeSliderYaxisRange(double l, double r)                 -> Figure& { yaxis["rangeslider_yaxis_range"] = createRange(l, r); return *this; }
auto Figure::yaxisRangeSliderYaxisRangeMode(std::string const& value)       -> Figure& { yaxis["rangeslider_yaxis_rangemode"] = value; return *this; }
auto Figure::yaxisScaleAnchor(std::string const& value)                     -> Figure& { yaxis["scaleanchor"] = value; return *this; }
auto Figure::yaxisScaleRatio(int value)                                     -> Figure& { yaxis["scaleratio"] = value; return *this; }
auto Figure::yaxisSeparateThousands(std::string const& value)               -> Figure& { yaxis["separatethousands"] = value; return *this; }
auto Figure::yaxisShowDividers(std::string const& value)                    -> Figure& { yaxis["showdividers"] = value; return *this; }
auto Figure::yaxisShowExponent(std::string const& value)                    -> Figure& { yaxis["showexponent"] = value; return *this; }
auto Figure::yaxisShowGrid(std::string const& value)                        -> Figure& { yaxis["showgrid"] = value; return *this; }
auto Figure::yaxisShowLine(std::string const& value)                        -> Figure& { yaxis["showline"] = value; return *this; }
auto Figure::yaxisShowSpikes(std::string const& value)                      -> Figure& { yaxis["showspikes"] = value; return *this; }
auto Figure::yaxisShowTickLabels(std::string const& value)                  -> Figure& { yaxis["showticklabels"] = value; return *this; }
auto Figure::yaxisShowTickPrefix(std::string const& value)                  -> Figure& { yaxis["showtickprefix"] = value; return *this; }
auto Figure::yaxisShowTickSuffix(std::string const& value)                  -> Figure& { yaxis["showticksuffix"] = value; return *this; }
auto Figure::yaxisSide(std::string const& value)                            -> Figure& { yaxis["side"] = value; return *this; }
auto Figure::yaxisSpikeColor(std::string const& value)                      -> Figure& { yaxis["spikecolor"] = value; return *this; }
auto Figure::yaxisSpikeDash(std::string const& value)                       -> Figure& { yaxis["spikedash"] = value; return *this; }
auto Figure::yaxisSpikeMode(std::string const& value)                       -> Figure& { yaxis["spikemode"] = value; return *this; }
auto Figure::yaxisSpikeSnap(std::string const& value)                       -> Figure& { yaxis["spikesnap"] = value; return *this; }
auto Figure::yaxisSpikeThickness(int value)                                 -> Figure& { yaxis["spikethickness"] = value; return *this; }
auto Figure::yaxisTick0(std::string const& value)                           -> Figure& { yaxis["tick0"] = value; return *this; }
auto Figure::yaxisTickAngle(std::string const& value)                       -> Figure& { yaxis["tickangle"] = value; return *this; }
auto Figure::yaxisTickColor(std::string const& value)                       -> Figure& { yaxis["tickcolor"] = value; return *this; }
// auto Figure::yaxisTickFontSpecs(std::string const& value)                -> Figure& { yaxis["tickfont"] = value; return *this; }
auto Figure::yaxisTickFontColor(std::string const& value)                   -> Figure& { yaxis["tickfont_color"] = value; return *this; }
auto Figure::yaxisTickFontFamily(std::string const& value)                  -> Figure& { yaxis["tickfont_family"] = value; return *this; }
auto Figure::yaxisTickFontSize(int value)                                   -> Figure& { yaxis["tickfont_size"] = value; return *this; }
auto Figure::yaxisTickFormat(std::string const& value)                      -> Figure& { yaxis["tickformat"] = value; return *this; }
// auto Figure::yaxisTickFormatStops(std::string const& value)              -> Figure& { yaxis["tickformatstops"] = value; return *this; }
// auto Figure::yaxisTickFormatStopsDtickRange(std::string const& value)    -> Figure& { yaxis["tickformatstops_dtickrange"] = value; return *this; }
auto Figure::yaxisTickFormatStopsEnabled(std::string const& value)          -> Figure& { yaxis["tickformatstops_enabled"] = value; return *this; }
auto Figure::yaxisTickFormatStopsName(std::string const& value)             -> Figure& { yaxis["tickformatstops_name"] = value; return *this; }
auto Figure::yaxisTickFormatStopsTemplateItemName(std::string const& value) -> Figure& { yaxis["tickformatstops_templateitemname"] = value; return *this; }
auto Figure::yaxisTickFormatStopsValue(std::string const& value)            -> Figure& { yaxis["tickformatstops_value"] = value; return *this; }
auto Figure::yaxisTickLabelMode(std::string const& value)                   -> Figure& { yaxis["ticklabelmode"] = value; return *this; }
auto Figure::yaxisTickLabelOverflow(std::string const& value)               -> Figure& { yaxis["ticklabeloverflow"] = value; return *this; }
auto Figure::yaxisTickLabelPosition(std::string const& value)               -> Figure& { yaxis["ticklabelposition"] = value; return *this; }
auto Figure::yaxisTickLabelStep(std::string const& value)                   -> Figure& { yaxis["ticklabelstep"] = value; return *this; }
auto Figure::yaxisTickLength(int value)                                     -> Figure& { yaxis["ticklen"] = value; return *this; }
auto Figure::yaxisTickMode(std::string const& value)                        -> Figure& { yaxis["tickmode"] = value; return *this; }
auto Figure::yaxisTickPrefix(std::string const& value)                      -> Figure& { yaxis["tickprefix"] = value; return *this; }
auto Figure::yaxisTicks(std::string const& value)                           -> Figure& { yaxis["ticks"] = value; return *this; }
auto Figure::yaxisTickson(std::string const& value)                         -> Figure& { yaxis["tickson"] = value; return *this; }
auto Figure::yaxisTickSuffix(std::string const& value)                      -> Figure& { yaxis["ticksuffix"] = value; return *this; }
// auto Figure::yaxisTickText(std::string const& value)                     -> Figure& { yaxis["ticktext"] = value; return *this; }
// auto Figure::yaxisTickValues(std::string const& value)                   -> Figure& { yaxis["tickvals"] = value; return *this; }
auto Figure::yaxisTickWidth(int value)                                      -> Figure& { yaxis["tickwidth"] = value; return *this; }
// auto Figure::yaxisTitleSpecs(std::string const& value)                   -> Figure& { yaxis["title"] = value; return *this; }
// auto Figure::yaxisTitleFontSpecs(std::string const& value)               -> Figure& { yaxis["title_font"] = value; return *this; }
auto Figure::yaxisTitleFontColor(std::string const& value)                  -> Figure& { yaxis["title_font_color"] = value; return *this; }
auto Figure::yaxisTitleFontFamily(std::string const& value)                 -> Figure& { yaxis["title_font_family"] = value; return *this; }
auto Figure::yaxisTitleFontSize(int value)                                  -> Figure& { yaxis["title_font_size"] = value; return *this; }
auto Figure::yaxisTitleStandoff(int value)                                  -> Figure& { yaxis["title_standoff"] = value; return *this; }
auto Figure::yaxisTitleText(std::string const& value)                       -> Figure& { yaxis["title_text"] = value; return *this; }
auto Figure::yaxisType(std::string const& value)                            -> Figure& { yaxis["type"] = value; return *this; }
auto Figure::yaxisUirevision(std::string const& value)                      -> Figure& { yaxis["uirevision"] = value; return *this; }
auto Figure::yaxisVisible(std::string const& value)                         -> Figure& { yaxis["visible"] = value; return *this; }
auto Figure::yaxisZeroLine(std::string const& value)                        -> Figure& { yaxis["zeroline"] = value; return *this; }
auto Figure::yaxisZeroLineColor(std::string const& value)                   -> Figure& { yaxis["zerolinecolor"] = value; return *this; }
auto Figure::yaxisZeroLineWidth(int value)                                  -> Figure& { yaxis["zerolinewidth"] = value; return *this; }

} // namespace reaktplot
