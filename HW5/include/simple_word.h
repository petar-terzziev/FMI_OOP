#ifndef SIMPLE_WORD_H
#define SIMPLE_WORD_H

#include "word.h"


class simple_word : public Word
{
    public:
        simple_word();
        simple_word(const char*);
        virtual ~simple_word();
        simple_word(const simple_word& other);
        simple_word& operator=(const simple_word& other);
virtual int compare(Word*);
virtual Word* clone();
    protected:
virtual bool validate(const char*);

    private:
};

#endif // SIMPLE_WORD_H
