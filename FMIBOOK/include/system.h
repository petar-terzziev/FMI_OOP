#ifndef SYSTEM_H
#define SYSTEM_H
#include "vector.h"
#include "post.h"
#include "fp.h"
#include <iostream>
#include <fstream>
#include "admin.h"
class SYSTEM
{
    public:
      inline static SYSTEM* Get_SYSTEM(const char* str,unsigned n){
       static SYSTEM the_system(str,n);
       return &the_system;
       }
       void process_command(char*,char*);

       void add_user(User&);
       void block_user(const char*,const char*);
       void unblock_user(const char*,const char*);
       void remove_post(const char*, unsigned);
       void generate_post(unsigned);
       char* file_name(unsigned);
       bool is_blocked(User*);
        bool is_blocked(const char*);
       User* get_user(const char*);
       Moderator* get_moderator(const char*);
       void add_post(const char*,Post&);
       ~SYSTEM();
    private:
    SYSTEM(const char*,unsigned);
    Admin admin;
  vector<User> users;
  vector<Moderator> moderators;
  vector <const User*>blocked_users;
};
#endif // SYSTEM_H
