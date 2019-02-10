#include <stdio.h>
#include <stdlib.h>

int sum(int i){
    return ++i;
}

int main()
{
    printf("Hello world!\n");

    for(int i=0; i<=1; i++){
        printf("%d", sum(i));
    }
    return 0;
}
