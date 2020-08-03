#include "Draw.h"

void Draw::DrawWindow() {
    SDL_Window* window;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("hola", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 500, SDL_WINDOW_OPENGL);
    Update();
}

void Draw::Update() {
    
}