/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:37:41 by javsanch          #+#    #+#             */
/*   Updated: 2022/09/27 14:46:24 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		src_len;
	size_t		dst_len;
	size_t		z;
	size_t		j;

	z = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = src_len + dst_len;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	if (src_len == 0)
		return (dst_len);
	while (src[z] != '\0' && dst_len < dstsize - 1)
	{
		dst[dst_len] = src[z];
		dst_len++;
		z++;
	}
	dst[dst_len] = '\0';
	return (j);
}	
