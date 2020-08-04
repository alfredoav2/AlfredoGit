#pragma once
#include <math.h>
#include <vector>
#include "Vector2D.h"
class Flee {
public:
    Vector2D flee(Vector2D target, Vector2D position, Vector2D velocity,
        float maxspeed, float maxforce) {

        Vector2D mol = position.operator-(target);
        mol.normalize();
        Vector2D desired = mol.operator*(maxspeed);
        Vector2D steer = desired.operator- (velocity);
        //steer.limit(maxforce);
        return steer;
    }
};