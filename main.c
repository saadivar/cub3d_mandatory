/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:18:15 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/19 17:30:24 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main_fun(t_win *win)
{
	win->angle += win->viewing;
	if (win->movement != MOVE_DEF)
	{
		if (win->movement == 0)
			wkey(win);
		else if (win->movement == PI / 2)
			akey(win);
		else if (win->movement == PI)
			skey(win);
		else if (win->movement == -PI / 2)
			dkey(win);
	}
	return (loop_hook(win));
}

void	calcul_x_y(t_win *win)
{
	int	i;

	i = 0;
	win->x_len = gnl_strlen(win->map[0]);
	while (win->map[i])
		i++;
	win->y_len = i - 1;
}

void	initmain(t_win *win)
{
	if (win->map[(int)win->yp][(int)win->xp] == 'N')
		win->angle = PI / 2;
	else if (win->map[(int)win->yp][(int)win->xp] == 'S')
		win->angle = 3 * PI / 2;
	else if (win->map[(int)win->yp][(int)win->xp] == 'W')
		win->angle = PI;
	else if (win->map[(int)win->yp][(int)win->xp] == 'E')
		win->angle = 0;
	win->img = NULL;
	win->imgn = NULL;
	win->imgs = NULL;
	win->imgw = NULL;
	win->imge = NULL;
	win->viewing = VIEW_DEF;
	win->movement = MOVE_DEF;
}

int	end_program(t_win *win)
{
	(void)win;
	printf("you end the game");
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_win	*win;
	t_check	*check;

	if (ac == 2)
	{
		checkext(av[1]);
		win = malloc(sizeof(t_win));
		check = malloc(sizeof(t_check));
		win->check = check;
		checking(av[1], win, check);
		win->mlx = mlx_init();
		win->window = mlx_new_window(win->mlx, WIN_H, WIN_W, "cub3d");
		initmain(win);
		get_data(win);
		mlx_hook(win->window, 2, 0, key_hook, win);
		mlx_hook(win->window, 3, 0, realising, win);
		mlx_hook(win->window, 17, 0l, end_program, &win);
		mlx_loop_hook(win->mlx, main_fun, win);
		mlx_loop(win->mlx);
	}
	else
		printferror("wrong arguments");
	return (0);
}
