
RunProgram: HovedProgram.o  TempSensorStub.o
	gcc -pthread HovedProgram.o TempSensorStub.o -o RunProgram

ClientTemp.o: ClientTemp.c 
	gcc -c ClientTemp.c 

TempSensorStub.o: TempSensorStub.c TempSensorStub.h
	gcc -c TempSensorStub.c 

clean:
	rm *.o RunProgram
	@echo "clean completed"

