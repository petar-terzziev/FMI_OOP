#include "hero.h"

void Hero::Takelife()
{
    life--;
}
void Hero::shoot(vector<Flyweight_Bullet>& bullets)
{
    Flyweight_Bullet b(this->h/2+center.x,this->w+1,this->b,1);
    bullets.push_back(b);
}
const Bullet* Hero::getbullet()const
{
    return b;
}
Hero::Hero(int x,int y,const char* s,int mh,int mw,const Bullet& mb):
    concrete_object::concrete_object(x,y,s,mh,mw),
    life(3)
    ,b(&mb)
{}
void Hero::save_to_file(std::ofstream& file)
{
    int s=strlen(shape)+1;
    file.write(reinterpret_cast<char*>(&s),sizeof(int));
    file.write(shape,s);
    file.write(reinterpret_cast<char*>(&center),sizeof(Point));
    file.write(reinterpret_cast<char*>(&h),sizeof(int));
    file.write(reinterpret_cast<char*>(&w),sizeof(int));
    file.write(reinterpret_cast<char*>(&life),sizeof(int));
    file.write(reinterpret_cast<char*>(&b),sizeof(Bullet*));
}
void Hero::read_from_file(std::ifstream& file)
{
    clearr();
    int s;
    std::cout<<s<<std::endl;
    file.read(reinterpret_cast<char*>(&s),sizeof(int));
    std::cout<<s<<std::endl;
    shape=new char[s];
    file.read(shape,s);
    file.read(reinterpret_cast<char*>(&center),sizeof(Point));
    file.read(reinterpret_cast<char*>(&h),sizeof(int));
    file.read(reinterpret_cast<char*>(&w),sizeof(int));
    file.read(reinterpret_cast<char*>(&life),sizeof(int));
}
void Hero::setbullet(const Bullet* hb)
{
    if(hb) b=hb;
}
Hero::~Hero()
{
}
