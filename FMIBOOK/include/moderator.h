#ifndef MODERATOR_H
#define MODERATOR_H

#include "user.h"


class Moderator : public User
{
    public:
        Moderator();
        Moderator(const char*,unsigned);
        ~Moderator();
        Moderator& operator=(const Moderator&);
        bool operator==(const Moderator&);
        void block_user(vector<const User*>&,const User*);
         bool remove_post(vector<User>&,unsigned);
        void unblock_user(vector<const User*>&,const User*);

protected:

    private:

};

#endif // MODERATOR_H
