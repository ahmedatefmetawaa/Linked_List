#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

#define DELETE_NODE_AT_BEGINNING

struct Node{
    uint32 NodeData;
    struct Node *LeftNodeLink;
    struct Node *RightNodeLink;
};

struct Node *DLL_1 = NULL;

void Insert_Node_At_Beginning(struct Node **List, uint32 Data);
void Insert_Node_At_End(struct Node *List, uint32 Data);
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position);
void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node_At_End(struct Node *List);
void Delete_Node_At_Intermediate(struct Node *List, uint32 position);
void Display_All_Nodes_Forward(struct Node *List);
void Display_All_Nodes_Reverse(struct Node *List);

int main()
{
    Insert_Node_At_Beginning(&DLL_1, 11);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_At_Beginning(&DLL_1, 22);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_At_Beginning(&DLL_1, 33);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Insert_Node_At_End(DLL_1, 99);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_At_End(DLL_1, 100);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");

    Insert_Node_After(DLL_1, 44, 2);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_After(DLL_1, 55, 3);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_After(DLL_1, 66, 5);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Insert_Node_Before(&DLL_1, 77, 3);
    Display_All_Nodes_Reverse(DLL_1);
    Insert_Node_Before(&DLL_1, 88, 1);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Delete_Node_At_Beginning(&DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    Delete_Node_At_Beginning(&DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Delete_Node_At_End(DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    Delete_Node_At_End(DLL_1);
    Display_All_Nodes_Reverse(DLL_1);
    printf("----------------------\n");
    Delete_Node_At_Intermediate(DLL_1, 2);
    Display_All_Nodes_Reverse(DLL_1);
    Delete_Node_At_Intermediate(DLL_1, 3);
    Display_All_Nodes_Reverse(DLL_1);

    return 0;
}

void Insert_Node_At_Beginning(struct Node **List, uint32 Data){
    struct Node *TempNode = NULL; /* Points to the new node */

    TempNode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        TempNode->NodeData = Data;
        /* Check if the list is empty */
        if(NULL == *List){
            TempNode->LeftNodeLink = NULL;  /* This is the only node */
            TempNode->RightNodeLink = NULL; /* This is the only node */
            (*List) = TempNode;   /* Make the Head pointer points to this only node */
        }
        else{
            TempNode->RightNodeLink = (*List); /* Make the new node to be the head */
            TempNode->LeftNodeLink = NULL;     /* The LeftNodeLink always NULL in the Head node */
            (*List)->LeftNodeLink = TempNode;  /* This now became the second node */
            (*List) = TempNode; /* Make the Head pointer points to the new node */
        }
    }
    else{
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_At_End(struct Node *List, uint32 Data){
    struct Node *TempNode = NULL; /* Points to the new node */
    struct Node *NodeListCounterOne = NULL;  /* Traverse to the needed node */
    TempNode = (struct Node*)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        TempNode->NodeData = Data;
        TempNode->RightNodeLink = NULL;
        NodeListCounterOne = List;
        while(NULL != NodeListCounterOne->RightNodeLink){
            NodeListCounterOne = NodeListCounterOne->RightNodeLink;
        }
        TempNode->LeftNodeLink = NodeListCounterOne;
        NodeListCounterOne->RightNodeLink = TempNode;
    }
    else{
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_After(struct Node *List, uint32 Data, uint32 position){
    struct Node *TempNode = NULL;            /* Points to the new node */
    struct Node *NodeListCounterOne = NULL;  /* Traverse to the needed node */
    struct Node *NodeListCounterTwo = NULL;  /* Traverse to the needed node */

    NodeListCounterOne = List; /* Points to the head node now */
    while(position != 1){
        NodeListCounterOne = NodeListCounterOne->RightNodeLink; /* Move the pointer */
        position--;
    }

    /* Create the new node */
    TempNode = (struct Node*)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        TempNode->NodeData = Data;
        /* Check if we reach the End Node of the List :: Adding the new node at the end */
        if(NULL == NodeListCounterOne->RightNodeLink){
            NodeListCounterOne->RightNodeLink = TempNode;
            TempNode->LeftNodeLink = NodeListCounterOne;
            TempNode->RightNodeLink = NULL;
        }
        else{
            NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
            /* Update the information of the new node */
            NodeListCounterOne->RightNodeLink = TempNode; /* Make the left node points to the new node */
            NodeListCounterTwo->LeftNodeLink = TempNode;  /* Make the right node points to the new node */
            TempNode->LeftNodeLink = NodeListCounterOne;  /* Update the left pointer of the new node */
            TempNode->RightNodeLink = NodeListCounterTwo; /* Update the right pointer of the new node */
        }
    }
    else{
        printf("Can't allocate the new node !! \n");
    }
}

void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position){
    struct Node *TempNode = NULL;            /* Points to the new node */
    struct Node *NodeListCounterOne = NULL;  /* Traverse to the needed node */
    struct Node *NodeListCounterTwo = NULL;  /* Traverse to the needed node */
    uint32 NodePosition = position;

    NodeListCounterOne = (*List); /* Points to the head node now */
    while(NodePosition > position-1){ /* This to point to the node before the given position */
        NodeListCounterOne = NodeListCounterOne->RightNodeLink;
        NodePosition--;
    }

    /* Create the new node */
    TempNode = (struct Node*)malloc(sizeof(struct Node));
    if(NULL != TempNode){
        TempNode->NodeData = Data;
        /* Check if the position = 1 :: Adding the new node at the beginning */
        if(1 == position){
            TempNode->LeftNodeLink = NULL;  /* This is the only node */
            TempNode->RightNodeLink = *List;
            (*List)->LeftNodeLink = TempNode;
            *List = TempNode;
        }
        else{
            NodeListCounterTwo = NodeListCounterOne->RightNodeLink;
            NodeListCounterOne->RightNodeLink = TempNode;
            NodeListCounterTwo->LeftNodeLink = TempNode;
            TempNode->RightNodeLink = NodeListCounterTwo;
            TempNode->LeftNodeLink = NodeListCounterOne;
        }
    }
    else{
        printf("Can't allocate the new node !! \n");
    }
}

void Delete_Node_At_Beginning(struct Node **List){
    struct Node *TempNode = *List; /* Points to the node that we need to delete */

#ifdef DELETE_NODE_AT_BEGINNING
    /* Update the head node */
    *List = (*List)->RightNodeLink;
    (*List)->LeftNodeLink = NULL;
    /* Free the first node */
    free(TempNode);
    TempNode = NULL;
#else
    *List = (*List)->RightNodeLink;
    free((*List)->LeftNodeLink);
    (*List)->LeftNodeLink = NULL;
#endif
}

void Delete_Node_At_End(struct Node *List){
    struct Node *NodeListCounterOne = NULL;
    struct Node *NodeListCounterTwo = NULL;

    NodeListCounterOne = List;
    while(NodeListCounterOne->RightNodeLink != NULL){
        NodeListCounterOne = NodeListCounterOne->RightNodeLink;
    }
    NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
    NodeListCounterTwo->RightNodeLink = NULL;
    free(NodeListCounterOne);
    NodeListCounterOne = NULL;
}

void Delete_Node_At_Intermediate(struct Node *List, uint32 position){
    struct Node *NodeListCounterOne = NULL;
    struct Node *NodeListCounterTwo = NULL;
    uint32 NodePosition = position;

    if(1 == NodePosition){
        printf("Please use the Delete_Node_At_Beginning !! \n");
    }
    else{
        NodeListCounterOne = List;
        while(NodePosition > 1){
            NodeListCounterOne = NodeListCounterOne->RightNodeLink;
            NodePosition--;
        }

        NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
        NodeListCounterTwo->RightNodeLink = NodeListCounterOne->RightNodeLink;
        NodeListCounterOne->RightNodeLink->LeftNodeLink = NodeListCounterTwo;
        free(NodeListCounterOne);
        NodeListCounterOne = NULL;
    }
}

void Display_All_Nodes_Forward(struct Node *List){
    struct Node *TempNode = List;

    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    printf("%d -> ", TempNode->NodeData);
    while(TempNode->RightNodeLink != NULL){
        TempNode = TempNode->RightNodeLink;
        printf("%d -> ", TempNode->NodeData);
    }
    if(NULL == TempNode->RightNodeLink){
        printf("NULL");
    }
    printf("\n");
}

void Display_All_Nodes_Reverse(struct Node *List){
    struct Node *TempNode = List;

    printf("\nTraversal in reverse direction ==> ");
    printf("Data : ");
    while(TempNode->RightNodeLink != NULL){
        TempNode = TempNode->RightNodeLink;
    }
    while(TempNode != NULL){
        printf("%d -> ", TempNode->NodeData);
        TempNode = TempNode->LeftNodeLink;
    }
    if(NULL == TempNode){
        printf("NULL");
    }
    printf("\n");
}












