
#include"voting_request.h"

/****************fun defination for deleting voting req form*****************************/

void delete_voting_req_form()
{
	int form_option;                                                // user choice for form deletion
	char form[30];
	if(Count > 0)                                                   // is threre any form exists or not
	{
		printf("Available voting forms are: \n");
		for(int i = 0;i < Count;i++)                            // to display list of existing form
		{
			printf("%d. %s\n", i+1, Existing_forms[i]);
		}
		printf("Enter the option: ");
		scanf("%d", &form_option);
		strcpy(form, Existing_forms[form_option-1]);     // becoz array started with zero,getting the name of form to deleting file
		strcat(form,".xlsx");

		if(remove(form)==0)                                     // to remove given file 
			printf("File deleted successfully\n");
		else
			printf("File is not deleted\n");
		for(int i = form_option;i < Count;i++)                 //to maintain sequence of form list
		{
			strcpy(Existing_forms[i-1], Existing_forms[i]);

		}
		Count--;                                              // updating form count
	}
	else
	{
		printf("No voting forms created\n");
	}
}


