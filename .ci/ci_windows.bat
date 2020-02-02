@ECHO OFF

SETLOCAL

IF "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2015" (
    SET CMAKE_IMAGE_NAME=Visual Studio 14 2015
    SET VS_DATE=vs2015
)

IF "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2017" (
    SET CMAKE_IMAGE_NAME=Visual Studio 15 2017
    SET VS_DATE=vs2017
)

IF "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2019" (
    SET CMAKE_IMAGE_NAME=Visual Studio 16 2019
    SET VS_DATE=vs2019
)

IF "%platform%"=="Win32" (
    SET CMAKE_GENERATOR_NAME=%CMAKE_IMAGE_NAME%
    SET "PROGRAM_FILES=Program Files (x86)"
)

IF "%platform%"=="x64" (
    SET CMAKE_GENERATOR_NAME=%CMAKE_IMAGE_NAME% Win64
    SET "PROGRAM_FILES=Program Files"
)

IF "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2019" (
    SET CMAKE_GENERATOR_NAME=%CMAKE_IMAGE_NAME%
    SET "PROGRAM_FILES=Program Files (x86)"
)

ECHO %image%
ECHO %platform%
ECHO %CMAKE_IMAGE_NAME%
ECHO %CMAKE_GENERATOR_NAME%
ECHO %PROGRAM_FILES%

CD C:\projects\Taktix\Submodules

CD SFML
git checkout 2.5.x
MD build
CD build
IF "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2019" (
    cmake -G "%CMAKE_GENERATOR_NAME%" -A "%platform%" -DCMAKE_BUILD_TYPE=Release ..
) ELSE (
    cmake -G "%CMAKE_GENERATOR_NAME%" -DCMAKE_BUILD_TYPE=Release ..
)
cmake --build . --config "Release"
cmake --build . --target INSTALL --config "Release"
CD ../..

DIR .

CD TGUI
git checkout 0.8
MD build
CD build
IF "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2019" (
    cmake -G "%CMAKE_GENERATOR_NAME%" -A "%platform%" -DCMAKE_BUILD_TYPE=Release -DSFML_ROOT="C:/%PROGRAM_FILES%/SFML/" ..
) ELSE (
    cmake -G "%CMAKE_GENERATOR_NAME%" -DCMAKE_BUILD_TYPE=Release -DSFML_ROOT="C:/%PROGRAM_FILES%/SFML/" ..
)
cmake --build . --config "Release"
cmake --build . --target INSTALL --config "Release"
CD ../../..

CD Build
IF "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2019" (
    cmake -G "%CMAKE_GENERATOR_NAME%" -A "%platform%" -DCMAKE_BUILD_TYPE=Release -DSFML_ROOT="C:/%PROGRAM_FILES%/SFML/" -DTGUI_ROOT="C:/%PROGRAM_FILES%/TGUI/" ..
) ELSE (
    cmake -G "%CMAKE_GENERATOR_NAME%" -DCMAKE_BUILD_TYPE=Release -DSFML_ROOT="C:/%PROGRAM_FILES%/SFML/" -DTGUI_ROOT="C:/%PROGRAM_FILES%/TGUI/" ..
)
cmake --build . --config "Release"

XCOPY ..\Submodules\SFML\build\lib\Release\*.dll Application\. /s /e /y
XCOPY ..\Submodules\TGUI\build\lib\Release\*.dll Application\. /s /e /y

DIR Application\
RD Application\CMakeFiles\ /s /q
DEL Application\cmake_install.cmake
DEL Application\Taktix.vcxproj
DEL Application\Taktix.vcxproj.filters
XCOPY Application\Release\Taktix.exe Application\. /y
RD Application\Release\ /s /q
RD Application\Taktix.dir\ /s /q
REN Application Taktix

MOVE C:\projects\Taktix\Build\Taktix C:\projects\Taktix\.