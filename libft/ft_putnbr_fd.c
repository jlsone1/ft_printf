/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:38:14 by javsanch          #+#    #+#             */
/*   Updated: 2022/10/14 17:12:28 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	zero(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		ft_putstr_fd ("-2147483648", fd);
	if (n == 0)
		ft_putstr_fd ("0", fd);
	if (n == 0 || n == -2147483648)
	i = 1;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 1000000000;
	if (zero (n, fd) == 1)
		return ;
	if (n < 0 && n != -2147483648)
	{	
		n = -n;
		ft_putchar_fd ('-', fd);
	}
	while (n / i == 0 && n > 0)
	{
		n = n % i;
		i = i / 10;
	}
	while (i != 1 && n != -2147483648)
	{
		ft_putchar_fd (n / i + 48, fd);
		n = n % i;
		i = i / 10;
	}
	if (i == 1)
		ft_putchar_fd (n + 48, fd);
}
