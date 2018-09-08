#include "moderator.h"

Moderator::Moderator()
{}
Moderator::Moderator(const char* str,unsigned n):
    User::User(str,n)
    {}

void Moderator::block_user(vector<const User*>& blocked_users,const User* user){

if(!blocked_users.contains(user)) blocked_users.push_back(user);
}
void Moderator::unblock_user(vector<const User*>& blocked_users,const User* user){
    unsigned s=blocked_users.size();
for(int i=0;i<s;i++){
    if(blocked_users[i]==user) blocked_users.remove(i);
}
}

bool Moderator::remove_post(vector<User>& users,unsigned n){
unsigned s=users.size();
for(int i=0;i<s;i++){
   if(users[i].remove_post(n)) return true;
}
return false;
}
Moderator& Moderator::operator=(const Moderator& rhs){
User::operator=(rhs);
}
bool Moderator::operator==(const Moderator& rhs){
User::operator==(rhs);
}
Moderator::~Moderator()
{}
