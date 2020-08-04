#pragma once
#include <math.h>
#include <vector>
#include "Vector2D.h"
class Evade {
public:
    Vector2D evade(Vector2D target, Vector2D position, Vector2D velocity,
        float maxspeed, float maxforce) {

        Vector2D tv = target;
        tv.normalize();
        tv *= (40);
        Vector2D aheadvector = target + tv;


        Vector2D desired = aheadvector - (position);
        float d = desired.length();
        desired.normalize();
        Vector2D steer = desired - (velocity);
        if (d < 50)
        {
            desired*= (maxspeed);
            steer = velocity - desired;
        }
        else
        {
            desired *= (maxspeed);
        }
        // steer.limit(maxforce);
        return steer;
    }
};
