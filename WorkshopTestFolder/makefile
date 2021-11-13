#Change RunProgram.exe to RunProgram if run on Linux

RunProgram.exe: HovedProgram.o  TempSensorStub.o
	gcc -pthread HovedProgram.o TempSensorStub.o -o RunProgram.exe 

HovedProgram.o: HovedProgram.c 
	gcc -c HovedProgram.c 

TempSensorStub.o: TempSensorStub.c TempSensorStub.h
	gcc -c TempSensorStub.c 

clean:
	del *.o RunProgram.exe
	@echo "clean completed"

#Remove comment if run on Linux
#clean:
#	rm *.o RunProgram.exe
#	@echo "clean completed"

