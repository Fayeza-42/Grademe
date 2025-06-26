
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(int c, int i)
{
    i++;
    write(1, &c, 1);
    return(i);
}

int ft_found_s(char *s, int i)
{
    int j = 0;
    if (!s)
        i = ft_found_s("(null)", i);
    while (s && s[j])
    {
        i = ft_putchar(s[j], i);
        j++;
    }
    return (i);
}

int ft_found_x(unsigned int d, int i)
{
    if (d == 0)
        i = ft_putchar('0', i);
    else if (d >= 16)
    {
        i = ft_found_x(d / 16, i);
        i = ft_found_x(d % 16, i);
    }
    else
    {
        if (d >= 9)
            i = ft_putchar(d + 'a' - 10, i);
        else 
            i = ft_putchar(d + '0', i);
    }
    return (i);
}


int ft_found_d(int d, int i)
{
    if (d == -2147483648)
        i = ft_found_s("-2147483648", i);
    else if (d < 0)
    {
        i = ft_putchar('-', i);
        i = ft_found_d(-d, i);
    }
    else if (d >= 0 && d < 10)
        i = ft_putchar(d + '0', i);
    else 
    {
        i = ft_found_d(d / 10, i);
        i = ft_found_d(d % 10, i);
    }
    return (i);
}

int ft_printf(const char *format, ... )
{
    va_list args;
    int i = 0;
    int j = -1;

    va_start(args, format);
    while (format[++j])
    {
        if (format[j] == '%')
        {
            j++;
            if (format[j] == 's')
                i = ft_found_s(va_arg(args, char *), i);
            else if (format[j] == 'd')
                i = ft_found_d(va_arg(args, int), i);
            else if (format[j] == 'x')
                i = ft_found_x(va_arg (args, unsigned int), i);
        }
        else
            i = ft_putchar (format[j], i);
    }
    va_end(args);
    return(i);
}


// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
//     ft_printf ("--toto-wiurwuyrhwrywuier%s", NULL);
// }