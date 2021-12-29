%{
#include <math.h>
#include <string.h>
#include "symtab.h"

#define BEGIN_T    257
#define END_T      258
#define IF_T       259
#define TAL_T      260
#define VARIABEL_T 261
	struct symnote *sptr;
	float           val;

%}

realtal      ([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)
variabelnavn [a-zA-Z][a-zA-Z0-9]*

%%
begin          {return BEGIN_T;}
end            {return END_T;}
if             {return IF_T;}


{realtal}      {val = atof(yytext);
	        return TAL_T;}

{variabelnavn} {if ((sptr = lookup_sym(yytext)) == NULL)
		  sptr = insert_sym(yytext);
	        return VARIABEL_T;}

[\t \n]        ;

.               {return yytext[0];}

%%

int yywrap() {return 1;}

int
hash(char *s)
{
	int             hv = 0;
	int             i;
	for (i = 0; s[i] != '\0'; i++) {
		int             v = (hv >> 28) ^ (s[i] & 0xf);
		hv = (hv << 4) | v;
	}
	hv = hv & 0x7fffffff;
	return hv % HASHSIZE;
}

struct symnote *
lookup_sym(char *s)
{
	struct symnote *sptr;
	int             index = hash(s);
	sptr = symbolarray[index];
	while ((sptr != NULL) && (strcmp(sptr->name, s) != 0))
		sptr = sptr->next;

	if (sptr== NULL) printf("\"%s\" Not found\n", s);
	else  printf("\"%s\" Found\n", s);

	return sptr;
}

struct symnote *
insert_sym(char *s)
{

	struct symnote *sptr;
	int             index = hash(s);
	sptr = symbolarray[index];
	symbolarray[index] = (struct symnote *) malloc(sizeof(struct symnote));

	if (sptr == NULL)
		symbolarray[index]->next = NULL;
	else
		symbolarray[index]->next = sptr;
	symbolarray[index]->name = strdup(s);
	symbolarray[index]->type = 0;

	printf("\"%s\" inserted\n", s);

	return symbolarray[index];
}

init_sym()
{
	int             i;
	for (i = 0; i < HASHSIZE; i++)
		symbolarray[i] = NULL;
}

void
print_sym()
{
	struct symnote *sptr;
	int             index;
	printf("Synboltabel:\n");
	for (index = 0; index < HASHSIZE; index++) {
		printf("index:%d -> ", index);
		sptr = symbolarray[index];
		while (sptr != NULL) {
			printf("%s -> ", sptr->name);
			sptr = sptr->next;
		}
		printf("NULL\n");
	}
}

int
main()
{
	int             token;
	while ((token = yylex()) != END_T) {
		printf("token: %d, ", token);
		switch (token) {
		case BEGIN_T:
			printf("type: BEGIN\n");
			break;
		case END_T:
			printf("type: END\n");
			break;
		case IF_T:
			printf("type: IF\n");
			break;
		case TAL_T:
			printf("type: TAL  vaerdi: %f, stavemaade: %s\n", val, yytext);
			break;
		case VARIABEL_T:
			printf("type: VARIABEL,   stavemaade: %s\n", yytext);
			break;
		default:
			printf(" type: Enkelttegn, stavemaade: %s\n", yytext);
			break;
		}
	}
	print_sym();
}
