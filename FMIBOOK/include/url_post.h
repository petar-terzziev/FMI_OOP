#ifndef URL_POST_H
#define URL_POST_H

#include "Post.h"


class URL_Post : public Post
{
    public:
        URL_Post();
        URL_Post(const char*,const char*);
        URL_Post(const URL_Post&);
        URL_Post& operator=(const URL_Post&);
        virtual Post* clone();
        virtual char* Make_HTML();
        virtual ~URL_Post();

    protected:

    private:
        char* description;
};

#endif // URL_POST_H
