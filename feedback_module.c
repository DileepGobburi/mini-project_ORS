#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"registration.h"
#include"feedback.h"

void feedback_module()
{
	int i=0,count=0,option;
	char choice;

	if(Forms_count==0) //checking if training registarion is made or not
	{
		printf("No registrations are made\n");
		main();
	}
	if(Forms_count>0)
	{
		printf("Available trining forms:\n");
		for(i=0;i<Forms_count;i++) //to print the available registration forms
		{
			printf("%d.%s\n",i+1,Forms[i]);
		}
		while(1)
		{
			if(count<3)
			{
				printf("Please select the option from the avilable training forms:\n");
				scanf("%d",&option);
			//	option=((int)choice)-48;
				if(option<=Forms_count)
				{
					feedback(option);
				}
				else
				{
					printf("Invalid option\n");
					count++;
				}
			}
			else
			{
				printf("User Entered 3 times wrong option\n");
				main();
			}
		}
	}
}

/*int give_feedback(int option)
  {
  char emp_id[10];
  char filename[30];
  char form_name[30];
  char c;
  int count=0;
  strcpy(filename,forms[option-1]);
  strcat(filename,".xlsx");
  FILE *fp=fopen(filename,"r");
  if(fp==NULL)
  {
  printf("File does not exists\n");
  }
  else
  {
  for (c = getc(fp); c != EOF; c = getc(fp))
  {
  if (c == '\n') // Increment count if this character is newline
  count = count + 1;
  }
  }
  if(count==1)
  {
  printf("Only form is created no entries are made\n");
  main();
  }
  else
  {
  strcpy(form_name,forms[option-1]);
  strcat(form_name,"_feedback.xlsx");
  FILE *fp1=fopen(form_name,"w");
  if(fp1==NULL)
  {
  printf("File does not exists\n");
  }
  else
  {
  feedback user={"emp_id","emp_name","emp_email","reporting_mgr","feedback"};


  fprintf(fp1,"%s\t%s\t%s\t%s\t%s\n",user.emp_id,user.emp_name,user.emp_email,user.reporting_mgr,user.feedback);
  fclose(fp1);
  pthread_t thread[3];
  pthread_create(&thread[0], NULL, thread_handler1, (void *)&option);
//pthread_create(&thread[1], NULL, thread_handler2, (void *)&form_option);
//pthread_create(&thread[2], NULL, thread_handler3, (void *)&form_option);
pthread_join(thread[0], NULL);
//pthread_join(thread[1], NULL);
//pthread_join(thread[2], NULL);
}
}
}

void *thread_handler1(void *option)
{
pthread_mutex_lock(&lock);
char form[30];
char form1[30];
char emp_id[20];
char buffer[100][30];
char buffer1[50][50];
int *option = (int *)option;
strcpy(form, forms[*option - 1]);
strcat(form, ".xlsx");
FILE *file_pointer = fopen(form, "r");
employee *temp = Ad[*forms_option - 1];
int i = 0,j = 0,val = 0,element = 0,flag;

printf("Enter the Emp_id:");
scanf("%s",emp_id);
while(!feof(file_pointer))
{
	fscanf(file_pointer,"%[^\t]%*c",buffer[i]);
	if(buffer[i]== '0')
	{
		strcpy(buffer1[j],buffer[i]);
		j++;
		element++;
	}
	//	element++;
	i++;
}
for(i=0;i<element;i++)
{
	if(strcmp(buffer1[i],emp_id)==0)
	{
		strcpy(emp_id,buffer1[i]);
		flag==1;
	}
}
if(flag==0)
{
	printf("Cant give the feedback since user not registered forthe training\n");
	main();
}
else
{
	strcpy(form1, forms[*option - 1]);
	strcat(form1, "_feedback.xlsx");
	FILE *fp2 = fopen(form, "a");
	pthread_mutex_lock(&lock);
	char name[80];
	feedback user1;
	if(emp_id == '0')
	{
		strcpy(user1.emp_id, emp_id);
		fprintf(fp2,"%s\t",user1.emp_id);

	}

	printf("Enter the emp_name:");
	scanf("%[^\n]%*c",name);

	int k = 0, flag = 0;
	while(name[k] != '\0')
	{
		if(name[k] == ' ' || (name[k] >= 65 && name[k] <= 90) || (name[k] >= 97 && name[k] <=122))
		{
			k++;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		strcpy(user1.emp_name,name);
		fprintf(fp2,"%s\t",user1.emp_name);
	}
	char Email_id[30];
	printf("Enter the email_id:");
	scanf("%[^\n]%*c",Email_id);
	char *ptr1 = strchr(Email_id, '@');
	if(strcmp(ptr1, "@thundersoft.com") == 0)
	{
		strcpy(user1.emp_email, Email_id);
		fprintf(fp2, "%s\t",user1.emp_email);
	}
	char reporting_manager[80];
	printf("Enter the Reporting manger name:");
	scanf("%[^\n]%*c",reporting_manager);

	int k = 0, flag = 0;
	while(reporting_manger[k] != '\0')
	{
		if(reporting_manger[k] == ' ' || (reporting_manager[k] >= 65 && reporting_manager[k] <= 90) || (reporting_manager[k] >= 97 && reporting_manager[k] <=122))
		{
			k++;
		}
		else
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		strcpy(user1.reporting_mgr,reporting_manager);
		fprintf(fp2,"%s\t",user1.reporting_mgr);
	}
}
char feedback_training[256];
printf("Enter the Feedback for the training:");
scanf("%[^\n]%*c",feeback_training);

int k = 0, flag = 0;
while(feedback_training[k] != '\0')
{
	if(feeback_training[k] == ' ' || (feedback_trainibg[k] >= 65 && feedback_training[k] <= 90) || (feedback_training[k] >= 97 && feedback_training[k] <=122))
	{
		k++;
	}
	else
	{
		flag = 1;
		break;
	}
}
if(flag == 0)
{
	strcpy(user1.feedback,feedback_training);
	fprintf(fp2,"%s\t",user1.feedback);
}

printf("User details: \n");
for(int j = 0;j < val;j++)
{
	printf("%s\t",buffer[j]);
	fprintf(file_pointer, "%s\t", buffer[j]);
}
printf("\n");
fprintf(fp2, "\n");
fclose(fp2);
pthread_mutex_unlock(&lock);
}*/
