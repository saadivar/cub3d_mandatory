/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:02:13 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/18 19:17:38 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*p;
	unsigned char	*g;

	i = 0;
	p = (unsigned char *)s1;
	g = (unsigned char *)s2;
	if (!n)
		return (0);
	while (p[i] && g[i] && i < n - 1 && p[i] == g[i])
		i++;
	return (p[i] - g[i]);
}
