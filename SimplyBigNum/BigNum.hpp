#ifndef __BIG_HPP
#define __BIG_HPP
namespace Numbers {
namespace Constant {
static unsigned int defaultMaxSize=1024;
};//namespace Constant

enum errorsThrow{
UncorrectType
};//Enum errorsThrow


class BigNumber{
char * self_number;
unsigned long long size;
protected:
template< typename T >char * NumberToString(T number);
void ReverseString(char * string);
char * ResizeString(char * string);
char * copy_string(char * string);
char * set_from_buf(const char * string);
public:
BigNumber(long long number);
BigNumber(const char * number);


friend BigNumber& operator+(BigNumber &n,int number);
friend BigNumber& operator+(BigNumber &n,const char * number);
friend BigNumber& operator-(BigNumber &n,int number);
friend BigNumber& operator-(BigNumber &n,const char * number);
friend BigNumber& operator*(BigNumber &n,int number);
friend BigNumber& operator*(BigNumber &n,const char * number);
friend BigNumber& operator/(BigNumber &n,int number);
friend BigNumber& operator/(BigNumber &n,const char * number);

};//class

};//Namespace Numbers

#endif
