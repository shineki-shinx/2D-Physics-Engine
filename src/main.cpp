#include "raylib.h"
#include<Vector2.hpp>
#include<iostream>
#include<string>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Custom Engine here we go");
    SetTargetFPS(60);
    // Defining Physical States
    Vec2 Velocity(0.0f,0); //initial toss
    Vec2 Acceleration (0, 980.0f); // 98px/s^2
    Vec2 Position(screenWidth/2,screenHeight/2); //initial position
    const float radius = 15.0f;
    const float CoeffOfElasciticity = 0.75f;

    
    while (!WindowShouldClose()) {
        // Physics update would go here (Euler / Verlet)
        float DeltaTime = GetFrameTime(); // Getting the time between frames
        
        // Euler's Integration
        Velocity = Velocity + (Acceleration * DeltaTime);
        Position = Position + (Velocity * DeltaTime);
        
        //Floor Collision 
        if ( Position.y + radius >= screenHeight){
            Position.y = screenHeight- radius;
            Velocity.y = -1*Velocity.y*CoeffOfElasciticity;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            //Draw baseline
            DrawLine(0, screenHeight-1, screenWidth, screenHeight-1, RED);
            DrawCircleV(Vector2{Position.x, Position.y }, radius, GREEN);
            DrawFPS(screenWidth - 90, 20);

            //Drawing Information
            DrawText(TextFormat("Position : (%.1f, %.1f)", Position.x, Position.y), 20, 20 , 18, RAYWHITE);
            DrawText(TextFormat("Velocity : (%.1f, %.1f)", Velocity.x, Velocity.y), 20, 60 , 18, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
