#include <stdio.h>
#include <stdlib.h>

/*fflush is typically used for output stream only, it is used
to clear/flush the output buffer and move the buffered data
to console (in case of stdout) or disk (in case of file output
stream.*/

/*As per C standard it is undefined behavior to use
fflush(stdin) but some compilers such as VS allow it,
while taking string input with spaces, the buffer does not
get cleared for the nextr input and considers the previous
input for the same. To solve this problem fflush(stdin)
is used*/

int main()
{
    char str[20];
    int i;
    for (i=0;i<2;i++)
    {
        scanf("%[^\n]s", str);
        fflush(stdin); //this gives undefined behaviour as per C++ 11 standard on my machien
        printf("%s\n", str);
    }
    return 0;
}