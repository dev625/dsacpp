#include <stdio.h>
#include <stdlib.h>


/*calloc is used in C to dynamically allocated
the speciifed number of blocks of memory of specified
type. Each block is initialized with default val 0

Syntax:
    ptr = (cast-type*)calloc(n,element-size);
    Eg:
    ptr = (float*)calloc(25,sizeof(float));
    This statement allocates contiguous space
    in memory for 25 elemetns each with the size
    of float.
    If space is insufficient allocation fails and
    returns a NULL pointer.
*/

int main()
{
    int *ptr;
    int i,n = 5;
    printf("Enter the number of array elements: %d \n",n);
    ptr = (int*)calloc(5,sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated:\n");
        exit(0);
    }
    else{
    printf("Memory successfully allocated by calloc method.");
    for(i=0;i<n;i++)
    {
        ptr[i]=i+1;
    }
    printf("The array elements are as follows:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }
    }
}