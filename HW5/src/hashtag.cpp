#include "hashtag.h"

Hashtag::Hashtag()
{}
Hashtag::Hashtag(const char* str):Word::Word(str){if(!validate(str))throw "invalid";}
Hashtag::~Hashtag()
{}

Hashtag::Hashtag(const Hashtag& other):Word::Word(other)
{
}

Hashtag& Hashtag::operator=(const Hashtag& rhs)
{
 Word::operator=(rhs);
}
bool Hashtag::validate(const char* str){
if(str[0]!='#') return false;
while(*str){
    if(!isword(*str)) return false;
    else str++;
}
return true;
}
int Hashtag::compare(Word* rhs){
   if(dynamic_cast<Hashtag*>(rhs)){
    if(precentcmp(this->data,rhs->getdata())==100) return 100;
    else return 0;
}
else return 0;
}
Word* Hashtag::clone(){
return new Hashtag(*this);
}
