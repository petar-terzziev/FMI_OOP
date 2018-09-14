#include "bullet.h"
Bullet::Bullet(int x,int y,const char* str,int bh,int bw,bool d):
    concrete_object::concrete_object(x,y,str,bh,bw)
    ,dir(d)
{}
Bullet::Bullet()
{}
Bullet::Bullet(const Bullet& b):concrete_object::concrete_object(b) {}
bool Bullet::Getdir()const
{
    return dir;
}
void Bullet::save_to_file(std::ofstream& file)
{

    int s=strlen(shape)+1;
    file.write(reinterpret_cast<char*>(&s),sizeof(int));
    file.write(shape,s);
    file.write(reinterpret_cast<char*>(&center),sizeof(Point));
    file.write(reinterpret_cast<char*>(&h),sizeof(int));
    file.write(reinterpret_cast<char*>(&w),sizeof(int));
}
void Bullet::read_from_file(std::ifstream& file)
{
    clearr();
    int s;
    file.read(reinterpret_cast<char*>(&s),sizeof(int));
    shape=new char[s];
    file.read(shape,s);
    file.read(reinterpret_cast<char*>(&center),sizeof(Point));
    file.read(reinterpret_cast<char*>(&h),sizeof(int));
    file.read(reinterpret_cast<char*>(&w),sizeof(int));
}

Bullet::~Bullet()
{}


