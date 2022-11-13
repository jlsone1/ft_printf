/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:36:13 by javsanch          #+#    #+#             */
/*   Updated: 2022/09/21 13:28:33 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	dst1 = (char *)dst;
	src1 = (char *)src;
	if ((dst == src) || len == 0)
		return (dst);
	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
		return (dst);
	}
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}	
	return (dst);
}
