#define HASHSIZE 20
//#define NULL 0

struct symnote
{
	struct symnote *next;
	char           *name;
	int             type;
	double          value;
};

struct symnote *symbolarray[HASHSIZE];

struct symnote *lookup_sym();
struct symnote *insert_sym();
