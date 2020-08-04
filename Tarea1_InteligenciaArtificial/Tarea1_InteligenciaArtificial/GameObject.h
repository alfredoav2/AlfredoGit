#pragma once
#include "Vector2D.h"

class GameObject
{
protected:
    Vector2D pos;

public:

    float GetX()
    {
        return pos.getX();
    }

    float GetY()
    {
        return pos.getY();
    }

    void SetX(float x)
    {
        this->pos.setX(x);
    }

    void SetY(float y)
    {
        this->pos.setY(y);
    }
    Vector2D GetPos()
    {
        return pos;
    }
    virtual void Update() = 0;
};