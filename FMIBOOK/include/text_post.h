#ifndef TEXT_POST_H
#define TEXT_POST_H

#include "Post.h"


class Text_Post : public Post
{
    public:
        Text_Post();
        Text_Post(const char*);
        Text_Post(const Text_Post&);
        virtual char* Make_HTML();
        virtual Post* clone();
     virtual ~Text_Post();

    protected:

    private:
};

#endif // TEXT_POST_H
