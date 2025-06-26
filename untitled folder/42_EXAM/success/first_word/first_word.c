
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        char *s = argv[1];

        while (s[i] && s[i] == ' ')
            i++;
        while (s[i] && s[i] != ' ')
        {
            write (1, &s[i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}