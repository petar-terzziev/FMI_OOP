#include "concrete_object.h"

concrete_object::concrete_object():
    shape(nullptr)
    ,h(0)
    ,w(0)
{
}
concrete_object::concrete_object(int x,int y,const char* s,int ch,int cw):Object::Object(x,y)
    ,shape(new char[strlen(s)+1])
    ,h(ch)
    ,w(cw)

{
    strcpy(shape,s);
}
concrete_object::concrete_object(const concrete_object& rhs)
{
    coppy(rhs);
}
concrete_object& concrete_object::operator=(const concrete_object& rhs)
{
    if(this!=&rhs)
    {
        clearr();
        coppy(rhs);
    }
    return *this;
}
int concrete_object::getheight()const
{
    return h;
}
int concrete_object::getwidth()const
{
    return w;
}
const char* concrete_object::getshape()const
{
    return shape;
}
concrete_object::~concrete_object()
{
    clearr();
}
void concrete_object::coppy(const concrete_object& rhs)
{
    shape=new char[strlen(rhs.shape)+1];
    strcpy(shape,rhs.shape);
    center=rhs.center;
    h=rhs.h;
    w=rhs.w;
}
void concrete_object::clearr()
{
    delete [] shape;
}
