void	ft_putchar(char c);

void	ft_print_line(char a, char b, char c, int size)
{
	int	i;

	i = -1;
	ft_putchar(a);
	while (++i < size - 2)
		ft_putchar(b);
	if (size >= 2)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = -1;
	if (x <= 0 || y <= 0)
		return ;
	ft_print_line('A', 'B', 'A', x);
	while (++i < y - 2)
		ft_print_line('B', ' ', 'B', x);
	if (y >= 2)
		ft_print_line('A', 'B', 'A', x);
}
