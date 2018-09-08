
#include "vector.h"
#include "image_post.h"
#include "system.h"
#include <iostream>
using std::cin;
using std::cout;

int main()
{
SYSTEM* system=SYSTEM::Get_SYSTEM("Admin",19);
 while(true){
        try{
char actor[30];
char action[30];
cin>>actor;
if(!strcmp(actor,"quit")) break;
cin>>action;
if(!system->is_blocked(actor))
system->process_command(actor,action);
else cout<<"User is blocked"<<std::endl;
        }
        catch(const char* str){
        cout<<str<<std::endl;
        }
}
return 0;
}
