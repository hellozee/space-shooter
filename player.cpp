#include "player.h"

Player::Player(int x,int y)
{
    _xPos = x;
    _yPos = y;
}

Player::~Player()
{

}

void Player::draw()
{
    auto surface = IMG_Load("res/sprites/ship.png");

    if(!surface){
        std::cerr << "Unable to load player." << std::endl;
    }

    _playerTex = SDL_CreateTextureFromSurface(Window::renderer,surface);

    SDL_FreeSurface(surface);

    _playerRect = {_xPos,_yPos,42,65};

    if(_keyLeft && _xPos > 0){
        _xPos -= 5;
    }

    if(_keyRight && _xPos < 289){
        _xPos += 5;
    }

    SDL_RenderCopy(Window::renderer,_playerTex,nullptr,&_playerRect);
}

void Player::pollEvents(SDL_Event event)
{   
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_LEFT:
                if(_xPos > 0){
                    _keyLeft = true;
                }
                break;
            case SDLK_RIGHT:
                if(_xPos < 289){
                    _keyRight = true;
                }
                break;
        }
    }else if(event.type = SDL_KEYUP){
        _keyLeft = false;
        _keyRight = false;
    }
}