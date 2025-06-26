

int space(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

int value(char c)
{
    if (c >= '0' && c <= '9')
        return(c - '0');
    else if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (0);
}

int valid(char c, int base)
{
    char s1[17] = "0123456789abcdef";
    char s2[17] = "0123456789ABCDEF";

    while (base--)
    {
        if (s1[base] == c || s2[base] == c)
            return (1);
    }
    return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    while (str[i] && space(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (valid(str[i], str_base))
    {
        result = result * str_base + value (str[i]);
        i++;
    }
    return (sign * result);
}
// #include <stdio.h>
// int main()
// {
//     int i = ft_atoi_base("ff", 16);
//     printf("%d", i);
// }