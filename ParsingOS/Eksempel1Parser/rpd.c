#include <stdio.h>
#include "rpd.h"
#include "symtab.h"
#include <stdlib.h>

int    Ctype= 0,nextT = -1;
char *yytext;
struct symnote *sptr= NULL;

print_token(int token)
{
  if (token < 256) printf("token: %c\n", (char)token);
  else
  switch (token) {
    case intT: 	   printf("token: intT\n"); break;	
    case floatT:   printf("token: floatT\n"); break;
    case idT:      printf("token: idT  - %s\n",yytext); break;
    case beginT:   printf("token: beginT\n"); break;
    case endT:	   printf("token: endT\n"); break;
    case realT:	   printf("token: realT\n"); break;
    case programT: printf("token: programT\n"); break;
    default:	   printf("token: %d Ukendt  - %s\n", token, yytext); 
  }
}

void
checkfor(int token)
{
      					print_token(token);
	if (token != nextT) {
		printf("Syntax Error \n ");
		exit(0);
	} else
		nextT = yylex();
}


void
program()
{
	checkfor(programT);
	checkfor('(');
	checkfor(idT);
	checkfor(')');
	varlist();
	checkfor(beginT);
	stlist();
	checkfor(endT);
        printf("Compilering faerdig. Ingen fejl\n ");
}

void
varlist()
{
	type();
	identlist();
	checkfor(';');
	Ctype = 0;
}

void
type()
{
	if (nextT == floatT) {
		checkfor(floatT); Ctype= floatT;}
	else {
		if (nextT == intT) {
			checkfor(intT); Ctype= intT;}
		else {
			printf("Syntax Error 'int' eller 'float' type forvendtet! \n ");
			exit(0);
		}
	}
}

void
identlist()
{
	if (nextT == idT) yylval.symptr->type= Ctype;
       	checkfor(idT);
	identelmlist();
}

void
identelmlist()
{
	
	if (nextT == ',') {
		checkfor(',');
		if (nextT == idT) yylval.symptr->type= Ctype;
		checkfor(idT); 
		identelmlist();
	}

}

void
stlist()
{
	if (nextT == idT) {
		statement();
		stlist();
	}
}

void
statement()
{

	checkfor(idT);
	checkfor('=');
	aexp();
	checkfor(';');
}

void
aexp()
{
	if (nextT == idT) {
					printf("%s\n",yytext);
		checkfor(idT);
	 	bexp(); 
      	} else 
	if (nextT == '(') {
		checkfor('(');
		aexp();
		checkfor(')');
		bexp();
	} else {
		printf("Syntax Error 'ident' eller '(' forvendtet! \n ");
		exit(0);
	}
}

void
bexp()
{
	if (nextT == '+') {
		checkfor('+'); 
		aexp();
		bexp();
					printf("+\n");
	} else
     	if (nextT == '-') {
		checkfor('-'); 
		aexp();
		bexp();
					printf("-\n");
	}
}

int main()
{
  init_sym();
  nextT = yylex();
  program(); 
  exit(0);
}
