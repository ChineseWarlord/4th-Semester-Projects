
RunProgram: HovedProgram.o  TempSensorStub.o
	gcc -pthread HovedProgram.o TempSensorStub.o -o RunProgram

HovedProgram.o: HovedProgram.c 
	gcc -c HovedProgram.c 

TempSensorStub.o: TempSensorStub.c TempSensorStub.h
	gcc -c TempSensorStub.c 
	
clean:
	rm *.o RunProgram
	@echo "clean completed"

