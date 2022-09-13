# Installation

{{reaktplot}} is a header-only library that needs a C++17-capable compiler.

It has no external dependencies for compiling! The only external runtime dependencies are [gnuplot-palettes] for providing color palettes (automatically handled for you) and a [gnuplot] executable.

Thus, please install [Gnuplot](http://www.gnuplot.info/)!.

Installing {{reaktplot}} is easy, since it is a *header-only library*. Follow the steps below.

## Download

Download {{reaktplot}} by git cloning its [GitHub repository][github]:

~~~shell
git clone https://github.com/reaktplot/reaktplot --recursive
~~~

## Installation by copying

Assuming the git cloned repository or extracted source code resides in a
directory named `reaktplot`, you can now copy the directory `reaktplot/reaktplot`
to somewhere in your project directory and directly use {{reaktplot}}.

This quick and dirty solution should suffice in most cases. If this solution
bothers you, read the next section!

## Installation using FetchContent

The [`FetchContent`](
https://cmake.org/cmake/help/latest/module/FetchContent.html) CMake module can
also be used to fetch Sciplot properly:

```cmake
include(FetchContent) # If not included already

FetchContent_Declare(reaktplot_content
  GIT_REPOSITORY https://github.com/reaktplot/reaktplot.git
  GIT_TAG master)

FetchContent_GetProperties(reaktplot_content)
if(NOT reaktplot_content_POPULATED)
  FetchContent_Populate(reaktplot_content)
endif()

include_directories(${reaktplot_content_SOURCE_DIR})
```

## Installation using CMake

If you have `cmake` installed in your system, you can then install {{reaktplot}}
(and also build its tests and examples) as follows:

~~~shell
mkdir build && cd build
cmake ..
cmake --build . --target install
~~~

!!! attention ""

    We assume above that you are in the root of the source code directory, under
    `reaktplot`! The build directory will be created at `reaktplot/build`.

The previous installation commands will require administrative rights in most
systems. To install {{reaktplot}} locally, use:

~~~shell
cmake .. -DCMAKE_INSTALL_PREFIX=/some/local/dir
~~~

[github]: https://github.com/reaktplot/reaktplot
[zip]: https://github.com/reaktplot/reaktplot/archive/master.zip

## Installation failed. What do I do?

Check the [known issues](known_issues.md) and if your problem persists, create a [new issue][issues], and let us know what happened and possibly how we can improve the installation process of {{reaktplot}}.

[issues]: https://github.com/reaktplot/reaktplot/issues/new
