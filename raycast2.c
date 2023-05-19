/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:14:36 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/05/18 20:33:14 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw_line(double x1, t_win *win, double i, double x)
{
	draw_wall(win, x1, x, i);
	return (1);
}

void	select_sides_of_textures_right(t_win *win, t_ray *ray)
{
	if (ray->i > 0 && ray->i < PI)
	{
		if (ray->flag < ray->flag2)
			win->direction = 'N';
		else
			win->direction = 'E';
	}
	else
	{
		if (ray->flag < ray->flag2)
			win->direction = 'S';
		else
			win->direction = 'E';
	}
}

void	select_sides_of_textures(t_win *win, t_ray *ray)
{
	if (ray->i > PI / 2 && ray->i < 3 * PI / 2)
	{
		if (ray->i > 0 && ray->i < PI)
		{
			if (ray->flag < ray->flag2)
				win->direction = 'N';
			else
				win->direction = 'W';
		}
		else
		{
			if (ray->flag < ray->flag2)
				win->direction = 'S';
			else
				win->direction = 'W';
		}
	}
	else
		select_sides_of_textures_right(win, ray);
}

void	init_parametres(t_win *win, t_ray *ray, int inc_x, int inc_y)
{
	ray->flag = win->delta_x;
	ray->flag2 = win->delta_y;
	ray->check_x = win->xp + ray->flag * cos(ray->i);
	ray->check_y = win->yp - ray->flag2 * sin(ray->i);
	if (!inc_y)
		ray->tmp_y = (int)win->yp - 1;
	else
		ray->tmp_y = (int)win->yp + 1;
	if (inc_x)
		ray->tmp_x = (int)win->xp + 1;
	else
		ray->tmp_x = (int)win->xp - 1;
	if ((int)(ray->check_x) < 0)
		(ray->check_x) = 0;
	if ((int)(ray->check_x) > win->x_len)
		(ray->check_x) = win->x_len;
	if ((int)(ray->check_y) < 0)
		(ray->check_y) = 0;
	if ((int)(ray->check_y) > win->y_len)
		(ray->check_y) = win->y_len;
}

void	calcul_lenght_of_ray_x(t_win *win, t_ray *ray, int inc_y)
{
	while (win->map[ray->tmp_y][(int)(ray->check_x)]
		&& win->map[ray->tmp_y][(int)(ray->check_x)] != '1'
		&& win->map[ray->tmp_y][(int)(ray->check_x)] != 32)
	{
		if (!inc_y)
			ray->tmp_y--;
		if (inc_y)
			ray->tmp_y++;
		ray->flag += ray->firstx_dis;
		ray->check_x = win->xp + ray->flag * cos(ray->i);
		if ((int)(ray->check_x) < 0)
			(ray->check_x) = 0;
		if ((int)(ray->check_x) > win->x_len)
			(ray->check_x) = win->x_len;
		if (ray->tmp_y < 0)
			ray->tmp_y = 0;
		if (ray->tmp_y > win->y_len)
			ray->tmp_y = win->y_len;
	}
}
