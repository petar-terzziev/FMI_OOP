#include "admin.h"

Admin::Admin(const char* str,unsigned n):
    Moderator::Moderator(str,n)
{}
void Admin::add_user(vector<User>& users,User& user){
if(!users.contains(user)) users.push_back(user);
}

void Admin::add_mod(vector<Moderator>& users,Moderator& user){
if(!users.contains(user)) users.push_back(user);
}

Admin::~Admin()
{
    //dtor
}
