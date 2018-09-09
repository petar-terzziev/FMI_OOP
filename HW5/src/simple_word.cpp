#include "simple_word.h"

simple_word::simple_word()
{}
simple_word::simple_word(const char* str):Word::Word(str){
if(!validate(str)) throw "invalid";
}
simple_word::~simple_word()
{}

simple_word::simple_word(const simple_word& other):Word::Word(other)
{
}

simple_word& simple_word::operator=(const simple_word& rhs)
{
Word::operator=(rhs);
}

Word* simple_word::clone(){
return new simple_word(*this);
}
bool simple_word::validate(const char* str){
while(*str){
    if(!isword(*str)) return false;
    else str++;
}
return true;
}
int simple_word::compare(Word* s){
return 0;
}
