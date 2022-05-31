#include"voting_response.h"
#include"voting_request.h"

/******************************Function definition of voting_response()***************************************************************************/

pthread_mutex_t lock;

void *thread_handler1(void *Form_option)
{
	pthread_mutex_lock(&lock);                          //locking the thread1
	char form[FORM_LEN];                               //for storing form name
	int *form_option = (int*)Form_option;              //typecasting from void* to unt*
	strcpy(form, Forms[*form_option - 1]);              //copy forms of particular index name to form character array
	strcat(form, ".xlsx");                           //concatenate the form name with .xlsx
	FILE *file_pointer = fopen(form, "a");          //opens a particular form in append mode
	Vote *temp = Root[*form_option - 1];           //temp pointer of type structure to point to first field
	char buffer[BUF_R][BUF_C];                      //Buffer global variable to store the user details after every thread execution
	int buf_index = 0;                              //for storing index value of Buffer

	while( temp != NULL)                          //Looping untill temp not equal to NULL
	{
		char field[30];                       //character array to store field name
		strcpy(field, temp->fields);          //copy temp field name to field

		char *ptr1 = strstr(field, "Email-id");   //ptr1 to store the return pointer of strstr after searching "Email-id" with field name
		char *ptr2 = strchr(field, 'i');         //ptr2 to store the return pointer of strchr after searching 'i' with field name


		if(ptr1 != NULL)
		{
			if(strcasecmp(ptr1,"Email-id")==0)
			{
				char str[30];                        //character array to scan the input from user
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				char *ptr = strchr(str, '@');         //searching for '@' in user str
				if(strcmp(ptr, "@thundersoft.com") == 0)  //check for comparing the ptr value with "@thundersoft.com" returns 0
				{
					strcpy(buffer[buf_index], str);        //copying that str value to buffer
					buf_index++; 
					temp = temp->link;                     //move to next node

					continue;                             //check for condition again
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
			if(strcasecmp(ptr2, "id") == 0)                               //comparing ptr2 with "id" string in str input
			{
				char str[30];                                    //character array to scan the input from user
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				if(str[0] == '0')                               //checking for employee id starts from 0
				{
					strcpy(buffer[buf_index], str);         //copying that str value to buffer
					buf_index++;
					temp = temp->link;                      //move to next node
					continue;                               //check for condition again
				}
				else
				{
					printf("Please enter valid Employee id\n");
					continue;
				}
			}
		}
		else                                                  //this case is for other than Employee id and Email id 
		{
			char str[80];                                //character array to scan the input from user
			printf("Enter %s: ", temp->fields);
			scanf("%s", str);
			int i = 0, flag = 0;
			while(str[i] != '\0')
			{
				if(str[i] == ' ' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <=122))             //check for emp details contains special character or not 
				{
					i++;
				}
				else
				{
					flag = 1;       
					break;                              //break the loop
				}
			}
			if(flag == 0)
			{
				strcpy(buffer[buf_index], str);                 //copying that str value to buffer
				buf_index++;
				temp = temp->link;                              //move to next node

				continue;                                       //check for condition again           
			}
		}
	}
	printf("User details: \n");
	for(int i = 0;i < buf_index;i++)                                        //loop to store the user details to excel form and display each user details from buffer
	{
		printf("%s\t",buffer[i]);
		fprintf(file_pointer, "%s\t", buffer[i]);
	}
	printf("\n");
	fprintf(file_pointer, "\n");
	fclose(file_pointer);                                                  //close file
	pthread_mutex_unlock(&lock);
}

void *thread_handler2(void *Form_option)
{
	pthread_mutex_lock(&lock);                          //locking the thread2
	char form[FORM_LEN];                               //for storing form name
	int *form_option = (int*)Form_option;              //typecasting from void* to unt*
	strcpy(form, Forms[*form_option - 1]);              //copy forms of particular index name to form character array
	strcat(form, ".xlsx");                           //concatenate the form name with .xlsx
	FILE *file_pointer = fopen(form, "a");          //opens a particular form in append mode
	Vote *temp = Root[*form_option - 1];           //temp pointer of type structure to point to first field
	char buffer[BUF_R][BUF_C];                      //Buffer global variable to store the user details after every thread execution
	int buf_index = 0;                              //for storing index value of Buffer

	while( temp != NULL)                          //Looping untill temp not equal to NULL
	{
		char field[30];                       //character array to store field name
		strcpy(field, temp->fields);          //copy temp field name to field

		char *ptr1 = strstr(field, "Email-id");   //ptr1 to store the return pointer of strstr after searching "Email-id" with field name
		char *ptr2 = strchr(field, 'i');         //ptr2 to store the return pointer of strchr after searching 'i' with field name


		if(ptr1 != NULL)
		{
			if(strcasecmp(ptr1,"Email-id")==0)
			{
				char str[30];                        //character array to scan the input from user
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				char *ptr = strchr(str, '@');         //searching for '@' in user str
				if(strcmp(ptr, "@thundersoft.com") == 0)  //check for comparing the ptr value with "@thundersoft.com" returns 0
				{
					strcpy(buffer[buf_index], str);        //copying that str value to buffer
					buf_index++;
					temp = temp->link;                     //move to next node

					continue;                             //check for condition again
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
			if(strcmp(ptr2, "id") == 0)                               //comparing ptr2 with "id" string in str input
			{
				char str[30];                                    //character array to scan the input from user
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				if(str[0] == '0')                               //checking for employee id starts from 0
				{
					strcpy(buffer[buf_index], str);         //copying that str value to buffer
					buf_index++;
					temp = temp->link;                      //move to next node
					continue;                               //check for condition again
				}
				else
				{
					printf("Please enter valid Employee id\n");
					continue;
				}
			}
		}
		else                                                  //this case is for other than Employee id and Email id 
		{
			char str[80];                                //character array to scan the input from user
			printf("Enter %s: ", temp->fields);
			scanf("%s", str);
			int i = 0, flag = 0;
			while(str[i] != '\0')
			{
				if(str[i] == ' ' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <=122))             //check for emp details contains special character or not 
				{
					i++;
				}
				else
				{
					flag = 1;       
					break;                              //break the loop
				}
			}
			if(flag == 0)
			{
				strcpy(buffer[buf_index], str);   //copying that str value to buffer
				buf_index++;              
				temp = temp->link;                              //move to next node
				continue;                                       //check for condition again           
			}
		}
	}
	printf("User details: \n");
	for(int i = 0;i < buf_index;i++)                                        //loop to store the user details to excel form and display each user details from buffer
	{
		printf("%s\t",buffer[i]);
		fprintf(file_pointer, "%s\t", buffer[i]);
	}
	printf("\n");
	fprintf(file_pointer, "\n");
	fclose(file_pointer);                                                  //close file
	pthread_mutex_unlock(&lock);
}

void *thread_handler3(void *Form_option)
{
	pthread_mutex_lock(&lock);                          //locking the thread3
	char form[FORM_LEN];                               //for storing form name
	int *form_option = (int*)Form_option;              //typecasting from void* to unt*
	strcpy(form, Forms[*form_option - 1]);              //copy forms of particular index name to form character array
	strcat(form, ".xlsx");                           //concatenate the form name with .xlsx
	FILE *file_pointer = fopen(form, "a");          //opens a particular form in append mode
	Vote *temp = Root[*form_option - 1];           //temp pointer of type structure to point to first field
	char buffer[BUF_R][BUF_C];                      //Buffer global variable to store the user details after every thread execution
	int buf_index = 0;                              //for storing index value of Buffer

	while( temp != NULL)                          //Looping untill temp not equal to NULL
	{
		char field[30];                       //character array to store field name
		strcpy(field, temp->fields);          //copy temp field name to field

		char *ptr1 = strstr(field, "Email-id");   //ptr1 to store the return pointer of strstr after searching "Email-id" with field name
		char *ptr2 = strchr(field, 'i');         //ptr2 to store the return pointer of strchr after searching 'i' with field name


		if(ptr1 != NULL)
		{
			if(strcasecmp(ptr1,"Email-id")==0)
			{
				char str[30];                        //character array to scan the input from user
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				char *ptr = strchr(str, '@');         //searching for '@' in user str
				if(strcmp(ptr, "@thundersoft.com") == 0)  //check for comparing the ptr value with "@thundersoft.com" returns 0
				{
					strcpy(buffer[buf_index], str);        //copying that str value to buffer
					buf_index++;
					temp = temp->link;                     //move to next node                        
					continue;                             //check for condition again
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
			if(strcmp(ptr2, "id") == 0)                               //comparing ptr2 with "id" string in str input
			{
				char str[30];                                    //character array to scan the input from user
				printf("Enter %s: ", temp->fields);
				scanf("%s", str);
				if(str[0] == '0')                               //checking for employee id starts from 0
				{
					strcpy(buffer[buf_index], str);         //copying that str value to buffer
					buf_index++;
					temp = temp->link;                      //move to next node
					continue;                               //check for condition again
				}
				else
				{
					printf("Please enter valid Employee id\n");
					continue;
				}
			}
		}
		else                                                  //this case is for other than Employee id and Email id 
		{
			char str[80];                                //character array to scan the input from user
			printf("Enter %s: ", temp->fields);
			scanf("%s", str);
			int i = 0, flag = 0;
			while(str[i] != '\0')
			{
				if(str[i] == ' ' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <=122))             //check for emp details contains special character or not 
				{
					i++;
				}
				else
				{
					flag = 1;       
					break;                              //break the loop
				}
			}
			if(flag == 0)
			{
				strcpy(buffer[buf_index], str);                 //copying that str value to buffer
				buf_index++;
				temp = temp->link;                              //move to next node

				continue;                                       //check for condition again           
			}
		}
	}
	printf("User details: \n");
	for(int i = 0;i < buf_index;i++)                                        //loop to store the user details to excel form and display each user details from buffer
	{
		printf("%s\t",buffer[i]);
		fprintf(file_pointer, "%s\t", buffer[i]);
	}
	printf("\n");
	fprintf(file_pointer, "\n");
	fclose(file_pointer);                                                  //close file
	pthread_mutex_unlock(&lock);
}


void voting_response()
{
	pthread_t thread[3];               //declaring array of threads                               
	pthread_create(&thread[0], NULL, thread_handler1, (void *)&Form_option); //creating thread1 with handler function thread handler1 
	pthread_create(&thread[1], NULL, thread_handler2, (void *)&Form_option);  //creating thread2 with handler function thread handler2
	pthread_create(&thread[2], NULL, thread_handler3, (void *)&Form_option);  //creating thread3 with handler function thread handler3
	pthread_join(thread[0], NULL);  //wait for thread1 to complete execution
	pthread_join(thread[1], NULL);  //wait for thread2 to complete execution
	pthread_join(thread[2], NULL);  //wait for thread3 to complete execution
}


