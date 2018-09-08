#include "url_post.h"

URL_Post::URL_Post()
{}

URL_Post::URL_Post(const char* cont,const char* des):
    Post::Post(cont)
    ,description(new char[strlen(des)+1])
{
    strcpy(description,des);
}

URL_Post::URL_Post(const URL_Post& up){
coppy(up);
description=new char [strlen(up.description)+1];
strcpy(description,up.description);
}

char* URL_Post::Make_HTML(){
 char* p=new char [strlen(content)+15];
strcpy(p,"<a href=\"");
strcat(p,content);
strcat(p," \">");
strcat(p,description);
strcat(p,"</a>");
return p;
}
Post* URL_Post::clone(){
return new URL_Post(*this);
}
URL_Post::~URL_Post()
{
  delete [] description;
}
