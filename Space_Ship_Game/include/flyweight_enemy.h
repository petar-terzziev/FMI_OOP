#ifndef FLYWEIGHT_ENEMY_H
#define FLYWEIGHT_ENEMY_H

#include "Object.h"
class Flyweight_Enemy;
class Flyweight_Bullet;
#include "flyweight_bullet.h"
#include "enemy.h"
class Enemy;
class Flyweight_Enemy : public Object
{
public:
    Flyweight_Enemy();
    Flyweight_Enemy(int x,int y,const Enemy* e);
    virtual ~Flyweight_Enemy();
    int getheight()const;
    int getwidth()const;
    const char* getshape()const;
    void shoot(vector<Flyweight_Bullet>&);
    bool overlaps(vector<Flyweight_Enemy>&);

protected:

private:
    const  Enemy* concrete;
};

#endif // FLYWEIGHT_ENEMY_H
