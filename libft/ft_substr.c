/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:16:49 by javsanch          #+#    #+#             */
/*   Updated: 2022/10/05 11:23:29 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	if (ft_strlen(s) < start)
	{
		c = malloc(sizeof(*s) * 1);
		c[0] = '\0';
		return (c);
	}
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	c = malloc(sizeof(*s) * (len + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (i < len)
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
