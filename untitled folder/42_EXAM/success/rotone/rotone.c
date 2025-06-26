
#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    if(argc == 2)
    {
        char *s = argv[1];
        while(s[i])
        {
            if((s[i] >= 'a' && s[i] < 'z') || (s[i] >= 'A' && s[i] < 'Z'))
                s[i] += 1;
            else if(s[i] == 'z')
                s[i] = 'a';
            else if(s[i] == 'Z')
                s[i] = 'A';
            write(1, &s[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}