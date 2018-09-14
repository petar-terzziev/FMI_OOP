#ifndef BULLET_H
#define BULLET_H

#include "concrete_object.h"

class Bullet : public concrete_object
{
public:
    Bullet();
    Bullet(int,int,const char*,int,int,bool);
    Bullet(const Bullet&);
    virtual ~Bullet();
    bool Getdir()const;
    void save_to_file(std::ofstream&);
    void read_from_file(std::ifstream&);

private:
    bool dir;


};

#endif // BULLET_H
