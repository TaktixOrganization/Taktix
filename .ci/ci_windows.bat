@echo off

setlocal

if "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2015" set CMAKE_IMAGE_NAME=Visual Studio 14 2015
if "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2017" set CMAKE_IMAGE_NAME=Visual Studio 15 2017

if "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2015" set VS_DATE=vs2015
if "%APPVEYOR_BUILD_WORKER_IMAGE%"=="Visual Studio 2017" set VS_DATE=vs2017

if "%platform%"=="Win32" set CMAKE_GENERATOR_NAME=%CMAKE_IMAGE_NAME%
if "%platform%"=="x64"   set CMAKE_GENERATOR_NAME=%CMAKE_IMAGE_NAME% Win64
if "%platform%"=="Win32" set PROGRAM_FILES=Program Files (x86)
if "%platform%"=="x64" set PROGRAM_FILES=Program Files

echo %image%
echo %platform%
echo %CMAKE_IMAGE_NAME%
echo %CMAKE_GENERATOR_NAME%

cd C:\projects\Taktix\Submodules

cd SFML
git checkout 2.5.x
md build
cd build
cmake -G "%CMAKE_GENERATOR_NAME%" -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config "Release"
cmake --build . --target INSTALL --config "Release"
cd ../..

dir .

cd TGUI
git checkout 0.8
md build
cd build
cmake -G "%CMAKE_GENERATOR_NAME%" -DCMAKE_BUILD_TYPE=Release -DSFML_ROOT="C:/%PROGRAM_FILES%/SFML/" ..
cmake --build . --config "Release"
cmake --build . --target INSTALL --config "Release"
cd ../../..

cd Build
cmake -G "%CMAKE_GENERATOR_NAME%" -DCMAKE_BUILD_TYPE=Release -DSFML_ROOT="C:/%PROGRAM_FILES%/SFML/" -DTGUI_ROOT="C:/%PROGRAM_FILES%/TGUI/" ..
cmake --build . --config "Release"

xcopy ..\Submodules\SFML\build\lib\Release\*.dll Application\. /s /e /y
xcopy ..\Submodules\TGUI\build\lib\Release\*.dll Application\. /s /e /y

dir Application\
rd Application\CMakeFiles\ /s /q
del Application\cmake_install.cmake
del Application\Taktix.vcxproj
del Application\Taktix.vcxproj.filters
xcopy Application\Release\Taktix.exe Application\. /y
rd Application\Release\ /s /q
rd Application\Taktix.dir\ /s /q
ren Application Taktix

move C:\projects\Taktix\Build\Taktix C:\projects\Taktix\.