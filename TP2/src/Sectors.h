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
}eSector;

#endif /* SECTORS_H_ */


void showSectors(eSector sectors[],int lenSector);
void showSector(eSector sectors);
int loadSectorDescription(int sectorId,eSector sectors[],int lenSector,char description[]);
