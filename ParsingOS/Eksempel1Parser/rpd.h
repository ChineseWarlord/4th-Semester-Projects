#define intT 	256
#define floatT 	257
#define idT 	258
#define beginT 	259
#define endT 	260
#define realT 	261
#define programT 	262

void init_sym();


void varlist();
void vartypelist();
void type();
void identlist();
void identelmlist();
void stlist();
void statement();
void aexp();
void bexp();



typedef union {
	char           *string;
	double          dval;
	struct symnote *symptr;
} YYSTYPE;

YYSTYPE yylval;


