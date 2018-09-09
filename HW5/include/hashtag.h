#ifndef HASHTAG_H
#define HASHTAG_H

#include "word.h"


class Hashtag : public Word
{
    public:
        Hashtag();
        Hashtag(const char*);
        virtual ~Hashtag();
        Hashtag(const Hashtag& other);
        Hashtag& operator=(const Hashtag& other);
virtual int compare(Word*);
virtual Word* clone();
    protected:
virtual bool validate(const char*);
    private:
};

#endif // HASHTAG_H
