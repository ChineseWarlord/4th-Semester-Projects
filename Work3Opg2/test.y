%{
 #include<stdio.h>
 int yylex(void);
 int yyerror(char *);
%}

%token A B 

%%
//production rules for grammar
expr: //Empty string
| A
| A A
| A A A
| A B
| A B B
| A B B B
| A A B
| A A B B
| A A B B B
| A A A B
| A A A B B
| A A A B B B

| B
| B B
| B B B
| B A
| B A A
| B A A A
| B B A
| B B A A
| B B A A A
| B B B A
| B B B A A
| B B B A A A
;
%%

int main()
{
 
 printf("Enter the string \n");
 yyparse(); 
 return 0;
}

int yyerror(char *s)
{
 printf("Invalid string\n");
}

