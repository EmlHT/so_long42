/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:02:48 by ehouot            #+#    #+#             */
/*   Updated: 2023/05/30 20:39:01 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_path
{
	int		i;
	int		j;
	char	**cpy;
	int		nb_line;
}				t_path;

typedef struct s_vars
{
	char	**map;
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*wall;
	void	*red_key;
	void	*door_closed;
	void	*door_open;
	void	*forward_one;
	void	*forward_two;
	void	*backward_one;
	void	*backward_two;
	void	*left_one;
	void	*left_two;
	void	*right_one;
	void	*right_two;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		door_x;
	int		door_y;
	int		nb_obj;
	int		nb_moves;
}				t_vars;

/* -- PRINTF -- */

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf_c_s(char tag, va_list ptr, int i);
int		ft_printf_d_i(va_list ptr, int i);
int		ft_printf_u(va_list ptr, unsigned int i);
int		ft_printf_percent(int i);
int		ft_printf_hexa(char tag, va_list ptr, int i);
int		ft_printf_p(va_list ptr, unsigned long long i);

/* -- GNL -- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, bool free_first_param);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

/* -- SO_LONG -- */

# define WALL "./img/wall.xpm"
# define FLOOR "./img/floor.xpm"
# define PLAYER "./img/forward_one.xpm"
# define DOOR "./img/door_closed.xpm"
# define KEY "./img/red_key.xpm"

int		main(int argc, char **argv);
char	**parsing(int argc, char **argv, t_path *path);
int		count_line(int fd);
void	check_pathing(t_path *path);
int		key_hook(int keycode, t_vars *vars);
int		ft_escape(t_vars *var);
void	ft_backward(t_vars *var);
void	ft_left(t_vars *var);
void	ft_forward(t_vars *var);
void	ft_right(t_vars *var);
void	print_wall(t_vars *var);
void	print_floor(t_vars *var);
void	print_door(t_vars *var);
void	print_player(t_vars *var);
void	print_key(t_vars *var);
void	initialize_map(t_vars *var);
char	**ft_tabdup(char **s1, t_path p);
int		is_door_open(t_vars *var);
void	free_map(char **tab);

#endif