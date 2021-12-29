# LEX YACC maker

LEX= flex
LIBS=  -lm
CC= gcc 

PROG= lextst

$(PROG): lex.yy.o 
	$(CC) -o $@ lex.yy.o $(LIBS) 


lex.yy.c: $(PROG).l
	$(LEX) $(PROG).l

clean:
	rm *.o *.c $(PROG) 
