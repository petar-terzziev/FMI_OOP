#include "../include/grid.h"

Grid::Grid(int h,int w):
    plane(h,vector<char>(w,' '))
{}
void Grid::print(){
        int h=plane.size();
    int w=plane[0].size();
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        std::cout<<plane[i][j];
    }
    std::cout<<std::endl;
}

}
void Grid::clean(){
    int h=plane.size();
    int w=plane[0].size();
for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        plane[i][j]=' ';
    }

}
}
void Grid::paint(Object* o){
    Point p=o->Getpoint();
const char* shape=o->getshape();
   int h=o->getheight();
   int w=o->getwidth();
   int cnt=0;
      for(int i=p.x;i<h+p.x;i++){
    for(int j=p.y;j<w+p.y;j++){
        plane[i][j]=shape[cnt];
        cnt++;
    }
   }

}
unsigned Grid::Getwidth()const{
return plane[0].size();
}
unsigned Grid::Getheight()const{
return plane.size();
}

Grid::~Grid()
{}
