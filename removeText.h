#ifndef REMOVETEXT_H_INCLUDED
#define REMOVETEXT_H_INCLUDED

void removeText(){

    printf("Write \"back\" whenever to return main menu.\n");
    int check;
    char targetedFile[25];

    printf("Give a filename to make empty: ");
    scanf("%s", targetedFile);
    if (strcmp("back",targetedFile)==0) // Back to main menu.
        {
        printf("\n");
        return;
        }

    if (access(targetedFile, F_OK ) == -1) // If file is not accessible
        {
        printf("ERROR! File already not here.\n\n");
        return;
        }

    check = remove(targetedFile); // Delete file.

    FILE *f;
	f = fopen(targetedFile, "ab+"); // Recreate it with same name.
	if (f && check == 0)
        {
		printf("File successfully emptied.\n\n");
        }
    else
        {
		printf("ERROR! You are not permitted to empty this file.\n\n");
        }
	fclose(f);

	return;
}


#endif // REMOVETEXT_H_INCLUDED
