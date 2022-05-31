//#ifndef HEADER_H
//#define HEADER_H

/*************************************************************************************/
// i.	Name of the module=                           Voting request module:header.h
//ii.	Date of creation=                             27/5/2022
//iii.	Author of module=                             Dipa Mantre
//iv.	Description of module=                        Creating voting request forms
//v.	Different functions supported in the module=  1.voting_request
//                                                    2.create_voting_req_form
//                                                    3.delete_voting_req_form
//vi.	Revision/Modification History=                V1.0 
/************************************************************************************/        
#include"header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***************Structure declaration************************/

typedef struct Voting
{
	char fields[30];       
	struct Voting *link;
}Vote;

/***************Global variable declarations***************/

int Count;	                                     //count of forms created
char Existing_forms[10][30];	                     //for storing already created forms
char Forms[20][30];
Vote *Root[30];

/***************Function declartions**********************/

void create_voting_req_form();                  //create voting requested form
void delete_voting_req_form();                  //create voting requested form
void voting_request();
//#endif 	                              //HEADER_H

