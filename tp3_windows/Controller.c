#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* dirección del Archivo
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si la carga fue correcta, (-1) Si el archivo no pudo ser abierto
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret =-1;
	FILE* pArch;
	pArch= fopen(path,"r");//LEVANTO SÓLO LECTURA, CARGO MEMORIA DINÁMICA Y LO CIERRO. VUELVO A ABRIRLO PARA GUARDAR LOS CAMNIOS SÓLO EN LA OPCIÓN 8

	if(pArch != NULL && pArrayListEmployee != NULL)
	{
		 parser_EmployeeFromText(pArch,pArrayListEmployee);
		 ret = 0;
		 printf("\n * Archivos cargados desde data.csv en modo txt. * \n\n");
		 fclose(pArch);
	}
	else
	{
		printf("\n * Error. El archivo no pudo ser abierto * ");
	}

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* dirección del Archivo
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si la carga fue correcta, (-1) Si el archivo no pudo ser abierto
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* pArch;
	pArch= fopen(path,"rb");

	if(pArch != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromBinary(pArch,pArrayListEmployee);
		printf("\n * Archivos cargados desde data.csv en modo Binario. * \n\n");
		fclose(pArch);
		ret=0;

	}
	else
	{
		printf("\n * Error. El archivo no pudo ser abierto * ");
	}


 return ret;
}

