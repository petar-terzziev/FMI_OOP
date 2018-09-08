#ifndef IMAGE_POST_H
#define IMAGE_POST_H
#include "post.h"
class Image_Post: public Post
{
    public:
        Image_Post(const Image_Post&);
        Image_Post();
        Image_Post(const char*);
        Image_Post& operator=(const Image_Post&);
        virtual Post* clone();
        virtual ~Image_Post();
virtual  char*   Make_HTML();
    protected:

    private:
};

#endif // IMAGE_POST_H
