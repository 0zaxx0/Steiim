#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void MenuP()
{
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	printf("|                                  	    |");
	printf("|     1.- Crear Matriz             	    |");
	printf("|     2.- Calcular valores propios    	    |");
	printf("|     3.- Calcular vectores propios         |");
	printf("|     4.- Calcular ecs. que rigen cambio    |");
	printf("|     5.- Mostrar Matriz P (normalizada)    |");
	printf("|     6.- Calcular angulo de rotacion       |");
	printf("|     7.- Calcular ecuacion trasladada	    |");
	printf("|     8.- Graficar			    |");
	printf("|     9.- Salir			    	    |");
	printf("|					    |");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
}

void menu1()
{
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	printf("|					    |");
	printf("|					    |");
	printf("|    					    |");
	printf("|					    |");
	printf("|     1.- Ingresar valores o ecuacion       |");
	printf("|     2.- Leer matriz desde archivo         |");
	printf("|     3.- Volver   			    |");
	printf("|     					    |");
	printf("|					    |");
	printf("|					    |");
	printf("|					    |");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
}

//generar matriz ingresada por usuario o leida desde archivo
//calcular valores propios
//calcular vectores propios

int main(int argc, int **argv)
{
	int *A;
	int flag=0;
	int x;
	int R; 
	int opc=0;
	int opc1=0;
	x=atoi(argv[1]);
	R=x*x;
	while(opc!=9)
	{
		system("clear");
		MenuP();
		//leer opc
		if(opc==1)	//generar Matriz
		{		
			A=(int*)malloc(R*sizeof(int));
			menu1();
			//leer opc1
			system("clear");
			while(opc1!=3)
			{
				if(opc1==1)
				{
					//leer valores desde terminal
					flag==1;
				}
				if(opc1==2)
				{
					//leer valores desde un archivo
					flag==1;
				}
			}
		}
		if(opc==2)		//calcular valores propios
		{
			if(flag<1)
			{
				printf("\n\n\tNo existe matriz\n\n");
				//pause
			}
			else
			{
				//hacerlo
				flag==2;
			}
		}
		if(opc==3)		//calcular vectores propios
		{
			if(flag<2)
			{
				printf("\n\n\tNo se puede calcular vetores\n\n");
				//pause
			}
			else
			{
				//hacerlo
				flag=3;
			}
		}
		if(opc==4) 		//Calcular ecs. que rigen el cambio
		{
			if(flag<3)
			{
				printf("\n\n\tNo se puede calcular las ecs.\n\n");
				//pause
			}
			else
			{
				//hacerlo
				flag=4;
			}
		}
		if(opc==5)		//Morstar matriz P
		{
			if(flag<4)
			{
				printf("\n\n\tNo se puede mostrar la matriz P\n\n");
				//pause
			}
			else
			{
				//hacerlo
				flag=5;
			}
		}
		if(opc==6)		//calcular angulo de rotacion
		{
			if(flag<5)
			{
				printf("\n\n\tNo se puede calcular angulo de rotacion\n\n");
				//pause
			}
			else
			{
				//hacerlo
				flag=6;
			}
		}
		if(opc==7)		//calcular ec. trasladada
		{
			if(flag<6)
			{
				printf("\n\n\tNo se puede calcular ec trasladada\n\n");
				//pause
			}
			else
			{
				//hacerlo
				flag=7;
			}
		}
		if(opc==8)
		{
			if(flag<7)
			{
				printf("\n\n\tNo se puede graficar\n\n");
				//pause
			}
			else
			{
				//hacerlo
			}
		}
	}
	return 0;
}
