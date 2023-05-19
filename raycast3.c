/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:17:18 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/05/18 20:28:03 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calcul_lenght_of_ray_y(t_win *win, t_ray *ray, int inc_x)
{
	while (win->map[(int)(ray->check_y)][ray->tmp_x]
		&& win->map[(int)(ray->check_y)][ray->tmp_x] != '1'
		&& win->map[(int)(ray->check_y)][ray->tmp_x] != 32)
	{
		if (inc_x)
			ray->tmp_x++;
		if (!inc_x)
			ray->tmp_x--;
		ray->flag2 += ray->firsty_dis;
		ray->check_y = win->yp - ray->flag2 * sin(ray->i);
		if (ray->tmp_x > win->x_len)
			ray->tmp_x = win->x_len;
		if (ray->tmp_x < 0)
			ray->tmp_x = 0;
		if ((int)(ray->check_y) < 0)
			(ray->check_y) = 0;
		if ((int)(ray->check_y) > win->y_len)
			(ray->check_y) = win->y_len;
	}
}

void	laseeee9(t_win *win, t_ray *ray, int inc_x, int inc_y)
{
	init_parametres(win, ray, inc_x, inc_y);
	calcul_lenght_of_ray_x(win, ray, inc_y);
	calcul_lenght_of_ray_y(win, ray, inc_x);
	select_sides_of_textures(win, ray);
	if (ray->flag < ray->flag2)
		draw_line(ray->flag, win, ray->i, ray->x);
	else
		draw_line(ray->flag2, win, ray->i, ray->x);
}

void	init_raycaste(t_win *win, t_ray *ray)
{
	ray->ray_len = 1;
	ray->x = 1199;
	if (win->angle < 0)
		win->angle = 2 * PI + win->angle;
	if (win->angle > 2 * PI)
		win->angle = win->angle - 2 * PI;
	win->ang_str = win->angle - PI / 6;
	win->ang_end = win->angle + PI / 6;
	if (win->ang_end >= 2 * PI)
	{
		win->ang_end = win->ang_end - 2 * PI;
		win->ang_str = win->ang_str - 2 * PI;
	}
	ray->i = win->ang_str;
}

void	left(t_win *win, t_ray *ray)
{
	if (ray->i > 0 && ray->i < PI)
	{
		ray->yi = win->yp - (int)(win->yp);
		ray->xi = win->xp - (int)win->xp;
		win->delta_x = ray->yi / cos(ray->i - PI / 2);
		win->delta_y = ray->xi / sin(ray->i - PI / 2);
		ray->firstx_dis = 1 / sin(PI - ray->i);
		ray->firsty_dis = 1 / cos(PI - ray->i);
		laseeee9(win, ray, 0, 0);
	}
	else
	{
		ray->yi = (int)(win->yp + 1) - win->yp;
		ray->xi = win->xp - (int)win->xp;
		win->delta_x = ray->yi / sin(ray->i - PI);
		win->delta_y = ray->xi / cos(ray->i - PI);
		ray->firstx_dis = 1 / sin(ray->i - PI);
		ray->firsty_dis = 1 / cos(ray->i - PI);
		laseeee9(win, ray, 0, 1);
	}
}

void	right(t_win *win, t_ray *ray)
{
	if (ray->i > 0 && ray->i < PI)
	{
		ray->yi = win->yp - (int)(win->yp);
		ray->xi = ((int)win->xp + 1) - win->xp;
		win->delta_x = ray->yi / cos(PI / 2 - ray->i);
		win->delta_y = ray->xi / sin(PI / 2 - ray->i);
		ray->firstx_dis = 1 / cos(PI / 2 - ray->i);
		ray->firsty_dis = 1 / sin(PI / 2 - ray->i);
		laseeee9(win, ray, 1, 0);
	}
	else
	{
		ray->yi = (int)(win->yp + 1) - win->yp;
		ray->xi = (int)(win->xp + 1) - win->xp;
		win->delta_x = ray->yi / cos(ray->i - 3 * PI / 2);
		win->delta_y = ray->xi / sin(ray->i - 3 * PI / 2);
		ray->firstx_dis = 1 / cos(ray->i - 3 * PI / 2);
		ray->firsty_dis = 1 / sin(ray->i - 3 * PI / 2);
		laseeee9(win, ray, 1, 1);
	}
}
