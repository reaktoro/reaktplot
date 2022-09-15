
# CMake-Based Project Using reaktplot

## Introduction
This example demonstrates how CMake's command `find_package` can be used to
resolve the dependency of an executable `app` on **reaktplot**, a header-only
C++17 library.

The source file `main.cpp` includes the header-file `reaktplot/forward.hpp` and
uses a forward mode automatic differentiation algorithm to compute the derivatives of a scalar function.

The `CMakeLists.txt` file uses the command:

```cmake
find_package(reaktplot)
```

to find the **reaktplot** header files. The executable target `app` is then
linked against the imported target `reaktplot::reaktplot`:

```cmake
target_link_libraries(app reaktplot::reaktplot)
```

## Building and Executing the Application
To build the application, do:

```bash
cd cmake-project
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/reaktplot/install/dir
make
```

To execute the application, do:

```bash
./app
```

Note: If **reaktplot** has been installed system-wide, then the CMake argument
`CMAKE_PREFIX_PATH` should not be needed. Otherwise, you will need to specify
where **reaktplot** is installed in your machine. For example:

```cmake
cmake .. -DCMAKE_PREFIX_PATH=$HOME/local
```

assuming directory `$HOME/local` is where **reaktplot** was installed to, which should then contain the following directory:

```
$HOME/local/include/reaktplot/
```

where the **reaktplot** header files are located.
