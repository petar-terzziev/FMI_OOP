#include "post.h"
unsigned Post::cnt=0;
Post::Post():
    content(nullptr)
    ,id(cnt++)
{}
Post::Post(const char* str):
    content(new char[strlen(str)+1])
    ,id(cnt++)
{
strcpy(content,str);
}
Post::Post(const Post& rhs){
coppy(rhs);
}
Post& Post::operator=(const Post& rhs){
if(this!=&rhs){
clearr();
coppy(rhs);
}
return *this;
}
const unsigned Post::tell_id() const  {
return id;
}
void Post::coppy(const Post& rhs){
content=new char[strlen(rhs.content)+1];
strcpy(content,rhs.content);
id=rhs.id;
}
void Post::clearr(){
delete [] content;
content=nullptr;
}
Post::~Post()
{
delete [] content;
}
