/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** GraphicLib
*/

#include "GraphicLib.hpp"

GraphicLib::GraphicLib()
{
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(DEFAULT_FPS);

    Vector3 position = {0.0f, 0.0f, 0.0f};
    Vector3 target = {0.0f, 0.0f, 0.0f};
    Vector3 up = {0.0f, 1.0f, 0.0f};

    _camera.position = position;                        // Camera position
    _camera.target = target;                            // Camera looking at point
    _camera.up = up;                                    // Camera up vector (rotation towards target)
    _camera.fovy = 45.0f;                               // Camera field-of-view Y
    _camera.projection = CAMERA_PERSPECTIVE;            // Camera projection type
}

GraphicLib::~GraphicLib()
{
    if (!WindowShouldClose())
        CloseWindow();
}

bool GraphicLib::isWindowOpen()
{
    return !WindowShouldClose();
}

void GraphicLib::clear()
{
    ClearBackground(Color{225, 206, 173, 255});
}

void GraphicLib::startDraw()
{
    if (!isWindowOpen())
        return;
    BeginDrawing();
}

void GraphicLib::endDraw()
{
    if (!isWindowOpen())
        return;
    EndDrawing();
}

bool GraphicLib::closeWindow()
{
    if (isWindowOpen()) {
        CloseWindow();
        return true;
    }
    return false;
}

std::pair<int, int> GraphicLib::getMousePosition()
{
    return std::make_pair<int, int>(GetMouseX(), GetMouseY());
}

std::pair<float, float> GraphicLib::getSizeWithWindow(float width, float height)
{
    return std::pair<float, float>{width * GetScreenWidth() / DEFAULT_WINDOW_WIDTH, height * GetScreenHeight() / DEFAULT_WINDOW_HEIGHT};
}

void GraphicLib::drawTexture(std::string texturePath, float posx, float posy, float scale, Color Color)
{
    if (!isWindowOpen())
        return;
    if (_textures.find(texturePath) == _textures.end())
        _textures[texturePath] = LoadTexture(texturePath.c_str());

    std::pair<float, float> positionPair = getSizeWithWindow(posx, posy);
    Vector2 position = {positionPair.first, positionPair.second};

    DrawTextureEx(_textures[texturePath], position, 0, getScaleWithWindow(scale), Color);
}

float GraphicLib::getScaleWithWindow(float scale)
{
    float windowScaleX = (float)GetScreenWidth() / DEFAULT_WINDOW_WIDTH;
    float windowScaleY = (float)GetScreenHeight() / DEFAULT_WINDOW_HEIGHT;
    return (windowScaleX < windowScaleY) ? windowScaleX * scale : windowScaleY * scale;
}

void GraphicLib::drawRectangle(int x, int y, float width, float height)
{
    DrawRectangleLines(x, y, width, height, Color{0,0,0,255});
}
