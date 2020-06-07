/*
 * Reports.h
 *
 *  Created on: 16 may. 2020
 *      Author: Usuario
 */
#include"ArrayEmployees.h"



#ifndef REPORTS_H_
#define REPORTS_H_



#endif /* REPORTS_H_ */

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param Employee*  Pointer to array of employees
* \param len int Array length
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
void sortClients(eClient employees[],int len ,eLoan sectors[],int lenSector,int order);
//-----------------------------------------------------------------------------------------------
/** \brief calculate total wages, Avarage Salary, and shoes above average salary
*
* \param  Employees* Pointer to array of employees
* \param len int Array length
* \return void
*
*/

void calculateAvarageSalary(eClient employees[],eLoan sectors[],int len,int lenSector);
//-----------------------------------------------------------------------------------------------
/** \brief find an Employee by Id an returns the index position in array.
*
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id int employee id
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int searchEmployeeById(int id, eClient employees[],int len);

//---------------------------------------------------------------------------------
/** \brief Shown reports menu if there are loaded employees
*
* \param
* \return ( ) void
*/
void reportsMenu(eClient employees[],eLoan sectors[],int len,int lenSectors);
//--------------------------------------------------------------------------------------

/** \brief Shown Principal Menu
*
* \param
* \return ( ) void
*/

int menu();


