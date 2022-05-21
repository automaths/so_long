/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:26:15 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 22:13:15 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx.h"

typedef struct s_list
{
	char			**map;
	char			*name;
	int				check_item;
	int				check_exit;
	int				check_start;
	int				check_surround;
	int				check_composition;
	int				check_shape;
	int				check_name;
	int				height_map;
	int				length_map;
	int				counter;
	int				on_exit;
	int				exiting;
	void			*mlx;
	void			*mlx_win;
	void			*img_player;
	int				img_player_width;
	int				img_player_height;
	int				player_posx;
	int				player_posy;
	void			*img_exit;
	int				img_exit_width;
	int				img_exit_height;
	void			*img_wall;
	int				img_wall_width;
	int				img_wall_height;
	void			*img_ground;
	int				img_ground_width;
	int				img_ground_height;
	void			*img_sprites;
	int				img_sprites_width;
	int				img_sprites_height;
}			t_list;

int					init_mlx(t_list *data);
void				freeing_map(t_list *data);
int					freeing(t_list *data);
int					ft_printf(const char *format, ...);
size_t				ft_strlen(const char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *str);
char				*ft_strchr_gnl(char *str);
char				*get_next_line(int fd);
char				*new_buffer(char *buffer);
char				*get_the_line(char *buffer);
char				*read_fd(int fd, char *buffer);
int					check_errors(t_list *data);
void				check_map_one(t_list *data);
void				check_map_two(t_list *data);
int					check_shape(t_list *data);
int					check_surround(t_list *data);
int					check_name(char *name);
void				data_init_one(t_list *data);
void				data_init_two(t_list *data);
void				free_map(t_list *data);
void				count_height_and_length(t_list *data);
char				**gnl_split(t_list *data);
int					init_xpm_one(t_list *data);
int					init_xpm_two(t_list *data);
int					map_parsing(t_list *data);
int					parsing(int argc, char **argv, t_list *data);
void				going_down(t_list *data);
void				going_up(t_list *data);
void				going_left(t_list *data);
void				going_right(t_list *data);
int					key_press(int keycode, t_list *data);
void				print_game_one(t_list *data);
void				print_game_two(t_list *data);
int					exiting(t_list *data);
void				is_game_complete(t_list *data);

#endif