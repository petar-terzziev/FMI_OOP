#ifndef POST_H
#define POST_H
#include <cstring>

class Post
{
    public:
        Post();
        Post(const char*);
        Post(const Post&);
        Post& operator=(const Post&);
        virtual ~Post();
        virtual Post* clone()=0;
        virtual char* Make_HTML()=0;
        const unsigned tell_id()const;
    protected:
       void coppy(const Post&);
        void clearr();
        char* content;
        unsigned id;
        static unsigned cnt;

    private:
};

#endif // POST_H
