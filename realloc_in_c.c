#include <stdio.h>
#include <stdlib.h>

/* realloc is used to dynamically change the memory allocation
of a previously allocated memory. reallocation of memory maintains
the already present value and new blocks will be initialized
with default garbage value
Syntax : 
ptr = realloc(ptr, newSize);
If space is insufficient, allocation fails and returns 
a NULL pointer.
*/

int main()
{
    int *ptr;
    int n,i;
    n = 5;
    printf("Enter the number of elements: %d\n",n);
    ptr = (int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using calloc.\n");
        for(i=0;i<n;i++)
        {
            ptr[i]= i+1;
        }
        printf("The elements of the array are :\n");
        for(i=0;i<n;i++)
            printf("%d ,",ptr[i]);
        n = 10; //new size of the array
        printf("Enter the new size of the array : %d \n",n);
        ptr = realloc(ptr,n*sizeof(int));
        printf("Memory successfully reallocated using realloc.\n");
        for(i=5;i<n;i++)
        {
            ptr[i] = i+1;
        }
        printf("The updated elements of the array are :\n");
        for(i=0;i<n;i++)
        {
            printf("%d , ",ptr[i]);
        }
        free(ptr);
    }
    return 0;
    
}