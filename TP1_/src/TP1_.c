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
		int flagA=0,flagB=0,flagCalculo=0;
		float division,respuestaDivision;
		long int factorialA,factorialB;
		int opcionMenu;
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
							printf("2-Ingresar 2do operando (B=y) \n");

						}
						else
						{
							printf("2-Ingresar 2do operando (B=%d) \n",b);

						}

							printf(
							"3-Calcular todas las operaciones:\n"
							"      a) Calcular la suma (A+B)\n"
							"      b) Calcular la resta (A-B)\n"
							"      c) Calcular la division (A/B)\n"
							"      d) Calcular la multiplicacion(A*B)\n"
							"      e) Calcular el factorial (A!)\n\n"
							"4-Informar resultados\n"
							"5-Salir\n\n"
							"---------------------------------------\n\n--> ");
							scanf("%d",&opcionMenu);




			switch(opcionMenu)
			{

			case 1://Toma valor A y marca que se ingresó.
				flagA=1;
				math_getNumber(&a,"\nIngrese el 1er valor a calcular : ","Error.\n\n\n", -99999,99999,3);
				break;

			case 2://Toma valor B y marca que se ingresó.
				math_getNumber(&b,"\nIngrese el 2do valor a calcular : ","Error.\n\n\n", -99999,99999,3);
				flagB=1;
				break;

			case 3://INFORMA QUE SE REALIZARON LAS OPERACIONES y marca si se pasó por este paso antes del resultado.
					flagCalculo=1;

					if(flagA==0 && flagB==0)//Si no se ingresó ningún valor.
					{
						printf("\n\n* DEBE INGRESAR ALMENOS UN VALOR PARA OPERAR *\n\n");
					}
					else if(flagA==0 && flagB==1)//Si sólo ingresó valor B.
					{

							factorialB=math_factorialInt(b);
							printf("\n**************************************************************\n\n");
							printf("Se calculó SÓLO EL FACTORIAL del VALOR B");
							printf("\n\n*PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES*");
							printf("\n\nIngrese -4- para ver resultado...\n\n");
							printf("\n**************************************************************\n\n");
						}
						else if(flagA==1 && flagB==0)//Si sólo ingresó valor A.
						{
						factorialA=math_factorialInt(a);
						printf("\n**************************************************************\n\n");
						printf("Se calculó SÓLO EL FACTORIAL del VALOR A");
						printf("\n\n*PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES*");
						printf("\n\nIngrese -4- para ver resultado...\n\n");
						printf("\n**************************************************************\n\n");
						}
						else
						{

							suma=math_sumInt(a, b);
							resta=math_subtractionInt(a,b);
							multiplicacion=math_multiplicationInt(a,b);
							factorialA=math_factorialInt(a);
							factorialB=math_factorialInt(b);
							respuestaDivision=math_divisionint(&division, a, b);


						if(respuestaDivision==0) //REALIZA LA DIVISIÓN SÓLO SI B!=0
						{
							respuestaDivision=division;
							divisionValida=0;
						}
						else//MARCA QUE EL DIVISOR ES 0 PARA INFORMARLO MÁS TARDE.
						{
							divisionValida=-1;
						}
						math_messageCalculated(divisionValida,a,b);
					}
						break;

			case 4://INFORMA EL RESULTADO
				if(flagCalculo==0)
				{
					printf("\n\n * DEBE INGRESAR VALORES Y REALIZAR LOS CÁLCULOS PARA VISUALIZAR LOS RESULTADOS *\n\n");
				}
				else
				{
					if(flagA==0 && flagB==0)//Si no se ingresó ningún valor.
					{
						printf("\n\n* DEBE INGRESAR ALMENOIS UN VALOR PARA OPERAR*\n\n");
					}
					else if(flagA==0 && flagB==1)//Si sólo ingresó valor B.
					{
						printf("\n**************************************************************\n\n");
						printf("\n\nFACTORIAL de %d : %ld",b,factorialB);
						printf("\n\n * PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES *\n\n");
						printf("\n**************************************************************\n\n");
}
					else if(flagA==1 && flagB==0)//Si sólo ingresó valor A.
					{
						printf("\n**************************************************************\n\n");
						printf("\nFACTORIAL de %d : %ld",a,factorialA);
						printf("\n\n * PARA REALIZAR EL RESTO DE LAS OPERACIONES DEBE INGRESAR DOS VALORES *\n\n");
						printf("\n**************************************************************\n\n");
					}
					else
					{
						math_messageResult(divisionValida,a,b,suma,resta,multiplicacion,respuestaDivision,factorialA,factorialB);
					}
				}

				break;
			default:
				printf("\n\n * ERROR. LA OPCIÓN INGRESADA NO ES CORRECTA * \n\n");

			}//FIN DE SWITCH

		}while(opcionMenu!=5);

	return EXIT_SUCCESS;
}



