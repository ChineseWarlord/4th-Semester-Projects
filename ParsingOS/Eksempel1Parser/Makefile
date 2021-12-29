LEX= flex
CC= gcc

rpd: rpd.o rpdlex.o
	$(CC) -o $@ rpd.o rpdlex.o  -lm

rpd.o: rpd.c rpd.h symtab.h

rpdlex: rpdlex.l rpd.h
	$(LEX) -t rpdlex.l > $@.c

rpdlex.o: rpdlex.c rpd.h symtab.h

clean:
	rm *.o rpd rpdlex.c rpd.exe

run:
	./rpd < tst.pro


