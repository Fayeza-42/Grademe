#include <stdio.h>
#include <stdlib.h>
int value(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int len(int n)
{
    int i = 1;
    if (n <= 0)
        i++;
    while (n / 10)
    {
        i++;
        n = n / 10;
    }
    return (i);
}

char	*ft_itoa(int nbr)
{
    int l = len(nbr);
    char *result;
    result = malloc (sizeof(char) * (l + 1));
    if (!result)
        return (NULL);
    result[l] = '\0';
    int sign = 0;
    if (nbr < 0)
    {
        result[0] = '-';
        sign = 1;
    }
    else if (nbr == 0)
    {
        return ("0");
    }
    while (l > 0 + sign)
    {
        l--;
        result[l] = (value(nbr) % 10) + '0';
        nbr = nbr / 10;
    }
    return (result);
}

// int main()
// {
//     int i = 12323;
//     printf("%d\n", i);
//     char *s = ft_itoa(i);
//     printf("%s\n", s);
// }