#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include"ArrayEmployees.h"
#include "Sectors.h"
#include "utn.h"
#include "reports.h"



void sortEmployee(eEmployee employees[],int len ,eSector sectors[],int lenSector,int order)
{
	eEmployee auxEmployee;

	int flag=0;
	if(employees!=NULL && len>0 && sectors!= NULL && lenSector>0 && order >=0)
	{
				while(flag==0)
				{
					flag=1;

					for(int i=0;i<len;i++)
					{
							if((strcmp(employees[i].lastName,employees[i+1].lastName)>0) && (employees[i].isEmpty==0 && employees[i+1].isEmpty==0))
							{
	    	 				     	 auxEmployee=employees[i];
	    	 				    	 employees[i]=employees[i+1];
	    	 				    	  employees[i+1]=auxEmployee;
	    	 				    	 flag=0;

	    	 				}
							else if((strcmp(employees[i].lastName,employees[i+1].lastName)==0)&& (employees[i].isEmpty==0 && employees[i+1].isEmpty==0))
	    	 			 	 {
	    	 				 	 if(employees[i].sector>employees[i+1].sector)
	    	 				 	 	 {
	    	 				 	 	 	 auxEmployee=employees[i];
	    	 				 	 	 	 employees[i]=employees[i+1];
	    	 				 	 	 	 employees[i+1]=auxEmployee;
	    	 				 	 	 	 flag=0;
	    	 				 	 	 }

	    	 			 	 }
	    	 		 }

	     	 }
				printf("\n          * Employees sorted by lastName and Sector * ");
	}

}

//--------------------------------------------------------------------------------------------------------------------------
void calculateAvarageSalary(eEmployee employees[],eSector sectors[],int len,int lenSector)
{
	int i;
	int acc=0;
	float sum=0;
	float avarage;
	if(employees!=NULL && len>0 && sectors!= NULL && lenSector>0 )
		{
			for(i=0;i<len;i++)
			{
				if(employees[i].isEmpty==0)
				{
				sum+=employees[i].salary;
				acc++;
				}
			}

			avarage=(float)sum/acc;

			printf("\n\n-------------------------------------------------------------------");
			printf("\n-----------------------    TOTAL WAGES   --------------------------\n");
			printf("                            $%.2f  ",sum);
			printf("\n-----------------------                  --------------------------");
			printf("\n-------------------------------------------------------------------");
			printf("\n----------------------   AVARAGE SALARY  --------------------------\n");
			printf("                            $%.2f   ",avarage);
			printf("\n----------------------                   --------------------------");
			printf("\n-------------------------------------------------------------------");
			printf("\n----------------  EMPLOYEES ABOVE AVARAGE WAGE  -------------------");
			printf("\n-------------------------------------------------------------------\n");
			printf(" ID   LAST NAME    NAME     SALARY       SECTOR        STATUS \n");
			printf("-------------------------------------------------------------------\n");
			for(i=0;i<len;i++)
			{
				if(employees[i].salary>avarage && employees[i].isEmpty==0)
				{

					printEmployee(employees[i],sectors,len,lenSector);

				}
			}
			printf("-------------------------------------------------------------------\n");
			printf("-------------------------------------------------------------------\n");
		}
}



//--------------------------------------------------------------------------------------------------------------------------

int searchEmployeeById(int id, eEmployee employees[],int len)
{
	int index=-1;
	if(employees!=NULL && len>0 && id>0)
		{
	for(int i=0;i<len;i++)
	{
		if(employees[i].isEmpty==0 && employees[i].id==id)
		{
			index=i;
			break;
		}
	}
		}
	return index;
}

//--------------------------------------------------------------------------------------------------------------------------

void reportsMenu(eEmployee employees[],eSector sectors[],int len,int lenSectors)
{
	int option;

	if(pointOutIfThereIsSomethingLoaded(employees,len)==0)
				{
					printf("\n * There is no employees loaded yet. Please load payroll information to operate *");
				}
			else
			{
				do{

				printf("\n\n");
				printf("----------------------------------------\n");
				printf("--------------- REPORTS ----------------\n\n");
				printf(" 1- List sorted by LastName and sector \n");
				printf("\n 2- Total and average salary list \n "
						"   Those who exceed the average salary\n");
				printf("\n 3- Back to menu \n\n");
				printf("-----------------------------------------\n");
				printf("-----------------------------------------\n");
				utn_getNumber(&option,"\n-->   ", "\n * INVALID OPTION * \n",1, 3,100);

					switch(option)
						{
						case 1:
							sortEmployee(employees,len,sectors,lenSectors,1);
							printEmployees(employees, sectors,len, lenSectors);
							break;
						case 2:
							calculateAvarageSalary(employees, sectors,len, lenSectors);
							break;
						}
				 }while(option!=3);


			}


}

//--------------------------------------------------------------------------------------------------------------------------
int menu()
{
	int opcion;
	printf("\n\n----------------------------");
	printf("\n----- PRINCIPAL MENU -------");
	printf("\n  1-  Add employee");
	printf("\n  2-  Modify data");
	printf("\n  3-  Remove Employee");
	printf("\n  4-  Reports");
	printf("\n  5-  Exit");
	printf("\n----------------------------");
	printf("\n----------------------------\n");
	utn_getNumber(&opcion,"\n--> ", "\n * INVALID OPTION * \n",1, 5,100);
	return opcion;
}

