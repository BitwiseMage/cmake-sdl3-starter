@echo off
setlocal

cmake -DCMAKE_BUILD_TYPE=Debug -G Ninja -S . -B build
if %ERRORLEVEL% neq 0 (
    echo CMake configuration failed!
    pause
    exit /b %ERRORLEVEL%
)

cmake --build build
if %ERRORLEVEL% neq 0 (
    echo Build failed!
    pause
    exit /b %ERRORLEVEL%
)

for /r bin %%f in (*.exe) do (
    echo Running: %%f
    %%f
    pause
    exit /b %ERRORLEVEL%
)

echo No executable found in the bin folder!
pause
exit /b 1