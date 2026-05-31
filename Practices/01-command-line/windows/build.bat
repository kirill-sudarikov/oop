@echo off

chcp 65001 >nul

if not exist build\windows (
	mkdir build\windows
)

cl ^
	/Fo: build\windows\ ^
	/Fe: build\windows\practice1.exe ^
	main.c

if %errorlevel% == 0 (
	build\windows\practice1.exe
)