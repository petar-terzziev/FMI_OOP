#ifndef COLLECTION_H
#define COLLECTION_H
#include "message.h"

class Collection
{
    public:
        Collection();
         ~Collection();
        void addmsg(const Message&);
        Collection& operator+=(const Message&);
        void display_hashtags();


    private:
        void ressize();
        Message* msgs;
        int ms,mc;
};

#endif // COLLECTION_H
