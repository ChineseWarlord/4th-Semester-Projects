%{
#include <stdio.h>
%}

letter [a-zA-Z]
digit  [0-9]
TAL    [+-]?[0-9]+
VAR    {letter}({digit}|{letter}|[_!])*

%%

begin   {printf("predef:  \t BEGIN\n");}
end     {printf("predef:  \t END\n");}
[a-zA-Z]([0-9]|[a-zA-Z]|[_!])*  {printf("Variabel:\t %s\n",yytext);}
{TAL}   {printf("Tal: \t vaerdi= %d\n",atoi(yytext));}

[ \t\n] ;

.       {printf("enkelt tegn:\t %s\n",yytext);}
%%

//int yywrap() { return 1; }

main()
{
  yylex();
}
