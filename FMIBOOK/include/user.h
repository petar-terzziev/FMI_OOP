#ifndef USER_H
#define USER_H
#include "vector.h"
#include "image_post.h"
#include "URL_Post.h"
#include "Text_Post.h"
class User
{
    public:
        User();
        User(const char*,unsigned);
        User(const User&);
       virtual ~User();
        bool operator==(const User&);
        User& operator=(const User&);
         Post* get_post(unsigned)const;
        virtual  bool remove_post(unsigned);
         const char* get_name()const ;
         void add_post (Post&);
protected:
      void  coppy(const User&);
      void  clearr();
        char* nickname;
        unsigned age;
        vector<Post*> posts;
};

#endif // USER_H
