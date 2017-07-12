#ifndef RENAMEFILE_H_INCLUDED
#define RENAMEFILE_H_INCLUDED

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void renameFile()
{
    printf("Write \"back\" whenever to return main menu.\n");
    int check;
    char targetedFile[25];
    char newFilename[25];
    printf("Give a filename to change: ");
    scanf("%s", targetedFile);
    while (1)
        {
        if (strcmp("back",targetedFile)==0) // If back command found, return to main menu.
            {
            printf("\n");
            return;
            }
        if (access(targetedFile, F_OK ) == -1) // Check if file is not accessible, raise an error.
            {
            printf("ERROR! There is no such a file. If you want to create this file use \"n\" command.\n\n");
            printf("Give a filename change or write back to return main menu: ");
            scanf("%s", targetedFile);
            }
        else
            {
                break;
            }
        }

    printf("Give a new filename or write back to return main menu: ");
    scanf("%s", newFilename);

    while (1)
        {
        if (strcmp("back",newFilename)==0)
            {
            printf("\n");
            return;
            }
        if (access(newFilename, F_OK ) != -1)
            {
            printf("ERROR! Filename already occupied.\n\n");
            printf("Give a new filename or write back to return main menu: ");
            scanf("%s", newFilename);
            }
        else
            {
                break;
            }
        }


    check = rename(targetedFile, newFilename); // Rename function, file rename occurs here.
    if (check == 0) //Success or not.
        {
        printf("File successfully renamed.\n\n");
        }
    else
        {
        printf("ERROR! You are not permitted to rename this file.\n\n");
        }
    return;
}

#endif // RENAMEFILE_H_INCLUDED
