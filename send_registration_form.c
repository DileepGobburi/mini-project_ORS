
#include"registration.h"

pthread_mutex_t lock;

void *thread_handler_1(void *form_option)
{
	pthread_mutex_lock(&lock); //Acquiring lock
	char form[30];
	char buffer[30][30];
	int *forms_option = (int *)form_option;
	strcpy(form, Forms[*forms_option - 1]);
	strcat(form, "_training.xlsx");
	FILE *file_pointer = fopen(form, "a"); //To open file in append mode
	Employee_training_data *temp = First_field[*forms_option - 1]; //To store the address of first field of particular form to temporary pointer
	int index = 0;
	//To take user input for employee details
	while(temp != NULL)
	{
		char field[30];
		strcpy(field, temp->fields);
		char *ptr1 = strstr(field, "Email-id"); 
		char *ptr2 = strchr(field, 'i');

		if(ptr1 != NULL)
		{
			if(strcasecmp(ptr1, "Email-id") == 0)
			{
				char str[30];
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				char *ptr = strchr(str, '@');
				if(strcmp(ptr, "@thundersoft.com") == 0)
				{
					strcpy(buffer[index], str);
					temp = temp->link;
					index++;
					continue;
				}
				else
				{
					printf("Please enter valid Email-id\n");
					continue;
				}
			}
		}
		else if(ptr2 != NULL)
		{
			if(strcasecmp(ptr2, "id") == 0)
			{
				char str[30];
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				if(str[0] == '0')
				{
					strcpy(buffer[index], str);
					index++;
					temp = temp->link;
					continue;
				}
				else
				{
					printf("Please enter valid Empoyee-id\n");
					continue;
				}
			}
		}
		else
		{
			char str[80];
			printf("Enter %s: ", temp->fields);
			scanf("%s", str);
			int i = 0, flag = 0;
			while(str[i] != '\0')
			{
				if(str[i] == ' ' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <=122))
				{
					i++;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				strcpy(buffer[index], str);
				index++;
				temp = temp->link;
				continue;
			}
		}
	}
	//To store the employee details to excel sheet and print the details in console
	printf("User details: \n");
	for(int j = 0;j < index;j++)
	{
		printf("%s\t",buffer[j]);
		fprintf(file_pointer, "%s\t", buffer[j]);
	}
	printf("\n");
	fprintf(file_pointer, "\n");
	fclose(file_pointer);
	pthread_mutex_unlock(&lock);
}

void *thread_handler_2(void *form_option)
{
	pthread_mutex_lock(&lock); //Acquiring lock
	char form[30];
	char buffer[30][30];
	int *forms_option = (int *)form_option;
	strcpy(form, Forms[*forms_option - 1]);
	strcat(form, "_training.xlsx");
	FILE *file_pointer = fopen(form, "a"); //To open file in append mode
	Employee_training_data *temp = First_field[*forms_option - 1]; //To store the address of first field of particular form to temporary pointer
	int index = 0;
	//To take user input for employee details
	while(temp != NULL)
	{
		char field[30];
		strcpy(field, temp->fields);
		char *ptr1 = strstr(field, "Email-id"); 
		char *ptr2 = strchr(field, 'i');

		if(ptr1 != NULL)
		
		{
			if(strcasecmp(ptr1, "Email-id") == 0)
			{
				char str[30];
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				char *ptr = strchr(str, '@');
				if(strcmp(ptr, "@thundersoft.com") == 0)
				{
					strcpy(buffer[index], str);
					temp = temp->link;
					index++;
					continue;
				}
				else
				{
					printf("Please enter valid Email-id\n");
					continue;
				}
			}
		}
		else if(ptr2 != NULL)
		{
			if(strcmp(ptr2, "id") == 0)
			{
				char str[30];
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				if(str[0] == '0')
				{
					strcpy(buffer[index], str);
					index++;
					temp = temp->link;
					continue;
				}
				else
				{
					printf("Please enter valid Empoyee-id\n");
				}
			}
		}
		else
		{
			char str[80];
			printf("Enter %s: ", temp->fields);
			scanf("%s", str);
			int i = 0, flag = 0;
			while(str[i] != '\0')
			{
				if(str[i] == ' ' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <=122))
				{
					i++;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				strcpy(buffer[index], str);
				index++;
				temp = temp->link;
				continue;
			}
		}
	}
	//To store the employee details to excel sheet and print the details in console
	printf("User details: \n");
	for(int j = 0;j < index;j++)
	{
		printf("%s\t",buffer[j]);
		fprintf(file_pointer, "%s\t", buffer[j]);
	}
	printf("\n");
	fprintf(file_pointer, "\n");
	fclose(file_pointer);
	pthread_mutex_unlock(&lock);
}

