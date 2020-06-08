#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void *xmalloc(unsigned int nrOcteti)
{
	void *a=0;
	a=malloc(nrOcteti);
	if(!a)
	{
		printf("alocare dinamica esuata");
		exit(1);
	}
	return a;
}

int **aloc2d(int l,int c)
{
	int **a=0;
	int i;
	a=(int**)xmalloc(l*sizeof(int*));
	for(i=0;i<l;++i)
	{
		a[i]=(int*)xmalloc(c*sizeof(int));
	}
	return a;
}

void dealoc2d(int **a,int l)
{
	int i;
	for(i=0;i<l;++i)
	{
		free(a[i]);
		a[i]=0;
	}
	free(a);
	a=0;
}

int **citireM(int l,int c)
{
	int **a=0;
	int i,j;
	a=aloc2d(l,c);
	for(i=0;i<l;++i)
	{
		printf("randul %d: ",i);
		for(j=0;j<c;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	return a;
}

double *citireV(int l)
{
	double *v=0;
	int i;
	v=(double*)xmalloc(l*sizeof(double));
	for(i=0;i<l;++i)
	{
		printf("pret/randul %d: ",i);
		scanf("%lf",&v[i]);
	}
	return v;
}

char *denumire()
{
	// char *den;
	// char buff[101];
	// fgets(buff,101,stdin);
	// buff[strlen(buff-1)]='\0';
	// den=(char*)xmalloc((strlen(buff)+1)*sizeof(char));
	// strcpy(den,buff);
	// return den;
	char *den;
	char buff[101];
	den=fgets(buff,100,stdin);
	return den;
}


void afisare1(char *den,int **a,double *v,int l,int c,FILE *f)
{
	fprintf(f,"La spectacolul \"%s\" ocuparea salii si preturile au fost:\n",den);
	int i,j;
	for(i=0;i<l;++i)
	{
		fprintf(f,"\t");
		for(j=0;j<c;++j)
		{
			fprintf(f,"%d ",a[i][j]);
		}
		fprintf(f," - pret/loc: %lf lei",v[i]);
		fprintf(f,"\n");
	}
}




























