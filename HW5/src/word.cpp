#include "word.h"

Word::Word():
    data(nullptr)
{}
Word::Word(const char* str):data(new char[strlen(str)+1])
{
    strcpy(data,str);
}
Word::Word(const Word& other):data(new char[strlen(other.data)+1])
    {
        strcpy(data,other.data);
    }
    Word& Word::operator=(const Word& other)
    {
    if(this!=&other){
        delete [] data;
        data=new char[strlen(other.data)+1];
        strcpy(data,other.data);
    }
    return *this;
    }
Word::~Word()
{
    delete [] data;
}

unsigned precentcmp(const char* str1,const char* str2){
    int i=0;
    int precent=0;
    int j=std::max(strlen(str1),strlen(str2));
while(i<j)
{
if((str1[i]==str2[i]||str1[i]==(char)(str2[i]+32)||str1[i]==(char)(str2[i]-32)||(char)(str1[i]+32)==str2[i]||(char)(str1[i]-32)==str2[i])) precent++;
i++;
}
return (100*precent)/j;
}
const char* Word::getdata()const{
return this->data;
}
