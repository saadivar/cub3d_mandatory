/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:14:27 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/19 15:19:43 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	double_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_path(char *line, char c, t_check *check)
{
	int	fd;

	fd = open(line, O_RDWR);
	if (fd == -1)
		printferror("THE PATH OF PICTURE IS WRONG !");
	if (c == 'n')
		check->north = line;
	if (c == 's')
		check->sud = line;
	if (c == 'w')
		check->west = line;
	if (c == 'e')
		check->east = line;
}

void	checker(char c, t_check *check, char *line)
{
	if (c == 'n')
		check->n_c++;
	if (c == 's')
		check->s_c++;
	if (c == 'w')
		check->w_c++;
	if (c == 'e')
		check->e_c++;
	line = get_new_string(line, 3);
	check_path(line, c, check);
}

int	count_virgules(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	check_line(t_check *check, char *line)
{
	if (!line)
		exit(1);
	line = get_new_string(line, 0);
	if (check_north_and_south(check, line) == 1)
		return ;
	if (check_east_and_west(check, line) == 1)
		return ;
	if (check_color(check, line) == 1)
		return ;
	else
		printferror("ELEMENTS OF PIC ARE WRONG !!");
}
