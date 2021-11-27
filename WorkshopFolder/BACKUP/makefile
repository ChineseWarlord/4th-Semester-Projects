
all: RunClient StartServer

RunClient: ClientTemp.o  TempSensorStub.o 
	gcc -pthread ClientTemp.o TempSensorStub.o -o RunClient

StartServer: Server.o
	gcc -pthread Server.o -o StartServer

ClientTemp.o: ClientTemp.c 
	gcc -c ClientTemp.c 

TempSensorStub.o: TempSensorStub.c TempSensorStub.h
	gcc -c TempSensorStub.c 

Server.o: Server.c
	gcc -c -pthread Server.c
	
clean:
	rm *.o all
	@echo "clean completed"

