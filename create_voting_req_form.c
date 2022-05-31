
#include"voting_request.h"

/************ function defination of creating voting request form**************************/

void create_voting_req_form()
{
	char form[30];                                           //user requested form name                                       
	int flag = 0;
	int count_fields=0;                                     // to enter no of fields base of user
	FILE *file_pointer = NULL;
	printf("Enter the form name: ");
	scanf("%s", form);
	for(int i = 0;i < Count; i++)                          // to check form already exists or not
	{
		if(strcasecmp(Existing_forms[i], form) == 0)
		{
			flag = 1;
		}
	}

	strcpy(Forms[Count], form);
	if(flag == 0)
	{
		strcat(form, ".xlsx");                               // adding file extention in file name
		file_pointer = fopen(form, "w");                    // to open form file
		if(file_pointer == NULL)                           //if fopen failed
		{
			printf("File open not successfull\n");
		}

		printf("Enter the number of fields required: ");  // to enter no of fields base on users choice
		scanf("%d", &count_fields);      
		Root[Count] = NULL;		//head pointer of linklist
		Vote *lastnode = NULL;
		for(int i = 0;i < count_fields;i++)
		{

			Vote *newnode = NULL;
			newnode=(Vote*)malloc(sizeof(Vote));
			printf("Enter field name: ");
			scanf("%s", newnode->fields);
			newnode->link = NULL;

			if(Root[Count] == NULL)                        // if linklist is empty add node as head pointer
			{
				Root[Count] = newnode;
			}
			else                                // if list is not empty
			{      
				lastnode->link = newnode;                   // to add at last         
			}
			lastnode = newnode;
			fprintf(file_pointer, "%s\t", newnode->fields);
		}
	}
	fprintf(file_pointer,"\n");
	fclose(file_pointer);
	Count++;
}

