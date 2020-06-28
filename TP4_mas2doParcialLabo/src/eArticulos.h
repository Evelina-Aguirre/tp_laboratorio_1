/*
 * eArticulos.h
 *
 *  Created on: 25 jun. 2020
 *      Author: Usuario
 */

#ifndef EARTICULOS_H_
#define EARTICULOS_H_

typedef struct
{
	int id;
    char articulo[128];
    char medida[50];
    int precio;
    int rubroId;
    float descuentoAplicado;
}Employee;



Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* articuloStr,char* medida,char* precio,char* rubroId);

void eArticulos_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int eArticulos_setArticulo(Employee* this,char* nombre);
int eArticulos_getArticulo(Employee* this,char* nombre);

int eArticulos_setMedida(Employee* this,char* medida);
int eArticulos_getMedida(Employee* this,char* medida);

int eArticulos_setPrecio(Employee* this,int precio);
int eArticulos_getPrecio(Employee* this,int * precio);

int eArticulos_setRubroId(Employee* this,int rubroId);
int eArticulos_getRubroId(Employee* this,int* rubroId);

int eArticulos_setDescuentoAplicado(Employee* this,float descuentoAplicado);
int eArticulos_getDescuentoAplicado(Employee* this,float* descuentoAplicado);


#endif /* EARTICULOS_H_ */

//--------------------------------------------------------------------------------------------------------------------
int eArticulos_searchLastId(LinkedList* pArrayListEmployee);
int eArticulos_getIndexFromId(int* index, LinkedList* pArrayListEmployee,int id);
int eArticulos_printOneArticle(Employee* employee);

//--------------------------------------------------------------------------------------------------------------------


int eArticulos_sortByArticulo(void * thisA,void *thisB);



//---------------------------------------------------------------------------------------------------------------------
//MENUES
int eArticulos_sortMenu();
int removeMenu();
int modifyMenu();
int menuSeleccionarRubro();

//---------------------------------------------------------------------------------------------------------------------
void switchRubro(int rubro,char* rubroString);
void ventas_calculaDescuento(void* articulo);
int contadorPrecioMayorA100(void* articulo);
int contadorArticulosRubro1(void* articulo);

