#include "raylib.h"
#include<Vector2.hpp>
#include<iostream>
#include<string>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "Custom Engine here we go");
    SetTargetFPS(60);
    Vec2 V1(5,6);
    Vec2 V2(3,4);
    float x;
    // Placeholder particle position
    Vector2 ballPos = { 400.0f, 300.0f };
    if(V1 != V2){
         x = 0;
    }else  x = 5.0;
    while (!WindowShouldClose()) {
        // Physics update would go here (Euler / Verlet)

        BeginDrawing();
            ClearBackground(BLACK);
            DrawText(TextFormat("Suck my dick %.1f", x), 20, 20, 18, LIGHTGRAY);
            DrawCircleV(ballPos, 15.0f, MAROON);
            DrawFPS(screenWidth - 90, 20);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
