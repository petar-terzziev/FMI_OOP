#include "Object.h"

Object::Object():
    center{-1,-1}
{}
Object::Object(int x,int y):
    center{x,y}
{}
const Point& Object::Getpoint()const
{
    return center;
}
void Object::Movepoint(int x,int y)
{

    center.x+=x;
    center.y+=y;
}
void Object::Setpoint(int x,int y)
{
    if(x>=0&&y>=0)
    {
        center.x=x;
        center.y=y;
    }
}
Object::~Object()
{}
