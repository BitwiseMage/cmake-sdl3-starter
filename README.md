## SDL3 Project Starter with CMake
Barebones CMake config to start a **C++17** project with **[SDL3](https://github.com/libsdl-org/SDL)**.

## Requirements:
- C++ compiler with support for version C++17
- [CMake v3.21](https://github.com/Kitware/CMake) _(earlier versions might work but haven't been tested)_

## How to run
### Using the helper scripts
> You need to have the compiler, [`CMake`](https://github.com/Kitware/CMake), and [`Ninja`](https://github.com/ninja-build/ninja) on your enviromnent variables.

- If on Windows, run the file `build_and_run_windows.bat`.
- If Linux or MacOS, run the file `build_and_run_bash.sh`.

### No IDE, using [Ninja](https://github.com/ninja-build/ninja):
- Clone the repository.
- [Optional] Rename all instances of `cmake-sdl3-starter` according to your preference.
- Run the project files generation command. Example: `cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja -S . -B build`.
    - `-DCMAKE_BUILD_TYPE=Debug` specifies the build type as `Debug`.
    - `-G Ninja` specifies the files generator. If you have Visual Studio 2022, it can be `-G "Visual Studio 17 2022"`.
    - `-S .` sets the directory where the root `CMakeLists.txt` file is (`.` means the current directory where the terminal is).
    - `-B build` sets the output directory for the generated files.
    
>NOTE: If you used `-G "Visual Studio 17 2022"`, open the `build` folder, open the solution and skip the following step.
- Build the project with: `cmake --build build`. 
    - Where `--build build` tells CMake that the previously generated files are in the `build` folder, which we set with `-B build` in the previous command.