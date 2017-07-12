#ifndef DELETEFILE_H_INCLUDED
#define DELETEFILE_H_INCLUDED

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void deleteFile()
{
    printf("Write \"back\" whenever to return main menu.\n");
    int check;
    char targetedFile[25];
    printf("Give a filename to delete: ");
    scanf("%s", targetedFile);
    if (strcmp("back",targetedFile)==0) // return to main menu.
        {
        printf("\n");
        return;
        }

    if (access(targetedFile, F_OK ) == -1) // If file is not exist
        {
        printf("ERROR! File already not here.\n\n");
        return;
        }

    check = remove(targetedFile); // Delete file.
    if (check == 0)
        {
        printf("File successfully deleted.\n\n");
        }
    else
        {
        printf("ERROR! You are not permitted to delete this file.\n\n");
        }

    return;
}



#endif // DELETEFILE_H_INCLUDED
