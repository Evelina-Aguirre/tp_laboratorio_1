#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

#include "LinkedList.h"
#include "Controller.h"
#include "eArticulos.h"
#include "utn.h"

//-----------------------------------------------------------------------------------------------------------------------------------------------------

Employee* employee_new()
{
	Employee* articulos= (Employee*)malloc(sizeof(Employee));

		if(articulos!=NULL)
		{
			//EL ID SE AUTOINCREMENTA EN EL CONTROLLER_ADD..EN CASO DE QUERER AÑADIR ELEMENTOS
			employee_setId(articulos,0);
			eArticulos_setArticulo(articulos,"");
			eArticulos_setMedida(articulos,"");
			eArticulos_setPrecio(articulos,0);
			eArticulos_setRubroId(articulos,0);

		}

	return articulos;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

Employee* employee_newParametros(char* idStr,char* articuloStr,char* medida,char* precio,char* rubroId)
{
	Employee* articulo=employee_new();
	//float descuentoInit=0.0;

			employee_setId(articulo,atoi(idStr));
			eArticulos_setArticulo(articulo,articuloStr);
			eArticulos_setMedida(articulo,medida);
			eArticulos_setPrecio(articulo,atoi(precio));
			eArticulos_setRubroId(articulo,atoi(rubroId));
			eArticulos_setDescuentoAplicado(articulo,0);


		return articulo;
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

int eArticulos_setArticulo(Employee* this,char* articulo)
{
	int ret=-1;
	if(articulo!=NULL && strlen(articulo)>0)
		{
			strcpy(this->articulo,articulo);
			ret=0;
		}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_getArticulo(Employee* this,char* articulo)
{
	int ret = -1;
	if(this!= NULL)
	{
		strcpy(articulo,this->articulo);
		ret=0;
	}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_setMedida(Employee* this,char* medida)
{
	int ret = -1;
		if(this!= NULL && medida>=0)
		{
			strcpy(this ->medida,medida);
			ret=0;
		}
		return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_getMedida(Employee* this,char* medida)
{
	int ret=-1;
	if(this!= NULL)
	{
		strcpy(medida,this->medida);
		ret=0;
	}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_setPrecio(Employee* this,int precio)
{
	int ret=-1;
	if(this!=NULL && precio>=0)
		{
			this->precio=precio;
			ret=0;
		}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_getPrecio(Employee* this,int * precio)
{
	int ret=-1;
		if(this!=NULL)
			{
				*precio=this->precio;
				ret=0;
			}
		return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------



int eArticulos_setRubroId(Employee* this,int rubroId)
{
	int ret=-1;
	if(this!=NULL && rubroId>=0)
		{
			this->rubroId=rubroId;
			ret=0;
		}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_getRubroId(Employee* this,int* rubroId)
{
	int ret=-1;
		if(this!=NULL)
			{
				*rubroId=this->rubroId;
				ret=0;
			}
		return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------



int eArticulos_setDescuentoAplicado(Employee* this,float descuentoAplicado)
{
	int ret=-1;
	if(this!=NULL && descuentoAplicado>=0)
		{
			this->descuentoAplicado=descuentoAplicado;
			ret=0;
		}
	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_getDescuentoAplicado(Employee* this,float* descuentoAplicado)
{
	int ret=-1;
		if(this!=NULL)
			{
				*descuentoAplicado=this->descuentoAplicado;
				ret=0;
			}
		return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------

int eArticulos_searchLastId(LinkedList* pArrayListEmployee)
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
int eArticulos_getIndexFromId(int* index, LinkedList* pArrayListEmployee,int id)
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

int eArticulos_printOneArticle(Employee* articulo)
{
	int ret =-1;
	char rubro[30];

	if(articulo != NULL)
	{
		switchRubro(articulo->rubroId,rubro);//CAMBIO INT POR RUBRO STRING SÓLO PARA IMPRIMIRLO, EL RESTRO DEL PROGRAMA SE MANEJA CON INT
		printf(" %2d	%.16s	%.6s	$%d	%s 	 %.2f \n", articulo->id,articulo->articulo,articulo->medida,articulo->precio,rubro,articulo->descuentoAplicado);
		ret=1;
	}

	return ret;

}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
int eArticulos_sortByArticulo(void * thisA,void *thisB)
{
	int ret ;
	char artA[50];
	char artB[50];

	eArticulos_getArticulo(thisA,artA);
	eArticulos_getArticulo(thisB,artB);
	printf("\nOrdenando Artículoa A-Z, por favor espere...");

	if(strcmp(artA,artB)>0)
	{
		ret=1;//ASCENDENTE
	}
	else if(strcmp(artB,artA)>0)
	{
		ret=-1;//DESCENDENTE

	}
	else
	{
		ret=0;//SON IGUALES
	}
	return ret;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------
int eArticulos_sortMenu()
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

	printf("\n1-  Modificar Artículo");
	printf("\n2-  Modificar Medida");
	printf("\n3-  Modificar Precio");
	printf("\n4-  Modificar Rubro");
	printf("\n5-  Volver al menú anterior");

	utn_getNumber(&opcion,"\n--> ", "\n * LA OPCIÓN ELEGIDA NO ES VÁLIDA * \n",1, 5,100);
	return opcion;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------

void switchRubro(int rubro,char* rubroString)
{
	switch(rubro)
	{
	case 1:
		strcpy(rubroString,"Cuid_Ropa(1)");
		break;
	case 2:
		strcpy(rubroString,"Limp_Desinf(2)");
		break;
	case 3:
		strcpy(rubroString,"Cuid_Pers_Hig(3)");
		break;
	case 4:
		strcpy(rubroString,"Cuid_Automotor(4)");
		break;
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
int menuSeleccionarRubro()
{
	int rubroElegido;
	printf("\n\n1- Cuidado_Ropa");
	printf("\n2- Limpieza_Desinfección");
	printf("\n3- Cuidado_Personal_Higiene");
	printf("\n4- Cuidado_Automotor\n");
	utn_getNumber(&rubroElegido,"\nIngrese Rubro -->","\n * Error. El rubro seleccionado es inexistente *",1,4,10);
	return rubroElegido;
}


//--------------------------------------------------------------------------------------------------------
void ventas_calculaDescuento(void* articulo)
{

	articulo=(Employee*)articulo;
	int rubroId;
	int precio;
	float calculo;


	if(articulo!=NULL)
	{
		eArticulos_getRubroId(articulo,&rubroId);//GETEO TUBRO Y PRECIO PARA HACER CALCULO DEL DESCUENTO
		eArticulos_getPrecio(articulo,&precio);

		switch(rubroId)
		{
		case 1://si es cuidado ropa

			if(precio>=120)
			{
				calculo=precio-(precio*20/100);
				eArticulos_setDescuentoAplicado(articulo,calculo);//SETEO EL VALOR OBTENIDO EN EL CAMPO DESCUENTO

			}
			break;

		case 2://si es limpieza
			if(precio<=200)
			{
				calculo=precio-(precio*10/100);
				eArticulos_setDescuentoAplicado(articulo,calculo);//SETEO EL VALOR OBTENIDO EN EL CAMPO DESCUENTO

			}
			break;

		default:

			break;
		}


	}

}

//-----------------------------------------------------------------------------------------------------------------------------
//INFORMES
int contadorPrecioMayorA100(void* articulo)
{
	articulo=(Employee*)articulo;
	int ret=-1;
	int precio;

	if(articulo != NULL)
	{
		eArticulos_getPrecio(articulo,&precio);
		if(precio>100)
		{
			ret=1;
		}
	}
	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------
int contadorArticulosRubro1(void* articulo)
{
	int ret=-1;
	int rubroId;
	articulo=(Employee*)articulo;

	if(articulo != NULL)
	{
		eArticulos_getRubroId(articulo,&rubroId);

			if(rubroId==1)
			{
				ret=1;
			}
			else
			{
				ret=0;//Se agrega retorno 0 para que no cuente -1, en caso de no pertenecer a Rubro 1;
			}
	}

	return ret;
}


