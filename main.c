#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc,char *argv[])
{
	int **a=0;
	double *v=0;
	char *den=0;
	char *numeFisier=0;
	int l,c;
	printf("denumirea spectacolului:");
	den=denumire();
	printf("nr de randuri:"); scanf("%d",&l);
	printf("nr de locuri/rand:"); scanf("%d",&c);
	a=citireM(l,c);
	v=citireV(l);
	FILE *f;
	numeFisier=(char*)xmalloc(strlen((argv[1])+1)*sizeof(char));
	strcpy(numeFisier,argv[1]);
	f=fopen(numeFisier,"w");
	if(!f)
	{
		printf("eroare la afisare in fisier");
		exit(1);
	}
	afisare1(den,a,v,l,c,f);
	dealoc2d(a,l);
	free(v);
	v=0;
	return 0;
}

