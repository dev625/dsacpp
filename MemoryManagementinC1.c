#include <stdio.h>
/*bss is used by many compilers and linkers
for the portion of an object file or executable
containing statically-allocated variables that are not
explicitly initialized to any value.*/

int global;

int main(void)
{
    static int i;
    return 0;
}
/*Outputs 
text    data     bss     dec     hex filename
1418     544       8    1970     7b2 memory-layout*/

/*Uninitialzed static an global variables are stored in the bss*/

/* Updated output after adding 2 vars :
text    data     bss     dec     hex filename
1418     544       8    1970     7b2 memory-layout*/