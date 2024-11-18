/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** GraphicLib
*/

#pragma once

#include "raylib.h"
#include "Rules.hpp"

#include <iostream>
#include <unordered_map>

class GraphicLib {

    public:

        GraphicLib();

        ~GraphicLib();

        bool isWindowOpen();

        void clear();

        void startDraw();

        void endDraw();

        bool closeWindow();

        std::pair<int, int> getMousePosition();

        void drawTexture(std::string texturePath, float posx, float posy, float scale, Color Color);

        std::pair<float, float> getSizeWithWindow(float width, float height);

        float getScaleWithWindow(float scale);

        void drawRectangle(int x, int y, float width, float height);

        bool isMouseButtonReleased(int button);


    private:

        Camera                                      _camera;        //< Player camera.
        std::unordered_map<std::string, Texture2D>  _textures;      //< List textures loaded.
};
