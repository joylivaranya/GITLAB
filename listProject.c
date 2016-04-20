//
//  listProject.c
//  Code
//
//  Created by Siva on 4/8/2557 BE.
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
STUDENT_T* pHead=NULL;
STUDENT_T* pTail=NULL;
void askChoice();
int insertTail();
int insertHead();
int insertMiddle();
int removeData();
void printList();
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
        printf("\n1.Insert a data at tail\n");
        printf("2.Insert a data at head\n");
        printf("3.Insert a data at middle\n");
        printf("4.Print list\n");
        printf("5.Remove a data\n");
        printf("6.Exit program\n\n");
        printf("Please enter the choice: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%d",&choice);
        switch(choice)
            {
            case 1:
                {
                bok=insertTail();
                break;
                }
            case 2:
                {
                bok=insertHead();
                break;
                }
            case 3:
                {
                bok=insertMiddle();
                break;
                }
            case 4:
                {
                printList();
                break;
                }
            case 5:
                {
                removeData();
                break;
                }
            case 6:
                {
                exit (0);
                }
            }
        }while(1);
    }
int removeData()
    {
    STUDENT_T* pSearch=pHead;
    STUDENT_T* pPrevious=NULL;
    int bok=0;
    char input[36];
    char removeName[36];
    if(pHead==NULL)
        {
        printf("Sorry, there is no member in the list\n");
        return bok;
        }
    printf("Please enter the name you want to remove: ");
    fgets(input,sizeof(input),stdin);
    sscanf(input,"%s",removeName);
    do
        {
        if(strcasecmp(pSearch->name,removeName)==0)
            {
            printf("Found %s\n",pSearch->name);
            break;
            }
        else
            {
            pPrevious=pSearch;
            pSearch=pSearch->pNext;
            }
        if(pSearch==NULL)
            {
            printf("Sorry, there is no student named \"%s\" in the list\n",removeName);
            return bok;
            }
        }while(1);
        /*the target to erase is head*/
        if(pPrevious==NULL)
            {
            pHead=pSearch->pNext;
            }
        /*the target to erase is on the middle*/
        else
            {
            pPrevious->pNext=pSearch->pNext;
            }
        /*the target to erase is on the tail*/
        if(pSearch==pTail)
            {
            pTail=pPrevious;
            }
        free(pSearch);
        printf("Erase: \"%s\" completed\n",removeName);
    }
int insertTail()
    {
    int bok=1;
    char input[36];
    STUDENT_T* pStudent=NULL;
    do
        {
        pStudent=(STUDENT_T*) calloc(1,sizeof(STUDENT_T));
        printf("Please enter the name and grade of that student: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%s %d",pStudent->name,&pStudent->grade);
        if(strcasecmp(pStudent->name,"-1")==0)
            {
            return bok;
            }
        else
            {
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
int insertHead()
    {
    int bok=1;
    STUDENT_T* pStudent=NULL;
    char input[36];
    do
        {
        pStudent=(STUDENT_T*) calloc(1,sizeof(STUDENT_T));
        printf("Please enter the name and grade of that student: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%s %d",pStudent->name,&pStudent->grade);
        if(strcasecmp(pStudent->name,"-1")==0)
            {
            return bok;
            }
        else
            {
            if(pHead==NULL)
                {
                pHead=pStudent;
                }
            else
                {
                pStudent->pNext=pHead;
                pHead=pStudent;
                }
            }
        }while(1);
    }
int insertMiddle()
    {
    int bok=1;
    STUDENT_T* pStudent=NULL;
    char input[36];
    do
        {
        pStudent=(STUDENT_T*) calloc(1,sizeof(STUDENT_T));
        printf("Please enter the name and grade of that student: ");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%s %d",pStudent->name,&pStudent->grade);
        if(strcasecmp(pStudent->name,"-1")==0)
            {
            return bok;
            }
        else
            {
            if((pHead==NULL)||(pTail==NULL))
                {
                bok=-1;
                printf("Please insert head first\n");
                return bok;
                }
            else
                {
                
                }
            }
        }while(1);
    }
void printList()
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

