#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include"ArrayEmployees.h"
#include "Sectors.h"
#include "utn.h"
#include "reports.h"



void harcodeClients(eClient employees[],int len, int howMany)
{


	eClient auxList[]=
	{
			{101,"Maria","Rodríguez",1256,1002,0},
			{102,"Marcos","Castro",1600,1001,0},
			{103,"Marcela","Vazquez",1277,1002,0},
			{104,"Marcia","Parodi",1800,1000,0},
			{105,"Maximo","Escalar",2250,1002,0},
			{106,"Pedro","Benitez",1330,1000,0},
			{107,"Lucas","Martinez",1479,1001,0},
			{108,"Lucia","Gimenez",2100,1002,0},
			{109,"Oscar","Lugares",1600,1001,0},
			{110,"Martin","Gutierrez",1400,1001,0}

	};

	if(howMany<len && howMany<11)
	{
		for(int i=0;i<=howMany;i++)
		{
			employees[i]=auxList[i];

		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------

int initClients(eClient employees[],int len)
{
	int i;
	int ret=-1;

	if(employees!= NULL && len>0)
	{
		for(i =0; i<=len;i++)
		{
			employees[i].isEmpty=1;//INITIALIZE ALL IN 1

		}
	ret=0;
	}
	return ret;

}
//--------------------------------------------------------------------------------------------------------------------------

int addClient(eClient employees[],int len, int id,eLoan sectors[],int lenSector)
{
	int success=-1;
	int index;
	char name[50];
	char lastName[50];
	float salary;
	int sector;

	if(employees!=NULL && len>0 && sectors!= NULL && lenSector>0)
		{
		printf("\n-------- Registration ---------");
		index=searchFreeSpace(employees,len);


		if(index==-1)//IF THERE ARE NO FREE SPACES
		{

			printf("\n\n-------------------------------\n\n");
			printf(" * THERE ARE NO FREE SPACES * ");
			printf("\n\n-------------------------------\n\n");

		}
		else// AN EMPTY PLACE FOUND REQUESTS DATA
		{
			fflush(stdin);
			utn_getName(name,"\nEnter Name : "," * Error. Not a valid name. *",0,237,30,10);
			fflush(stdin);
			utn_getName(lastName,"Enter Last Name : ","* Error. Not a valid name. *",0,237,30,10);

			utn_getNumeroConDecimales(&salary, "Enter salary : ","* Error. Invalid salary *", 0, 1000000000, 10);

			showLoans(sectors,lenSector);
			utn_getNumber(&sector,"\n\nEnter Sector id : ","\n* INVALID SECTOR ID *",1000,1002,5);


			employees[index]=newClient(id,name,lastName,salary,sector);
			printf("\n\n---------------------------------------");
			printf("\n * New employee successfully added * ");
			printf("\n---------------------------------------\n");
			success=0;

		}
	}

	return success;

}

//--------------------------------------------------------------------------------------------------------------------------

int searchFreeSpace(eClient employees[],int len)
{
	int index=-1;

	for(int i=0;i<len;i++)
	{
		if(employees[i].isEmpty==1)
		{
			index=i;
			break;
		}
	}
	return index;
}

//--------------------------------------------------------------------------------------------------------------------------

eClient newClient(int id,char name[],char lastName[], float salary,int sector)
{
	eClient newEmployee;
	newEmployee.id=id;
	strcpy(newEmployee.name,name);
	strcpy(newEmployee.lastName,lastName);
	newEmployee.salary=salary;
	newEmployee.sector=sector;
	newEmployee.isEmpty=0;

	return newEmployee;
}

//--------------------------------------------------------------------------------------------------------------------------

int removeClientMenu()
{
	int option;

	printf("------ Remove Employee ------\n");
	printf("-----------------------------\n\n");
	printf(" 1- Enter id ");
	printf("\n 2- Back to menu \n\n");
	printf("-----------------------------\n");
	utn_getNumber(&option,"\n-->   ", "\n * INVALID OPTION * \n",1, 2,100);
	return option;
}

//--------------------------------------------------------------------------------------------------------------------------

int removeClient(eClient employees[],int len,eLoan sectors[],int lenSector)
{
		int success=0;
		int employeeId;
		int index;
		int confirm;
		int optionRemMenu;

		if(employees!=NULL && len>0 && sectors!= NULL && lenSector>0)
		 {
			if(pointOutIfThereAreClientsLoaded(employees,len)==0)//CHECK IF THE USER PREVIOUSLY LOADED AN EMPLOYEE
			{
				printf("\n * There is no employees loaded yet. Please load payroll information to operate... *\n\n");
			}
			else
			{

				do{
					printClients(employees, sectors,len,lenSector);//CHECK IF THE USER PREVIOUSLY LOADED AN EMPLOYEE
					optionRemMenu=removeClientMenu();

					if(optionRemMenu==1)
					{
						printf("\n**** Remove Employee ****");
						utn_getNumber(&employeeId,"\n\nEnter id :","* ID NOT FOUND * ",0, 1100,2);
						index= searchClient(employeeId,employees,len);//SERCH EMPLOYEE

						if(index==-1)//IF ID NOT FOUNF
						{
							printf("\n\n* ID NOT FOUND *\n");


						}
						else//IF ID FOUND,SHOWS EMPLOYEE AND  REQUEST CONFIRMATION TO REMOVE
						{

							printf("\n-----------------------------------------------------------------");
							printf("\n------------------------  EMPLOYEES -----------------------------\n");
							printf(" ID   LAST NAME    NAME     SALARY       SECTOR        STATUS \n");
							printf("-----------------------------------------------------------------\n");
							printClient(employees[index],sectors,len,lenSector);
							printf("-----------------------------------------------------------------\n");
							printf("\n 1- CONFIRM");
							printf("\n 2- BACK TO MENU \n\n");
							utn_getNumber(&confirm,"--> ", "\n* NOT A VALID OPTION * \n 1- CONFIRM\n 2- BACK TO REMOVE MENU \n\n",1, 2,100);
							if(confirm==1)
							{
								employees[index].isEmpty=1;
								printf("\n\n** ID REMOVED **\n");
							success=1;
							}
							else
							{
								printf("\n\n ** No changes were made ** \n");
							}




						}//fin opción baja baja
					}
					else
					{
						break;
					}//fin menu
			}while(optionRemMenu!=2);
			}//Fin condición empleados cargados
		 }
		return success;

}

//--------------------------------------------------------------------------------------------------------------------------

int modifyClient(eClient employees[],int len,eLoan sectors[],int lenSector)
{
	int success=-1;
	int index;
	int id;
	int option;
	char lastName[30];
	char name[30];
	int sector;
	float salary;
	int confirm;


	if(employees!=NULL && len>0 && sectors!= NULL && lenSector>0)
		{
		if(pointOutIfThereAreClientsLoaded(employees,len)==0)//CHECK IF THE USER PREVIOUSLY LOADED AN EMPLOYEE
			{
			printf("\n * There is no employees loaded yet. Please load payroll information to operate... *");
			}
		else
		{

			printClients(employees,sectors,len,lenSector);
			utn_getNumber(&id,"Enter id :","Error.",0,1000,10);


			index=searchClient(id,employees,len);
			if(index==-1)//IF ID NOT FOUNF
			{
				printf("\n-----------------------------------------------------------------");
				printf("\n\n* ID NOT FOUND *\n");
				printf("\n-----------------------------------------------------------------");
			}
			else//IF ID FOUND,SHOWS EMPLOYEE AND  REQUEST CONFIRMATION TO REMOVE
			{
				do{

					printf("\n------------------  MODIFY EMPLOYEE ----------------------------\n\n");
					printf(" ID   LAST NAME    NAME     SALARY       SECTOR        STATUS \n");

					printClient(employees[index],sectors,len,lenSector);


					printf("\n-----------------------------------------------------------------");
					printf("\n-----------------------------------------------------------------\n");
					utn_getNumber(&option,"\n1-Modify Name\n2-Modify Last Name\n3-Modify Sector\n4-Modify Salary\n5-Exit\n\n"
							"-----------------------------------------------------------------\n"
							"-----------------------------------------------------------------"
							"\n\n--> ","Invalid option",1,5,10);
					switch(option)//REQUEST INFORMATION
					{
					case 1:
						printf("Enter Name:");
						gets(name);
						confirm=confirmModificationMenu();
						if(confirm==1)
						{
							strcpy(employees[index].name,name);
							printf("\n* EMPLOYEE DATA UPDATED *\n\n");
							success=1;
						}
						else
						{
							printf("\n\n ** No changes were made ** \n");
						}

						success=0;

						break;

					case 2:

						printf("Enter Last Name : ");
						gets(lastName);
						confirm=confirmModificationMenu();

						if(confirm==1)
						{
							strcpy(employees[index].lastName,lastName);
							printf("\n* EMPLOYEE DATA UPDATED *\n\n");
							success=0;
						}
						else
						{
							printf("\n\n ** No changes were made ** \n");
						}
						success=0;
						break;

					case 3:

						showLoans(sectors,lenSector);
						utn_getNumber(&sector,"\n\nEnter Sector id : ","\n* INVALID OPTION *",1000,1002,10);
						confirm=confirmModificationMenu();

						if(confirm==1)
						{
							employees[index].sector=sector;
							printf("\n* EMPLOYEE DATA UPDATED *\n\n");
							success=1;
						}
						else
						{
							printf("\n\n ** No changes were made ** \n");
						}
						success=0;

						break;

					case 4:
						utn_getNumeroConDecimales(&salary, "Enter salary","Error.\n\n Enter Salary :", 0, 1000000000, 10);
						confirm=confirmModificationMenu();

						if(confirm==1)
						{
							employees[index].salary=salary;
							printf("\n* EMPLOYEE DATA UPDATED *\n\n");
							success=1;
						}
						else
						{
							printf("\n\n ** No changes were made ** \n");
						}
						success=0;
						break;

					}
				}while(option!=5);



			}
		}
	}
	return success;
}

//--------------------------------------------------------------------------------------------------------------------------

void printClients(eClient employees[], eLoan sectors[],int len,int lenSector)
{
	int i;
	if(employees!=NULL && len>0 && sectors!=NULL && lenSector>0)
	{
		printf("\n-----------------------------------------------------------------");
		printf("\n------------------------  EMPLOYEES -----------------------------\n\n");
		printf(" ID   LAST NAME    NAME     SALARY       SECTOR        STATUS \n");
		printf("-----------------------------------------------------------------\n");

		for(i=0;i<len;i++)
		{
			if(employees[i].isEmpty==0)
			{
			printClient(employees[i],sectors,len,lenSector);

			}

		}


		printf("-----------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------\n");
		printf("\n\n");
	}
}

//--------------------------------------------------------------------------------------------------------------------------

void printClient(eClient employees,eLoan sectors[],int len,int lenSector)
{
	char descSector[20];
	char status[10];


		if(employees.isEmpty==0)
		{
			strcpy(status,"ACTIVE");
		}
		else
		{
			strcpy(status,"INACTIVE");
		}
		if(loadLoansDescription(employees.sector,sectors,lenSector,descSector))
		{
			printf(" %d   %.8s    %.8s    $%.2f    %d-%s     %s\n",
				employees.id,
				employees.lastName,
				employees.name,
				employees.salary,
				employees.sector,
				descSector,
				status);
		}


}

//--------------------------------------------------------------------------------------------------------------------------

int searchClient(int id, eClient employees[],int len)
{
	int index=-1;

	for(int i=0;i<len;i++)
	{
		if(employees[i].isEmpty==0 && employees[i].id==id)
		{
			index=i;
			break;
		}
	}
	return index;
}


//--------------------------------------------------------------------------------------------------------------------------

int confirmModificationMenu()
{
	int confirm;
	printf("\n 1- CONFIRM");
	printf("\n 2- BACK TO MENU \n\n");

	utn_getNumber(&confirm,"--> ", "\n* NOT A VALID OPTION * \n 1- CONFIRM\n 2- BACK TO REMOVE MENU \n\n",1, 2,10);

	return confirm;
}

//--------------------------------------------------------------------------------------------------------------------------


int pointOutIfThereAreClientsLoaded(eClient employees[],int len)
{
	int success=0;
	if(employees!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(employees[i].isEmpty==0)
			{

				success=1;
				break;
			}
			else
			{
				success=0;
			}
		}
	}
		return success;
}

//--------------------------------------------------------------------------------------------------------------------------



