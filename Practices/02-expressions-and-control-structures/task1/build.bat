@echo off

setlocal EnableDelayedExpansion

chcp 65001 >nul

if not exist "build\" (
  mkdir "build"
)

cd build

if not exist "std.ifc" (
  cl /std:c++23preview /EHsc /utf-8 /c "%VCToolsInstallDir%\modules\std.ixx"
)

cl /std:c++23preview /EHsc /utf-8 /reference std.ifc ..\main.cpp std.obj

if %errorlevel% == 0 (
  main.exe
)