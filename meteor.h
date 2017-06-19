#ifndef METEOR
#define METEOR

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "window.h"

class Meteor{

public:
    Meteor(int x,int y);
    ~Meteor();
    void draw();
    inline int getX() const {return _xPos;}
    inline int getY() const {return _yPos;}
    
private:
    SDL_Texture *_meteorTex;
    SDL_Rect _meteorRect;
     int _xPos,_yPos;
};

#endif