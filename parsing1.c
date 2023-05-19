/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:03:56 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/18 20:31:58 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_spaces_at_end(char **map, t_parsing *pars, int i)
{
	int	tmp;

	tmp = pars->y;
	while (map[i][pars->y] && map[i][pars->y] == 32)
		pars->y++;
	if (map[i][pars->y] != 0)
		pars->y = tmp;
	else
		return (0);
	return (1);
}

void	check_first_line(char **map, t_parsing *pars)
{
	if (!map[6] || !map[7] || !map[8])
		printferror("ENTER A VALID MAP PLEASE !");
	while (map[6][pars->y])
	{
		if (map[6][pars->y] != '1' && map[6][pars->y] != 32)
			printferror("FIRST LINE !!!");
		if (handle_spaces_at_end(map, pars, 6) == 0)
			break ;
		if (map[6][pars->y] == 32)
		{
			if (map[7][pars->y] != '1' && map[7][pars->y] != 32)
				printferror("WRONG SPACE IN FIRST LINE !");
		}
		pars->y++;
	}
}

void	check_last_line(char **map, t_parsing *pars)
{
	pars->y = 0;
	while (map[pars->i][pars->y])
	{
		if (map[pars->i][pars->y] != '1' && map[pars->i][pars->y] != 32)
			printferror("LAST LINE INVALID !!");
		if (handle_spaces_at_end(map, pars, pars->i) == 0)
			break ;
		if (map[pars->i][pars->y] == 32)
		{
			if (map[pars->i - 1][pars->y] != '1' && map[pars->i
				- 1][pars->y] != 32)
				printferror("HIGH IS OPEN !!");
		}
		pars->y++;
	}
}

int	check_ver(char *line)
{
	int	i;

	i = gnl_strlen(line) - 1;
	while (line[i] == 32)
		i--;
	if (line[i] != '1')
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'W' && line[i] != 'E' && line[i] != 'S'
			&& line[i] != '0' && line[i] != '1' && line[i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (line[i] == 32)
		i++;
	if (line[i] != '1')
		return (1);
	return (0);
}

void	hindle_all_elements(char *line, t_parsing *pars, t_win *win, char **map)
{
	if (line[pars->y - 1] == 32 || line[pars->y + 1] == 32)
		printferror("map not surounded");
	if (map[pars->i - 1][pars->y] == 32 || map[pars->i + 1][pars->y] == 32)
		printferror("map not surounded");
	if (line[pars->y] != '0')
	{
		win->xp = pars->y + 0.5;
		win->yp = pars->i - 6 + 0.5;
		pars->count++;
		if (pars->count != 1)
			printferror("multiplayer !!");
	}
}
