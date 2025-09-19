# Heaps

This repository goes over some of the basics of the heap data structure.

## Building Executables With CMake Via the Terminal

You can use [CMake][cmake] to compile and build the executables for the project. First, you need to create a `build/` directory in the project. The build directory will house all of the compiled files as well as the `Makefile` for the project. Note that we do NOT check the `build/` directory into version control since each person will have to regenerate the executables on their own machine.

```bash
mkdir build
cd build
```

Once you are inside of the build directory, you can run the following command to build all of the executables for the project:

```bash
cmake .. && make
```

## Building Executables With CMake Via an IDE

Many IDEs like [CLion][clion] and [Visual Studio][vs] have built-in support for CMake. You should be able to open the project and the IDE will automatically detect the `CMakeLists.txt` file. Then, the IDE will build all of the artifacts listed in the file.

[clion]: https://www.jetbrains.com/clion/
[cmake]: https://cmake.org/
[vs]: https://visualstudio.microsoft.com/
