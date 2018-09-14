#ifndef Object_H
#define Object_H
#include "vector.h"
#include "cstring"
#include "fstream"
struct Point
{
    int x,y;
};

class Object
{
public:
    Object();
    Object(int,int);
    virtual ~Object();
    void Setpoint(int, int);
    const Point& Getpoint() const;
    void Movepoint(int,int );
    virtual int getheight()const=0;
    virtual int getwidth()const=0;
    virtual const char* getshape()const=0;
protected:
    Point center;
};

#endif // Object_H
