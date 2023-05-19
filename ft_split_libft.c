/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:17:24 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/17 22:17:26 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_word(char const *s1, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (*s1)
	{
		if (*s1 != c && a == 0)
		{
			a = 1;
			i++;
		}
		else if (*s1 == c)
			a = 0;
		s1++;
	}
	return (i);
}

int	count_len(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*free_split(char **split, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

void	ft_cpysplit(char const *s, char **split, char c)
{
	int	ichar;
	int	iword;

	iword = 0;
	while (*s)
	{
		ichar = 0;
		if (*s == c)
			s++;
		else
		{
			split[iword] = (char *)malloc(sizeof(char) * count_len(s, c) + 1);
			if (!split[iword])
				free_split(split, count_len(s, c));
			while (*s != c && *s)
			{
				split[iword][ichar++] = *s;
				s++;
			}
			split[iword++][ichar] = '\0';
		}
	}
	split[iword] = 0;
}

char	**ft_split1(char const *s, char c)
{
	char	**split;

	split = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!split)
		return (NULL);
	ft_cpysplit(s, split, c);
	return (split);
}
