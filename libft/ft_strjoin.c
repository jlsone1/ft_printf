/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:09:55 by javsanch          #+#    #+#             */
/*   Updated: 2022/10/05 12:35:41 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	c = malloc(sizeof(char) * ((i + j) + 1));
	i = 0;
	if (!c)
		return (NULL);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		c[i] = s2[j];
		j++;
		i++;
	}
	c[i] = '\0';
	return (c);
}
