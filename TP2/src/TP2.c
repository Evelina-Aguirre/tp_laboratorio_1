/*
 ============================================================================
 Name        : TP2.c
 Author      : Evelina Aguirre
 Version     : v1.0
 Copyright   : Your copyright notice
 Description : Payroll management application
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include "ArrayEmployees.h"
#include "Sectors.h"
#include "Reports.h"
#include "utn.h"

#define QTY_EMP 1000
#define QTY_SEC 3


int main(void) {

	setbuf(stdout,NULL);

		eEmployee arrayEmployee[QTY_EMP];
		eSector arraySectors[]={{1000,"RRHH"},{1001,"SYS"},{1002,"MNGT"}};;
		int id=100;
		int opcionMenu;


		initEmployees(arrayEmployee,QTY_EMP);

		//enable the function below to hardcode
		//harcodeEmployees(arrayEmployee,QTY_EMP,9);


	do{

		opcionMenu=menu();
		switch(opcionMenu)
		{
		case 1://ADD EMPLOYEE
			if(addEmployee(arrayEmployee,QTY_EMP,id,arraySectors,QTY_SEC))
				{
				id++;//Auto-increase ID
				}
			break;

		case 2://MODIFY EMPLOYEE

			modifyEmployee(arrayEmployee,QTY_EMP,arraySectors,QTY_SEC);
			break;

		case 3://REMOVE EMPLOYEE
			removeEmployee(arrayEmployee,QTY_EMP,arraySectors,QTY_SEC);
			 	 break;

		case 4://REPORTS
			reportsMenu(arrayEmployee,arraySectors,QTY_EMP,QTY_SEC);

					break;
			}

	}while(opcionMenu!=5);

	return EXIT_SUCCESS;
}








