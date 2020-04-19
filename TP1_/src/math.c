#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int*pResultado);
static int esNumerica(char* cadena);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
 *
 * \brief Suma los valores ingresados en valor1(x) y valor2(y).
 * \param float x Para valor 1.
 * \param float y Para valor 2.
 * \return Retorna la suma de los dos valores.
 *
 */
int math_sumInt (int x, int y)
{
   return x+y;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
 *
 * \brief Resta los valores ingresados en valor1(x) y valor2(y).
 * \param float x Para valor 1.
 * \param float y Para valor 2.
 * \return Retorna la resta de los 2 valores.
 *
 */
int math_subtractionInt(int x, int y)
{
    return x-y;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Multiplica los valores ingresados en valor1(x) y valor2(y).
 * \param float x Para valor 1.
 * \param float y Para valor 2.
 * \return Retorna el producto de los 2 valores.
 *
 */
int math_multiplicationInt (int x, int y)
{
    return x*y;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
 *
 * \brief Divide los valores ingresados en valor1(x) y valor2(y).
 * \param float x Para valor 1.
 * \param float y Para valor 2.
 * \return retorna 0 si se pudo realizar la división y (-1) en caso de que el dividendo sea igual a 0;
 *
 */

float math_divisionint(float *pResultado, int x , int y)
{
	int retorno;
	if(y != 0)
    {
		*pResultado =(float) x / y;
		retorno=0;

    }
	else
	{
	retorno =-1;
	}


    return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Factorial toma el valor de x y realiza la multiplicación de todos los números enteros positivos desde 1 hasta el valor ingresado.
 * \param float x para el valor del cual se calculara el factorial.
 * \return retorna el factorial del valor x.
 *
 */
long int math_factorialInt(int x)
{

	long int valor;
    valor = 1;
        while(x > 1) {
        	valor *= x;
           x--;
        }
    return valor;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * \brief utn_getNumero solicita un número al usuario, lo valida y devuelve el número ingresado.
 * \param pResultado Puntero donde se guardará el número ingresado.
 * \param mensaje es el mensaje a ser mostrado.
 * \param mensajeError Mensaje que se mostrará en caso de que el dato ingresado no sea válido.
 * \param minimo Valor mínimo aceptado.
 * \param maximo Valor máximo aceptado.
 * \param reintentos Cantidad de reintentos aceptados.
 * \return En caso de Exito devuelve 0, en caso de error devuelve -1.
 *
 */


int math_getNumber(int* pResultado,char*mensaje, char*mensajeError, int minimo,int maximo,int reintentos)
{
	int ret;
	int num;


	while(reintentos>0)
	{
		printf("%s",mensaje);
		//scanf("%d",&num);
		fflush(stdin);
		if(getInt(&num)==1)
		{

			if(num<=maximo&&num>=minimo)
			{break;}
		}

		reintentos--;
		printf("%s",mensajeError);

	}

	if(reintentos==0)
	{
	 ret=-1;
	}
	else
	{
	 ret=0;
	 *pResultado = num;
	}
	return ret;
	}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

static int getInt(int*pResultado)
{
	int ret=-1;
	char buffer[64];
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strlen(buffer)-1]='\0';
	if(esNumerica(buffer))
	{
		*pResultado=atoi(buffer);
		return 1;
	}

	return ret;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
static int esNumerica(char* cadena)
{
	int ret=-1;
	int i=0;
	if(cadena!=NULL)
	{
		while(cadena[1]!='\0')
		{
			if(cadena[i]<'0'||cadena[i]>'9')
				{break;}

			i++;
		}

	if(cadena[i]=='\0')
		{ret=1;}


	}
	return ret;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief math_messageCalculated IMPRIME MENSAJE DE QUE SE HAN CALCULADO LAS OPERACIONES SUMA, RESTA,MULTIPLICACIÓN, DIVISIÓN Y FACTORIAL,
 * \param CondicionAValidar  SI ES -1-IMPRIME MENSAJE ,SI ES (-1)IMPRIME MENSAJE CON ERROR SI NO SE REALIZÓ LA DIVISION
 * \param valorUno OPERANDO UNO.
 * \param valorDos OPERNCO DOS.
 *
 * \return VOID
 *
 */
void math_messageCalculated(int CondicionAValidar,int valorUno,int valorDos)
{
	if(CondicionAValidar!=0){ //CASO ERROR EN DIVISIÓN
		CondicionAValidar=printf("\n**************************************************************\n\n"
									"Se realizaron SUMA, RESTA, MULTIPLICACIÓN Y FACTORIAL entre :\n\n"
									"Operando 1: %d\n"
									"Operando 2: %d\n\n"
									"**NO SE CALCULÓ COCIENTE: El operando 2 debe ser diferente de 0**\n\n"
									"Ingrese -4- para ver resultado...\n\n"
									,valorUno,valorDos);
							printf("**************************************************************\n\n");


						}
						else//CASO DIVISIÓN CORRECTA
						{

						printf("\n**************************************************************\n\n");
						printf("Se calcularon SUMA, RESTA, MULTIPLICACIÓN,DIVISIÓN Y FACTORIAL entre:\n\n"
								"Operando 1: %d\n"
								"Operando 2: %d\n\n"
								"Ingrese -4- para ver resultado...\n\n"
								,valorUno,valorDos);
						printf("**************************************************************\n\n");


						}

}


/**
 * \brief math_messageResult IMPRIME RESULTADO DE LAS OPERACIONES SUMA, RESTA,MULTIPLICACIÓN, DIVISIÓN Y FACTORIAL.
 * \param CondicionAValidar  SI ES -1- IMPRIME MENSAJE ,-CUALQUIER OTRO VALOR- IMPRIME MENSAJE CON ERROR SI NO SE REALIZÓ LA DIVISION
 * \param valorUno OPERANDO UNO.
 * \param valorDos OPERNCO DOS.
 * \param suma,resta,multiplicacion,respuestaDivision,factorialA,factorialB  RESULTADO DE LAS OPERACIONES
 *
 * \return VOID
 *
 */

void math_messageResult(int CondicionAValidar,int valorUno,int valorDos,int suma,int resta,int multiplicacion,float respuestaDivision,long factorialA,long factorialB)
{
	if(CondicionAValidar!=1)//RESPUESTA EN CASO DE DIVISIÓN CORRECTA
				{
				printf("\n******* RESULTADO DE OPERACIONES CON VALORES %d y %d  *********\n\n"
						"Suma : %d\n"
						"Resta: %d\n"
						"Multiplicación :%d\n"
						"División : * Para realizar esta operación el divisor debe ser diferente de 0 *\n"
						"Factorial Operando 1 : %ld\n"
						"Factorial Operando 2: %ld\n\n"
						"**************************************************************\n\n"
						,valorUno,valorDos,suma, resta,multiplicacion,factorialA,factorialB);
				}
				else//RESPUESTA EN CASO DE DIVISIÓN CON DIVISOR IGUAL A 0.
				{
					printf("\n******* RESULTADO DE OPERACIONES CON VALORES %d y %d  *********\n\n"
							"Suma : %d\n"
							"Resta: %d\n"
							"Multiplicacion :%d\n"
							"División : %.2f\n"
							"Factorial Operando 1 : %ld\n"
							"Factorial Operando 2: %ld\n\n"
							"**************************************************************\n\n"
							,valorUno,valorDos,suma, resta,multiplicacion,respuestaDivision,factorialA,factorialB);
				}

}
