#include "meteor.h"

/*int _xPos = 0;
int _yPos = 0;*/

Meteor::Meteor(int x,int y)
{
    _xPos = x;
    _yPos = y;
}

Meteor::~Meteor()
{

}

void Meteor::draw()
{
    auto surface = IMG_Load("res/sprites/rock.png");

    if(!surface){
        std::cerr << "Unable to load meteor." << std::endl;
    }

    _meteorTex = SDL_CreateTextureFromSurface(Window::renderer,surface);

    SDL_FreeSurface(surface);

    _meteorRect = {_xPos,_yPos,43,42};
    _yPos += 3;

    SDL_RenderCopy(Window::renderer,_meteorTex,nullptr,&_meteorRect);
}