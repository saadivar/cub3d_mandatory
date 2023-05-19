/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:22:27 by esafouan          #+#    #+#             */
/*   Updated: 2023/05/19 17:32:29 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define WIN_H 1200
# define WIN_W 800
# define GRID_SIZE 20
# define VIEW_DEF 0
# define MOVE_DEF -1
# define PI 3.1415926536

typedef struct raycasting
{
	double			i;
	double			ray_len;
	double			x;
	double			xi;
	double			yi;
	double			flag;
	double			flag2;
	double			firstx_dis;
	double			firsty_dis;
	double			check_x;
	double			check_y;
	double			distance_finale;
	int				tmp_y;
	int				tmp_x;

}					t_ray;

typedef struct check
{
	int				w_c;
	int				e_c;
	int				n_c;
	int				s_c;
	int				f_c;
	int				c_c;
	char			*north;
	char			*sud;
	char			*west;
	char			*east;
	int				f_color;
	int				c_color;
}					t_check;

typedef struct parsing
{
	char			**color;
	int				r;
	int				g;
	int				b;
	char			*line;
	char			*dst;
	int				flag;
	int				j;
	int				i;
	int				count;
	int				y;
	int				k;
	int				flag3;
	int				flag2;
	char			**new_map;
}					t_parsing;

typedef struct win
{
	double			i;
	double			j;
	double			viewing;
	double			movement;
	char			**map;
	void			*window;
	void			*mlx;
	double			xp;
	double			yp;
	double			delta_x;
	double			delta_y;
	double			angle;
	double			ang_str;
	double			ang_end;
	void			*img;
	void			*imgn;
	void			*imgs;
	void			*imgw;
	void			*imge;
	int				size_line;
	int				size_line1;
	int				size_line2;
	int				size_line3;
	int				size_line4;
	unsigned int	*data_img;
	unsigned int	*data_imgn;
	unsigned int	*data_imgw;
	unsigned int	*data_imge;
	unsigned int	*data_imgs;
	int				x_len;
	int				y_len;
	double			wall_len;
	double			wall_len2;
	int				pose;
	double			xfinal;
	double			yfinal;
	t_check			*check;
	char			direction;
	int				fd;

}					t_win;

int					gnl_strlen(const char *s);
char				*gnl_strchr(const char *s, int c);
char				*gnl_strjoin(char *s1, char *s2);
char				*get_next_line(int fd);
void				*gnl_calloc(int count, int size);
char				**ft_split1(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2, int n);
int					ft_atoi(const char *str);
char				*ft_strjoin(char *s1, char *s2);
void				printferror(char *str);
char				*ft_strdup(const char *src);
void				free_dbl(char **arr);
void				pars_map(t_win *win, t_check *check);
void				check_for_new_lines(t_parsing *pars);
char				**get_ready_map(char **map);
void				check_first_elements(char **map, t_check *check);
void				check_map(t_win *win, char **map);
int					handle_spaces_at_end(char **map, t_parsing *pars, int i);
void				check_first_line(char **map, t_parsing *pars);
void				check_last_line(char **map, t_parsing *pars);
void				check_midle(char *line, t_parsing *pars, t_win *win,
						char **map);
int					check_ver(char *line);
int					max_len(char **map);
char				*fill_spaces(int size);
void				last_map(t_win *win);
void				skip_lines_with_spaces(t_parsing *pars, char **map);
int					count_spaces(char **map);
void				check_line(t_check *check, char *line);
int					check_color(t_check *check, char *line);
int					check_east_and_west(t_check *check, char *line);
int					check_north_and_south(t_check *check, char *line);
int					get_colors(char *line);
int					count_virgules(char *line);
void				checker(char c, t_check *check, char *line);
void				check_path(char *line, char c, t_check *check);
char				*get_new_string(char *line, int skip);
int					double_len(char **str);
void				skey(t_win *win);
void				wkey(t_win *win);
int					realising(int key, t_win *win);
int					loop_hook(t_win *win);
void				xpm_to_img(t_win *win);
void				draw_lineof_direction(t_win *win, t_ray *ray);
void				drawangel(t_win *win);
void				drawf_c(t_win *win);
void				drawing(t_win *win);
int					key_hook(int key, t_win *win);
void				right(t_win *win, t_ray *ray);
void				left(t_win *win, t_ray *ray);
void				init_raycaste(t_win *win, t_ray *ray);
void				laseeee9(t_win *win, t_ray *ray, int inc_x, int inc_y);
void				calcul_lenght_of_ray_y(t_win *win, t_ray *ray, int inc_x);
int					draw_line(double x1, t_win *win, double i, double x);
void				select_sides_of_textures_right(t_win *win, t_ray *ray);
void				select_sides_of_textures(t_win *win, t_ray *ray);
void				init_parametres(t_win *win, t_ray *ray, int inc_x,
						int inc_y);
void				calcul_lenght_of_ray_x(t_win *win, t_ray *ray, int inc_y);
void				draw_wall(t_win *win, double ray_len, double angle,
						double l);
void				initstuf(t_win *win, double ray_len, double l);
void				put_empty_in_mini(t_win *win, int x, int y);
void				put_img(t_win *win, int key, int x, int y);
void				dkey(t_win *win);
void				akey(t_win *win);
void				hindle_all_elements(char *line, t_parsing *pars, t_win *win,
						char **map);
void				get_data(t_win *win);
int					checkext(char *av);
void				checking(char *s, t_win *win, t_check *check);
void				calcul_x_y(t_win *win);
#endif
