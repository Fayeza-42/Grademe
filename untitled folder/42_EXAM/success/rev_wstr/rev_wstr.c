#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        char *new;
        int i = 0;
        while(argv[1][i])
            i++;
        new = malloc (sizeof(char) * (i + 1));
        if(!new)
            return(1);
        new[i] = '\0';
        i--;
        int j= 0;
        int k = 0;
        char *s = argv[1];
        while(i >= 0)
        {
            while( i >= 0 && s[i] != ' ' )
                i--;
            i++;
            j = i;
            while(s[j] && s[j] != ' ')
            {
                new[k++] = s[j++];
            }
            if (i != 0)
                new[k++] = ' ';
            i--;
            i--;
        }
        k = 0;
        while(new[k])
        {
            write(1, &new[k], 1);
            k++;
        }
        free (new);
    }
    write(1, "\n", 1);
}