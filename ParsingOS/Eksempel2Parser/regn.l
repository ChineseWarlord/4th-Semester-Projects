%{
#include <math.h>
#include <string.h>
#include "symtab.h"
#include "regn.tab.h"
%}

realtal      ([0-9]+|([0-9]*\.[0-9]+))([eE][-+]?[0-9]+)?



%%
{realtal}      {yylval.dval = atof(yytext); 
                return TAL;}


[ \t] ;


'$'            {return 0;} 

\n|.           {return yytext[0];} 

%%

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

init_sym()
{
	int  i;
	for (i = 0; i < HASHSIZE; i++)
		symbolarray[i] = NULL;
}
