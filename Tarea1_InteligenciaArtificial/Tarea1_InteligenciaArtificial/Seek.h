#pragma once
#include <math.h>
#include <vector>
#include "Vector2D.h"
class Seek {
public:
    Vector2D seek(Vector2D target, Vector2D position, Vector2D velocity, 
        float maxspeed, float maxforce) {
        Vector2D desired = target.operator-(position);
        desired.normalize();
        desired.operator*= (maxspeed);
        Vector2D steer = desired.operator- (velocity);
        steer.limit(maxforce);
        return steer;
    }
};