/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:52:46 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/13 14:28:45 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printfud(unsigned int i)
{
	int				l;
	unsigned int	j;
	int				u;

	j = 1000000000;
	l = 0;
	while (i / j == 0)
		j = j / 10;
	while (j >= 10)
	{
		u = (int)(i / j) + 48;
		write (1, &u, 1);
		l++;
		if (j == 10)
		{
			u = (int)(i % j) + 48;
			write (1, &u, 1);
			l++;
		}
		i = i % j;
		j = j / 10;
	}	
	return (l);
}

int	ft_printfu(unsigned int i)
{
	int	u;
	int	l;

	if (i < 10)
	{
		u = (int)i + 48;
		write (1, &u, 1);
		return (1);
	}
	l = ft_printfud(i);
	return (l);
}	
