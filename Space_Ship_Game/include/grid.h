#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <cstring>
#include<stdlib.h>
#include <windows.h>
#include <fstream>
#include "vector.h"
#include "hero.h"
class Grid
{
public:
    Grid(int,int);
    ~Grid();
    void print ();
    void clean();
    void paint(Object*);
    unsigned Getwidth()const;
    unsigned Getheight()const;
protected:

private:
    vector<vector<char>>  plane;

};

#endif // GRID_H
