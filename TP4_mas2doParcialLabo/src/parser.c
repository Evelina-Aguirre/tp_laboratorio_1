#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eArticulos.h"
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
	Employee* auxEmployee=NULL;
	int cant;// cantidad de elementos que pudo leer fscanf;
	char buffer[6][30];


	if(pFile!= NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);  //lectura "fantasma" renglón título.

		do{

			cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
			if(cant<5)
			{
				ret=-1;
				break;
			}
			else
			{

				auxEmployee=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
				ll_add(pArrayListEmployee,auxEmployee);
				ret=0;
			}


			}while(!feof(pFile));

	}
    return ret;
}

//-----------------------------------------------------------------------------------------------------------------------



