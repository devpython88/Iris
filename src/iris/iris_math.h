#pragma once
#include <raylib.h>
#include <cmath>

#define ORIGIN_TOPLEFT      Vec2(0.0f, 0.0f)
#define ORIGIN_TOPRIGHT     Vec2(1.0f, 0.0f)
#define ORIGIN_TOP          Vec2(0.5f, 0.0f)
#define ORIGIN_CENTERLEFT   Vec2(0.0f, 0.5f)
#define ORIGIN_CENTER       Vec2(0.5f, 0.5f)
#define ORIGIN_CENTERRIGHT  Vec2(1.0f, 0.5f)
#define ORIGIN_BOTTOMLEFT   Vec2(0.0f, 1.0f)
#define ORIGIN_BOTTOM       Vec2(0.5f, 1.0f)
#define ORIGIN_BOTTOMLRIGHT Vec2(1.0f, 1.0f)


class Vec2 {
    public:
    float x, y;


    Vec2() = default;
    Vec2(float x, float y): x(x), y(y){}

    float xy(){ return x + y; }
    float area(){ return x * y; }

    operator Vector2(){
        return Vector2{x, y};
    }

    Vec2 operator+(Vec2 v){
        return Vec2(v.x + x, v.y + y);
    }

    Vec2 operator+(float scalar){
        return Vec2(scalar + x, scalar + y);
    }

    Vec2 operator-(Vec2 v){
        return Vec2(v.x - x, v.y - y);
    }

    Vec2 operator-(float scalar){
        return Vec2(scalar - x, scalar - y);
    }

    Vec2 operator*(Vec2 v){
        return Vec2(v.x * x, v.y * y);
    }

    Vec2 operator*(float scalar){
        return Vec2(scalar * x, scalar * y);
    }

    Vec2 operator/(Vec2 v){
        return Vec2(v.x / x, v.y / y);
    }

    Vec2 operator/(float scalar){
        return Vec2(scalar / x, scalar / y);
    }
};

class Vec3 {
public:
    float x, y, z;

    Vec3() = default;
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    float xyz() { return x + y + z; }
    float volume() { return x * y * z; }

    operator Vector3() {
        return Vector3{x, y, z};
    }

    Vec3 operator+(Vec3 v) {
        return Vec3(v.x + x, v.y + y, v.z + z);
    }

    Vec3 operator+(float scalar) {
        return Vec3(scalar + x, scalar + y, scalar + z);
    }

    Vec3 operator-(Vec3 v) {
        return Vec3(v.x - x, v.y - y, v.z - z);
    }

    Vec3 operator-(float scalar) {
        return Vec3(x - scalar, y - scalar, z - scalar);
    }

    Vec3 operator*(Vec3 v) {
        return Vec3(v.x * x, v.y * y, v.z * z);
    }

    Vec3 operator*(float scalar) {
        return Vec3(scalar * x, scalar * y, scalar * z);
    }

    Vec3 operator/(Vec3 v) {
        return Vec3(x / v.x, y / v.y, z / v.z);
    }

    Vec3 operator/(float scalar) {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }
};

class Vec4 {
public:
    float x, y, z, w;

    Vec4() = default;
    Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    float xyzw() { return x + y + z + w; }
    float hypervolume() { return x * y * z * w; }

    operator Vector4() {
        return Vector4{x, y, z, w};
    }

    Vec4 operator+(Vec4 v) {
        return Vec4(v.x + x, v.y + y, v.z + z, v.w + w);
    }

    Vec4 operator+(float scalar) {
        return Vec4(scalar + x, scalar + y, scalar + z, scalar + w);
    }

    Vec4 operator-(Vec4 v) {
        return Vec4(v.x - x, v.y - y, v.z - z, v.w - w);
    }

    Vec4 operator-(float scalar) {
        return Vec4(x - scalar, y - scalar, z - scalar, w - scalar);
    }

    Vec4 operator*(Vec4 v) {
        return Vec4(v.x * x, v.y * y, v.z * z, v.w * w);
    }

    Vec4 operator*(float scalar) {
        return Vec4(scalar * x, scalar * y, scalar * z, scalar * w);
    }

    Vec4 operator/(Vec4 v) {
        return Vec4(x / v.x, y / v.y, z / v.z, w / v.w);
    }

    Vec4 operator/(float scalar) {
        return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
    }
};




class Boolean2 {
    public:
    bool a, b;

    Boolean2() = default;
    Boolean2(bool a, bool b): a(a), b(b){}
};