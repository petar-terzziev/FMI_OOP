#include "flyweight_enemy.h"

Flyweight_Enemy::Flyweight_Enemy(int x,int y,const Enemy* e):Object::Object(x,y)
    ,concrete(e)
{
}
Flyweight_Enemy::Flyweight_Enemy():concrete(nullptr) {}
int Flyweight_Enemy::getheight()const
{
    concrete->getheight();
}
int Flyweight_Enemy::getwidth()const
{
    concrete->getwidth();
}
const char* Flyweight_Enemy::getshape()const
{
    concrete->getshape();
}
void Flyweight_Enemy::shoot(vector<Flyweight_Bullet>& bullets)
{
    Flyweight_Bullet b(concrete->getheight()/2+center.x,center.y-concrete->getwidth()-1,concrete->getBullet(),0);
    bullets.push_back(b);
}
bool Flyweight_Enemy::overlaps(vector<Flyweight_Enemy>& enemies)
{
    int dx,dy;
    for(int i=0; i<enemies.size(); i++)
    {
        dx=(center.x-enemies[i].center.x)>0? (center.x-enemies[i].center.x):(center.x-enemies[i].center.x)*(-1);
        dy=(center.y-enemies[i].center.y)>0? (center.y-enemies[i].center.y):(center.y-enemies[i].center.y)*(-1);
        if(dx<getheight()&&dy<getwidth()) return true;
    }
    return false;
}
Flyweight_Enemy::~Flyweight_Enemy()
{
}
