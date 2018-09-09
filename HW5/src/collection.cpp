#include "collection.h"

Collection::Collection():ms(0)
,mc(8)
,msgs(new Message[8])
{}
void Collection::ressize(){
mc*=2;
Message* om=msgs;
Message* nm= new Message[mc];
for(int i=0;i<ms;i++){
    nm[i]=om[i];
}
msgs=nm;
delete [] om;
}
void Collection::addmsg(const Message& m){
if(ms>=mc) ressize();
msgs[ms++]=m;

}
Collection& Collection::operator+=(const Message& m){
addmsg(m);
return *this;
}
void Collection::display_hashtags(){
for(int i=0;i<ms;i++){
msgs[i].display_hashtags();
}
}
Collection::~Collection()
{
    delete [] msgs;
}
