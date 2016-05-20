#include<stdio.h>
#define SIZE(sort) sizeof((sort)) / sizeof(int);

void bubbleSort(int [],int);
void swap(int*,int*);
void main()
{
    int i;
    int sort[] = {100,23,120,64,8,10,22,98,66,32,10};
    int size = SIZE(sort);

    for(i = 0; i < size; ++i)
    {
        printf("%d ",sort[i]);
    }

    printf("\n\n");

    bubbleSort(sort,size);

    for(i = 0; i < size; ++i)
    {
        printf("%d ",sort[i]);
    }
}

void bubbleSort(int sort[],int size)
{
    int i,j;

    for(i = 1; i < size; ++i)
    {
        for(j = 0; j < size - i; ++j)
        {

            if(sort[j] > sort[j+1])
                swap(sort+j,sort+j+1);
        }
    }
}

void swap(int *a,int *b)
{
    int swap = *a;
    *a = *b;
    *b = swap;
}
