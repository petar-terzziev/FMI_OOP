#ifndef ADMIN_H
#define ADMIN_H
#include "moderator.h"

class Admin: public Moderator
{
    public:
        Admin();
        Admin(const char*,unsigned);
        ~Admin();
        void add_user(vector<User>&,User&);
        void add_mod(vector<Moderator>&,Moderator&);
    private:
};

#endif // ADMIN_H
