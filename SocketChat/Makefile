SOCKETLIBRARYNAME=ShitSimplySocket
NAMEPROGRAM=test
all: $(SOCKETLIBRARYNAME)LIB
	g++ main.cpp SimplyCrypto.cpp SocketChat.cpp -L. -lsimplysocket -o $(NAMEPROGRAM)

$(SOCKETLIBRARYNAME)LIB:
	cd $(SOCKETLIBRARYNAME)Class;make;cp library/* ../
clean:
	rm *.so
	rm $(NAMEPROGRAM)	
