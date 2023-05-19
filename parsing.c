/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:14:59 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/19 22:27:52 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_win *win, char **map)
{
	t_parsing	*pars;

	pars = malloc(sizeof(t_parsing));
	pars->count = 0;
	pars->y = 0;
	pars->k = 6;
	pars->i = 7;
	check_first_line(map, pars);
	while (map[pars->i + 1])
	{
		check_midle(map[pars->i], pars, win, map);
		pars->i++;
	}
	check_last_line(map, pars);
	if(	pars->count == 0)
		printferror("where is messi");
	free(pars);
}

void	check_first_elements(char **map, t_check *check)
{
	int	i;

	i = 0;
	check->e_c = 0;
	check->n_c = 0;
	check->w_c = 0;
	check->s_c = 0;
	check->f_c = 0;
	check->c_c = 0;
	while (i < 6)
	{
		check_line(check, map[i]);
		if (check->e_c > 1 || check->n_c > 1 || check->w_c > 1 || check->s_c > 1
			|| check->c_c > 1 || check->f_c > 1)
			printferror("DUPLICATE ELMENTS !!");
		i++;
	}
}

char	**get_ready_map(char **map)
{
	t_parsing	*pars;
	char		**my_map;

	pars = malloc(sizeof(t_parsing));
	pars->i = 0;
	while (map[pars->i])
		pars->i++;
	pars->j = pars->i - count_spaces(map);
	pars->new_map = malloc((pars->j + 1) * 8);
	pars->k = 0;
	pars->i = 0;
	while (map[pars->i])
	{
		pars->j = 0;
		if (map[pars->i][pars->j] == 32)
			skip_lines_with_spaces(pars, map);
		else
			pars->new_map[pars->k++] = ft_strdup(map[pars->i++]);
	}
	pars->new_map[pars->k] = 0;
	my_map = pars->new_map;
	free(pars);
	free_dbl(map);
	return (my_map);
}

void	check_for_new_lines(t_parsing *pars)
{
	if (pars->line[0] != '\n')
	{
		pars->j = 0;
		pars->flag3 = 0;
		if (pars->line[0] == 32)
		{
			while (pars->line[pars->j] == 32 && pars->line[pars->j] != '\n')
				pars->j++;
			if (pars->line[pars->j] == '\n')
				pars->flag3 = 1;
		}
		if (pars->flag3 == 0)
			pars->flag++;
	}
	if (pars->flag > 6 && pars->line[0] != '\n')
		pars->flag2 = 1;
	if (pars->flag2 && pars->line[0] == '\n')
		printferror("NEW LINE IN MAP !!");
}

void	pars_map(t_win *win, t_check *check)
{
	t_parsing	*pars;

	pars = malloc(sizeof(t_parsing));
	pars->flag2 = 0;
	pars->flag = 0;
	pars->dst = calloc(1, 1);
	while (1)
	{
		pars->line = get_next_line(win->fd);
		if (!pars->line)
			break ;
		check_for_new_lines(pars);
		pars->dst = gnl_strjoin(pars->dst, pars->line);
		free(pars->line);
	}
	win->map = ft_split1(pars->dst, '\n');
	free(pars->dst);
	win->map = get_ready_map(win->map);
	check_first_elements(win->map, check);
	check_map(win, win->map);
	win->map = win->map + 6;
	free(pars);
}
