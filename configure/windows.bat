@echo off

echo Making directories

cd build

if not exist dist_win (
	mkdir dist_win
	mkdir dist_win\include
	mkdir dist_win\lib
)

echo Enter cmake build system (case sensitive)
set /p pBs=

echo Generating files...
cmake -G "%pBs%" ..

if errorlevel==0 (
	echo Building...
	cmake --build .
	if errorlevel==0 (
		echo Copying
		copy .\libiris.a dist_win\lib
		copy .\iris.lib dist_win\lib
		xcopy ..\src\iris dist_win\include
		echo Done.
	)
)
