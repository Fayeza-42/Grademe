
#include <unistd.h>

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return(i);
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        char *s = argv[1];
        int i = 0;
        int len = ft_strlen(s);
        len--;
        while(s[len] == ' ' && len != 0)
            len--;
        while(s[len] != ' ' && len != 0)
            len--;
        len++;
        while(s[len] && s[len] != ' ')
        {
            write(1, &s[len], 1);
            len++;
        }
    }
    write(1, "\n", 1);
}