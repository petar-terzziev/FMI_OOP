#include "text_post.h"

Text_Post::Text_Post()

{}
Text_Post::Text_Post(const char* str):
    Post::Post(str)

    {}
    Text_Post::Text_Post(const Text_Post& rhs){

coppy(rhs);
    }
    char* Text_Post::Make_HTML(){
    char* p=new char[strlen(content)+8];
    strcpy(p,"<p>");
    strcat(p,content);
    strcat(p,"</p>");
    return p;
    }
   Post*  Text_Post::clone(){
   return new Text_Post(*this);
   }
Text_Post::~Text_Post()

{}
