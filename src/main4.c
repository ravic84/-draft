#include <stdio.h>
#include <string.h>

int main()
{
	char name[50];
	char answer[50];
	printf("\n Hello, my name is Dmitry. What is your name? \n Enter you name: \n ");
	gets(name);
	
	printf(" Your name is: %s",name);
	printf("\n All right?\n ");
	gets(answer);
	printf(" Your answer - %s",answer);
	if (strcmp (answer,"yes")==0){
        	printf("\n Thank you for your time %s",name);
        	printf("\n");
        	}
        else
        	printf("\n Please restart the application again\n");
	
	return 0;
}	 
