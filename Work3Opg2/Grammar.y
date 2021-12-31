%{
   /* Definition section */
  #include<stdio.h>
  #include<stdlib.h>
 %}
  
%token A B NL
  
/* Rule Section */
%%
stmt: A s B {printf("valid string\n"); exit(0);}
;
s: A s B
s: A
;
%%
  
int yyerror(char *msg)
 {
  printf("invalid string\n");
 }
  
  
//driver code 
main()
 {
  printf("enter the string\n");
  yyparse();
 }