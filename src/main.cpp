#include "raylib.h"
#include<Vector2.hpp>
#include "body.hpp"
#include<vector>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Custom Engine here we go");
    SetTargetFPS(60);
    // Defining Physical States
    Vec2 Gravity (0, 980.0f); // 98px/s^2
    Vec2 Position(screenWidth/2,screenHeight/2); //initial position
    Vec2 FrictionCoEff(-4,0);
    std::vector<body> b;
    // Lighter Ball
    body BallA(Vec2{200.0f,100.0f}, 1.0f,15.0f);
    BallA.Velocity = Vec2{0,0};
    BallA.restitution = 0.85f;
    b.push_back(BallA);

    body BallB(Vec2{400.0f,300.0f}, 5.0f, 20.0f);
    BallB.Velocity = Vec2{0.0f,0.0f};
    BallB.restitution = 0.5f;
    b.push_back(BallB);

    while (!WindowShouldClose()) {
        // Physics update would go here (Euler / Verlet)
        float DeltaTime = GetFrameTime(); // Getting the time between frames
    
        BeginDrawing();
            ClearBackground(BLACK);
            
            for( auto& bodies : b){
            bodies.AddForce(Gravity* bodies.mass); //Gravity W= mg
            bodies.AddForce(Vec2{0.0f,0.0f}); // Force Generator
            bodies.Integrate(DeltaTime); // Sympletic Euler Integration
            //FLoor collisions
              if ( bodies.Position.y + bodies.radius >= screenHeight){
            bodies.Position.y = screenHeight- bodies.radius;
            bodies.Velocity.y = -1*bodies.Velocity.y*bodies.restitution;
        }
            //Friction handling Prototype
            if (bodies.Velocity.x <= 0){
                bodies.Acceleration = Vec2(0,980.0f);
                FrictionCoEff = Vec2(0,0);
            }else bodies.Velocity.x -= FrictionCoEff.x;
            
            
            
            DrawCircleV(Vector2{bodies.Position.x,bodies.Position.y},bodies.radius, RED);
            DrawText(TextFormat("Position : (%.1f, %.1f)", bodies.Position.x, bodies.Position.y), 20, 20 , 18, RAYWHITE);
            DrawText(TextFormat("Velocity : (%.1f, %.1f)", bodies.Velocity.x, bodies.Velocity.y), 20, 60 , 18, RAYWHITE);
            Vec2 ValEnd = bodies.Position + bodies.Velocity*0.1f; //drawing the line
            DrawLineV(Vector2{bodies.Position.x,bodies.Position.y},Vector2{bodies.Position.x,bodies.Position.y},LIME);
        }
        
           
            DrawFPS(screenWidth - 90, 20);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
