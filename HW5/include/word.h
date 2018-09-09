#ifndef WORD_H
#define WORD_H
#include <iostream>
#include<cstring>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
inline bool isword(const char c){
return (c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c=='-'||c=='#');
}
unsigned precentcmp(const char* str1,const char* str2);
class Word
{
    public:
        Word();
        Word(const char*);
        Word(const Word&);
        Word& operator=(const Word&);
        const char* getdata()const;
        virtual ~Word();
virtual int compare(Word*)=0;
virtual Word* clone()=0;
    protected:
        virtual bool validate(const char*) =0;
    protected:
        char* data;
};
/*
class WordCreator{
    public:
WordCreator(const char* cmd);
virtual ~WordCreator() {}
const char* getcmd()const {return cmd;}
    protected:
        const char* cmd;
};
*/
#endif // WORD_H
