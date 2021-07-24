/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:32:40 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/13 17:39:20 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	long	i;
	long	negative;

	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	negative = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative++;
		str++;
	}
	i = 0;
	while (*str >= '0' && *str <= '9')
		i = i * 10 + *str++ - '0';
	if (negative % 2 == 1)
		i *= -1;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	do_op(int argc, char **argv)
{
	if ((argv[2][0] == '/' && argv[3][0] == '0')
			|| (argv[2][0] == '%' && argv[3][0] == '0'))
	{
		if (argv[2][0] == '/')
			write(1, "Stop : division by zero", 23);
		if (argv[2][0] == '%')
			write(1, "Stop : modulo by zero", 21);
	}
	if (argc == 4 && (!((argv[2][0] == '/' && argv[3][0] == '0')
		|| (argv[2][0] == '%' && argv[3][0] == '0'))))
	{
		if (argv[2][0] == '+')
			ft_putnbr(ft_atoi(argv[1]) + ft_atoi(argv[3]));
		else if (argv[2][0] == '-')
			ft_putnbr(ft_atoi(argv[1]) - ft_atoi(argv[3]));
		else if (argv[2][0] == '*')
			ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
		else if (argv[2][0] == '/')
			ft_putnbr(ft_atoi(argv[1]) / ft_atoi(argv[3]));
		else if (argv[2][0] == '%')
			ft_putnbr(ft_atoi(argv[1]) % ft_atoi(argv[3]));
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (argv[2][1] != '\0')
		{
			write(1, "0", 1);
			write(1, "\n", 1);
			return (0);
		}
		else
			do_op(argc, argv);
	}
	else
		return (0);
}
