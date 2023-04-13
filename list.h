#ifndef _LIST_H
#define _LIST_H
#include "platform.h"

struct Node {
    uint32_t nodedata;
    struct Node *nodelink;
};

void Insert_Node_At_Beginning (struct Node **List );
void Insert_Node_At_End (struct Node **List );
void Insert_Node_After (struct Node *List );
void Delete_Node_At_Beginning (struct Node **List );
void Delete_Node (struct Node *List );
void Display_All_Nodes (struct Node *List);
uint32_t getlength (struct Node *List);
#endif // _LIST_H


