%{
#include <string.h>
#include <stdio.h>
#include "symtab.h"
#include "rpd.h"
%}

variabelnavn [a-zA-Z][a-zA-Z0-9]*

%%
begin   {return beginT;}
end     {return endT;}
int     {return intT;}
float   {return floatT;}
program {return programT;}

{variabelnavn} {if ((yylval.symptr= lookup_sym(yytext)) == NULL)
                    yylval.symptr= insert_sym(yytext);
               return idT;}
               
--C--(.|\n)*--C-- { printf("%s\n",yytext);}

[ \t\n\r] {;}

.           {return yytext[0];} 

%%

int yywrap() {return 1;}

int
hash(char *s)
{
	int             hv = 0;
	int             i;
	for (i = 0; s[i] != '\0'; i++) {
		int v = (hv >> 28) ^ (s[i] & 0xf);
		hv = (hv << 4) | v;
	}
	hv = hv & 0x7fffffff;
	return hv % HASHSIZE;
}

struct symnote *
lookup_sym(char *s)
{
	struct symnote *sptr;
	int  index = hash(s);
        //printf("lookup: %s\n",s);
	sptr = symbolarray[index];
	while ((sptr != NULL) && (strcmp(sptr->name, s) != 0))
		sptr = sptr->next;
	return sptr;
}


struct symnote *
insert_sym(char *s)
{
	struct symnote *sptr;
	int  index = hash(s);
        //printf("insert: %s\n",s);
	sptr = symbolarray[index];
	if (sptr == NULL) {
		sptr = (struct symnote *) malloc(sizeof(struct symnote));
		symbolarray[index] = sptr;
	} else {
		while ((sptr->next != NULL))
			sptr = sptr->next;
		sptr->next = (struct symnote *) malloc(sizeof(struct symnote));
		sptr = sptr->next;
	}
	sptr->next = NULL;
	sptr->name = strdup(s);
	return sptr;
}

void init_sym()
{
	int  i;
	for (i = 0; i < HASHSIZE; i++)
		symbolarray[i] = NULL;
}
