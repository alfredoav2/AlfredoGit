// Tarea1_InteligenciaArtificial.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
#include <iostream>
#include <stdio.h>
#include"SDL.h"
#include"SDL_image.h"
#include "Draw.h"   
#include "Agente.h"

bool quit = false;
SDL_Renderer* gRenderer = NULL;
SDL_Event e;
void loop() {
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
	}
}

void close() {
	IMG_Quit();
	SDL_Quit();
}
int main(int argc, char* argv[])
{
	Agente agente = Agente(50,30);
	//agente.applyBehaviors(agente);
    while (!quit) {
		loop();
		agente.seek(Vector2D (100, 300));
		agente.Update();
    }

    return 0;
}
*/
#include <iostream>
#include <stdio.h>
#include"SDL.h"
#include"SDL_image.h"
#include "Draw.h"
#include "Agente.h"

bool quit = false;
SDL_Renderer* gRenderer = NULL;
SDL_Event e;
void loop() {
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
    }
}

void close() {
    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[])
{
    Agente agente = Agente(50, 30);
    while (!quit) {
        loop();
        agente.applyBehaviors(agente);
        agente.Update();
    }

    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
