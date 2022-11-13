/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfxX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:44:30 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/13 15:24:04 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

unsigned int	counthexx(unsigned int i)
{
	unsigned int	j;

	if (i < 16)
		return (1);
	j = 0;
	while (i / 16 > 0)
	{
		j++;
		i = i / 16;
	}
	return (j + 1);
}

void	stockhexx(unsigned int i, unsigned int *hex)
{
	unsigned int	j;

	if (i < 16)
		hex[0] = i;
	else
	{
		j = 0;
		while (i / 16 > 0)
		{
			hex[j] = i % 16;
			i = i / 16;
			j++;
		}
		hex[j] = i;
	}
}

int	ft_printfxx(unsigned int i, char format)
{
	char				*hexcodex;
	char				*hexcodexx;
	unsigned int		j;
	unsigned int		*hex;
	int					l;

	hexcodex = "0123456789abcdef";
	hexcodexx = "0123456789ABCDEF";
	j = counthexx(i);
	hex = malloc(sizeof(unsigned int) * j);
	if (!hex)
		return (0);
	stockhexx(i, hex);
	l = 0;
	while (l < (int)j)
	{	
		if (format == 'x')
			write (1, &hexcodex[hex[j - l - 1]], 1);
		else
			write (1, &hexcodexx[hex[j - l - 1]], 1);
		l++;
	}
	free (hex);
	return (l);
}
