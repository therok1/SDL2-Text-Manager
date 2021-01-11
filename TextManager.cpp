 #include "TextManager.h"

TextManager::TextManager() {
	
}

TextManager::~TextManager() {
	TTF_CloseFont(font);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void TextManager::initialise(SDL_Renderer* ren, const std::string& fontPath, int fontSize, const std::string messageText, const SDL_Color& colour) {
	texture = update(ren, fontPath, fontSize, messageText, colour);
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
}

void TextManager::render(SDL_Renderer* ren, int x, int y) const {
	rect.x = x;
	rect.y = y;
	SDL_RenderCopy(ren, texture, NULL, &rect);
}

SDL_Texture* TextManager::update(SDL_Renderer* ren, const std::string& fontPath, int fontSize, const std::string messageText, const SDL_Color& colour) {
	font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (!font) {
		Warn::warn("SDL failed to load font.", TTF_GetError());
	}
	SDL_Surface* surface = TTF_RenderText_Solid(font, messageText.c_str(), colour);
	if (!surface) {
		Warn::warn("SDL failed to create surface.", TTF_GetError());
	}
	texture = SDL_CreateTextureFromSurface(ren, surface);
	if (!texture) {
		Warn::warn("SDL failed to create text texture.", TTF_GetError());
	}
	return texture;
}

TTF_Font* TextManager::return_font() {
	return font;
}

void TextManager::clear() {
	TTF_CloseFont(font);
}
