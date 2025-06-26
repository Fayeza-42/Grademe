
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *s = argv[1];
        int i = 0;
        while (s[i])
        {
            int j;
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                j = s[i] - 'a' + 1;
                while (j != 0)
                {
                    write (1, &s[i], 1);
                    j--;
                }
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                j = s[i] - 'A' + 1;
                while (j != 0)
                {
                    write (1, &s[i], 1);
                    j--;
                }
            }
            else
                write (1, &s[i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
}