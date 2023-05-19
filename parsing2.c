/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:03:33 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/18 20:28:11 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_len(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = gnl_strlen(map[0]);
	while (map[i])
	{
		if (j < gnl_strlen(map[i]))
			j = gnl_strlen(map[i]);
		i++;
	}
	return (j);
}

char	*fill_spaces(int size)
{
	char	*spaces;
	int		i;

	i = 0;
	spaces = malloc(size + 1);
	while (i < size)
	{
		spaces[i] = 32;
		i++;
	}
	spaces[i] = 0;
	return (spaces);
}

void	last_map(t_win *win)
{
	int		len;
	int		size;
	int		x;
	char	*spaces;
	int		i;

	i = 0;
	len = max_len(win->map);
	while (win->map[i])
	{
		x = gnl_strlen(win->map[i]);
		size = len - x;
		if (size > 0)
		{
			spaces = fill_spaces(size);
			win->map[i] = ft_strjoin(win->map[i], spaces);
		}
		i++;
	}
}

int	count_spaces(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j] == 32)
		{
			while (map[i][j] && map[i][j] == 32)
				j++;
			if (!map[i][j])
				count++;
		}
		i++;
	}
	return (count);
}

void	skip_lines_with_spaces(t_parsing *pars, char **map)
{
	while (map[pars->i][pars->j] && map[pars->i][pars->j] == 32)
		pars->j++;
	if (!map[pars->i][pars->j])
		pars->i++;
	else
	{
		pars->new_map[pars->k++] = ft_strdup(map[pars->i++]);
	}
}
