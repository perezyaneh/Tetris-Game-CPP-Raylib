#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime =GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}
int main() 
{
    Color darkBlue = {44,44,127,255};
    InitWindow(300,600, "Tetris"); //Window Width and height
    SetTargetFPS(60); //Actual speed of the game set to 60 fps
    Game game = Game();

    while(WindowShouldClose() == false)
    {
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
}