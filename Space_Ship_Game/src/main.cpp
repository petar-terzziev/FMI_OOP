#include "include/hero.h"
#include "include/grid.h"
#include "include/enemy.h"
#include "include/game.h"
//#include "include/object_parameters.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int h=20;
    const int w=60;
    const int easy=800;
    const int medium=500;
    const int hard=200;
    char c;
    int d;
    Game game(h,w);
    std::cout<<"Do you wish to continue a saved game?[Y/N]"<<std::endl;
    std::cin>>c;
    if(c=='y') try
        {
            game.Read_game();
            game.run_game();
        }
        catch(const char* str)
        {
            std::cout<<str<<std::endl;
        }
    else
    {
        std::cout<<"Choose Difficulty: Press H,M or E"<<std::endl;
        std::cin>>c;
        if(c=='e') d=easy;
        else if (c=='m') d=medium;
        else if (c=='h') d=hard;
        game.setdif(d);
        game.run_game();
    }
    return 0;
}
