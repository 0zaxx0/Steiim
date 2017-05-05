#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
//#include <size.h>

int valorabs(int x)
{
	x=x>>31;
	return x;
}

int32_t diff(int32_t a, int32_t b)
{
	int32_t temp = a-b;
	if((temp)<0)
	{
		return (a-b)*-1;
	}
	else
	{
		return (a-b);
	}
}

uint8_t size(int32_t a)
{
	if(a & 0xff == a)
	{
		return 0;
	}
	if(a & 0xffff == a)
	{
		return 1;	
	}
	if(a & 0xffffff == a)
	{
		return 2;
	}
	if(a & 0xffffffff == a)
	{
		return 3;
	}
}

uint8_t pack(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
	uint8_t code=0;
	code=(d<<6)|(c<<4)|(b<<2)|a;
	return code;
}

void steim(int32_t *compr, size_t n, int32_t **res, uint8_t *code)
{
	int32_t tmp[4];
	uint8_t code_temp; // de deracha a izquierda (realloc)
	int i;
	code=(uint8_t*)malloc(4*sizeof(uint8_t));
	tmp[0]=size(compr[0]);
	for(i=1;i<4;i++)
	{
		tmp[i]=size(diff(compr[i],compr[i-1]));
	}
	code[0]=pack(tmp[0],tmp[1],tmp[2],tmp[3]);
	printf("%d",code[0]);
}

void mostrar(int *a, int largo)
{
	int cont;
	for (cont=0;cont<largo;cont=cont+1)
	{
		printf("\n%d\n",a[cont]);
	}
}

void descomp(int *a, int largo)
{
	int cont;
	int *array;
	array=(int*)malloc(largo*sizeof(int));
	array[0]=a[0];
	for(cont=1;cont<largo;cont=cont+1)
	{
		if(cont==largo-1)
		{
			array[cont]=a[cont];
		}
		else
		{
			array[cont]=array[cont-1]-a[cont];
		}
	}
	mostrar(array,largo);
}

void compres(int *a, int largo)
{
	int cont;	//contador para moverse en el arreglo
	int *array;	//cabecera del arreglo
	array=(int*)malloc(largo*sizeof(int));	//originalmente el largo del arreglo debe ser ((2*n)-2) donde la primera mitad guarda la diff
	array[0]=a[0];
	for(cont=1;cont<largo;cont=cont+1)
	{	
		if(cont==largo-1)
		{
			array[cont]=a[cont];
		}
		else
		{
			array[cont]=diff(a[cont],a[cont-1]);
		}
	}
	mostrar(array,largo);
	descomp(array,largo);
}


/*

void comprime(int x; int y)
{
	if((sizeof(y)-sizeof(x))==1)
	{
		return 01;	
	}
	if(sizeof(y)-sizeof(x)==2)
	{
		return 10;	
	}
	return 0;
}

*/


int main(int argc,char **argv)
{
	int x;
	int i;
	int r;
	int y;
	int *arreglo;
	int steim1[argc-1];
	x=atoi(argv[1]);
	y=size(x); 
	printf("%d",y);
	int32_t **res;
	uint8_t *code;
	arreglo=(int*)malloc(x*sizeof(int));
	for(i=0;i<x;i=i+1)
	{
		arreglo[i]=rand() % x;	//arreglo para nada random
	}
	steim(arreglo,x,res,code);
	mostrar(arreglo,x);
	//descomp(arreglo,x);
	//y=valorabs(x);
	//printf("\n%d\n",y);
	//printf("%d",x);
	return 0;
}
