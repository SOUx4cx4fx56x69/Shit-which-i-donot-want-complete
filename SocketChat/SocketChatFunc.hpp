#ifndef SocketFunc_HPP
#define SocketFunc_HPP
#include "main.hpp"
#include "SimplyClassSocket.hpp"
#include "SocketChat.hpp"

namespace SocketChatStuff{
enum UserType{
undefined,guest
};
struct User{
char IP_ADDR[INET_ADDRSTRLEN];
Sockets::Socket::udp_packet last_packet;
UserType type;
ULL self_key;
char * nick;
char * password;
};
};


namespace SocketChat{
class Functional {
protected:
SocketChatStuff::User users;
public:
bool auth(const char * nick,const char * password);
bool regsiter(const char * nick,const char * password);
ULL Keys(ULL,ULL);
};


};

#endif
