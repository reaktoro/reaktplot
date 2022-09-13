#include "Plotly.hpp"

// pybind11 includes
#include <pybind11/embed.h>

namespace reaktplot {
namespace detail {

const auto initscript = R"xyz(
reaktplot_template = pgo.layout.Template()

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
    colorway = ply.colors.qualitative.T10,
)

reaktplot_template.data.scatter = [pgo.Scatter(line=dict(width=4), marker=dict(symbol="circle", size=10))]

pio.templates["reaktplot"] = reaktplot_template
pio.templates.default = "reaktplot"

)xyz";

/// Used to keep storage of plotly modules used during the lifetime of the application.
struct PythonInit
{
    py::scoped_interpreter guard; ///< The guard used to ensure Python interpreter is initialized and closed correctly.
    py::module_ ply;              ///< The plotly module
    py::module_ pio;              ///< The plotly.io module
    py::module_ pgo;              ///< The plotly.graph_objects module

    PythonInit()
    {
        using namespace py::literals;

        ply = py::module_::import("plotly");
        pio = py::module_::import("plotly.io");
        pgo = py::module_::import("plotly.graph_objects");

        // Execute the initializing Python script (e.g., for setting customized default theme for reaktplot)
        py::exec(initscript, py::globals(), py::dict("ply"_a = ply, "pgo"_a = pgo, "pio"_a = pio));
    }
};

/// Used to initialize the plotly modules once and return them.
auto getPythonInit() -> PythonInit const&
{
    static PythonInit pyinit;
    return pyinit;
}

} // namespace detail

auto PlotlyModules::ply() -> py::module
{
    return detail::getPythonInit().ply;
}

auto PlotlyModules::pio() -> py::module
{
    return detail::getPythonInit().pio;
}

auto PlotlyModules::pgo() -> py::module
{
    return detail::getPythonInit().pgo;
}

auto Plotly::Figure() -> py::object
{
    return PlotlyModules::pgo().attr("Figure")();
}

auto Plotly::Layout() -> py::object
{
    return PlotlyModules::pgo().attr("Layout")();
}

auto Plotly::Scatter() -> py::object
{
    return PlotlyModules::pgo().attr("Scatter")();
}

auto Plotly::Bar() -> py::object
{
    return PlotlyModules::pgo().attr("Bar")();
}

} // namespace reaktplot plotly4cpp
