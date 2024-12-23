#include <iostream>
#include "raylib.h"


int main() {
    constexpr int windowWidth{512};
    constexpr int windoeHeight{380};

    SetTargetFPS(60);
    InitWindow(windowWidth, windoeHeight, "Dapper Dasher!");

    // (pixels/frame)/frame (pixels/s)/s
    constexpr int gravity{1'000};

    //texture
    Texture2D scarfy = LoadTexture("../textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;

    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windoeHeight - scarfyRec.height;

    int frame{};
    // amount of time before we update the animation frame
    float updateTime{1.0/12.0};


    float runningTime{};

    bool jumped;
    //pixel/second
    const int jumpVel{-600};

    int rVelocity{0};
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        const float dT{GetFrameTime()};

        if(scarfyPos.y >= windoeHeight - scarfyRec.height)
        {
            rVelocity = 0;
            scarfyPos.y = windoeHeight - scarfyRec.height;
            jumped = false;
        } else {
            rVelocity += gravity * dT;
            jumped = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !jumped) {
            rVelocity += jumpVel;
        }



        scarfyPos.y += rVelocity * dT;

        scarfyRec.x = frame * scarfyRec.width;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        runningTime += dT;
        if (runningTime >= updateTime) {
            runningTime = 0;
            frame++;
        }

        if (frame % 60 == 0) {
            frame = 0;
        }

        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();
}
