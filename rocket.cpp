#include "rocket.h"

/*int _xPos = 0;
int _yPos = 0;*/

Rocket::Rocket(int x,int y)
{
    _xPos = x;
    _yPos = y;
}

Rocket::~Rocket()
{

}

void Rocket::draw()
{
    auto surface = IMG_Load("res/sprites/rocket.png");

    if(!surface){
        std::cerr << "Unable to load rocket." << std::endl;
    }

    _rocketTex = SDL_CreateTextureFromSurface(Window::renderer,surface);

    SDL_FreeSurface(surface);

    _rocketRect = {_xPos,_yPos,15,30};
    _yPos -= 5;

    SDL_RenderCopy(Window::renderer,_rocketTex,nullptr,&_rocketRect);
}