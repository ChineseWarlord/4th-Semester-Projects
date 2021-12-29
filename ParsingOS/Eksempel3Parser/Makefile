# LEX YACC maker

LEX= flex
LIBS=  -lm -lfl
CC= gcc 

PROG= lexfil

$(PROG): lex.yy.o 
	$(CC) -o $@ lex.yy.o $(LIBS) 


lex.yy.c: $(PROG).l
	$(LEX) $(PROG).l

clean:
	rm *.o *.c $(PROG) 
