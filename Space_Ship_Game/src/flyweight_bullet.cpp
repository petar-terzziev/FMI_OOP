#include "flyweight_bullet.h"

Flyweight_Bullet::Flyweight_Bullet(int x,int y,const Bullet* b,bool d):Object::Object(x,y)
    ,concrete(b)
    ,dir(d)
{
}
Flyweight_Bullet::Flyweight_Bullet():Object::Object()
    ,concrete(nullptr) {}
Flyweight_Bullet::~Flyweight_Bullet()
{
}
bool Flyweight_Bullet::check_collision(vector<Flyweight_Enemy>& enemies,Hero& hero)
{

    if(center.y<=hero.Getpoint().y+hero.getwidth()/2)
    {
        hero.Takelife();
        return true;
    }

    for(int i=0; i<enemies.size(); i++)
    {
        bool c1=(center.y>=enemies[i].Getpoint().y-enemies[i].getwidth()/2)&&(center.y<=enemies[i].Getpoint().y+enemies[i].getwidth()/2);
        bool c2=(center.x>=enemies[i].Getpoint().x-enemies[i].getheight()/2)&&(center.x/2<=enemies[i].Getpoint().x+enemies[i].getheight()/2);
        if(c1&&c2)
        {
            enemies.remove(i);
            return true;
        }
    }
    return false;
}
int Flyweight_Bullet::getheight()const
{
    concrete->getheight();
}
int Flyweight_Bullet::getwidth()const
{
    concrete->getwidth();
}
const char* Flyweight_Bullet::getshape()const
{
    concrete->getshape();
}
void Flyweight_Bullet::setbullet(const Bullet* hb)
{
    if(hb) concrete=hb;
}
bool Flyweight_Bullet::getdir()const
{
    return dir;
}
