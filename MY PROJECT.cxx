#include <stdio.h>
int main ()
{
	char name[50];
	char DoB[20]; // Donot live spaces
	char gender[10];
	int age;
	char NIN[100]; // To be given on issuedate
	char issuedate[20];
	char imagepath[50];
	
	printf ("NIRA REGISTRATION APPLICATION.\n");
	printf ("Please Enter your details.\n");
	
	printf ("Enter your name:\n");
	scanf ("%s", name);
	
	printf ("Enter DoB:\n");
	scanf ("%s", DoB);
	
	printf ("Enter gender:\n");
	scanf ("%s", gender);
	
	printf ("Enter your age:\n");
	scanf ("%d", &age);
	getchar ();
	
	printf ("Paste an imagepath or link of your birthcertificate here:\n");
	scanf ("%[^\n]", imagepath); 
	

		FILE *image = fopen (imagepath, "r");	
		if (image==NULL){
		printf ("Error! image not found %s\n", imagepath);
		printf ("Enter image in this format: mark.jpg\n");
		return 0;
	}
		fclose (image);
	
		printf ("\n------FOR STAFF USE ONLY.------\n");
	
	printf ("Enter Citizen's NIN number:\n");
	scanf ("%s", NIN);
	
	printf ("Enter issuedate:\n");
	scanf ("%s", issuedate);
	
	FILE *file;
	file = fopen("Nira_records.txt", "a");
	
	if (file==NULL) {
	printf ("Error opening the file!\n");
	return 1;
	}
	else {
	fprintf (file, "Name: %s\nDoB: %s\nage: %d\ngender: %s\nNIN: %s\nissuedate: %s\nimagepath: %s\n", name, DoB, age, gender, NIN, issuedate, imagepath);
	printf ("--Registration successful. Data saved to Nira_records.txt--\n");
	fclose(file);
	}
	
	return 0;
}