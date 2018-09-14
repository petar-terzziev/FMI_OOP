#ifndef CONCRETE_OBJECT_H
#define CONCRETE_OBJECT_H

#include "object.h"


class concrete_object : public Object
{
public:
    concrete_object();
    concrete_object(const concrete_object&);
    concrete_object(int,int,const char*,int,int);
    concrete_object& operator=(const concrete_object&);
    int getheight()const;
    int getwidth()const;
    const char* getshape()const;
    virtual ~concrete_object();
    virtual   void save_to_file(std::ofstream&)=0;
    virtual  void read_from_file(std::ifstream&)=0;

protected:
    void coppy(const concrete_object&);
    void clearr();
    char* shape;
    int h,w;
};

#endif // CONCRETE_OBJECT_H
