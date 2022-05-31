
#include"registration.h"

void create_training_registration_form()
{
	char form[30]; //Array of character to store name of one form
	char fields[30]; //Array of character to store name of each fields
	int flag = 0;
	FILE *file_pointer = NULL; 
	printf("Enter the training name: ");
	scanf("%s", form);
	//Loop to check whether the training name is already present or not
	for(int i = 0;i < Forms_count; i++)
	{
		if(strcasecmp(Forms[i], form) == 0)
		{
			flag = 1;
		}
	}
	strcpy(Forms[Forms_count], form); //Copy the content of form to Forms[Forms_count])
        if(flag == 0)
	{
		strcat(form, "_training.xlsx"); 
		file_pointer = fopen(form, "w");// To open the file in write mode 
		if(file_pointer == NULL)
		{
			printf("File open not successfull\n");
		}
		int field_count; //Integer variable
		printf("Enter the number of fields required: ");
		scanf("%d", &field_count);
		Employee_training_data *lastnode = NULL;
		First_field[Forms_count] = NULL;
		for(int i = 0;i < field_count;i++)
		{
			Employee_training_data *newnode = (Employee_training_data *)malloc(sizeof(Employee_training_data));
	                printf("Enter field name: ");
			scanf("%s", newnode->fields);
			newnode->link = NULL;
			fprintf(file_pointer, "%s\t", newnode->fields);//To store content of newnode->fields to file
			if(First_field[Forms_count] == NULL)
			{
				First_field[Forms_count] = newnode;
			}
			else
			{
				lastnode->link = newnode;
				//printf("%p\n", lastnode->link);
			}
			lastnode = newnode;
		}
		fprintf(file_pointer, "\n");

	}	
		/* if(strcasecmp(form, "Basic_level_training.xlsx") == 0)
		{
			fprintf(file_pointer, "%s\t%s\t%s\t%s\t%s\n", "Emp_id", "Emp_name", "DOJ", "Email_id", "Source");
		}
		else if(strcasecmp(form, "Python.xls") == 0)
		{
			fprintf(file_pointer, "%s\t%s\t%s\t%s\t%s\n", "Emp_id", "Emp_name", "Email_id", "Reporting manager", "Expectation from training");
		}
		else if(strcasecmp(form, "EmailEtiquette.xlsx") == 0)
		{
			fprintf(file_pointer, "%s\t%s\t%s\t%s\t%s\n", "Emp_id", "Emp_name", "Email_id", "DOJ", "Reporting manager");
		}
		else if(strcasecmp(form, "LDD_training.xlsx") == 0)
		{
			fprintf(file_pointer, "%s\t%s\t%s\t%s\t%s\t%s\n", "Emp_id", "Emp_name", "Email_id", "Total experience in years", "Reporting manager", "Current project");
		}
		else
		{
			fprintf(file_pointer, "%s\t%s\t%s\t%s\t%s\n", "Emp_id", "Emp_name", "Email_id", "Reporting manager", "Expectation from trainin g");
		}
	}
	else
	{
		printf("File already created\n");
	}*/

		fclose(file_pointer);
		Forms_count++;
	
}

