#ifndef COPYFILE_H_INCLUDED
#define COPYFILE_H_INCLUDED

#include <unistd.h>
#include <stdio.h>
#include <string.h>


void copyFile()
{
    printf("Write \"back\" whenever to return main menu.\n");
    FILE *oldFile, *newFile;
    char ch, oldFileName[25], newFileName[25];

    printf("Give a filename to copy: ");
    scanf("%s",oldFileName);

    int fnf = access( oldFileName, F_OK );
    while (fnf == -1) // Demand a file name till the file is accessible.
        {
        printf("ERROR! There is no such a file. If you want to create this file use \"n\" command.\n\n");
        printf("Give a filename to copy or write back to return main menu: ");
        scanf("%s",oldFileName);
        fnf = access( oldFileName, F_OK );
        }

    oldFile = fopen(oldFileName, "r"); // source file.

    if( oldFile == NULL ) {
        printf("ERROR! You are not permitted to copy this file.\n\n");
        return(-1);
    }

    printf("Give a new filename or write back to return main menu: ");
    scanf("%s",newFileName);

    fnf = access( newFileName, F_OK );
    while(fnf != -1) // Demand a file name till the file not exist.
        {
        printf("ERROR! File already here.\n\n");
        printf("Give a new filename or write back to return main menu: ");
        scanf("%s",newFileName);

        fnf = access( newFileName, F_OK );
        }

    if (access( newFileName, F_OK ) != -1) {
        printf("ERROR! File already here.\n\n");
        return(-1);
    }

    newFile = fopen(newFileName, "wb");

    if( newFile == NULL ) {
      fclose(oldFile);
      printf("ERROR! You are not permitted to copy this file.\n\n");
      return(-1);
    }

    while ((ch = fgetc(oldFile)) != EOF) { // copy source to new file char by char till the end of file.
        fputc(ch, newFile);
    }

    printf("File successfully copied.\n\n");

    fclose(oldFile);
    fclose(newFile);

    return;



}


#endif // COPYFILE_H_INCLUDED
