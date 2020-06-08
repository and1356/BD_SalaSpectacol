#ifndef header_h_
#define header_h_

void *xmalloc(unsigned int nrOcteti);
int **aloc2d(int l,int c);
void dealoc2d(int **a,int l);
int **citireM(int l,int c);
double *citireV(int l);
char *denumire();
void afisare1(char *den,int **a,double *v,int l,int c,FILE *f);

#endif
