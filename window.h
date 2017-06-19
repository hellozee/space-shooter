#ifndef WINDOW
#define WINDOW

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Window{

public:

	Window(const std::string &title, int width, int height);
	~Window();

	void pollEvents(SDL_Event &event);
	void clear() const;

	inline bool isClosed() const {return _closed;}

private:

	bool init();


// Declarations

private:

	std::string _title;
	int _width, _height;
	bool _closed = false;
	SDL_Window *_window = nullptr;

public:
	static SDL_Renderer *renderer;
};

#endif
