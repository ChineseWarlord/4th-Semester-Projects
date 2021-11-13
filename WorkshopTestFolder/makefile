
output: HovedProgram.o TempSensorStub.h 
	gcc -pthread HovedProgram.o TempSensorStub.h -o RunProgram.exe 

HovedProgram.o: HovedProgram.c
	gcc -c HovedProgram.c 

TempSensorStub.o: TempSensorStub.h
	gcc -c TempSensorStub.h 

clean:
	del *.o RunProgram.exe
	@echo "clean completed"

#clean:
#	rm *.o RunProgram.exe      - Linux command
#	@echo "clean completed"