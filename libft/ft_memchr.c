/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:02:46 by javsanch          #+#    #+#             */
/*   Updated: 2022/10/03 13:54:19 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;
	unsigned char	nn;

	i = 0;
	ss = (unsigned char *)s;
	nn = (unsigned char)c;
	while (i < n)
	{
		if (ss[i] == nn)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
