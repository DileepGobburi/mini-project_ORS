#include"voting_response.h"
#include"voting_request.h"

void voting_response_module()
{
	int flag = 0,i = 0;
	if(Count > 0)
	{
		printf("Available voting forms are: \n");
		for(i = 0;i < Count;i++)
		{
			printf("%d. %s\n", i+1, Forms[i]);
		}
		while(1)
		{
			if(flag < 3)
			{
				printf("Please select from available voting forms for providing response : ");
				scanf("%d", &Form_option);
				if(Form_option > i)
				{
					printf("Please enter valid option\n");
					flag++;
				}
				else
				{
					voting_response();
					main();

				}
			}
			else
			{
				printf("You entered invalid option 3 times\n");
				main();
			}
		}
	}
	else
	{
		printf("No voting forms available\n");
		main();
	}
}

