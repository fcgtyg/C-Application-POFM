#include <stdio.h>
#include <string.h>
#include "createFile.h"
#include "deleteFile.h"
#include "renameFile.h"
#include "copyFile.h"
#include "moveFile.h"
#include "appendText.h"
#include "removeText.h"



void main() {
	char command[1024];

	printf("Welcome the POFM.\n");
	printf("Feel free to exit from program by writing \"exit\" at main menu .\n");
	printf("Feel free to back main menu anytime by writing \"back\"\n");
	printf("If you need any help about commands, just write \"help-COMMAND\"\n");
	printf("Please choose operation from below.\n\n");
    printf("+-----------------------+---------+\n");
    printf("| Operations\t\t| Command |\n");
    printf("+-----------------------+---------+\n");
	printf("| Create a new file\t|\    n    \|\n");
	printf("+-----------------------+---------+\n");
	printf("| Delete a file\t\t|\    d    \|\n");
	printf("+-----------------------+---------+\n");
	printf("| Rename a file\t\t|\    r    \|\n");
	printf("+-----------------------+---------+\n");
    printf("| Copy a file\t\t|\    c    \|\n");
    printf("+-----------------------+---------+\n");
    printf("| Move a file\t\t|\    m    \|\n");
    printf("+-----------------------+---------+\n");
    printf("+-----------------------+---------+\n");
    printf("| TXT Only Operations\t| Command |\n");
    printf("+-----------------------+---------+\n");
	printf("| Append text to the end|\    ta   \|\n");
	printf("+-----------------------+---------+\n");
	printf("| Remove all text \t|\    tr   \|\n");
	printf("+-----------------------+---------+\n\n");

	printf("Waiting for your command: ");
	scanf("%s", command);

	while(1)
    {
        if ((strcmp("n",command)==0) || (strcmp("N",command)==0))
            {
			createFile();
            }
        else if ((strcmp("d",command)==0) || (strcmp("D",command)==0))
            {
            deleteFile();
            }
        else if ((strcmp("r",command)==0) || (strcmp("R",command)==0))
            {
            renameFile();
            }
        else if ((strcmp("c",command)==0) || (strcmp("C",command)==0))
            {
            copyFile();
            }
        else if ((strcmp("m",command)==0) || (strcmp("M",command)==0))
            {
            moveFile();
            }
        else if ((strcmp("ta",command)==0) || (strcmp("TA",command)==0))
            {
            appendText();
            }
        else if ((strcmp("tr",command)==0) || (strcmp("TR",command)==0))
            {
            removeText();
            }
        else if (strcmp("exit",command)==0)
            {
                break;
            }
        else if (strcmp("help-n",command)==0)
            {
                printf("hepinizi sikim\n");
            }
        else if (strcmp("help-d",command)==0)
            {
                printf("hepinizi sikim2\n");
            }
        else if (strcmp("help-r",command)==0)
            {
                printf("hepinizi sikim3\n");
            }
        else if (strcmp("help-c",command)==0)
            {
                printf("hepinizi sikim4\n");
            }
        else if (strcmp("help-m",command)==0)
            {
                printf("hepinizi sikim4\n");
            }
        else if (strcmp("help-ta",command)==0)
            {
                printf("hepinizi sikim4\n");
            }
        else if (strcmp("help-tr",command)==0)
            {
                printf("hepinizi sikim4\n");
            }

        else
            {
            printf("Command not recognized. Please give a command from the TABLE.\n\n");
            }
        printf("Waiting for your command: ");
        scanf("%s", command);
    }
    return;
}
