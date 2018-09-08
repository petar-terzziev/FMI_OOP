#include "image_post.h"

Image_Post::Image_Post():
    Post::Post()
{}

Image_Post::Image_Post(const char* str):
    Post::Post(str)
{}

Image_Post::Image_Post(const Image_Post& rhs){
    coppy(rhs);
}
Image_Post& Image_Post::operator=(const Image_Post& rhs){
if(this!=&rhs){
    clearr();
    coppy(rhs);
}
return *this;
}
char* Image_Post::Make_HTML(){
    char* p=new char [strlen(content)+20];
strcpy(p,"<img src=\"");
strcat(p,content);
strcat(p," \" alt=\"\">");
return p;
}
Post* Image_Post::clone(){
return new Image_Post(*this);
}

Image_Post::~Image_Post()
{}
