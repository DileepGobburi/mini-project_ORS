
#include"registration.h"
void delete_training_registration_form()
{
	int form_option;
	if(Forms_count > 0)
	{
		printf("Available trainings are: \n");
		for(int i = 0;i < Forms_count;i++)
		{
			printf("%d. %s\n", i+1, Forms[i]);
		}
		printf("Enter the option: ");
		scanf("%d", &form_option);
		strcat(Forms[form_option - 1],"_training.xlsx");
		//To delete the file 
		if(remove(Forms[form_option - 1])==0)
			printf("File deleted successfully\n");
		else
			printf("File is not deleted\n");
		for(int i = form_option;i < Forms_count;i++)
		{
			strcpy(Forms[i-1], Forms[i]);
			First_field[i-1] = First_field[i];

		}
		Forms_count--;
		main();
	}
	else
	{
		printf("No training forms created\n");
		main();
	}
}

