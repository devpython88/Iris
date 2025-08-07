## iris/iris_math.h

This module contains `Vec2`, `Vec3` and `Vec4`
And also `Boolean2`

You've already seen those in many paramater lists, But if you haven't, here are their fields:

`Vec2`: `float x; float y`
`Vec3`: `float x; float y; float z`
`Vec4`: `float x; float y; float z; float w`
`Boolean2`: `bool a; bool b`

The vectors also contain operator overloads for `+`, `-`, `*` and `/`
All overloads can take a single value or another vector of the class's kind

All vectors have an `xy`, `xyz`, and `xyzw` method for each one
They return the values added together
aswell as `area`, `volume` and `hypervolume`


### MathUtils

MathUtils has some utility functions.

- `isZero(float)`: Floating point numbers often have inaccuracies which makes them not be exactly zero, instead be something closer (0.00...01, 0.00...04), So this function checks if the absolute value of the float is below 1e-6 (epilson)
- `getManhattanDistance(Vec2 a, Vec2 b)`: Returns the manhattan distance (useful in grid but mostly not anywhere else)
- `getEuclideanDistance(Vec2 a, Vec2 b)`: Returns the euclidean distance (useful outside of grids)
- `getManhattanDistance(float x1, float y1, float x2, float y2)`: Returns the manhattan distance (useful in grid but mostly not anywhere else)
- `getEuclideanDistance(float x1, float y1, float x2, float y2)`: Returns the euclidean distance (useful outside of grids)