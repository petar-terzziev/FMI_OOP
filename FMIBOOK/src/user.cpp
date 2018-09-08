#include "user.h"
#include<cstring>
User::User():
    nickname(nullptr)
    ,age(0){}
User::User(const char* str,unsigned n):
    nickname(new char[strlen(str)+1])
    ,age(n)
    {
    strcpy(nickname,str);
    }
    User::User(const User& rhs):
        nickname(nullptr)
        {
    coppy(rhs);
    }
    void User::clearr(){
    delete [] nickname;
    nickname=nullptr;
    }
  void User::coppy(const User& rhs){
    nickname=new char(strlen(rhs.nickname)+1);
    strcpy(nickname,rhs.nickname);
    age=rhs.age;
    posts=rhs.posts;
    }
    User& User::operator=(const User& rhs){
    if(this!=&rhs){
        clearr();
        coppy(rhs);
    }
    return *this;
    }
    const char* User::get_name()const {
    return nickname;
    }
  void User::add_post (Post& rhs){
  posts.push_back(rhs.clone());
  }
bool User::operator==(const User& rhs){
return !strcmp(nickname,rhs.nickname);
}
Post* User::get_post(unsigned n)const {
    unsigned s=posts.size();
for(int i=0;i<s;i++){
    if(posts[i]->tell_id()==n) return posts[i];
}
return nullptr;
}
bool User::remove_post(unsigned n){
  unsigned s=posts.size();
for(int i=0;i<s;i++){
    if(posts[i]->tell_id()==n){ posts.remove(i);
    return true;
    }
}
return false;
}

User::~User()
{
delete [] nickname;
unsigned s=posts.size();
for(int i=0;i<s;i++){
    delete posts[i];
}
}
