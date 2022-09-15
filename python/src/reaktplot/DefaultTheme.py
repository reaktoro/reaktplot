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


import plotly as ply4rkp
import plotly.graph_objects as pgo4rkp
import plotly.io as pio4rkp


reaktplot_template = pgo4rkp.layout.Template()

reaktplot_template.layout = dict(
    # FONT OPTIONS
    font_family = "Arial",
    font_size = 16,
    font_color = "#2e2e2e",

    # TITLE OPTIONS
    title_font_size = 24,
    title_font_color = "#636363",
    title_xref = "paper",
    title_yref = "paper",
    title_yanchor = "middle",
    title_x = 0.0,

    # LEGEND OPTIONS
    legend_title_text = "",

    margin_b = 100,
    margin_t = 100,
    margin_l = 100,
    margin_r = 100,
    margin_pad = 5,

    xaxis_title_font_size = 20,
    yaxis_title_font_size = 20,

    xaxis_zerolinecolor = "#2e2e2e",
    xaxis_zerolinewidth = 0,

    yaxis_zerolinecolor = "#2e2e2e",
    yaxis_zerolinewidth = 0,

    # BACKGROUND COLOR OPTIONS
    paper_bgcolor = "#f7f7f7",
    plot_bgcolor = "#f7f7f7",

    # COLORSCALE OPTIONS
    colorway = ply4rkp.colors.qualitative.T10,
)

reaktplot_template.data.scatter = [pgo4rkp.Scatter(line=dict(width=4), marker=dict(symbol="circle", size=10))]

pio4rkp.templates["reaktplot"] = reaktplot_template
pio4rkp.templates.default = "reaktplot"
