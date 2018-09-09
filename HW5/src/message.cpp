#include "message.h"

Message::Message():
    words(new Word*[8])
    ,ws(0)
    ,wc(8)
{}
Message::Message(const char* str):words(new Word*[8])
,ws(0)
,wc(8){
extract_words(str);
}
Message::~Message()
{
clearr();
}
Message::Message(const Message& other)
{
    coppy(other);
}

Message& Message::operator=(const Message& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    clearr();
    coppy(rhs);
    return *this;
}

void Message::resizze(){
wc*=2;
Word** ow=words;
Word** nw= new Word*[wc];
for(int i=0;i<ws;i++){
    nw[i]=ow[i];
}
words=nw;
delete [] ow;
}
void Message::addWord(Word* nw){
if(ws>=wc) resizze();
words[ws++]=nw->clone();
}
void Message::clearr(){
   for(int i=0;i<ws;i++){
    delete words[i];
   }
   delete [] words;

}
void Message::coppy(const Message& rhs){
ws=rhs.ws;
wc=rhs.wc;
words=new Word*[wc];
for(int i=0;i<ws;i++){
    words[i]=rhs.words[i]->clone();
}
}
void Message::extract_words(const char* str){
char buffer[280];
while(*str){
    while(!isword(*str))str++;
    int i=0;
    while(isword(*str)){
            buffer[i]=*str;
            str++;
            i++;
}
try{
Word* h=new Hashtag(buffer);
addWord(h);
}
catch(const char* str){
try{
Word* d=new date(buffer);
addWord(d);
}
catch(const char* str){
Word* s=new simple_word(buffer);
addWord(s);
}
}
}
}
void Message::display_hashtags()const {
for(int i=0;i<ws;i++){
    if(dynamic_cast<Hashtag*>(words[i])) std::cout<<words[i]->getdata()<<std::endl;
}
}
void Message::display()const{
for(int i=0;i<ws;i++){
    std::cout<<words[i]->getdata()<<" ";
}
std::cout<<endl;
}

int Message::compare(Word* w){
    int res=0;
for(int i=0;i<ws;i++){
    res+=words[i]->compare(w);
}

return res;
}
