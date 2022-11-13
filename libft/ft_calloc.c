/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:42:55 by javsanch          #+#    #+#             */
/*   Updated: 2022/10/28 13:58:35 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*a;
	size_t			i;
	void			*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	i = 0;
	ptr = malloc(count * size);
	a = (unsigned char *)ptr;
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		a[i] = '\0';
		i++;
	}
	return (ptr);
}
