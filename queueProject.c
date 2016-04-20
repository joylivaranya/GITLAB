//
//  queueProject.c
//  Code
//
//  Created by Siva on 3/22/2557 BE.
//  Copyright (c) 2557 Siva. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _student
    {
    char name[36];
    int grade;
    struct _student* pNext;
    }STUDENT_T;
/*Global variable*/
STUDENT_T* pHead=NULL;
STUDENT_T* pTail=NULL;
/*Public functions*/
void askChoice();
int enqueue();
void* dequeue();
void listMember();
int emptyList();
void destroyList();
/*Main function*/
int main(int argc,char* argv[])
    {
    askChoice();
    }
void askChoice()
    {
    char input[36];
    int choice=0;
    int bok=0;
    do
        {
        printf("\nStudent queue program\n");
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.List member\n");
        printf("4.Empty list\n");
        printf("5.Exit program\n\n");
        printf("Please enter a choice: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%d",&choice);
        switch(choice)
            {
            case 1:
                {
                bok=enqueue();
                break;
                }
            case 2:
                {
                STUDENT_T* pDequeue=dequeue();
                break;
                }
            case 3:
                {
                listMember();
                break;
                }
            case 4:
                {
                bok=emptyList();
                break;
                }
            case 5:
                {
                printf("This program exited\n");
                destroyList();
                exit (0);
                }
            }
        }while(1);
    }
int enqueue()
    {
    char name[36];
    char input[36];
    int grade=0;
    int bok=1;
    STUDENT_T* pStudent=NULL;
    do
        {
        printf("Please enter name and grade of that student: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%s %d",name,&grade);
        if(strcasecmp(name,"-1")==0)
            {
            return bok;
            }
        else
            {
            pStudent=(STUDENT_T*) calloc (1,sizeof(STUDENT_T));
            if(pStudent==NULL)
                {
                printf("Allocation failed\n");
                exit (0);
                }
            strcpy(pStudent->name,name);
            pStudent->grade=grade;
            if(pHead==NULL)
                {
                pHead=pStudent;
                }
            else
                {
                pTail->pNext=pStudent;
                }
            pTail=pStudent;
            }
        }while(1);
    }
void* dequeue()
    {
    void* data=NULL;
    STUDENT_T* pDequeue=pHead;
    if(pDequeue!=NULL)
        {
        data=pHead;
        pHead=pDequeue->pNext;
        free(pDequeue);
        printf("Dequque completed\n");
        printf("This will return %s\n",data);
        }
    return data;
    }
void listMember()
    {
    int i=0;
    STUDENT_T* pPrint=NULL;
    pPrint=pHead;
    while(pPrint!=NULL)
        {
        printf("%d.%s %d\n",i+1,pPrint->name,pPrint->grade);
        pPrint=pPrint->pNext;
        i++;
        }
    }
int emptyList()
    {
    STUDENT_T* pEmpty=pHead;
    while(pEmpty!=NULL)
        {
        if(dequeue()==NULL)
            {
            printf("The List has already been reseted\n");
            return 1;
            }
        }
    }
void destroyList()
    {
    STUDENT_T* pDelete=pHead;
    while(pDelete!=NULL)
        {
        free(pDelete);
        pDelete=pDelete->pNext;
        }
    }