#ifndef MOVEFILE_H_INCLUDED
#define MOVEFILE_H_INCLUDED

#include <stdio.h>
#include <unistd.h>

#include <stdio.h>
#include <unistd.h>

void moveFile() {

    FILE *file, *destination;
    char ch, fileName[1024], directoryName[1024];

    printf("Give a filename to move: ");
    scanf("%s",fileName);
    if (strcmp("back",fileName)==0) // Back to main menu
        {
        printf("\n");
        return;
        }

    int fnf = access( fileName, F_OK ); // file access check
    while (fnf == -1){ // demand file name until file can be accessible.
        printf("ERROR! There is no such a file. If you want to create this file use \"n\" command.\n\n");
        printf("Give a filename to move: ");
        scanf("%s",fileName);
        if (strcmp("back",fileName)==0)
        {
        printf("\n");
        return;
        }
        fnf = access( fileName, F_OK );
    }

    file = fopen(fileName, "r"); // Open file to copy.

    if( file == NULL ) {
       printf("ERROR! You are not permitted to move this file.\n\n");
    return;
    }

    printf("Give a pathname with file name to move: ");
    scanf("%s",directoryName);
    fnf = access( directoryName, F_OK );
    while(fnf != -1){ // Demand a directory till the directory is not full.
        printf("ERROR! File already here.\n\n");
        printf("Give a pathname with file name to move: ");
        scanf("%s",directoryName);
        if (strcmp("back",fileName)==0)
        {
        printf("\n");
        return;
        }
        fnf = access( directoryName, F_OK );
    }

    destination = fopen(directoryName, "wb"); // Open file to write content of source

    if( destination == NULL ) {
        fclose(file);
        printf("ERROR! You are not permitted to move this file.\n\n");
    }

    while (( ch = fgetc(file) ) != EOF) { // Write content of source to new file char by char till the end of file.
        fputc(ch, destination);
    }

    printf("File successfully moved.\n\n");

    fclose(file);
    fclose(destination);

    remove(fileName); // Remove source file
    return;
}


#endif // MOVEFILE_H_INCLUDED
