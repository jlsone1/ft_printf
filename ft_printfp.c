/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:29:46 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/13 14:40:49 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

unsigned long long	counthex(unsigned long long i)
{
	unsigned long long	j;

	if (i < 16)
		return (1);
	else
	{
		j = 0;
		while (i / 16 > 0)
		{
			i = i / 16;
			j++;
		}
		return (j + 1);
	}
}

void	stockhexp(unsigned long long i, unsigned long long *hexp)
{	
	unsigned long long	j;

	if (i < 16)
		hexp[0] = i;
	else
	{	
		j = 0;
		while (i / 16 > 0)
		{
			hexp[j] = i % 16;
			i = i / 16;
			j++;
		}
	hexp[j] = i;
	}
}

int	ft_printfp(unsigned long long i)
{
	unsigned long long	j;
	unsigned long long	*hexp;
	char				*hexcode;
	int					l;

	hexcode = "0123456789abcdef";
	j = counthex(i);
	hexp = malloc(sizeof(unsigned long long) * j);
	if (!hexp)
		return (0);
	stockhexp(i, hexp);
	l = 0;
	write (1, "0x", 2);
	while (l < (int)j)
	{
		write (1, &hexcode[hexp[j - l - 1]], 1);
		l++;
	}
	free (hexp);
	return (l + 2);
}	
