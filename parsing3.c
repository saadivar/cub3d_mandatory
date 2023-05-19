/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:13:07 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/18 20:32:29 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_east_and_west(t_check *check, char *line)
{
	if (*line && !ft_strncmp(line, "WE ", 3))
	{
		checker('w', check, line);
		return (1);
	}
	else if (*line && !ft_strncmp(line, "EA ", 3))
	{
		checker('e', check, line);
		return (1);
	}
	return (0);
}

int	check_north_and_south(t_check *check, char *line)
{
	if (*line && !ft_strncmp(line, "NO ", 3))
	{
		checker('n', check, line);
		return (1);
	}
	else if (*line && !ft_strncmp(line, "SO ", 3))
	{
		checker('s', check, line);
		return (1);
	}
	return (0);
}

char	*get_new_string(char *line, int skip)
{
	if (*line && *line + skip)
		line = line + skip;
	while (*line && *line == 32)
		line++;
	return (line);
}

void	rgb_format(t_parsing *pars, char *line)
{
	while (line[pars->count])
	{
		if (line[pars->count] != ',' && (line[pars->count] < 48
				|| line[pars->count] > 57))
			printferror("ERROR IN FORMAT OF RGB");
		pars->count++;
	}
	pars->count = count_virgules(line);
	if (pars->count != 2)
		printferror("ERROR IN FORMAT OF RGB");
}

int	get_colors(char *line)
{
	t_parsing	*pars;
	int			my_color;

	pars = malloc(sizeof(t_parsing));
	pars->count = 0;
	rgb_format(pars, line);
	pars->color = ft_split1(line, ',');
	if (!pars->color[0] || !pars->color[1] || !pars->color[2])
		printferror("WRONG NUMBER OF COLORS");
	pars->r = ft_atoi(pars->color[0]);
	pars->g = ft_atoi(pars->color[1]);
	pars->b = ft_atoi(pars->color[2]);
	if (pars->r > 255 || pars->r < 0 || pars->g > 255 || pars->g < 0
		|| pars->b > 255 || pars->b < 0)
		printferror("ERROR IN FORMAT OF RGB");
	my_color = (pars->r * (256 * 256)) + (pars->g * 256) + pars->b;
	free_dbl(pars->color);
	free(pars);
	return (my_color);
}
