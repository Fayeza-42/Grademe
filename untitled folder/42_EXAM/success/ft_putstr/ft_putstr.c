#include <unistd.h>

void	ft_putstr(char *str)
{
    if(!str)
        return ;
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
