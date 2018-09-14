#ifndef HERO_H
#define HERO_H

#include "concrete_object.h"
class Flyweight_Bullet;
#include "Flyweight_Bullet.h"

class Hero : public concrete_object
{
public:
    Hero(int,int,const char*,int,int,const Bullet& b);
    virtual ~Hero();
    int Getlife()const
    {
        return life;
    }
    void Takelife();
    const Bullet* getbullet()const;
    void shoot(vector<Flyweight_Bullet>&);
    void save_to_file(std::ofstream&);
    void read_from_file(std::ifstream&);
    void setbullet(const Bullet*);
private:
    int life;
    const  Bullet* b;

};

#endif // HERO_H
