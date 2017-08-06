#include "SocketChat.hpp"
#include <iostream>
namespace SocketChat{
SocketChat::SocketChat(const char * host, int port) :
	error (false)

{
	this->error=false;
	std::cout << "Try open socket\n";
	try{
	set_sock(init_socket_udp());
	}catch(Sockets::for_throws error){
		std::cout << "Error with init socket (" << error << ")" << std::endl;
		this->error=true;
	}
	std::cout << "Binding on " << host << ":"<<port << std::endl;
	try{
	binding(host,port);
	}catch(Sockets::for_throws error){
		std::cout << "Error with binding server on " << host << ":"<<port << " (" << error << ")" << std::endl;
		this->error=true;
	}

}
void SocketChat::AcceptingThread(void){
	if(error == true) throw(0);
	Sockets::Socket::udp_packet packet;
/*
REGISTER NickName Password/AUTH NickName Password/NKEY a (p)/PING/PONG/WRITE MESSAGE/QUIT MESSAGE
Connecting -> REGISTER/AUTH
If registered -> save to file.

If all okey->

Exchange keys which Time to life 3-10 times. -> 
Server-> NKEY A P
Client -> NKEY B
All have one keys.
Use simply XOR for all bytes.(Very unsecurity). But is funny program.

*/
	while(1){
	try{
	std::cout << "Start wait messages" << std::endl;
 	packet = Read_UDP();
  	char ipv4[INET_ADDRSTRLEN];
   	inet_ntop(AF_INET, &packet.from.sin_addr, ipv4, INET_ADDRSTRLEN);
   	write(packet.message,0,(struct sockaddr*)&packet.from);
   	printf("%s:%d write -> %s\n",ipv4,ntohs(packet.from.sin_port),packet.message);
  	delete packet.message;
	}catch(Sockets::for_throws err){
	}//catch
	}//while
}
}
