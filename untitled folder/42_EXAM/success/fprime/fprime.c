
#include <stdlib.h>
#include <stdio.h>

void    fprime(unsigned int n)
{
    if(n % 2 == 0)
    {
        printf("2*");
        n = n / 2;
    }
    int i = 3;
    while(n > i)
    {
        while(n % i == 0)
        {
            printf("%d*", i);
            n = n / i;
        }
        i += 2;
    }
        printf("%d", n);
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        unsigned int i = atoi(argv[1]);
        if((int)i > 0)
            fprime(i);
    }
    printf("\n");
}