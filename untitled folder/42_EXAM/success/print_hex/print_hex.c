
#include <unistd.h>

int     ft_atoi(char *s)
{
    int i = 0;
    int sign = 1;
    int n = 0;
    if (s[i] == '-' || s[i] == '+')
    {
        if(s[i] == '-')
            sign = -1;
        i++;
    }
    while(s[i] >= '0' && s[i] <= '9')
    {
        n = (n * 10) + (s[i] - '0');
        i++;
    }
    return (n * sign);
}

void print_hex(int n)
{
    char hex[] = "0123456789abcdef";
    if(n >= 16)
    {
        print_hex(n / 16);
        print_hex(n % 16);
    }
    else 
        write(1, &hex[n % 16], 1);
}
#include <stdio.h>
int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i = ft_atoi(argv[1]);
        print_hex(i);
    }
    write(1, "\n", 1);
}