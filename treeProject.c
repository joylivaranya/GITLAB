//
//  treeProject.c
//  Code
//
//  Created by Siva on 3/23/2557 BE.
//  Copyright (c) 2557 Siva. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _queue
    {
    void* data;
    struct _queue* pNext;
    }QUEUE_T;
typedef struct _node
    {
    char name[36];
    int grade;
    struct _node* pLeft;
    struct _node* pRight;
    }NODE_T;
typedef struct _tree
    {
    NODE_T* pRoot;
    }TREE_T;
    QUEUE_T* pHead=NULL;
NODE_T* pRoot=NULL;
QUEUE_T* pTail=NULL;
TREE_T* pTree=NULL;
void* dequeue();
void askChoice();
void enqueue();
void printNode(NODE_T* pNode);
int insertNode(NODE_T* pRoot,NODE_T* pStudent);
int insertRoot();
void createTree();
void traverseInOrder(NODE_T* pCurrent,void (*nodeFunction)(NODE_T* pNode ));
int main(int argc,char* argv[])
    {
    askChoice();
    }
void askChoice()
    {
    int bok=0;
    char input[36];
    int choice=0;
    do
        {
        printf("\n1.Create tree\n");
        printf("2.Insert node\n");
        printf("3.Remove node\n");
        printf("4.Recreate a tree\n");
        printf("5.Print node\n");
        printf("6.Exit the program\n\n");
        printf("Please enter the choice: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%d",&choice);
        switch(choice)
            {
            case 1:
                {
                createTree();
                break;
                }
            case 2:
                {
                bok=insertRoot();
                break;
                }
            case 3:
                {
                }
            case 4:
                {
                }
            case 5:
                {
                
                traverseInOrder(pTree->pRoot,&printNode);
                }
            case 6:
                {
                exit(0);
                }
            }
        }while(1);
    }
void enqueue(void* data)
        {
        QUEUE_T* pQueue=NULL;
        pQueue=(QUEUE_T*) calloc(1,sizeof(QUEUE_T));
        pQueue=data;
        if(pHead==NULL)
            {
            pHead=pQueue;
            }
        else
            {
            pTail->pNext=pQueue;
            }
        pTail=pQueue;
        }
void* dequeue()
        {
        QUEUE_T* pDequeue=pHead;
        void* data=NULL;
        if(pHead!=NULL)
            {
            data=pHead;
            pHead=pDequeue->pNext;
            free(pDequeue);
            }
        return data;
        }
void createTree()
        {
        pTree=(TREE_T*) calloc(1,sizeof(TREE_T));
        printf("The tree has already been created\n");
        }
int insertRoot()
        {
        char name[36];
        char input[36];
        int grade=0;
        NODE_T* pStudent=NULL;
        do
            {
            printf("Please enter the name and grade of that student: ");
            fgets(input,sizeof(input),stdin);
            sscanf(input,"%s %d",name,&grade);
            if(strcasecmp(name,"-1")==0)
                {
                return 0;
                }
            else
                {
                pStudent=(NODE_T*) calloc(1,sizeof(NODE_T));
                strcpy(pStudent->name,name);
                pStudent->grade=grade;
                if(pTree->pRoot==NULL)
                    {
                    pTree->pRoot=pStudent;
                    }
                else
                    {
                    insertNode(pTree->pRoot,pStudent);
                    }
                }
            }while(1);
        }
int insertNode(NODE_T* pRoot,NODE_T* pStudent)
    {
    NODE_T* pNextNode=NULL;
    enqueue(pRoot);
    while((pNextNode=dequeue())!=NULL)
        {
        if(pNextNode->pLeft==NULL)
            {
            pNextNode->pLeft=pStudent;
            }
        else if(pNextNode->pRight==NULL)
            {
            pNextNode->pRight=pStudent;
            }
        else
            {
            enqueue(pNextNode->pLeft);
            enqueue(pNextNode->pRight);
            }
        }
    }
void printNode(NODE_T* pNode)
    {
  
    printf("%s %d\n",pNode->name,pNode->grade);
    }
void traverseInOrder(NODE_T* pCurrent,void (*nodeFunction)(NODE_T* pNode ))
    {
        
    if (pCurrent->pLeft != NULL)
        {
        traverseInOrder(pCurrent->pLeft,nodeFunction);
        }
    (*nodeFunction)(pCurrent);
    if (pCurrent->pRight != NULL)
        {
        traverseInOrder(pCurrent->pRight,nodeFunction);
        }
    }


