#ifndef __SOCKETCHAT_HPP
#define __SOCKETCHAT_HPP
#include "SimplyClassSocket.hpp"
#include "SocketChatFunc.hpp"
#include "main.hpp"
namespace SocketChat{


class SocketChat : public Sockets::Socket, public Functional{
	bool error;		

	public:
	SocketChat(const char *, int);
	void AcceptingThread(void);
	void PingPong_Thread(void);
	
	
};

};


#endif
