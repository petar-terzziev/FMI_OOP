#ifndef MESSAGE_H
#define MESSAGE_H
#include "hashtag.h"
#include "simple_word.h"
#include "date.h"

class Message
{
    public:
        Message();
        Message(const char*);
        virtual ~Message();
        Message(const Message& other);
        Message& operator=(const Message& other);
        Word* getword(const char*)const ;
        void addWord(Word*);
        void display()const ;
        int compare(Word*);
        void display_hashtags()const;
    private:
        void extract_words(const char*);
          void resizze();
          void clearr();
          void coppy(const Message&);
            int ws,wc;
        Word** words;
};

#endif // MESSAGE_H
