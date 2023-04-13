#include <stdlib.h>
#include "list.h"

void Insert_Node_At_Beginning (struct Node **List )
{
    struct Node *tempnode = NULL;
    /*create the node */
    tempnode=(struct Node*)malloc(sizeof( struct Node));
    /*checking of allocation & initialize node data*/
    if(NULL != tempnode )
    {
        printf("enter data of node:");
        scanf("%i" , &tempnode->nodedata);
    }
    /*checking of empty list */
    if(*List == NULL)
    {
         tempnode->nodelink = NULL;
        *List = tempnode;
    }
    /*checking if list is not empty */
    else
    {
        tempnode->nodelink = *List;
        *List = tempnode;
    }

}
void Insert_Node_At_End (struct Node **List )
{
    struct Node *tempnode = NULL;
    struct Node *lastnode= NULL;
    /*create the node */
    tempnode=(struct Node*)malloc(sizeof( struct Node));
    /*checking of allocation & initialize node data*/
    if(NULL != tempnode )
    {
        printf("enter data of node:");
        scanf("%i" , &tempnode->nodedata);
        tempnode->nodelink = NULL;

    /*checking of empty list */
    if (NULL == *List)
    {
        *List = tempnode;
    }
    /*checking if list is not empty */
    else
    {
        lastnode = *List;
        while(lastnode->nodelink != NULL)
        {
            lastnode=lastnode->nodelink;
        }
        lastnode->nodelink = tempnode;
    }
  }
  else {/*nothing*/}
}
void Insert_Node_After (struct Node *List )
{
    struct Node *tempnode = NULL , *nodelistcounter= NULL;
    uint32_t nodeposition =0 , nodecounter=1 , listlength=0;

    printf("enter node position:");
    scanf("%i" , &nodeposition);
    listlength = getlength(List);
    if(nodeposition > listlength )
    {
        printf("invalid node position out of list\n");
    }
    else
    {
        nodelistcounter = List;
        while(nodecounter < nodeposition)
        {
            nodecounter++;
            nodelistcounter=nodelistcounter->nodelink;
        }

    /*create node data*/
    tempnode=(struct Node*)malloc(sizeof(struct Node));
        if(NULL != tempnode )
        {
            printf("enter the node data");
            scanf("%i" , &tempnode->nodedata);
            tempnode->nodelink = NULL;
            /*connect the created node on the right one*/
            tempnode->nodelink = nodelistcounter->nodelink;
            /*connect the created node on the right one*/
            nodelistcounter->nodelink= tempnode;
        }

        else{/*nothing*/}
    }
}

void Delete_Node_At_Beginning (struct Node **List )
{

    struct Node *tempnode = *List;
    uint32_t listlengh = 0;
    listlengh = getlength(*List);
    if(listlengh == 0)
    {
        printf("invalid!! no nodes in list to delet\n");
    }
    else
    {
        *List = tempnode->nodelink;
        tempnode->nodelink = NULL;
        free(tempnode);
    }
}

void Delete_Node (struct Node *List )
{
    struct Node *nodelistcounter = List;
    struct Node *nextnode = List;
    uint32_t nodeposition=0 , nodecounter=1, listlengh=0;

    printf ("enter the delete position(first node is position=1)");
    scanf ("%i"  , &nodeposition);
    listlengh =getlength(List);
    if ((nodeposition > listlengh) || (listlengh==1))
    {
        printf("you can use delete at the beginning function");
    }
    else
    {
        while(nodecounter < (nodeposition - 1))
        {
            nodecounter++;
            nodelistcounter=nodelistcounter->nodelink;
        }
        nextnode = nodelistcounter->nodelink;
        nodelistcounter->nodelink = nextnode->nodelink;
        free(nextnode);
    }
}
void Display_All_Nodes (struct Node *List)
{
    struct Node *tempnode= List;
    if (tempnode == NULL )
    {
        printf ("list is empty\n");
    }
    else
    {
        while (tempnode != NULL)
        {
            printf("data %i -> " , tempnode->nodedata);
            tempnode = tempnode->nodelink;
        }
        if(tempnode == NULL)
        {
            printf("null\n");
        }
    }
}

uint32_t getlength (struct Node *List)

{
    uint32_t nodecount=0;
    struct Node *tempnode= List;

        while(tempnode!=NULL)
        {
            tempnode= tempnode->nodelink  ;
            nodecount++;
        }

    return nodecount;
}


