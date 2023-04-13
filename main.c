#include <stdio.h>
#include <stdlib.h>
#include "list.h"

uint8_t userchoice;
struct Node *listhead = NULL ;
uint32_t listlengh =0;
int main()
{
    printf("welcome to linked list application\n");
    while(1)
    {
         printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &userchoice);

        switch(userchoice)
        {
        case 1:
            Insert_Node_At_Beginning(&listhead);
            break;
        case 2:
            Insert_Node_At_End(&listhead);
            break;
        case 3:
            Insert_Node_After(listhead);
            break;
        case 4:
            Delete_Node_At_Beginning(&listhead);
            break;
        case 5:
            Delete_Node(listhead);
            break;
        case 6:
            Display_All_Nodes(listhead);
            break;
        case 7:
           listlengh= getlength(listhead);
            printf ("lengh of list = %i\n" , listlengh);
            break;
        case 8:
            printf ("quite from application \n");
            exit(1);
            break;
        default:
            printf("your selection is out of range\n");
            break;
        }
    }

    return 0;
}
