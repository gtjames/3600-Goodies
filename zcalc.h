#define NSYMS 20

struct symtab {
  char *name;
  double (*funcptr)();
  double value;
} symtab[NSYMS];

struct symtab *symlook();

