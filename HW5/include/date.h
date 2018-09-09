#ifndef DATE_H
#define DATE_H

#include "word.h"

class date : public Word
{
    public:
        date();
        date(const char*);
        virtual ~date();
        date(const date& other);
        date& operator=(const date& other);
virtual int compare(Word*);
virtual Word* clone();
    protected:
virtual bool validate(const char*);
    private:
        int difference_days(date*);
        int countly(int,int);
};

#endif // DATE_H
