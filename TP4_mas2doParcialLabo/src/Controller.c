#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eArticulos.h"
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
	pArch= fopen(path,"r");//LEVANTO SÓLO LECTURA, CARGO MEMORIA DINÁMICA Y LO CIERRO. VUELVO A ABRIRLO PARA GUARDAR LOS CAMNIOS AL SALVAR

	if(pArch != NULL && pArrayListEmployee != NULL)
	{
		 parser_EmployeeFromText(pArch,pArrayListEmployee);
		 ret = 0;
		 printf("\n * Archivo cargado con éxito* \n\n");
		 fclose(pArch);
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
	char articulos[50];
	char medida[30];
	int precio;
	char auxPrecio[10];
	int rubroId;
	char auxRubroId[30];
	Employee* articulo;


	if(pArrayListEmployee != NULL)
	{
			fflush(stdin);
			utn_getName(articulos,"\nIngrese Artículo : "," * Error. El nombre no es válido. *",0,237,30,10);
			printf("Ingrese Medida: ");
			fflush(stdin);
			scanf("%s",medida);
			utn_getNumber(&precio,"\nIngrese Precio: ", "\n * Error. * \n",1, 5000,10);
			rubroId=menuSeleccionarRubro();
			lastId=eArticulos_searchLastId(pArrayListEmployee);
			lastId++;                                         //BUSCO ULTIMO ID Y LO INCREMENTO EN CASO DE AGREGAR UN ELEMENTO
			itoa(lastId,id,10);
			itoa(rubroId,auxRubroId,10);
			itoa(precio,auxPrecio,10);

			articulo=employee_newParametros(id,articulos,medida,auxPrecio,auxRubroId);
			ll_add(pArrayListEmployee, articulo);
			printf("\n\n---------------------------------------");
			printf("\n   * Se agregó un nuevo Articulo * ");
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
	Employee* eArticulo;
	int indexRelatedToThisId;
	int option;
	char medida[50];
	char articulo[50];
	int rubroId;
	int precio;


		utn_getNumber(&id,"\nIngrese ID del artículo a modificar : ","\n* NO SE ENCONTRÓ ID *",1,1000000,5);

		eArticulos_getIndexFromId(&indexRelatedToThisId, pArrayListEmployee,id);//RETORNA POR PARÁMETRO ÍNDICE RELACIONADO A ESE ID POR LA CANTIDAD
																			//DE ITERACIONES QUE TIENE QUE REALIZAR HASTA LLEGAR A ÉL
		eArticulo=ll_get(pArrayListEmployee,indexRelatedToThisId);
		if(eArticulo!= NULL)
		{

				printf("\nArtículo que se modificará: \n\n");
				printf("  ID   ARTICULO    MEDIDA     PRECIO   RUBRO  \n");
				eArticulos_printOneArticle(eArticulo);

				do{
					    	option=modifyMenu();

					        switch(option)
					        {
					            case 1:
					            	printf("\nIngrese nombre del Artículo :");
					            	scanf("%s",articulo);
					            	eArticulos_setArticulo(eArticulo,articulo);

					            	printf("\n * Artículo modificado correctamente *\n");
					            	ret =0;
					            	break;
					            case 2:
					            	printf("\nIngrese medida :");
					            	scanf("%s",medida);
					            	eArticulos_setMedida(eArticulo,medida);
					            	printf("\n * Medida modificada correctamente *\n");
					            	ret =0;
					            	break;
					            case 3:
					            	utn_getNumber(&precio,"\nIngrese precio : $","\n* Error. valor de sueldo inválido *",0,10000000,10);
					            	eArticulos_setPrecio(eArticulo,precio);
					            	printf("\n * Precio modificado correctamente *\n");

					            	ret =0;
					                break;
					            case 4:
					            	rubroId=menuSeleccionarRubro();
					            	eArticulos_setRubroId(eArticulo,rubroId);
					            	printf("\n * Rubro modificado correctamente *\n");

					            	ret =0;
					            	break;

					        }

					    }while(option != 5);
		}
    return ret;
}

//----------------------------------------------------------------------------------------------------------------------

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

	//int len=ll_len(pArrayListEmployee);

	Employee* employee=employee_new();

	if(pArrayListEmployee != NULL)
	{
		utn_getNumber(&id,"\nIngrese ID del empleado a dar de baja : ","\n* NO SE ENCONTRÓ ID *",1,10000000,5);

		if(!eArticulos_getIndexFromId(&indexRelatedToThisId, pArrayListEmployee,id))//RECORRO LA LINKEDLIST, LE ASIGNO UN "INDICE" POR CADA ITERACIÓN Y AL ENCONTRAR EL ID
		{																//RETORNA EL VALOR DE ESA POSICIÓN PARA USARLO EN REMOVE EMPLOYEE.
			employee=ll_get(pArrayListEmployee,indexRelatedToThisId);
			if(employee!= NULL)
				{
				printf("\nEmpleado a eliminar : \n\n");
				printf("  ID    NOMBRE     HORAS     SUELDO     \n");
				eArticulos_printOneArticle(employee);


				optionConfirm=removeMenu();
				if(optionConfirm==1)//CONFIRMA LA BAJA
				{
					if(ll_remove(pArrayListEmployee,indexRelatedToThisId)==0)
					{
					printf("\n* Empleado eliminado con exito *");
					ret=0;
					}
					else
					{
						printf("* Error. El empleado no puedo ser eliminado * ");
					}
				}
				else
				{
					printf("* No se realizaron cambios * ");
				}
			}
		}
		else
		{
			printf("El índice no fue encontrado");
		}
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

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
	Employee* employee=NULL;
	int i;
		if(pArrayListEmployee!=NULL)
		{
				printf("\n\n-------------------------------------------------------------------------------");
				printf("\n------------------------ ARTICULOS -------------------------------------------\n\n");
				printf("  ID       ARTÍCULO             MEDIDA  PRECIO    RUBRO            C/DESCUENTO                 \n");
				printf("\n--------------------------------------------------------------------------------\n");

				for(i=0;i<len;i++)
				{
					employee=ll_get(pArrayListEmployee,i);//LL_GET RETONA EL ELEMENTO POR CADA POSICIÓN DEL INDEX
					if(employee!=NULL)
					{
						eArticulos_printOneArticle(employee);
					}
				}
				printf("\n--------------------------------------------------------------------------------\n");
				printf("--------------------------------------------------------------------------------\n");
				printf("\n\n");
				retorno=1;

		}
    return retorno;
}



//----------------------------------------------------------------------------------------------------------------------

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
	FILE* pArch=fopen(path,"w");       //ABRO/CREO EL ARCHIVO, CON W LO BORRO DE EXISTIR Y ESCRIBO LO CARGADO EN MEMORIA
	Employee* employee=NULL;//VARIBLE ESTRUCTUA AUXILIAR INICIALIZADA QUE SE PISA CONSTANTEMENTE PARA VOLCAR DATOS A ARCHIVO DE A UNO
	int len=ll_len(pArrayListEmployee);
	char articulo[30];
	char medida[20];
	int id;
	int precio;
	int rubroId;
	float desc;
	int i;
	int cant;

	if(pArrayListEmployee != NULL)
	{
		fprintf(pArch,"id,articulo,medida,precio,rubroId,descuento\n");//PRIMER FILA ESCRIBO TÍTULO, SALTO A LA SIGUIENTE

		for(i=0;i<len-1;i++)//OBTENGO LOS DATOS CARGADOS EN MEMORIA DINÁMICA EN ESA "POSICIÓN"
		{
			 employee=ll_get(pArrayListEmployee,i);
			 if(employee!=NULL)
			 {
			 employee_getId(employee,&id);
			 eArticulos_getArticulo(employee,articulo);
			 eArticulos_getMedida(employee,medida);
			 eArticulos_getPrecio(employee,&precio);
			 eArticulos_getRubroId(employee,&rubroId);
			 eArticulos_getDescuentoAplicado(employee,&desc);



			cant= fprintf(pArch,"%d,%s,%s,%d,%d,%.2f\n",id,articulo,medida,precio,rubroId,desc);//ESCRIBO UN RENGLÓN EN ARCHIVO CON LO OBTENIDO
			if(cant<6)
			{

				break;
			}
		 }
	}
		printf("\n\n * Los datos se guardaron con éxito en el archivo (txt) * \n");
		ret=0;
		fclose(pArch);
	}

    return ret;
}



