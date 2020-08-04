/*#pragma once
#include"Draw.h"
#include"Vector2D.h"
#include"Seek.h"

class Agente{
public:
	Vector2D position = Vector2D(0,0);
	Vector2D velocity = Vector2D(0, 0);
	Vector2D acceleration = Vector2D(0, 0);
	Seek* seeker;
	Draw* draw = new Draw();
	float r;
	float maxforce;
	float maxspeed;

	Agente(float x, float y) {
		seeker = new Seek();
		draw->DrawWindow();
		position = Vector2D(x, y);
		r = 6;
		maxspeed = 10;
		maxforce = 2;
		acceleration = Vector2D(0, 0);
		velocity = Vector2D(0, 0);
	}

	void ApplyForces(Vector2D force) {
		acceleration = acceleration.operator+(force);
	}

	void applyBehaviors(Agente agentes) {
	}

	void seek(Vector2D target) {
		Vector2D desired = target.operator-(position);
		desired.normalize();
		Vector2D steer = desired.operator- (velocity);
		steer.limit(maxforce);
		ApplyForces(steer);
	}

	void Update() {

		/*Vector2D mol = target.operator-(position);
		mol.normalize();
		velocity = mol.operator*(maxspeed);
		velocity = velocity.operator+(acceleration);
		velocity.limit(maxspeed);
		*/
		/*velocity = velocity.operator+(acceleration);
		velocity.limit(maxspeed);
		position = position.operator+(velocity);
		acceleration.operator*=(0);
		draw->agentes[0].x = position.getX();
		draw->agentes[0].y = position.getY();
		draw->clear(draw->renderer);
		draw->Drawer(draw->renderer, draw->agentes[0]);
	}
};*/

#pragma once
#include"Draw.h"
#include"Vector2D.h"
#include"Seek.h"
#include"Flee.h"
#include"Arrival.h"
#include"Evade.h"

class Agente {
public:
	Vector2D position = Vector2D(0, 0);
	Vector2D velocity = Vector2D(0, 0);
	Vector2D acceleration = Vector2D(0, 0);
	Vector2D target = Vector2D(100, 300);
	Seek seeker;
	Flee fleeing;
	Evade evade;
	Draw* draw = new Draw();

	SDL_Event e;

	float r;
	float maxforce;
	float maxspeed;

	int xPrincipal;
	int yPrincipal;

	Agente(float x, float y) {
		draw->DrawWindow();
		position = Vector2D(x, y);
		r = 6;
		maxspeed = 5;
		maxforce = 2;
		acceleration = Vector2D(0, 0);
		velocity = Vector2D(0, 0);
	}

	void ApplyForces(Vector2D force) {
		acceleration = acceleration.operator+(force);
	}

	void applyBehaviors(Agente agentes) {
		//Vector2D seekForce = seeker.seek(Vector2D(xPrincipal, yPrincipal), position, velocity, maxspeed, maxforce);
		//Vector2D seekForce = seeker.seek(target, position, velocity, maxspeed, maxforce);
		// Vector2D seekForce = seektl(target, position, velocity, maxspeed, maxforce);
		// seekForce=(1);
		//ApplyForces(seekForce);
		Vector2D fleeForce = fleeing.flee(target, position, velocity, maxspeed, maxforce);
		ApplyForces(fleeForce);
	}

	void Update() {
		velocity = velocity.operator+(acceleration);
		//velocity.limit(maxspeed);
		position = position.operator+(velocity);
		acceleration.operator*= (0);
		draw->agentes[0].x = position.getX();
		draw->agentes[0].y = position.getY();
		draw->clear(draw->renderer);
		draw->Drawer(draw->renderer, draw->agentes[0]);

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				xPrincipal = e.button.x;
				yPrincipal = e.button.y;
			}
		}
	}
};