void *thread_handler_3(void *form_option)
{
	pthread_mutex_lock(&lock); //Acquiring lock
	char form[30];
	char buffer[30][30];
	int *forms_option = (int *)form_option;
	strcpy(form, Forms[*forms_option - 1]);
	strcat(form, "_training.xlsx");
	FILE *file_pointer = fopen(form, "a"); //To open file in append mode
	Employee_training_data *temp = First_field[*forms_option - 1]; //To store the address of first field of particular form to temporary pointer
	int index = 0;
	//To take user input for employee details
	while(temp != NULL)
	{
		char field[30];
		strcpy(field, temp->fields);
		char *ptr1 = strstr(field, "Email-id"); 
		char *ptr2 = strchr(field, 'i');

		if(ptr1 != NULL)
		{
			if(strcasecmp(ptr1, "Email-id") == 0)
			{
				char str[30];
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				char *ptr = strchr(str, '@');
				if(strcmp(ptr, "@thundersoft.com") == 0)
				{
					strcpy(buffer[index], str);
					temp = temp->link;
					index++;
					continue;
				}
				else
				{
					printf("Please enter valid Email-id\n");
					continue;
				}
			}
		}
		else if(ptr2 != NULL)
		{
			if(strcmp(ptr2, "id") == 0)
			{
				char str[30];
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				if(str[0] == '0')
				{
					strcpy(buffer[index], str);
					index++;
					temp = temp->link;
					continue;
				}
				else
				{
					printf("Please enter valid Empoyee-id\n");
				}
			}
		}
		else
		{
			char str[80];
			printf("Enter %s: ", temp->fields);
			scanf("%s", str);
			int i = 0, flag = 0;
			while(str[i] != '\0')
			{
				if(str[i] == ' ' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <=122))
				{
					i++;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				strcpy(buffer[index], str);
				index++;
				temp = temp->link;
				continue;
			}
		}
	}
	//To store the employee details to excel sheet and print the details in console
	printf("User details: \n");
	for(int j = 0;j < index;j++)
	{
		printf("%s\t",buffer[j]);
		fprintf(file_pointer, "%s\t", buffer[j]);
	}
	printf("\n");
	fprintf(file_pointer, "\n");
	fclose(file_pointer);
	pthread_mutex_unlock(&lock);
}

void send_training_registration_form()
{
	int form_option;
	if(Forms_count > 0)
	{
		// To list all the trainings available
		printf("Available trainings are: \n");
		for(int i = 0;i < Forms_count;i++)
		{
			printf("%d. %s\n", i+1, Forms[i]);
		}
		printf("Enter the option: ");
		scanf("%d", &form_option);
		pthread_t thread[3];
		//Create threads and take three different user inputs
		pthread_create(&thread[0], NULL, thread_handler_1, (void *)&form_option);
		pthread_create(&thread[1], NULL, thread_handler_2, (void *)&form_option);
		pthread_create(&thread[2], NULL, thread_handler_3, (void *)&form_option);
		pthread_join(thread[0], NULL); //To wait until particular thread termaination
		pthread_join(thread[1], NULL);
		pthread_join(thread[2], NULL);
		main();
	}
	else
	{
		printf("No trainings available\n");
		main();
	}
}

