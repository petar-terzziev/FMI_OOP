#include "date.h"

date::date()
{}

date::~date()
{}
date::date(const char* str):Word::Word(str){
if(!validate(str)) throw "invalid";
}
date::date(const date& other):Word::Word(other)
{}

date& date::operator=(const date& rhs)
{
 Word::operator=(rhs);
}
bool date::validate(const char* str){
    if(strlen(str)!=10) return false;
for(int i=0;i<10;i++){
   if(i==2||i==5){
        if(str[i]!='-') return false;
    }
     else if(!(str[i]>='0'&&str[i]<='9')) return false;
}
return true;
}
Word* date::clone(){
return new date(*this);
}

int date::compare(Word* rhs){
if(dynamic_cast<date*>(rhs)){
    return 100-difference_days(dynamic_cast<date*>(rhs));
}
else return 0;
}


int date::difference_days(date* rhs){
int d=0,m=0,y=0;
int od=0,om=0,oy=0;
const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
for(int i=0;i<2;i++){
    d+=((int)this->data[i]-'0')*(i%2?1:10);
    od+=((int)rhs->data[i]-'0')*(i%2?1:10);
}
for(int i=0;i<2;i++){
    m+=((int)this->data[i+3]-'0')*(i%2?1:10);
    om+=((int)rhs->data[i+3]-'0')*(i%2?1:10);
}
for(int i=0;i<4;i++){
    y+=((int)this->data[i+6]-'0')*(i<2?(i%2?100:1000):(i%2?1:10));
    oy+=((int)rhs->data[i+6]-'0')*(i<2?(i%2?100:1000):(i%2?1:10));
}

long int n1=y*365+d,n2=oy*365+od;
for(int i=0;i<m;i++){
    n1+=monthDays[i];
}
for(int i=0;i<om;i++){
    n2+=monthDays[i];
}
n1+=countly(y,m);
n2+=countly(oy,om);

return (n2-n1)>0?(n2-n1):-1*(n2-n1);
}
int date::countly(int y,int m){
int u=y;
if(m<=2) u--;
return u/4-u/100+u/400;
}
