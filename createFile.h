#ifndef CREATEFILE_H_INCLUDED
#define CREATEFILE_H_INCLUDED

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void createFile()
{
    printf("Write \"back\" whenever to return main menu.\n");
	char createdFile[25];
	printf("Give a filename to create: ");
	scanf("%s", createdFile);
	if (strcmp("back",createdFile)==0) // Return main menu
        {
        printf("\n");
        return;
        }

	if (access(createdFile, F_OK ) != -1) // If file exist
        {
		printf("ERROR! File already here.\n\n");
		return;
        }
    FILE *f;
	f = fopen(createdFile, "ab+"); // Create a file
	if (f)
        {
		printf("File successfully created.\n\n");
        }
    else
        {
		printf("ERROR! You are not permitted to create this file.\n\n");
        }
	fclose(f);

	return;
}



#endif // CREATEFILE_H_INCLUDED
