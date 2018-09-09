#include "include/hashtag.h"
#include"date.h"
#include "message.h"
#include "collection.h"
int main()
{
    char  filepath[40];
    Collection clctn;
    std::cin>>filepath;
    std::ifstream file(filepath,std::ios::in);
    if(!file) throw "No such file";
    while(file){
char buffer[280];
file.getline(buffer,280);
Message m(buffer);
clctn.addmsg(m);
    }
    clctn.display_hashtags();


    return 0;
}
