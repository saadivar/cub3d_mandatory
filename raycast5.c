/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:17:11 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/05/19 17:47:07 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_to_img(t_win *win)
{
	int	h;
	int	w;

	win->imgn = mlx_xpm_file_to_image(win->mlx, win->check->north, &h, &w);
	win->imge = mlx_xpm_file_to_image(win->mlx, win->check->east, &h, &w);
	win->imgs = mlx_xpm_file_to_image(win->mlx, win->check->sud, &h, &w);
	win->imgw = mlx_xpm_file_to_image(win->mlx, win->check->west, &h, &w);
}

int	loop_hook(t_win *win)
{
	int	bbp;
	int	endian;

	if (win->img)
		mlx_destroy_image(win->mlx, win->img);
	win->img = mlx_new_image(win->mlx, WIN_H, WIN_W);
	win->data_img = (unsigned int *)mlx_get_data_addr(win->img, &bbp,
			&win->size_line, &endian);
	if (win->angle >= 2 * PI || win->angle <= -(2 * PI))
		win->angle = 0;
	drawing(win);
	return (0);
}

int	realising(int key, t_win *win)
{
	if (key == 0 || key == 13 || key == 1 || key == 2)
	{
		win->movement = MOVE_DEF;
	}
	if (key == 123 || key == 124)
	{
		win->viewing = VIEW_DEF;
	}
	return (1);
}

void	wkey(t_win *win)
{
	if ((win->map[(int)(win->yp - 0.3 * sin(win->angle))][(int)(win->xp + 0.3
		* cos(win->angle))] != '1'))
	{
		win->xp += 0.1 * cos(win->angle);
		win->yp -= 0.1 * sin(win->angle);
	}
}

void	skey(t_win *win)
{
	if ((win->map[(int)(win->yp + 0.3 * sin(win->angle))][(int)(win->xp - 0.3
		* cos(win->angle))] != '1'))
	{
		win->xp -= 0.1 * cos(win->angle);
		win->yp += 0.1 * sin(win->angle);
	}
}
