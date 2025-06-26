
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        unsigned int i = atoi(argv[1]);
        unsigned int j = atoi(argv[2]);
        unsigned int k = 1;
        unsigned int l;
        while(i / k && j / k)
        {
            if(i % k == 0 && j % k == 0)
            {
                l = k;
            }
            k++;
        }
        printf("%d", l);
    }
    printf("\n");
}
