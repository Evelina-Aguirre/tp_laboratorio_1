/*
 * ArrayEmployees.h
 *
 *  Created on: 3 may. 2020
 *      Author: Usuario
 */
#include "Sectors.h"


#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef eClient;

#endif /* ARRAYEMPLOYEES_H_ */

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

void harcodeClients(eClient employees[],int len, int howMany);
//--------------------------------------------------------------------------------------------------
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param  Employees* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initClients(eClient employees[],int len);

//--------------------------------------------------------------------------------------------------

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param employee* Pointer to array of employees
* \param len int Array length
* \param id int AutoIvrease employee id
* \param sector* Pointer to array of sectors
* \param lenSector Sector array length
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
*free space] - (0) if Ok.
* */

int addClient(eClient employees[],int len, int id,eLoan sectors[],int lenSector);

//--------------------------------------------------------------------------------------------------
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int Employee id to remove
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee]
*
*/

int removeClient(eClient employees[],int len,eLoan sectors[],int lenSector);

//--------------------------------------------------------------------------------------------------

/** \brief Menu for removing employee
*
* \param void
* \return ( ) if the user confirm action, (2) cancel an back to previus menu.
*/
int removeClientMenu();

//--------------------------------------------------------------------------------------------------

/** \brief Modify an existing employee name, Last Name, salary or sector.
* \param employee* Pointer to array of employees
* \param len int Array length
* \param id int AutoIvrease employee id
* \param sector* Pointer to array of sectors
* \param lenSector Sector array length
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
*free space] - (0) if Ok.
* */
int modifyClient(eClient employees[],int len,eLoan sectors[],int lenSector);
//--------------------------------------------------------------------------------------------------

/** \brief find free spaces to load new employees en returns the index position in array.
*
* \param list Employee* Pointer to array of employees
* \param len intArray length
* \param id int employee id
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or free space not found]
*
*/
int searchFreeSpace(eClient employees[],int len);
//--------------------------------------------------------------------------------------------------

/** \brief find an Employee by Id an returns the index position in array.
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int employee id
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int searchClient(int id, eClient employees[],int len);

//--------------------------------------------------------------------------------------------------
/** \brief uploads data of a new employee to the payroll
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int Employee id to remove
* \return int Return new employee data loaded
*
*/

eClient newClient(int id,char name[],char lastName[], float salary,int sector);

//--------------------------------------------------------------------------------------------------
/** \brief print the content of an employee array
*
* \param  Employee  employee to print
* \param len int Aray length
* \return void
*
*/
void printClient(eClient employees,eLoan sectors[],int len,int lenSector);
//--------------------------------------------------------------------------------------------------

/** \brief print the content of employees array
*
* \param Employee* Pointer to Array Employees
* \param len int Array length
* \return void
*/
void printClients(eClient employees[], eLoan sectors[],int len,int lenSector);
//--------------------------------------------------------------------------------------------------

/** \brief Menu for confirm or goback an action
*
* \param void
* \return ( ) if the user confirm action, (2) cancel an back to previus menu.
*/
int confirmModificationMenu();
//--------------------------------------------------------------------------------------------------
/** \brief find out if there are Employees loaded
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return Return employee index position or (0) if [Invalid length or NULL
pointer received or employee not found] (1) if success
*
*/
int pointOutIfThereAreClientsLoaded(eClient employees[],int len);
//--------------------------------------------------------------------------------------------------





