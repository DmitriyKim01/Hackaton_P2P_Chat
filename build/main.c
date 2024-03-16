/*******************************************************************************************
*
*   LayoutName v1.0.0 - Tool Description
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 raylib technologies. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"
//#include  <Windows.h>

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 552;
    int screenHeight = 672;
    

    InitWindow(screenWidth, screenHeight, "layout_name");

    // layout_name: controls initialization
    //----------------------------------------------------------------------------------
    bool WindowBox000Active = true;
    bool Button001Pressed = false;
    bool TextBox002EditMode = false;
    char TextBox002Text[128] = "UserName";
    bool TextBox003EditMode = false;
    char TextBox003Text[128] = "Server IP (Optional)";
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        SetWindowState(FLAG_WINDOW_UNDECORATED);
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // raygui: controls drawing
        //----------------------------------------------------------------------------------
        if (WindowBox000Active)
        {
            WindowBox000Active = !GuiWindowBox((Rectangle) { 0, 0, 552, 672 }, "SAMPLE TEXT");
            Button001Pressed = GuiButton((Rectangle) { 72, 384, 408, 72 }, "SAMPLE TEXT");
            if (GuiTextBox((Rectangle) { 72, 120, 408, 72 }, TextBox002Text, 128, TextBox002EditMode)) TextBox002EditMode = !TextBox002EditMode;
            if (GuiTextBox((Rectangle) { 72, 240, 408, 72 }, TextBox003Text, 128, TextBox003EditMode)) TextBox003EditMode = !TextBox003EditMode;
        }
        else {
            EndDrawing();
            CloseWindow();
            return 0;
        }
        //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------

