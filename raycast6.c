/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:30:39 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/05/19 17:46:01 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	akey(t_win *win)
{
	if ((win->map[(int)(win->yp - 0.3 * sin(win->angle + PI
					/ 2))][(int)(win->xp + 0.3 * cos(win->angle + PI
			/ 2))] != '1'))
	{
		win->xp += 0.1 * cos(win->angle + PI / 2);
		win->yp -= 0.1 * sin(win->angle + PI / 2);
	}	
}

void	dkey(t_win *win)
{
	if ((win->map[(int)(win->yp - 0.3 * sin(win->angle - PI
					/ 2))][(int)(win->xp + 0.3 * cos(win->angle - PI
			/ 2))] != '1'))
	{
		win->xp += 0.1 * cos(win->angle - PI / 2);
		win->yp -= 0.1 * sin(win->angle - PI / 2);
	}	
}

void	check_midle(char *line, t_parsing *pars, t_win *win, char **map)
{
	pars->y = 0;
	while (line[pars->y])
	{
		while (line[pars->y] && line[pars->y] == 32)
			pars->y++;
		if (line[pars->y] == '0' && (pars->y + 1 > gnl_strlen(map[pars->i - 1])
				|| pars->y + 1 > gnl_strlen(map[pars->i + 1])))
			printferror("map not closed !!");
		if (check_ver(line) == 1)
			printferror("wrong map !!");
		if (line[pars->y] == 'N' || line[pars->y] == 'W' || line[pars->y] == 'E'
			|| line[pars->y] == 'S' || line[pars->y] == '0')
			hindle_all_elements(line, pars, win, map);
		if (line[pars->y])
			pars->y++;
	}
}

int	check_color(t_check *check, char *line)
{
	if (*line && !ft_strncmp(line, "F ", 2))
	{
		check->f_c++;
		line = get_new_string(line, 2);
		check->f_color = get_colors(line);
		return (1);
	}
	else if (*line && !ft_strncmp(line, "C ", 2))
	{
		check->c_c++;
		line = get_new_string(line, 2);
		check->c_color = get_colors(line);
		return (1);
	}
	return (0);
}

void	get_data(t_win *win)
{
	int	bbp;
	int	endian;

	xpm_to_img(win);
		win->data_imgn = (unsigned int *)mlx_get_data_addr(win->imgn, &bbp,
			&win->size_line1, &endian);
	win->data_imgw = (unsigned int *)mlx_get_data_addr(win->imgw, &bbp,
			&win->size_line2, &endian);
	win->data_imge = (unsigned int *)mlx_get_data_addr(win->imge, &bbp,
			&win->size_line3, &endian);
	win->data_imgs = (unsigned int *)mlx_get_data_addr(win->imgs, &bbp,
			&win->size_line4, &endian);
}
