#include "window.h"

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) : _title(title), _width(width), _height(height)
{
	if(!init()){
		_closed = true;
	}
}

Window::~Window()
{	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Window::init()
{
	if(SDL_Init(SDL_INIT_VIDEO)){
		std::cerr << "Failed to initialize, window." << std::endl;
		return false;
	}

	if(IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG){
		std::cerr << "Failed to initialize, Image module." << std::endl;
		return false;
	}

	if(TTF_Init() < 0){
		std::cerr << "Failed to initialize, Text module." << std::endl;
		return false;
	}
	_window = SDL_CreateWindow(_title.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,_width,_height,0);

	if(_window == nullptr){
		std::cerr << "Failed to create Window" << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(renderer == nullptr){
		std::cerr << "Failed to create renderer" << std::endl;
		return false;
	}

	return true;	
}

void Window::pollEvents(SDL_Event &event)
{
	switch (event.type){
		case SDL_QUIT :
			_closed = true;
			break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					_closed = true;
					break;
			}
		default:
			break;
	}
}

void Window::clear() const
{
	SDL_RenderPresent(renderer);
	
	auto back = IMG_Load("res/back.png");

	if(!back){
		std::cerr << "Failed to create surface" << std::endl;
	}

	auto texture = SDL_CreateTextureFromSurface(renderer,back);
	
	SDL_FreeSurface(back);
	
	SDL_Rect temp = {0,0,_width,_height};

	SDL_RenderCopy(renderer,texture,nullptr,&temp); 
	//SDL_RenderClear(renderer);
}