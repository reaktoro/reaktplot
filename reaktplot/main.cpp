// #include <vector>
// #include <deque>

// // #include <pybind11/pybind11.h>
// // #include <pybind11/stl.h>
// // #include <pybind11/numpy.h>
// // #include <pybind11/embed.h> // everything needed for embedding
// // namespace py = pybind11;
// // using namespace py::literals;
// #include "Scatter.hpp"
// #include "Figure.hpp"
// using namespace reaktplot;

// int main()
// {
//     std::deque<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
//     std::deque<double> sinx = {1.0, 4.0, 9.0, 16.0, 25.0};
//     std::deque<double> cosx = {2.0, 8.0, 18.0, 32.0, 50.0};

//     // py::initialize_interpreter();
//     // {
//     //     py::scoped_interpreter guard{}; // start the interpreter and keep it alive
//     // }

//     // py::module_ go = py::module_::import("plotly.graph_objects");
//     // auto fig = go.attr("Figure")();
//     // fig.attr("add_trace")(py::dict("x"_a=x, "y"_a=sinx, "name"_a="sin(x)"));
//     // fig.attr("add_trace")(py::dict("x"_a=x, "y"_a=cosx, "name"_a="cos(x)"));
//     // // auto trace2 = go.attr("Scatter")(py::dict("x"_a=x, "y"_a=y, "name"_a="cos(x)"));

//     // fig.attr("show")();
//     // py::print("Hello, World!"); // use the Python API
//     // py::print(fig); // use the Python API
//     // py::finalize_interpreter();

//     Figure fig;
//     // fig.addScatter(x, sinx, "new2-sin(x)");
//     // fig.addScatter(x, cosx, "new2-cos(x)");
//     fig.add(Scatter().x(x).y(sinx).name("new-3sin(x)"));
//     fig.add(Scatter().x(x).y(cosx).name("new-3cos(x)"));
//     fig.show();

//     Figure fig2;
//     fig2.addScatter(x, sinx, "new2-sin(x)");
//     fig2.addScatter(x, cosx, "new2-cos(x)");
//     fig2.title_text("reaktplot");
//     fig2.xaxis_title_text("Temperature [K]");
//     fig2.yaxis_title_text("Value [J]");
//     fig2.show();
// }
