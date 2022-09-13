# Tutorials

Check below for a series of examples on how to use {{reaktplot}}. If you like
{{reaktplot}}, please consider helping with more examples!

## Plotting sine functions

{{ inputcpp('examples/example-sine-functions.cpp', startline=26) }}

![](img/tutorials/example-sine-functions.svg){: loading=lazy }

## Plotting Bessel functions

We will skip the introduction to Bessel functions, which can be read in this
[Wikipedia article](https://en.wikipedia.org/wiki/Bessel_function) and go
straight to plotting them! This example assumes that they have already been
pre-computed and stored in `std::vector` objects (see below).

{{ inputcpp('examples/example-bessel-functions.cpp', startline=26) }}

![](img/tutorials/example-bessel-functions.svg){: loading=lazy }

## Plotting filled curves

{{ inputcpp('examples/example-filled-curves.cpp', startline=26) }}

![](img/tutorials/example-filled-curves.svg){: loading=lazy }

## Using logarithmic axes

{{ inputcpp('examples/example-logarithmic-axes.cpp', startline=26) }}

![](img/tutorials/example-logarithmic-axes.svg){: loading=lazy }

## Plotting multiple plots

{{ inputcpp('examples/example-multiplot.cpp', startline=26) }}

![](img/tutorials/example-multiplot.svg){: loading=lazy }

## Ploting trigonometric functions

{{ inputcpp('examples/example-sincos-functions.cpp', startline=26) }}

![](img/tutorials/example-sincos-functions.svg){: loading=lazy }

## Plotting boxes

{{ inputcpp('examples/example-boxes.cpp', startline=26) }}

![](img/tutorials/example-boxes.svg){: loading=lazy }

## Plotting boxes with custom tick labels

{{ inputcpp('examples/example-boxes-ticklabels.cpp', startline=26) }}

![](img/tutorials/example-boxes-ticklabels.svg){: loading=lazy }

## Plotting broken curves when NaN values are present

{{ inputcpp('examples/example-missing-data.cpp', startline=26) }}

![](img/tutorials/example-missing-data.svg){: loading=lazy }

## Plotting a 3D helix plot

{{ inputcpp('examples/example-3d-helix.cpp', startline=26) }}

![](img/tutorials/example-3d-helix.svg){: loading=lazy }

## Plotting multiple mixed 2D and 3D plots

{{ inputcpp('examples/example-multiplot-mixed.cpp', startline=26) }}

![](img/tutorials/example-multiplot-mixed.svg){: loading=lazy }

## Changing plots in a figure

{{ inputcpp('examples/example-plot-get.cpp', startline=26) }}

![](img/tutorials/example-plot-get.svg){: loading=lazy }

## Integration with CMake-based projects

Integrating {{reaktplot}} in a CMake-based project is very simple as shown next.

Let's assume our CMake-based project consists of two files: `main.cpp` and
`CMakeLists.txt`, whose contents are shown below:

----

**main.cpp**
{{ inputcpp('examples/cmake-project/main.cpp') }}

**CMakeLists.txt**

{{ inputcode('examples/cmake-project/CMakeLists.txt', 'cmake') }}

----

In the `CMakeLists.txt` file, note the use of the command:

```cmake
find_package(reaktplot)
```

to find the header files of the {{reaktplot}} library, and the command:

```cmake
target_link_libraries(app reaktplot::reaktplot)
```
to link the executable target `app` against the {{reaktplot}} library
(`reaktplot::reaktplot`) using CMake's modern target-based design.

To build the application, do:

```bash
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/reaktplot/install/dir
make
```

!!! attention

    If {{reaktplot}} has been installed system-wide, then the CMake argument
    `CMAKE_PREFIX_PATH` should not be needed. Otherwise, you will need to specify
    where {{reaktplot}} is installed in your machine. For example:

    ```bash
    cmake .. -DCMAKE_PREFIX_PATH=$HOME/local
    ```

    assuming directory `$HOME/local` is where {{reaktplot}} was installed to, which
    should then contain the following directory:

    ```
    $HOME/local/include/reaktplot/
    ```

    where the {{reaktplot}} header files are located.

To execute the application, do:

```bash
./app
```
