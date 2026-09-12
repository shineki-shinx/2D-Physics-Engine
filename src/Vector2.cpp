#include "Vector2.hpp"
#include<cmath>

Vec2::Vec2(): x(0.0f),y(0.0){}

Vec2::Vec2(float x, float y){
    this -> x = x;
    this -> y = y;
}

float Vec2::Magnitude() const {
    return sqrt(x*x + y*y);
}
float Vec2::MaginitudeSquared() const {
    return (x*x + y*y);
}
Vec2 Vec2::operator + (const Vec2& v) const{    return Vec2((x+v.x), (y+v.y)); /* used parametarized constructor to avoid null initialization*/ }
Vec2 Vec2::operator - (const Vec2& v) const{    return Vec2(x - v.x, y - v.y);  }
Vec2 Vec2::operator * (const float n) const{    return Vec2(x*n, y*n);      }
Vec2 Vec2::operator / (const float n) const{    return Vec2(x/n,y/n);           }
Vec2 Vec2::operator = (const Vec2& v) {         return Vec2(v.x,v.y);            }
bool Vec2::operator == (const Vec2& v){ return x == v.x && y == v.y;}
bool Vec2::operator != (const Vec2& v) {return !(*this == v);}