#include <stdio.h>
#include <stdlib.h>
#include "mycp.h"

int main(int argc,char *argv[])
{
    int choice;
    if (3!=argc){
    printf("input: ./file dest src\n");
    return 0;}
    while(1){
    printf("Please select:\n");
    printf("1.cp by char\n");
    printf("2.cp by record\n");
    printf("3.cp by row\n");
    printf("Your choice:");
    scanf("%d",&choice);
    if (choice>=1 && choice<=3)
        break;
    }
    mycp(argv[1],argv[2],choice);

    return 0;
}