//----------------------------------------------------------------------------------------------------------------------
int principalMenu()
{
	int opcion;
	printf("\n\n-------------------------------------------------------------------------------------");
	printf("\n---------------------------- MENU PRINCIPAL -----------------------------------------\n");
	printf("\n  1-  Cargar los datos de los artículos desde el archivo (modo texto).");
	printf("\n  2-  Ordenar Artículos de manera Ascendente  A-Z");
	printf("\n  3-  Imprimir");
	printf("\n  4-  Aplicar descuentos vigentes");
	printf("\n  5-  Informes");
	printf("\n  6-  Guardar los cambios en archivo de salida ('mapeado.csv')");
	printf("\n  7-  Exit");
	printf("\n-------------------------------------------------------------------------------------");
	printf("\n-------------------------------------------------------------------------------------\n");
	utn_getNumber(&opcion,"\n--> ", "\n * INVALID OPTION * \n",1, 7,100);
	return opcion;
}
//----------------------------------------------------------------------------------------------------------------------
int menuInformes()
{
	int opcion;

	printf("\n  1-  Cantidad de Artículos cuyo precio sea mayor a $100");
	printf("\n  2-  Cantidad de Artículos del Rubro 1 – CUIDADO DE ROPA");
	printf("\n  3-  Exit");
	utn_getNumber(&opcion,"\n--> ", "\n * INVALID OPTION * \n",1, 3,100);
	return opcion;
}
//----------------------------------------------------------------------------------------------------------------------

/** \brief Printea menú de informes y en cada caso hace el cálculo.
 *
 * \param pArrayListEmployee LinkedList* lista que se está manejando.
 * \param path dirección del archivo
 * \return int retorna -1 en caso de error , 0 si fue posible guardar los cambios en txt.
 *
 */
void menuInformesSwitch(LinkedList* listaArticulos)
{
	int opcion;
	int mayor100;
	int rubro1;
	if(listaArticulos !=NULL)
	{
		do{
		opcion=menuInformes();
			switch(opcion)
			{
			case 1:
				mayor100=ll_count(listaArticulos,contadorPrecioMayorA100);
				printf("\n * Artículos con precio superior a $100 --> %d   * \n\n",mayor100);
				break;
			case 2:
				rubro1=ll_count(listaArticulos,contadorArticulosRubro1);
				printf("\n * Artículos en Rubro 1  --> %d   * \n\n",rubro1);
				break;
		}
		}while(opcion!=3);
	}

}


//----------------------------------------------------------------------------------------------------------------------








