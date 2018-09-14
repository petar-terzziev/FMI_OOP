#include "enemy.h"
Enemy::Enemy(int x,int y,const char* s,int eh,int ew,const Bullet& eb):
    concrete_object::concrete_object(x,y,s,ew,eh)
    ,b(&eb)
{}
Enemy::Enemy()
{}
Enemy::~Enemy()
{}
void Enemy::save_to_file(std::ofstream& file)
{

    int s=strlen(shape)+1;
    file.write(reinterpret_cast<char*>(&s),sizeof(int));
    file.write(shape,s);
    file.write(reinterpret_cast<char*>(&center),sizeof(Point));
    file.write(reinterpret_cast<char*>(&h),sizeof(int));
    file.write(reinterpret_cast<char*>(&w),sizeof(int));
    file.write(reinterpret_cast<char*>(&b),sizeof(Bullet*));
}
void Enemy::read_from_file(std::ifstream& file)
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
void Enemy::setbullet(const Bullet* hb)
{
    if(hb) b=hb;
}
const Bullet* Enemy::getBullet()const
{
    return b;
}
