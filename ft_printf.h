/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:35:35 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/13 14:22:28 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_conver(va_list(args), char format);
int	ft_printf(const char *s, ...);
int	ft_printfstr(char *s);
int	ft_printfper(char c);
int	ft_printfdi(int i);
int	ft_printfp(unsigned long long i);
int	ft_printfu(unsigned int i);
int	ft_printfxx(unsigned int i, char format);

#endif
