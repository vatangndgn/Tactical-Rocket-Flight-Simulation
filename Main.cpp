#include "raylib.h"
#include "Rocket.h"
#include <cmath>

int main() {
    const int screenWidth = 1000;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Defense Industry - Tactical Rocket Overview");
    SetTargetFPS(60);

    Rocket rkt(45.0, 6.0, 3900.0, 2.5, 0.38, 0.005);
    bool isCrashed = false;
    while (!WindowShouldClose()) {
        double dt = (double)GetFrameTime();

        if (!isCrashed) {
            rkt.update(dt);
            if (rkt.getFlightTime() > 0.5 && rkt.getY() <= 0.0) {
                isCrashed = true;
            }
        }

        BeginDrawing();
        ClearBackground(SKYBLUE);

        // Ground
        float groundY = (float)(screenHeight - 100) + (float)(rkt.getY() * 1.5);
        if (groundY < (float)(screenHeight + 200)) {
            DrawRectangle(0, (int)groundY, screenWidth, screenHeight, DARKGREEN);
        }

        // Rocket
        Vector2 center = { (float)screenWidth / 2.0f, (float)screenHeight / 2.0f };
        float drawAngle = (float)(-rkt.getAngle() * (180.0 / 3.14159265));
        float radAngle = (float)(-rkt.getAngle());

        // Rocket Main Body
        Rectangle rocketBody = { center.x, center.y, 120.0f, 24.0f };
        Vector2 bodyOrigin = { 60.0f, 12.0f };
        DrawRectanglePro(rocketBody, bodyOrigin, drawAngle, DARKGRAY);

        // sharp tip 
        Vector2 noseTip = {
            center.x + cosf(radAngle) * 140.0f,
            center.y + sinf(radAngle) * 140.0f
        };
        Vector2 noseTop = {
            center.x + cosf(radAngle) * 60.0f - sinf(radAngle) * 12.0f,
            center.y + sinf(radAngle) * 60.0f + cosf(radAngle) * 12.0f
        };
        Vector2 noseBottom = {
            center.x + cosf(radAngle) * 60.0f + sinf(radAngle) * 12.0f,
            center.y + sinf(radAngle) * 60.0f - cosf(radAngle) * 12.0f
        };

        DrawTriangle(noseTop, noseBottom, noseTip, MAROON);
        DrawTriangle(noseBottom, noseTop, noseTip, MAROON);

        // Dynamic exhaust plume rendering
        if (rkt.getFuel() > 0.0) {
            float tailX = center.x - cosf(radAngle) * 65.0f;
            float tailY = center.y - sinf(radAngle) * 65.0f;

            float flameSize = (float)GetRandomValue(15, 30);
            DrawCircleV({ tailX, tailY }, flameSize, ORANGE);
            DrawCircleV({ tailX - cosf(radAngle) * 10.0f, tailY - sinf(radAngle) * 10.0f }, flameSize - 8.0f, YELLOW);
        }

        //TELEMETRY PANEL
       
        DrawRectangle(10, 10, 260, 120, Fade(BLACK, 0.8f));
        DrawRectangleLines(10, 10, 260, 120, LIME);
        DrawText(TextFormat("ALTITUDE : %.1f m", rkt.getY()), 20, 20, 20, LIME);
        DrawText(TextFormat("SPEED    : %.1f m/s", rkt.getSpeed()), 20, 45, 20, LIME);
        DrawText(TextFormat("FUEL  : %.1f kg", rkt.getFuel()), 20, 70, 20, LIME);
        DrawRectangle(270, 10, 270, 120, Fade(BLACK, 0.8f));
        DrawRectangleLines(270, 10, 270, 120, LIME);
        DrawText(TextFormat("MAX ALT: %.1f m", rkt.gethMax()), 280, 20, 20, LIME);
        DrawText(TextFormat("MAX SPEED: %.1f m/s", rkt.getMaxV()), 280, 45, 20, LIME);
        DrawText(TextFormat("FLIGHT TIME: %.1f s", rkt.getFlightTime()), 280, 70, 20, LIME);
        DrawText(TextFormat("RANGE : %.1f km", rkt.getX()/1000), 280, 95, 20, LIME);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}