#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct _List{
    int data;
    struct _List *next;
} List;

List * initList(void);

bool insertList(List *,int,int);

int searchList(List *,int);

void foreachList(List *);

void emptyList(List *);



int main()
{
    List *pHead = NULL;
    bool insert = false;
    int position = 0;

    pHead = initList();

    if(pHead == NULL)
        return 0;

    insert = insertList(pHead,1232,3);

    if(insert == false)
        return false;

    position = searchList(pHead,1232);

    printf("position is %d\n",position);

    foreachList(pHead);
}

List * initList(void)
{
    List *head = (List *)malloc(sizeof(List));

    if(head == NULL)
    {
        printf("³õÊ¼»¯Á´±íÊ§°Ü!\n");
        return NULL;
    }

    head->data = 0;
    head->next = NULL;

    return head;
}

bool insertList(List *head,int data,int position)
{
    List *element = (List *)malloc(sizeof(List));

    if(element == NULL)
    {
        printf("²åÈëÁ´±íÊ§°Ü\n");
        return false;
    }
    element->data = data;
    element->next = NULL;

    int _position = 1;
    while(_position++ != position && head->next != NULL)
        head = head->next;

    element->next = head->next;
    head->next = element;

    return true;
}

int searchList(List *head,int value)
{

    int _position = 0;
    while(head != NULL)
    {

        if(head->data == value)
            return _position;

        head = head->next;
        ++_position;
    }

    return 0;
}

void emptyList(List *head)
{
    List *pList = NULL;
    while(head != NULL)
    {
       pList = head->next;
       free(head);
       head = pList;
    }
}

void foreachList(List *head)
{
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}
