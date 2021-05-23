#include <stdio.h>
#include <stdlib.h>



int main(){
    int i = 9;
    printf("%d %d %d\n", i++, --i, i++);
    i = 9;
    printf("%d\n", i++);
    printf("%d\n", --i);
    printf("%d\n", i++);
    return 0;
}
