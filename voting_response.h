
/*********************** DESCRIPTION *******************************
Name of the module : Voting Response
Date of creation : 27/5/2022
Author of Module : Sindhushree J M
Description of module : The purpose of this module is to collect voting response from the users for the voting request conducted, it is recorded in the excel sheet
Different functions supported in this module : voting_response_module()
                                               voting_response()
Global variables accessed/modified by module : Form_option, Buffer, Buf_index
Revision/Modification History : V1.0

********************************************************************/


/**************************HEADER FILES*****************************/
#include"header.h"
#include<stdio.h>
#include<string.h>
#include<pthread.h>


/***********************MACROS****************************************/
#define FORM_LEN 30
#define BUF_R 20
#define BUF_C 20


/***************GLOBAL VARIABLES DECLARATION************************/
int Form_option;                   


/***************FUNCTION PROTOTYPES*********************************/

void voting_response_module();                           
void voting_response();

