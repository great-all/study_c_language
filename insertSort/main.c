#include <stdio.h>
#include <stdlib.h>

#define SIZE(sort) sizeof((sort)) / sizeof(int)

void insertSort(int [],int size);

void swap(int *,int*);

int main()
{
    int sort[] = {8,2,10,11,32,19,100,21,83,76,92};
    int i,size = SIZE(sort);

    for(i = 0 ; i < size; ++i)
        printf("%d ",sort[i]);

    printf("\n\n");

    insertSort(sort,size);

    for(i = 0 ; i < size; ++i)
        printf("%d ",sort[i]);
}

void insertSort(int sort[],int size)
{
    int i;
    for(i = 1; i < size; ++i)
    {
        int key = sort[i];
        int j = i - 1;
        while(j >= 0 && sort[j] > sort[j+1]){
            swap(sort+j,sort+j+1);
            --j;
        }

        sort[j+1] = key;
    }
}

void swap (int *a ,int *b)
{
    int swap = *a;
    *a = *b;
    *b = swap;
}
