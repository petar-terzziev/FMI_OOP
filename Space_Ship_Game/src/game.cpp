#include "game.h"
Game::Game(int x,int y):
    grid(x,y)
    ,real_bullet(-1,-1,"-",1,1,0)
    ,hero(x/2,0,"\\- =X>/- ",3,3,real_bullet)
    ,dif(0)
    ,real_enemy(-1,-1," ooooo oo ",3,3,real_bullet)

{}

void Game::run_game()
{
    bullets.reserve(20);
    enemies.reserve(20);
    while(hero.Getlife()>0)
    {
        Flyweight_Enemy e(rand()%(grid.Getheight()-3),grid.Getwidth()-3,&real_enemy);

        if(!e.overlaps(enemies))    enemies.push_back(e);
        Move_Hero();
        check_bullet_collision();
        Enemies_shoot();
        paint_obj();
        grid.print();
        if(GetAsyncKeyState(0x53)) Save_game();
        grid.clean();
        Sleep(dif);
        system("cls");
        Move_Bullets();
    }
}
void Game::Move_Hero()
{

    if(GetAsyncKeyState(VK_UP)) hero.Movepoint(-1,0);
    else if(GetAsyncKeyState(VK_DOWN)) hero.Movepoint(1,0);
    else if(GetAsyncKeyState(VK_RIGHT)) hero.Movepoint(0,1);
    else if(GetAsyncKeyState(VK_LEFT)) hero.Movepoint(0,-1);
    else if(GetAsyncKeyState(VK_SPACE)) hero.shoot(bullets);
}

void Game::Move_Enemies()
{
    unsigned s=enemies.size();
    for(int i=0; i<s; i++)
    {
        enemies[i].Movepoint(0,-1);
    }
}

void Game::Move_Bullets()
{
    unsigned s=bullets.size();
    for(int i=0; i<s; i++)
    {
        if(bullets[i].getdir())
            bullets[i].Movepoint(0,3);
        else bullets[i].Movepoint(0,-3);
        if(bullets[i].Getpoint().y>=grid.Getwidth()) bullets.remove(i);
    }

}
void Game::Enemies_shoot()
{
    unsigned s=enemies.size();
    if(s)
    {
        enemies[rand()%s].shoot(bullets);
    }
}
void Game::paint_obj()
{
    grid.paint(&hero);
    unsigned sb=bullets.size();
    for(int i=0; i<sb; i++)
    {

        grid.paint(&bullets[i]);
    }
    unsigned se=enemies.size();
    for(int i=0; i<se; i++)
    {
        grid.paint(&enemies[i]);
    }
}


void Game::check_bullet_collision()
{
    unsigned s=bullets.size();
    for(int i=0; i<s; i++)
    {
        if(bullets[i].check_collision(enemies,hero)) bullets.remove(i);
    }
}


void Game::Save_game()
{
    std::ofstream gamefile("last_game.dat",std::ios::binary|std::ios::trunc);
    if(!gamefile) throw "File not opened!";
    gamefile.write(reinterpret_cast<char*>(&dif),sizeof(int));
    real_bullet.save_to_file(gamefile);
    hero.save_to_file(gamefile);
    real_enemy.save_to_file(gamefile);
    unsigned se=enemies.size();
    gamefile.write(reinterpret_cast<char*>(&se),sizeof(unsigned));
    for(int i=0; i<se; i++)
    {
        gamefile.write(reinterpret_cast<char*>(&enemies[i]),sizeof(Flyweight_Enemy));
    }

    unsigned sb=bullets.size();
    gamefile.write(reinterpret_cast<char*>(&sb),sizeof(unsigned));
    for(int i=0; i<sb; i++)
    {
        gamefile.write(reinterpret_cast<char*>(&bullets[i]),sizeof(Flyweight_Bullet));
    }

}
void Game::Read_game()
{
    std::ifstream gamefile("last_game.dat",std::ios::in);
    if(!gamefile) throw "No saved game";
    gamefile.read(reinterpret_cast<char*>(&dif),sizeof(int));
    real_bullet.read_from_file(gamefile);
    hero.read_from_file(gamefile);
    hero.setbullet(&real_bullet);
    real_enemy.read_from_file(gamefile);
    real_enemy.setbullet(&real_bullet);
    /*
    unsigned se;
    gamefile.read(reinterpret_cast<char*>(&se),sizeof(unsigned));
     Flyweight_Enemy e;
    for(int i=0;i<se;i++){
        gamefile.read(reinterpret_cast<char*>(&e),sizeof(Flyweight_Enemy));
        enemies.push_back(e);
    }

    unsigned sb;
    gamefile.read(reinterpret_cast<char*>(&sb),sizeof(unsigned));
     Flyweight_Bullet b;
    for(int i=0;i<sb;i++){
        gamefile.read(reinterpret_cast<char*>(&b),sizeof(Flyweight_Bullet));
        bullets.push_back(b);
    }
    */
}
void Game::setdif(int s)
{
    dif=s;
}


Game::~Game()
{
}
