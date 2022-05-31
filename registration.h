#include"header.h"
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
typedef struct employee_data
{
    char fields[30];
    struct employee_data *link;
}Employee_training_data;

int Forms_count; //Variable to store count of training registration forms created
char Forms[10][30]; //2d-array to store names of trainings
Employee_training_data *First_field[30]; //An array of pointer to store the address of first field in each training registration form

void create_training_registration_form();
void delete_training_registration_form();
void send_training_registration_form();


