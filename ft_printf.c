/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:45:41 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/10 09:15:03 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft/libft.h"

int	ft_conver(va_list(args), char format)
{
	int	l;

	l = 0;
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		l++;
	}
	else if (format == 's')
		l = ft_printfstr(va_arg(args, char *));
	else if (format == '%')
		l = ft_printfper('%');
	else if (format == 'p')
		l = ft_printfp(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		l = ft_printfdi(va_arg(args, int));
	else if (format == 'u')
		l = ft_printfu(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		l = ft_printfxx(va_arg(args, unsigned int), format);
	return (l);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		l;
	va_list	args;

	va_start (args, s);
	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			l = l + ft_conver(args, s[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			l++;
		}
		i++;
	}
	va_end(args);
	return (l);
}
