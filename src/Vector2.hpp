#pragma once

struct Vec2{
    float x,y;

    Vec2(); // Default Constructor
    Vec2(float x,float y); // parameterized Constructor
    ~Vec2() = default; // Default Destructor

    float Magnitude() const; // the resultant 
    float MaginitudeSquared() const;// x^2 + y^2

    Vec2 operator = (const Vec2& v); // v1=v2
    bool operator == (const Vec2& v); // v1 == v2
    bool operator != (const Vec2& v); // v1 != v2

    Vec2 operator + (const Vec2& v) const; // v1 + v2
    Vec2 operator - (const Vec2& v) const; // v1 - v2
    Vec2 operator * (const float n) const; // v1*n
    Vec2 operator / (const float n) const; // v1/n
    Vec2 operator - (); // v1 = -v1

    Vec2 operator += (const Vec2& v);
    Vec2 operator -= (const Vec2& v);
    Vec2 operator *= (const float n);
    Vec2 operator /= (const float n);

};