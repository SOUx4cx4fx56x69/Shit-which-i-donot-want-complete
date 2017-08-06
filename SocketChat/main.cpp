#include "SocketChat.hpp"
#include <stdlib.h>
#include <stdio.h>

int main(int argcount,char**arguments){
SocketChat::SocketChat Chat = SocketChat::SocketChat(arguments[1],atoi(arguments[2]));
Chat.AcceptingThread();
}
