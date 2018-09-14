#ifndef FLYWEIGHT_BULLET_H
#define FLYWEIGHT_BULLET_H

#include "Object.h"
#include "bullet.h"
class Flyweight_Enemy;
#include"flyweight_enemy.h"
class Hero;
class Flyweight_Bullet : public Object
{
public:
    Flyweight_Bullet();
    Flyweight_Bullet(int,int,const Bullet*,bool);
    virtual ~Flyweight_Bullet();
    int getheight()const;
    int getwidth()const;
    const char* getshape()const;
    bool getdir()const;
    void setbullet(const Bullet*);
    bool check_collision(vector<Flyweight_Enemy>&,Hero&);

private:
    const   Bullet* concrete;
    bool dir;
};

#endif // FLYWEIGHT_BULLET_H
