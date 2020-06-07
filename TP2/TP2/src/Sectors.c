/*
 * Sectors.c
 *
 *  Created on: 4 may. 2020
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include"ArrayEmployees.h"
#include "Sectors.h"
#include "utn.h"
#include "reports.h"


void showLoans(eLoan sectors[],int lenSector)
{

		printf("\n\n\n**** SECTORS ****\n");
		printf("\n ID    DESCRIPTION\n");
		for(int i=0;i<lenSector;i++)
		{
			showLoan(sectors[i]);
		}
		printf("\n");
		printf(" *****************\n");

}

//--------------------------------------------------------------------------------------------------------------------------

void showLoan(eLoan sectors)
{
	printf("\n %d    %s   \n",sectors.sectorId,sectors.description);

}

//--------------------------------------------------------------------------------------------------------------------------

int loadLoansDescription(int sectorId,eLoan sectors[],int lenSector,char description[])
{
	int success=0;
	if(sectors!= NULL && lenSector>0 && sectorId>0&&description!=NULL)
	{

	for(int i=0;i<lenSector;i++)
	{
		if(sectors[i].sectorId==sectorId)
		{
			strcpy(description,sectors[i].description);
			success=1;
		}
	}
	}
	return success;
}







