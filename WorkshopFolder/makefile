
RunProgram: ClientTemp.o  TempSensorStub.o
	gcc -pthread ClientTemp.o TempSensorStub.o -o RunProgram

ClientTemp.o: ClientTemp.c 
	gcc -c ClientTemp.c 

TempSensorStub.o: TempSensorStub.c TempSensorStub.h
	gcc -c TempSensorStub.c 

bbfs: bbfs.o
	gcc -Wall bbfs.c `pkg-config fuse3 -cflags --libs -D_FILE_OFFSET_BITS=64` -o bbfs.o
	
clean:
	rm *.o RunProgram
	@echo "clean completed"

