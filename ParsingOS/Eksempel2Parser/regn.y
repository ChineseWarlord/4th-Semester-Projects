%{
#include <stdio.h>
#include <math.h>
#include "symtab.h"
#include <string.h>
%}

%union {
	char           *string;
	double          dval;
	struct symnote *symptr;
}

%token <dval> TAL
%token LOG EXP SQRT

%left '-' '+'
%left '*' '/'
%right UMINUS

%type <dval> expression

%%

statement_list: statement '\n'
	  | statement_list statement '\n' ;

statement:  expression    {printf("= %e\n",$1);};

expression: expression '+' expression   {$$ = $1 + $3;}
	  | expression '-' expression   {$$ = $1 - $3;}
	  | expression '*' expression   {$$ = $1 * $3;}
	  | expression '/' expression   {if ($3 == 0.0) 
                                           yyerror("divide dy zero");
                                         else $$ = $1 / $3;}
	  | '-' expression %prec UMINUS {$$ =  - $2;}
	  | '(' expression ')'          {$$= $2;}
          | TAL                         {$$ = $1;};
%%

main()
{ 
  //init_sym();
  yyparse(); 
}
