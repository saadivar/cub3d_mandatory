/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:14:31 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/05/19 16:01:55 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_img(t_win *win, int key, int x, int y)
{
	int	pose;

	pose = (y * win->size_line / 4) + x;
	if (pose >= (1200 * 800))
		return ;
	else if (pose < 0)
		return ;
	win->data_img[pose] = key;
}

void	put_wall_in_mini(t_win *win, int x, int y)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (a < GRID_SIZE - 1)
	{
		b = 0;
		while (b < GRID_SIZE - 1)
		{
			put_img(win, 0xFF0000, b + (x * 20), a + (y * 20));
			b++;
		}
		a++;
	}
}

void	put_empty_in_mini(t_win *win, int x, int y)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	while (a < GRID_SIZE - 1)
	{
		b = 0;
		while (b < GRID_SIZE - 1)
		{
			put_img(win, 0xFFFFFF, b + (x * 20), a + (y * 20));
			b++;
		}
		a++;
	}
}

void	initstuf(t_win *win, double ray_len, double l)
{
	win->j = 0;
	win->xfinal = win->xp + ray_len * cos(l);
	win->yfinal = win->yp - ray_len * sin(l);
	win->wall_len = 800 / (ray_len * cos(win->angle - l));
	win->wall_len2 = 800 / (ray_len * cos(win->angle - l));
	win->i = 400 - win->wall_len / 2;
	if (win->wall_len > 800)
	{
		win->j = win->wall_len2 / 2 - 550;
		if (win->j < 0)
			win->j = 0;
		win->wall_len2 = win->wall_len2 / 2 + 400;
	}
}

void	draw_wall(t_win *win, double ray_len, double angle, double l)
{
	initstuf(win, ray_len, l);
	while (win->j < win->wall_len2)
	{
		if (win->direction == 'N' || win->direction == 'S')
			win->pose = (((int)((win->j) * 250 / win->wall_len) % 250)
					* (win->size_line1 / 4)) + (win->xfinal - (int)win->xfinal)
				* 400;
		else
			win->pose = (((int)((win->j) * 250 / win->wall_len) % 250)
					* (win->size_line1 / 4)) + (win->yfinal - (int)win->yfinal)
				* 400;
		if (win->direction == 'N')
			put_img(win, win->data_imgn[win->pose], angle, win->j + win->i);
		else if (win->direction == 'S')
			put_img(win, win->data_imgs[win->pose], angle, win->j + win->i);
		else if (win->direction == 'W')
			put_img(win, win->data_imgw[win->pose], angle, win->j + win->i);
		else if (win->direction == 'E')
			put_img(win, win->data_imge[win->pose], angle, win->j + win->i);
		win->j++;
	}
}
