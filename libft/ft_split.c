/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:04:11 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/02 12:18:48 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	lensplit2(char const *s, char c)
{
	int	i;
	int	m;

	i = 0;
	while (s[i] == c)
		i++;
	m = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
		{
			m++;
		}
	i++;
	}
	return (m);
}

static size_t	countchars(char const *s, char c, int i)
{
	int	m;

	m = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		m++;
		i++;
	}
	return (m);
}

static char	**getout(char **split2, int m)
{
	m--;
	while (m >= 0)
	{
		free(split2[m]);
		m--;
	}
	free (split2);
	return (NULL);
}

static char	**spliting2(char const *s, char **split2, char c)
{
	int	i;
	int	m;

	i = 0;
	while (s[i] == c)
		i++;
	m = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != '\0' && i == 0 && s[i] != c)
			|| (s[i - 1] == c && s[i] != c && s[i] != '\0'))
		{
		split2[m] = malloc(sizeof(char ) * (countchars(s, c, i) + 1));
			if (!split2[m])
				getout(split2, m);
		split2[m] = ft_memmove(split2[m], &s[i], countchars(s, c, i));
		split2[m][countchars(s, c, i)] = '\0';
		m++;
		}
		i++;
	}
	split2[m] = NULL;
	return (split2);
}

char	**ft_split(char const *s, char c)
{
	char	**split2;

	if (s[0] == '\0')
	{
		split2 = malloc(sizeof(char *) * 1);
		split2[0] = NULL;
		return (split2);
	}
	split2 = malloc(sizeof(char *) * (lensplit2(s, c) + 1));
	if (!split2)
		return (NULL);
	if (lensplit2(s, c) == 0)
		split2[0] = NULL;
	else
		spliting2(s, split2, c);
	return (split2);
}
