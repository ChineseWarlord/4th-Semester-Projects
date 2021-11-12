
output: HovedProgram.o TempSensorStub.h 
	gcc -pthread HovedProgram.o TempSensorStub.h -o RunProgram 

HovedProgram.o: HovedProgram.c
	gcc -c HovedProgram.c 

TempSensorStub.o: TempSensorStub.h
	gcc -c TempSensorStub.h 

clean:
	rm *.o RunProgram