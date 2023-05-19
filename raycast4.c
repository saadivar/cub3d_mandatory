/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:17:13 by sel-biyy          #+#    #+#             */
/*   Updated: 2023/05/19 17:29:46 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawangel(t_win *win)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	init_raycaste(win, ray);
	while (ray->i < win->ang_end)
	{
		if (ray->i == 0 || ray->i == PI / 2 || ray->i == PI || ray->i == 3 * PI
			/ 2 || ray->i == 2 * PI)
			return ;
		if (ray->i > PI / 2 && ray->i < 3 * PI / 2)
			left(win, ray);
		else
			right(win, ray);
		ray->i += 0.0008;
		ray->x -= 0.9167324722;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
	free(ray);
}

void	drawf_c(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 1200)
	{
		y = 0;
		while (y < 400)
			put_img(win, win->check->c_color, x, y++);
		x++;
	}
	y = 400;
	x = 0;
	while (x < 1200)
	{
		y = 400;
		while (y < 800)
			put_img(win, win->check->f_color, x, y++);
		x++;
	}
}

void	drawing(t_win *win)
{
	drawf_c(win);
	drawangel(win);
}

int	key_hook(int key, t_win *win)
{
	if (key == 53)
	{
		mlx_destroy_window(win->mlx, win->window);
		printf("you end the game");
		exit(0);
	}
	if (key == 13)
		win->movement = 0;
	if (key == 1)
		win->movement = PI;
	if (key == 0)
		win->movement = PI / 2;
	if (key == 2)
		win->movement = -PI / 2;
	if (key == 123)
	{
		win->viewing = 0.1;
	}
	if (key == 124)
	{
		win->viewing = -0.1;
	}
	return (0);
}

int	checkext(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] != 'b' || av[i - 1] != 'u' || av[i - 2] != 'c' || av[i
			- 3] != '.')
		printferror("wrong exe");
	return (0);
}
