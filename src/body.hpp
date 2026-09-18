#pragma once
#include<Vector2.hpp>

struct body{
    Vec2 Position;
    Vec2 Acceleration{0.0f,0.0f};
    Vec2 Velocity{0.0f,0.0f};
    float mass = 1.0f;
    float restitution = 0.75f;
    float invmass;
    float radius = 15.0f;
    body(const Vec2& v, float m , float r );
    Vec2 ForceAccummulator{0,0};
    void AddForce(const Vec2& v);
    void Integrate(float dt);
    void ClearForce();
    
};