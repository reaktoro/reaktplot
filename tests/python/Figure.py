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

from reaktplot import *

import numpy as np
import pytest

def testFigure():

    x = np.linspace(0.0, 1.0, 10)
    u = x * x
    v = x * x * x
    w = x * x * x * x

    fig = Figure()

    fig.title("TESTING TITLE")
    assert fig.layout["title_text"] == "TESTING TITLE"

    fig.xaxisTitleText("x")
    assert fig.xaxis["title_text"] == "x"

    fig.yaxisTitleText("y")
    assert fig.yaxis["title_text"] == "y"

    fig.drawLine(x, u, "u")
    fig.drawLineWithMarkers(x, v, "v")
    fig.drawMarkers(x, w, "w")

    for ext in ["png", "pdf", "svg"]:
        try: fig.save(f"test_figure.{ext}")
        except RuntimeError as error:
            pytest.fail(f"'saving test_figure.{ext}' raised an exception {error}")

    colorway = fig.colorway()
    assert colorway == fig.fig.layout.template.layout.colorway

    fig.colorway(["black", "green"])

    colorway = fig.colorway()
    assert colorway == ["black", "green"]
