#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Warn.h"

class TextManager {
public:
	TextManager();
	~TextManager();
	void render(SDL_Renderer*, int, int) const;
	void initialise(SDL_Renderer*, const std::string&, int, const std::string, const SDL_Color&);
	void clear();
	SDL_Texture* update(SDL_Renderer*, const std::string&, int, const std::string, const SDL_Color&);
	TTF_Font* return_font();
private:
	SDL_Surface* surface;
	SDL_Texture* texture;
	mutable SDL_Rect rect;
	TTF_Font* font;
};

