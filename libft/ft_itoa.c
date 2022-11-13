/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:03:38 by javsanch          #+#    #+#             */
/*   Updated: 2022/10/20 14:40:52 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	countnumbers(int n)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	j = 1000000000;
	if (n == 0)
		return (1);
	if (n < 0)
		z++;
	while (n / j == 0)
	{
		j = j / 10;
		i++;
	}
	z = 10 - i + z;
	return (z);
}

static int	negsplit(char *c, int n)
{
	int	i;
	int	j;

	j = 1000000000;
	i = 0;
	if (n < 0)
	{
		c[i] = '-';
		i++;
	}
	return (i);
}

static char	*tostring(char *c, int n, int i)
{
	int	j;

	j = 1000000000;
	if (n == -2147483648)
	{
		c[i] = (n / j * -1) + 48;
		n = n % j * -1;
		j = j / 10;
		i++;
	}
	if (n < 0)
		n = n * -1;
	while (n / j == 0)
		j = j / 10;
	while (j > 0)
	{
	c[i] = n / j + 48;
	n = n % j;
	j = j / 10;
	i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*c;

	if (n == 0)
	{
		c = malloc(sizeof(char) * 2);
		if (!c)
			return (NULL);
		c[0] = '0';
		c[1] = '\0';
		return (c);
	}
	else
		c = malloc(sizeof(char) * (countnumbers(n) + 1));
	if (!c)
		return (NULL);
	tostring (c, n, negsplit (c, n));
	return (c);
}
