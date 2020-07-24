#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,*ptr,*ptr1;
    int n = 5;
    ptr = (int*)malloc(n*sizeof(int));
    ptr1 = (int*)calloc(n,sizeof(int));
    if(ptr==NULL || ptr1 == NULL)
    {
        printf("Memory not allocated successfully\n");
    }
    for(i=0;i<n;i++)
    {
        ptr[i]=i+1;
        ptr1[i] = i+2;
    }
    printf("The elements of both the arrays are : \n");
    printf("Array 1:\n");
    for(i=0;i<n;i++)
        printf("%d ,",ptr[i]);
    printf("\n Array 2:\n");
    for(i=0;i<n;i++)
        printf("%d ,",ptr1[i]);
    free(ptr); //When free is used the whole memory block allocated by malloc/alloc is released to the heap
    free(ptr1);
    printf("\nMemory Successfully deallocated by free() method.") ; 
}