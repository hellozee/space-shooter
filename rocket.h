#ifndef ROCKET
#define ROCKET

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "window.h"

class Rocket{

public:
    Rocket(int x,int y);
    ~Rocket();
    void draw();
    inline int getX() const {return _xPos;}
    inline int getY() const {return _yPos;}

private:
    SDL_Texture *_rocketTex;
    SDL_Rect _rocketRect;
    int _xPos,_yPos;
};

#endif