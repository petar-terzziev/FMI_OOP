#ifndef ENEMY_H
#define ENEMY_H

#include "concrete_object.h"
#include "grid.h"

class Enemy : public concrete_object
{
public:
    Enemy();
    Enemy(int,int,const char*,int,int,const Bullet& b);
    const Bullet* getBullet()const;
    virtual ~Enemy();
    void save_to_file(std::ofstream&);
    void read_from_file(std::ifstream&);
    void setbullet(const Bullet*);
private:
    const Bullet* b;
};

#endif // ENEMY_H
