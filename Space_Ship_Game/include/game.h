#ifndef GAME_H
#define GAME_H
#include "bullet.h"
#include "hero.h"
#include "grid.h"
#include "flyweight_enemy.h"

class Game
{
public:
    Game(int,int);
    ~Game();
    void run_game();
    void Move_Bullets();
    void Move_Enemies();
    void Move_Hero();
    void Enemies_shoot();
    void check_bullet_collision();
    void Save_game();
    void Read_game();
    void paint_obj();
    void setdif(int );


private:
    int dif;
    Grid grid;
    Bullet real_bullet;
    Hero hero;
    Enemy real_enemy;
    vector<Flyweight_Enemy> enemies;
    vector<Flyweight_Bullet> bullets;

};

#endif // GAME_H
