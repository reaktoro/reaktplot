#include <reaktplot/reaktplot.hpp>
using namespace reaktplot;

void plot()
{
    Array x = linspace(0.0, PI, 50);

    Figure fig;

    fig.xaxisTitleText("x");
    fig.yaxisTitleText("y");

    fig.addScatter(x, std::sin(x), "sin(x)");

    fig.save("my-sine-plot.pdf");
}
