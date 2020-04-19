#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int math_getNumber(int* pResultado,char*mensaje, char*mensajeError, int minimo,int maximo,int reintentos);

void math_messageCalculated(int CondicionAValidar,int valorUno,int valorDos);
void math_messageResult(int CondicionAValidar,int valorUno,int valorDos,int suma,int resta,int multiplicacion,float respuestaDivision,long factorialA,long factorialB);

int math_sumInt(int x, int y);
int math_subtractionInt(int x, int y);
int math_multiplicationInt(int x, int y);
float math_divisionint(float *pResultado, int x , int y);
long int math_factorialInt(int x);

