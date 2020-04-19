/*
 ============================================================================

 Name        : TP1_.c

 Objetivo    : Calculadora SUMA, RESTA , MULTIPLICACIÓN, DIVISION Y FACTORIAL con dos valores.

 Version     : 1.0 18/04/2020

 Authora      : Evelina Aguirre.

 *============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main(void) {

	setbuf(stdout,NULL);

		int a,b,suma,resta,multiplicacion;
		int flagA=0,flagB=0;
		float division,respuestaDivision;
		long int factorialA,factorialB;
		int opcionMenu,respuestaMenu;
		int divisionValida;

		do{
			if(flagA==0)
			{
				printf("\n--------------- MENU -----------------\n");
				printf("\n1-Ingresar 1er operando (A=x)\n");
			}
			else
			{
				printf("\n--------------- MENU -----------------\n");
				printf("\n1-Ingresar 1er operando (A=%d)\n",a);
			}
			if(flagB==0)
			{
				printf("2-Ingresar 2do operando (B=x) \n");
			}
			else
			{
				printf("2-Ingresar 2do operando (B=%d) \n",b);
			}

				respuestaMenu=math_getNumber(&opcionMenu,
				"3-Calcular todas las operaciones:\n"
				"      a) Calcular la suma (A+B)\n"
				"      b) Calcular la resta (A-B)\n"
				"      c) Calcular la division (A/B)\n"
				"      d) Calcular la multiplicacion(A*B)\n"
				"      e) Calcular el factorial (A!)\n\n"
				"4-Informar resultados\n"
				"5-Salir\n\n"
				"---------------------------------------\n\n--> ",
				"\n**Error.La opción no es válida**\n\n",1,5,100);


		if(respuestaMenu==0)
		{
			switch(opcionMenu)//CASOS OPCIONES MENU.
			{

			case 1:
				math_getNumber(&a,"\nIngrese el primer valor a calcular : ","Error.\n\n\n", -99999,99999,3);
				flagA=1;


				break;
			case 2:
				math_getNumber(&b,"\nIngrese el segundo valor a calcular : ","Error.\n\n\n", -99999,99999,3);
				flagB=1;

				break;

			case 3://INFORMA QUE SE REALIZARON LAS 5 OPERACIONES
					if(flagA==0 && flagB==0)//CASO =NOSE INGRESO NINGUN VALOR
					{
						printf("\n\n* DEBE INGRESAR ALMENOIS UN VALOR PARA OPERAR *\n\n");
					}
					else if(flagA==0 && flagB==1)//CASO =SOLO SE INGRESO B
					{
						factorialB=math_factorialInt(b);
						printf("\n**************************************************************\n\n");
						printf("Se calculó sólo en FACTORIAL del valor B");
						printf("\n\n*PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES*");
						printf("\n\nIngrese -4- para ver resultado...\n\n");
						printf("\n**************************************************************\n\n");
					}
					else if(flagA==1 && flagB==0)//CASO =SOLO SE INGRESO A
					{
						factorialA=math_factorialInt(a);
						printf("\n**************************************************************\n\n");
						printf("Se calculó sólo en FACTORIAL del valor A");
						printf("\n\n*PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES*");
						printf("\n\nIngrese -4- para ver resultado...\n\n");
						printf("\n**************************************************************\n\n");
					}
					else
					{
					math_messageCalculated(divisionValida,a,b);
				    suma=math_sumInt(a, b);
					resta=math_subtractionInt(a,b);
					multiplicacion=math_multiplicationInt(a,b);
					factorialA=math_factorialInt(a);
					factorialB=math_factorialInt(b);
					respuestaDivision=math_divisionint(&division, a, b);
					}

					if(respuestaDivision==1) //REALIZA LA DIVISIÓN SÓLO SI B!=0
					{
						respuestaDivision=division;
						divisionValida=0;
					}
					else//MARCA QUE EL DIVISOR ES 0 PARA INFORMARLO MÁS TARDE.
					{
						respuestaDivision=0;
						divisionValida=-1;
					}


					break;

			case 4://INFORMA EL RESULTADO
				if(flagA==0 && flagB==0)
				{
					printf("\n\n* DEBE INGRESAR ALMENOIS UN VALOR PARA OPERAR*");
				}
				else if(flagA==0 && flagB==1)
				{
					printf("\n**************************************************************\n\n");
					printf("\n\nFACTORIAL de %d : %ld",b,factorialB);
					printf("\n\n * PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES *\n\n");
					printf("\n**************************************************************\n\n");
}
				else if(flagA==1 && flagB==0)
				{
					printf("\n**************************************************************\n\n");
					printf("\n\nFACTORIAL de %d : %ld",a,factorialA);
					printf("\n\n * PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES *\n\n");
					printf("\n**************************************************************\n\n");
				}
				else
				{
						math_messageResult(divisionValida,a,b,suma,resta,multiplicacion,respuestaDivision,factorialA,factorialB);
				}

				break;
			}//FIN DE SWITCH
		}//FIN DE IF
		}while(opcionMenu!=5);

	return EXIT_SUCCESS;
}



