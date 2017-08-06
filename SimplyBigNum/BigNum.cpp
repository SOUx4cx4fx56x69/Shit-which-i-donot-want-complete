#define DEBUG
#include <math.h>
#ifdef DEBUG
 #include <stdio.h>
#endif
#include "BigNum.hpp"


#define TOEND(a){\
while(*a)*a++;\
}
#define COUNTERSETPLUSMINUS(counter,a){\
if(*a<48 || *a>57){\
while(*a<48){\
counter--;\
*a+=1;\
}\
while(*a>48){\
counter++;\
*a-=1;\
}\
}\
}
#define USECOUNTERPLUSMINUS(a,counter,operation){\
if(counter){\
 printf("Set number (%d%10) to %d\n",counter,(counter%10) operation 48);\
 *a=(counter%10) operation 48;\
 counter/=10;\
}\
}
//A MUST BE > B
#define COLUMNPLUSMINUS(a,b,operator){\
printf("I get numbers %s %s\n",a,b);\
void * firstA=a;\
void * firstB=b;\
TOEND(a);\
TOEND(b);\
*a--;*b--;\
register long long counter = 0;\
while(a != firstA){\
*a=((*a-48)operator(*b-48))+48;	\
if(*a>57)COUNTERSETPLUSMINUS(counter,a);\
if(counter)USECOUNTERPLUSMINUS(a,counter,operator);\
printf("%s %d \n",a,counter);\
*a--;*b--;\
}*a=((*a-48)operator(*b-48))+48;if(*a>57)COUNTERSETPLUSMINUS(counter,a);if(counter)USECOUNTERPLUSMINUS(a,counter,operator);\
}
namespace Numbers {

inline char * BigNumber::copy_string(char * string){
char * tmp = new char[Constant::defaultMaxSize];
void * ft = (void*)tmp;
void * fs = (void*)string;
while(*string) *tmp++=*string++;
string = (char*)fs;
ft = (char*)ft;
delete [] string;
string = nullptr;
return (char*)ft;
}inline char * BigNumber::ResizeString(char * string){
char * tmp = new char[Constant::defaultMaxSize];
void * firsttmp = (void*)tmp;
void * firststring = (void*)string;
while(*string)
	*tmp++=*string++;
tmp=(char*)firsttmp;
string=(char*)firststring;
delete[] string;
string=nullptr;
return tmp;
}inline void BigNumber::ReverseString(char * string){
Constant::defaultMaxSize*=2;
char * tmp = new char[Constant::defaultMaxSize];
void * firsttmp = (void*)tmp;
void * firststring = (void*)string;
while(*string)
 *string++;
*string--;
while(string!=firststring)
 *tmp++=*string--;
*tmp++=*string--;
*tmp++='\0';
tmp=(char*)firsttmp;
string=(char*)firststring;
while(*tmp){
 *string++=*tmp++;
}
tmp=(char*)firsttmp;
delete[] tmp;
}inline char * BigNumber::set_from_buf(const char * string){
char * tmp = new char[Constant::defaultMaxSize];
void * ft = (void*)tmp;
void * fs = (void*)string;
while(*string) *tmp++=*string++;
string = (char*)fs;
ft = (char*)ft;
return (char*)ft;
}




template< typename T >char * BigNumber::NumberToString(T number){
//if(*typeid(T).name() != TYPEIDLONGLONG) throw(UncorrectType);
char * result = new char[Constant::defaultMaxSize];
unsigned long long counter = 0;
while(number){
	if(counter+1 == Constant::defaultMaxSize) ResizeString(result); 
	result[counter++]=((T)number%10)+48;
	number/=10;
}
result[counter++]='\0';
ReverseString(result);
result = ResizeString(result);
return result;
}
//


BigNumber::BigNumber(long long number){
self_number=NumberToString<long long>(number);
}BigNumber::BigNumber(const char * number){
self_number=set_from_buf(number); 
}

BigNumber& operator+(BigNumber &n,int number){
char * tmp = n.NumberToString<long long>(number);
COLUMNPLUSMINUS(n.self_number,tmp,+);
#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}BigNumber& operator+(BigNumber &n,const char * number){
COLUMNPLUSMINUS(n.self_number,(char*)number,+);
#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}BigNumber& operator-(BigNumber &n,const char * number){
COLUMNPLUSMINUS(n.self_number,(char*)number,-);
#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}BigNumber& operator-(BigNumber &n,int number){
char * tmp = n.NumberToString<int>(number);
COLUMNPLUSMINUS(n.self_number,tmp,-);
#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}

BigNumber& operator*(BigNumber &n,int number){
char * tmp = n.NumberToString<int>(number);

#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}BigNumber& operator*(BigNumber &n,const char * number){

#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}BigNumber& operator/(BigNumber &n,int number){
char * tmp = n.NumberToString<int>(number);

#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}BigNumber& operator/(BigNumber &n,const char * number){

#ifdef DEBUG
printf("RESULT: %s\n",n.self_number);
#endif
return n;
}




}
#undef DEBUG
#undef COUNTERSETPLUSMINUS
#undef USECOUNTERPLUSMINUS
#undef COLUMNPLUSMINUS
