/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:21:45 by javsanch          #+#    #+#             */
/*   Updated: 2022/10/20 15:17:31 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	cs1insetstart(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		z;

	i = 0;
	z = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				i++;
				z++;
				j = 0;
			}
			else
				j++;
		}
		if (z > 0)
			return (i);
		break ;
	}
	return (0);
}

static size_t	cs1insetend(char const *s1, char const *set)
{
	long long	i;
	size_t		j;
	size_t		z;

	i = ft_strlen(s1) - 1;
	z = 0;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
			i--;
			j = 0;
			z++;
			}
			else
			j++;
		}
		if (z > 0)
			return (i);
		return (ft_strlen(s1) - 1);
	}
	return (0);
}

static void	copytrim(char *c, const char *s1, size_t i, size_t j)
{
	size_t	z;

	z = 0;
	while (i <= j)
	{
		c[z] = s1[i];
		i++;
		z++;
	}
	c[z] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*c;
	size_t	end;
	size_t	start;

	if (cs1insetstart(s1, set) == ft_strlen(s1))
	{
		c = malloc(sizeof(char) * 1);
		c[0] = '\0';
		return (c);
	}
	else
	{
		end = cs1insetend(s1, set);
		start = cs1insetstart (s1, set);
		c = malloc(sizeof(char) * ((end - start) + 2));
	}
	if (!c)
		return (NULL);
	copytrim (c, s1, cs1insetstart (s1, set), cs1insetend (s1, set));
	return (c);
}
