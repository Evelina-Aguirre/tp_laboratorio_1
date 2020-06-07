/*
 * Sectors.h
 *
 *  Created on: 4 may. 2020
 *      Author: Usuario
 */

#ifndef SECTORS_H_
#define SECTORS_H_

typedef struct{
	int sectorId;
	char description[20];
}eLoan;

#endif /* SECTORS_H_ */


void showLoans(eLoan sectors[],int lenSector);
void showLoan(eLoan sectors);
int loadLoansDescription(int sectorId,eLoan sectors[],int lenSector,char description[]);
