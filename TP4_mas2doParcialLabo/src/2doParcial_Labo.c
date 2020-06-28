/*
 ============================================================================
 Name        : 2doParcial_Labo.c
 Author      : Evelina Aguirre
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eArticulos.h"
#include "utn.h"


int main(void) {

		setbuf(stdout,NULL);
	    int option;
	    LinkedList* ListaArticulos = ll_newLinkedList();


	    do{
	    	option=principalMenu();

	        switch(option)
	        {
	            case 1:
	                controller_loadFromText("Data.csv",ListaArticulos);
	                break;
	            case 2:
	            	ll_sort(ListaArticulos,eArticulos_sortByArticulo,1);
	            	controller_ListEmployee(ListaArticulos);
	            	break;
	            case 3:
	            	controller_ListEmployee(ListaArticulos);
	                break;
	            case 4:
	            	if(!ll_map(ListaArticulos,ventas_calculaDescuento))
	            	{
	            		printf("\n * Descuentos vigentes aplicados con éxito * \n");
	            	}
	                break;
	            case 5:
	            	menuInformesSwitch(ListaArticulos);
	                 break;
	            case 6:
	            	controller_saveAsText("mapeado.csv" , ListaArticulos);
	            	break;

	        }

	    }while(option != 7);

	    free(ListaArticulos);


	    return 0;
}


