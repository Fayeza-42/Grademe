 #include <unistd.h>
void ft_putchar (char c)
{
	write(1, &c, 1);
}
void put_nbr(int x)
{


	if (x >= 10)
	{
		put_nbr(x / 10);
		put_nbr(x % 10);
	}
	else if (x < 10)
	{
		ft_putchar(x + '0');
	}
}
int main(int argc, char **argv)
{
	(void)argv;
	put_nbr(argc - 1);
	ft_putchar('\n');
}



