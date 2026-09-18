#include "body.hpp"

body::body(const Vec2& v, float m , float r) : Position(v),mass(m), radius(r){
    if (m > 0.0f) invmass = 1.0f/m;
    else invmass = 0.0f;
}
void body::AddForce(const Vec2& v){
    ForceAccummulator += v;
}

void body::Integrate(float dt){
        if(invmass == 0.0f) return;
        Acceleration = ForceAccummulator *invmass;
        Velocity += Acceleration*dt ;
        Position += Velocity *dt;

        ClearForce();
}   

void body::ClearForce(){
    ForceAccummulator = Vec2(0.0f,0.0f);
}