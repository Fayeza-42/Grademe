#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        char *s1 = argv[1];
        char *s2 = argv[2];
        int i = 0;
        int k = 0;
        int j;
        while(s1[i])
        {
            j = 0;
            while(s2[j])
            {
                if(s1[i] == s2[j])
                {
                    k = 0;
                    while(s1[i] != s1[k])
                        k++;
                    if(i == k)
                    {
                        k = 0;
                        while(s2[j] != s2[k])
                        {
                            k++;
                        }
                        if(k == j)
                        {
                            write(1, &s1[i], 1);
                        }
                    }
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}