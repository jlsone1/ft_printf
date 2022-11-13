/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:00:31 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/11 12:20:16 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printfdi(int i)
{
	char	*number;
	int		l;

	number = ft_itoa(i);
	l = ft_printfstr(number);
	free (number);
	return (l);
}	
