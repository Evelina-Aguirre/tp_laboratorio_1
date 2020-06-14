#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile archivo a parsear
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 en caso de error, 0 si fue posible cargar la Likedlist den modo txt.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret;
	Employee* auxEmployee;
	int cant;// cantidad de elementos que pudo leer fscanf;
	char buffer[4][30];

	if(pFile!= NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],",buffer[0],buffer[1],buffer[2],buffer[3]);  //lectura "fantasma" renglón título.

		do{

			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],",buffer[0],buffer[1],buffer[2],buffer[3]);
			if(cant<4)
			{
				ret=-1;
				break;
			}
			else
			{
				auxEmployee=employee_new();
				auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				ll_add(pArrayListEmployee,auxEmployee);
				ret=0;
			}


			}while(!feof(pFile));

	}
    return ret;
}

//-----------------------------------------------------------------------------------------------------------------------


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile archivo a parsear
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 en caso de error, 0 si fue posible cargar la Likedlist den modo Binario.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)//falta ajustes
{

	int ret;
	Employee* auxEmployee=employee_new();
	int cant;// cantidad de elementos que pudo leer fscanf;
	char buffer[4][30];

	if(pFile!= NULL && pArrayListEmployee != NULL)
	{
		fread(auxEmployee,sizeof(Employee),1,pFile);

		do{

			cant=fread(auxEmployee,sizeof(Employee),1,pFile);
			if(cant!=1)
			{
				ret=-1;
				break;
			}
			else
			{
				auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				ll_add(pArrayListEmployee,auxEmployee);
				ret=0;
			}


			}while(!feof(pFile));

	}
    return ret;
}
