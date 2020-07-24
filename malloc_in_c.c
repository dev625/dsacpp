#include <stdio.h>
#include <stdlib.h>
/*C Dynamic memory allocation can be defined as 
a procedure in which the size of a data structure
like Array can be changed during runtime*/

/*malloc syntax : 
    ptr = (cast-type*)malloc(byte-size)
malloc returns a pointer of type void which can be
cast into a pointer of any form. Default 
Initialization values are garbage values.
If space is insufficient allocation fails and
returns a NULL pointer.*/
int main()
{
    int *ptr;
    int n,i;
    n = 5;
    printf("Enter the number of elements: %d\n",n);
    ptr = (int*)malloc(n * sizeof(int));
    //Check if pointer has been sucessfully allocated 
    //by malloc or not
    if(ptr==NULL){
        printf("Memory not Allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory has been successfully allocated using malloc.\n");
        for(i=0;i<n;i++)
        {
            ptr[i] = i+1;
        }
        printf("The elements of the array are:\n");
        for(i=0;i<n;i++)
        {
            printf("%d, ",ptr[i]);
        }
    }
    return 0;
    
}
