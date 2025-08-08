cd build

echo "Making directories..."
# make dirs

if [ ! -e dist_unix ]; then
	mkdir dist_unix
	mkdir dist_unix/include
	mkdir dist_unix/lib
fi

echo "Enter build system (case sensitive)"
# read buidl system
read pBuildSys

echo "Generating cmake files..."
# generate files
cmake -G "$pBuildSys" ..

# if success then build
if [ $? -eq 0 ]; then
	echo "Building..."
	cmake --build .
	# if sucess then copy
	if [ $? -eq 0 ]; then
		echo "Copying files..."
		cp ./*.a dist_unix/lib
		cp -r ../src/iris dist_unix/include
		tar -czvf dist_unix.tar.gz dist_unix
		echo "done."
	fi
fi

cd ..
