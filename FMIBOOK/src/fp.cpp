#include<iostream>
#include "fp.h"
unsigned digits(unsigned n){
unsigned cnt=0;
while (n){
    n/=10;
    cnt++;
}
return cnt;
}
void reverse(char* str, int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        std::swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* inttc(unsigned num){
    int i=0;
char* str=new char[digits(num)+1];
if(!num) str[i++]='0';
 while (num)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }
 str[i]='\0';
 reverse(str,i);
 return str;
}
