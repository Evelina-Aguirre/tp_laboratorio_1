#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"



//-----------------------------------------------------------------------------------------------------------------------------------------------------

Employee* employee_new()
{
	Employee* employee= (Employee*)malloc(sizeof(Employee));

		if(employee!=NULL)
		{
			employee_setNombre(employee,"");
			employee_setHorasTrabajadas(employee,0);
			employee_setSueldo(employee,0);
		}

	return employee;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
			Employee* employee=employee_new();

			employee_setId(employee,atoi(idStr));
			employee_setNombre(employee,nombreStr);
			employee_setHorasTrabajadas(employee,atoi(horasTrabajadasStr));
			employee_setSueldo(employee,atoi(sueldo));

		return employee;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------


int employee_setId(Employee* this,int id)
{
	int ret=-1;
	if(this != NULL && id>=0)
	{
		this->id=id;
		ret=0;

	}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_getId(Employee* this,int* id)
{
	int ret = -1;
	if(this!= NULL)
	{
		*id = this ->id;
		ret=0;
	}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_setNombre(Employee* this,char* nombre)
{
	int ret=-1;
	if(nombre!=NULL && strlen(nombre)>0)
		{
			strcpy(this->nombre,nombre);
			ret=0;
		}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_getNombre(Employee* this,char* nombre)
{
	int ret = -1;
	if(this!= NULL)
	{
		strcpy(nombre,this->nombre);
		ret=0;
	}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int ret = -1;
		if(this!= NULL && horasTrabajadas>=0)
		{
			this ->horasTrabajadas=horasTrabajadas ;
			ret=0;
		}
		return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret=-1;
	if(this!= NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		ret=0;
	}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_setSueldo(Employee* this,int sueldo)
{
	int ret=-1;
	if(this!=NULL && sueldo>=0)
		{
			this->sueldo=sueldo;
			ret=0;
		}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret=-1;
		if(this!=NULL)
			{
				*sueldo=this->sueldo;
				ret=0;
			}
		return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_searchLastId(LinkedList* pArrayListEmployee)
{
	Employee * auxEmp;
	int len = ll_len(pArrayListEmployee);
	int lastId=0;
	int id;
	int i;

	if(pArrayListEmployee != NULL)
	{

		for(i=0;i<len;i++)
		{
			auxEmp=ll_get(pArrayListEmployee,i);
			employee_getId(auxEmp,&id);

			if(id>lastId)
			{
				lastId=id;

			}
		}

	}
	return lastId;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------
int employee_getIndexFromId(int* index, LinkedList* pArrayListEmployee,int id)
{
	int ret=-1;
	int i;
	int len=ll_len(pArrayListEmployee);
	Employee* employee=employee_new();

	if(employee!=NULL)
	{
		for(i=0;i<len;i++)//RECORRO LINKEDLIST Y LE ASIGNO UN "INDICE" HASTA ENCONTRAR EL ID DEL EMPLEADO
		{
			employee=ll_get(pArrayListEmployee,i);
			if(id==employee->id )
			{
				*index=i;
				ret=0;
				break;
			}
		}

	}

	return ret;


}
//--------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_printOneEmployee(Employee* employee)
{
	int ret =-1;

	if(employee != NULL)
	{
		printf("%5d %10s   %3d %8d \n", employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);


		ret=1;
	}

	return ret;

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_sortById(void * thisA,void *thisB)
{
	int ret ;
	int idA;
	int idB;

	employee_getId(thisA,&idA);
	employee_getId(thisB,&idB);

	printf("\nOrdenando por ID, por favor espere... ");
	printf(" ID A  %d",idA);
	printf(" -> ID B  %d",idB);


	if(idA>idB)
	{
		ret=1;
	}
	else if(idA<idB)
	{
		ret=-1;
	}
	else
	{
		ret=0;
	}
	return ret;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int employee_sortByName(void * thisA,void *thisB)
{
	int ret ;//Devulve 0 si son iguales
	char nameA[50];
	char nameB[50];

	employee_getNombre(thisA,nameA);
	employee_getNombre(thisB,nameB);
	printf("\nOrdenando por Nombre, por favor espere... El proceso demora apróximadamente 5 min. por cada 1000 empleados");

	if(strcmp(nameA,nameB)>0)
	{
		ret=1;
		printf(" caso 1");
	}
	else if(strcmp(nameA,nameB)>0)
	{
		ret=-1;
		printf(" caso -1");
	}
	else
	{
		ret=0;
		printf(" caso 0");
	}
	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------

int employee_sortByHs(void * thisA,void *thisB)
{
	int ret ;
	int hsA;
	int hsB;

	employee_getHorasTrabajadas(thisA,&hsA);
	employee_getHorasTrabajadas(thisB,&hsB);
	printf("\nOrdenando por Horas Trabajadas, por favor espere... El proceso demora apróximadamente 5 min. por cada 1000 empleados");
	printf(" HS A  %d",hsA);
	printf(" -> HS B  %d",hsB);
	if(hsA>hsB)
	{
		ret=1;
	}
	else if(hsA<hsB)
	{
		ret=-1;
	}
	else
	{
		ret=0;
	}
	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
int employee_sortBySalary(void * thisA,void *thisB)
{
	int ret;
	int salaryA;
	int salaryB;

	employee_getSueldo(thisA,&salaryA);
	employee_getSueldo(thisB,&salaryB);

	printf("\nOrdenando empleados por Salario. El proceso demora apróximadamente 5 min. por cada 1000 empleados, por favor espere... ");
	printf(" HS A  %d",salaryA);
	printf(" -> HS B  %d",salaryB);
	if(salaryA>salaryB)
	{
		ret=1;
	}
	else if(salaryA<salaryB)
	{
		ret=-1;
	}
	else
	{
		ret=0;
	}
	return ret;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
int employee_sortMenu()
{
	int opcion;
	printf("\n\n------------------------------------------------------");
	printf("\n-------------------- ORDENAR --------------------------\n");
	printf("\n  1-  ID - Mayor a Menor");
	printf("\n  2-  ID - Menor a Mayor");
	printf("\n  3-  Horas trabajadas - Mayor a Menor");
	printf("\n  4-  Horas trabajadas - Menor a Mayor");
	printf("\n  5-  Sueldo - Mayor a Menor");
	printf("\n  6-  Sueldo - Menor a Mayor");
	printf("\n  7-  Salir al menú Anterior");
	printf("\n-------------------------------------------------------");
	printf("\n-------------------------------------------------------\n");
	utn_getNumber(&opcion,"\n--> ", "\n * INVALID OPTION * \n",1, 7,100);
	return opcion;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int removeMenu()
{
	int opcion;

	printf("\n1-  Confirmar baja");
	printf("\n2-  Volver al menú anterior");

	utn_getNumber(&opcion,"\n--> ", "\n * LA OPCIÓN ELEGIDA NO ES VÁLIDA * \n",1, 2,100);
	return opcion;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
int modifyMenu()
{
	int opcion;

	printf("\n1-  Modificar Nombre");
	printf("\n2-  Modificar Horas Trabajadas");
	printf("\n3-  Modificar Sueldo");
	printf("\n4-  Volver al menú anterior");

	utn_getNumber(&opcion,"\n--> ", "\n * LA OPCIÓN ELEGIDA NO ES VÁLIDA * \n",1, 4,100);
	return opcion;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

