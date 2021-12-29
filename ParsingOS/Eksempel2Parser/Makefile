# LEX YACC maker

LEX= flex
YACC= bison
# LIBS= -L/Programmer/GnuWin32/lib -ly -lfl -lm
LIBS= -lfl
CC= gcc 

PROG= regn

$(PROG): $(PROG).tab.o lex.yy.o 
	$(CC) -o $@ $(PROG).tab.o lex.yy.o $(LIBS) 


lex.yy.o: $(PROG).tab.h 

$(PROG).tab.c "$(PROG).tab.h: $(PROG).y
	$(YACC) -d -v $(PROG).y

lex.yy.c: $(PROG).l
	$(LEX) $(PROG).l

clean:
	rm *.o *.c $(PROG) $(PROG).tab.h $(PROG).output