/** \brief Alta de empleados, agrega un empleado a la Linkedlist
 *
 * \param pArrayListEmployee LinkedList* lista que se está manejando
 * \return int retorna -1 en caso de error , 0 si lacarga fue exitosa.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int lastId;
	char id[50];
	char name[50];
	int hs;
	int salary;
	char auxHs[30];
	char auxSalary[10];
	Employee* employee;

	if(pArrayListEmployee != NULL)
	{
			fflush(stdin);
			utn_getName(name,"\nIngrese Nombre : "," * Error. El nombre no es válido. *",0,237,30,10);
			utn_getNumber(&hs,"\nIngrese Horas trabajadas : ", "\n * Error. * \n",1, 5000,10);
			utn_getNumber(&salary,"\nIngrese Salario : ","\n * Error. * \n",1, 9999999,10);
			lastId=employee_searchLastId(pArrayListEmployee);
			lastId++;                                         //BUSCO ULTIMO ID Y LO INCREMENTO
			itoa(lastId,id,10);
			itoa(hs,auxHs,10);
			itoa(salary,auxSalary,10);

			employee=employee_newParametros(id,name,auxHs,auxSalary);
			ll_add(pArrayListEmployee, employee);
			printf("\n\n---------------------------------------");
			printf("\n   * Se agregó un nuevo Empleado * ");
			printf("\n---------------------------------------\n");
			retorno=0;

	}
    return retorno;
}


/** \brief Modificar datos de empleado, permite modificar nombre, sueldo y Horas Trabajadas
 *
* \param pArrayListEmployee LinkedList* lista que se está manejando
 * \return int retorna -1 en caso de error , 0 si lacarga fue exitosa.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int id;
	Employee* employee;
	int indexRelatedToThisId;
	int option;
	char nombre[50];
	int hs;
	int salary;


		utn_getNumber(&id,"\nIngrese ID del empleado a modificar : ","\n* NO SE ENCONTRÓ ID *",1,1000000,5);

		employee_getIndexFromId(&indexRelatedToThisId, pArrayListEmployee,id);//RETORNA POR PARÁMETRO ÍNDICE RELACIONADO A ESE ID POR LA CANTIDAD
																			//DE ITERACIONES QUE TIENE QUE REALIZAR HASTA LLEGAR A ÉL
		employee=ll_get(pArrayListEmployee,indexRelatedToThisId);
		if(employee!= NULL)
		{

				printf("\nEmpleado a modificar : \n\n");
				printf("  ID    NOMBRE     HORAS     SUELDO     \n");
				employee_printOneEmployee(employee);

				do{
					    	option=modifyMenu();

					        switch(option)
					        {
					            case 1:
					            	printf("\nIngrese Nombre :");
					            	scanf("%s",nombre);
					            	employee_setNombre(employee,nombre);
					            	printf("\n * Nombre modificado correctamente *\n");
					            	ret =0;
					            	break;
					            case 2:
					            	utn_getNumber(&hs,"\nIngrese sueldo : ","\n* Error. valor de sueldo inválido *",0,5000,10);
					            	employee_setHorasTrabajadas(employee,hs);
					            	printf("\n * Horas Trabajadas modificadas correctamente *\n");

					            	ret =0;
					            	break;
					            case 3:
					            	utn_getNumber(&salary,"\nIngrese sueldo : ","\n* Error. valor de sueldo inválido *",0,10000000,10);
					            	employee_setSueldo(employee,salary);
					            	printf("\n * Sueldo modificado correctamente *\n");

					            	ret =0;
					                break;

					        }

					    }while(option != 4);
		}
    return ret;
}

/** \brief Baja de empleado
 *
* \param pArrayListEmployee LinkedList* lista que se está manejando
 * \return int retorna -1 en caso de error , 0 si la baja fue exitosa.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int id;
	int indexRelatedToThisId;
	int optionConfirm;


	Employee* employee=employee_new();

	if(pArrayListEmployee != NULL)
	{
		utn_getNumber(&id,"\nIngrese ID del empleado a dar de baja : ","\n* NO SE ENCONTRÓ ID *",1,1000000,5);

		employee_getIndexFromId(&indexRelatedToThisId, pArrayListEmployee,id);//RECORRO LA LINKEDLIST, LE ASIGNO UN "INDICE" POR CADA ITERACIÓN Y AL ENCONTRAR EL ID
																			//RETORNA EL VALOR DE ESA POSICIÓN PARA USARLO EN REMOVE EMPLOYEE.
		employee=ll_get(pArrayListEmployee,indexRelatedToThisId);			//YO QUE DECÍA QUE NUNCA IBA A ENTENDER ESTO, GRACIAS PROFES POR EXPLICARLO!
		if(employee!= NULL)
		{

				printf("\nEmpleado a eliminar : \n\n");
				printf("  ID    NOMBRE     HORAS     SUELDO     \n");
				employee_printOneEmployee(employee);


				optionConfirm=removeMenu();
					if(optionConfirm==1)
					{
						ll_remove(pArrayListEmployee,indexRelatedToThisId);
						printf("\n* Empleado eliminado con exito *");
						ret=0;
					}
					else
					{
						printf("* No se realizaron cambios *");
					}
		}
	}
	return ret;
}

/** \brief Listar empleados
 *
* \param pArrayListEmployee LinkedList* lista que se está manejando
 * \return int retorna -1 en caso de error , 0 si s pudo listar correctamente.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;

	int len=ll_len(pArrayListEmployee);
	Employee* employee=employee_new();
	int i;
		if(pArrayListEmployee!=NULL)
		{
				printf("\n--------------------------------------------------");
				printf("\n------------ LISTA DE EMPLEADOS ------------------\n\n");
				printf("  ID    NOMBRE     HORAS     SUELDO     \n");
				printf("\n--------------------------------------------------\n");

				for(i=0;i<len;i++)
				{
					employee=ll_get(pArrayListEmployee,i);
					if(employee!=NULL)
					{
						employee_printOneEmployee(employee);

					}
				}
				printf("\n------------------------------------------------------\n");
				printf("------------------------------------------------------\n");
				printf("\n\n");
				retorno=1;

		}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* lista que se está manejando
 * \return int retorna -1 en caso de error , 0 si fue posible ordenar los empleados corectamente.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int option;
	if(pArrayListEmployee != NULL)
	{

		do{
		    	option=employee_sortMenu();

		        switch(option)
		        {
		            case 1://ID MAYOR A MENOR
		            	ll_sort(pArrayListEmployee,employee_sortById,1);
		            	printf("\n* Se Ordenaron correctamente los IDs de Mayor a Menor. *");
		            	retorno =0;
		            	break;
		            case 2://ID MENOR A MAYOR
		            	ll_sort(pArrayListEmployee,employee_sortById,0);
		            	printf("\n* Se Ordenaron correctamente los IDs de Menor a Mayor. *");
		            	retorno =0;
		            	break;
		            case 3://HS MAYOR A MENOR
		            	ll_sort(pArrayListEmployee,employee_sortByHs,1);
		            	printf("\n* Se Ordenaron correctamente los empleados por Horas Trabajadas de Mayor a Menor *");
		            	retorno =0;
		                break;
		            case 4://HS MENOR A MAYOR
		            	ll_sort(pArrayListEmployee,employee_sortByHs,0);
		            	printf("\n* Se Ordenaron correctamente los empleados por Horas Trabajadas de Menor a Mayor *");
		            	retorno =0;
		                break;
		            case 5://SUELDO MAYOR A MENOR
		            	ll_sort(pArrayListEmployee,employee_sortBySalary,1);
		            	printf("\n* Se Ordenaron correctamente los empleados por Salrio de Mayor a Menor*");
		            	retorno =0;
		               	break;
		            case 6://SUELDO MENOR A MAYOR
		            	ll_sort(pArrayListEmployee,employee_sortBySalary,0);
		            	printf("\n* Se Ordenaron correctamente los empleados por salario de Menor a Mayor. *");
		            	retorno =0;
		                break;
		        }

		    }while(option != 9);

	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList* lista que se está manejando.
 * \param path dirección del archivo
 * \return int retorna -1 en caso de error , 0 si fue posible guardar los cambios en txt.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* pArch=fopen(path,"w");       //ABRO EL ARCHIVO, CON W LO BORRO Y ESCRIBO LO CARGADO EN MEMORIA
	Employee* employee=employee_new();//VARIBLE ESTRUCTUA AUXILIAR INICIALIZADA QUE SE PISA CONSTANTEMENTE PARA VOLCAR DATOS A ARCHIVO DE A UNO
	int len=ll_len(pArrayListEmployee);
	char name[30];
	int id;
	int hs;
	int salary;
	int i;

	if(pArrayListEmployee != NULL)
	{
		fprintf(pArch,"ID,nombre,Horas Trabajadas,Sueldo\n");//PRIMER FILA ESCRIBO TÍTULO, SALTO A LA SIGUIENTE

		for(i=0;i<len;i++)//OBTENGO LOS DATOS CARGADOS EN MEMORIA DINÁMICA EN ESA "POSICIÓN"
		{
			 employee=ll_get(pArrayListEmployee,i);
			 employee_getId(employee,&id);
			 employee_getNombre(employee,name);
			 employee_getHorasTrabajadas(employee,&hs);
			 employee_getSueldo(employee,&salary);


			 fprintf(pArch,"%d,%s,%d,%d \n",id,name,hs,salary);//ESCRIBO UN RENGLÓN EN ARCHIVO CON LO OBTENIDO

		}
		printf("\n\n * Los datos se guardaron con éxito en el archivo data.csv (txt) * \n");
		ret=0;
	}
	fclose(pArch);


    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo Binario).
 *
 * \param pArrayListEmployee LinkedList* lista que se está manejando.
 * \param path dirección del archivo
 * \return int retorna -1 en caso de error , 0 si fue posible guardar los cambios en Binario.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* pArch=fopen(path,"wb");       //ABRO EL ARCHIVO, CON W LO BORRO Y ESCRIBO LO CARGADO EN MEMORIA
	Employee* employee;
	int len=ll_len(pArrayListEmployee);
	int i;

	if(pArrayListEmployee != NULL && pArch !=NULL )
	{

		for(i=0;i<len;i++)//OBTENGO LOS DATOS CARGADOS EN MEMORIA DINÁMICA EN ESA "POSICIÓN"
		{
			 employee=ll_get(pArrayListEmployee,i);

			fwrite(employee,sizeof(Employee),1,pArch);//ESCRIBO UN RENGLÓN EN ARCHIVO CON LO OBTENIDO

		}
		printf("\n\n * Los datos se guardaron con éxito en el archivo data.csv (Binario) * \n");
		ret=0;
	}
		fclose(pArch);


	    return ret;

}

//-------------------------------------------------------------------------------------------------------------------
int principalMenu()
{
	int opcion;
	printf("\n\n-------------------------------------------------------------------------------------");
	printf("\n---------------------------- MENU PRINCIPAL -----------------------------------------\n");
	printf("\n  1-  Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
	printf("\n  2-  Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
	printf("\n  3-  Alta de empleado");
	printf("\n  4-  Modificar datos de empleado");
	printf("\n  5-  Baja de empleado");
	printf("\n  6-  Listar empleados");
	printf("\n  7-  Ordenar empleados");
	printf("\n  8-  Guardar los datos de los empleados en el archivo data.csv (modo binario)");
	printf("\n  9-  Guardar los datos de los empleados en el archivo data.csv (modo texto)");
	printf("\n  10- Exit");
	printf("\n-------------------------------------------------------------------------------------");
	printf("\n-------------------------------------------------------------------------------------\n");
	utn_getNumber(&opcion,"\n--> ", "\n * INVALID OPTION * \n",1, 11,100);
	return opcion;
}
//----------------------------------------------------------------------------------------------------------------------





