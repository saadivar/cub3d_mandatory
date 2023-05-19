/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 05:13:29 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/19 15:37:53 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printferror(char *str)
{
	write(2, "ERROR: ", 7);
	write(2, str, gnl_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;

	sign = 1;
	i = 0;
	j = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str && str[i] && str[i] <= '9' && str[i] >= '0')
	{
		j = j * 10 + str[i] - 48;
		i++;
	}
	return (j * sign);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	i = 0;
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[gnl_strlen(s1) + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	free(s1);
	free(s2);
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!(p))
		return (NULL);
	p[i] = '\0';
	while (i >= 0)
	{
		p[i] = src[i];
		i--;
	}
	return (p);
}

void	free_dbl(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
