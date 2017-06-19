#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "window.h"

class Player{

public:
    Player(int x,int y);
    ~Player();
    void draw();
    void pollEvents(SDL_Event event);
    inline int getX() const {return _xPos;}
    inline int getY() const {return _yPos;}

private:
    SDL_Texture *_playerTex;
    SDL_Rect _playerRect;
    int _xPos,_yPos;
    bool _keyLeft = false,_keyRight = false;
};

#endif