#ifndef APPENDTEXT_H_INCLUDED
#define APPENDTEXT_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFERSIZE 10
#define MAX_SZ 256

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFERSIZE 10
#define MAX_SZ 256

void appendText() {
    printf("Write \"back\" whenever to return main menu.\n");

	FILE *f;
	char text[4096];
	char targetFile[1024];

	printf("Enter name of the file to edit: ");
	scanf("%s", targetFile);

    if (strcmp("back",targetFile)==0) // Back to main menu.
        {
        printf("\n");
        return;
        }

	int fnf = access( targetFile, F_OK );
	while (fnf == -1) // Demand a file name till the file can be accessible.
        {
        printf("Error: File already not here.\n");
        printf("Enter name of the file to edit: ");
        scanf("%s", targetFile);
        if (strcmp("back",targetFile)==0)
            {
            printf("\n");
            return;
            }
        fnf = access( targetFile, F_OK );
        }

	printf("Enter a line to append: ");
	scanf("%s", text);
    if (strcmp("back",text)==0)
        {
        printf("\n");
        return;
        }

	char *check;
	char buffer[1024];

	if ((check = fgets(buffer, 1024, stdin)) != NULL) // Save the keyboard input to the buffer
        {
		strcat(text, buffer); // cast the buffer into text.
        }
	f = fopen(targetFile, "a"); // open file to append in append mode.

	if( f == NULL ) {
       printf("Error:Permission Denied!\n");
    }

	fprintf(f, "%s", text); // writedown the text into file.
	fclose(f);

	printf("Success.\n");
}
#endif // APPENDTEXT_H_INCLUDED
