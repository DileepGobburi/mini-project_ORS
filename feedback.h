#include<stdio.h>

#define size 80
#define max_size 256

typedef struct employee_f
{
char emp_id[size];
char emp_name[size];
char emp_email[size];
char reporting_mgr[size];
char feedback[max_size];
}Employee_training_feedback;

void feedback_module();
void feedback(int option);
