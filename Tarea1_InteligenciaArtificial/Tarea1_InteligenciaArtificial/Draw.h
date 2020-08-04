#pragma once
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <array>
#include"SDL.h"

class Draw {
private:
public: 
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::array<SDL_Rect,8> agentes;
	void DrawWindow() {
		SDL_Init(SDL_INIT_VIDEO);
		window = SDL_CreateWindow("hola", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 500, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);
		DrawRects(0);
	}
    void DrawRects(int x) {
		SDL_Rect rect;
		rect.x = x;
		rect.y = 10;
		rect.w = 10;
		rect.h = 10;
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		agentes[0] = rect;
    }

	void Drawer(SDL_Renderer* rendr, SDL_Rect r) {
		SDL_SetRenderDrawColor(rendr, 255, 0, 0, 255);
		SDL_RenderFillRect(rendr, &r);
		SDL_RenderPresent(rendr);
	}
	void clear(SDL_Renderer* rendr) {
		SDL_SetRenderDrawColor(rendr, 0, 0, 255, 255);
		SDL_RenderClear(rendr);
		SDL_RenderPresent(rendr);
	}
};