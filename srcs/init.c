/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:37:47 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 22:03:51 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_height_and_length(t_list *data)
{
	char	*line;
	int		fd;
	int		n;
	int		i;

	n = 0;
	fd = open(data->name, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (line == NULL)
		return ;
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	data->length_map = i;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		n++;
	}
	data->height_map = n;
	close(fd);
}

void	data_init_one(t_list *data)
{
	data->map = 0;
	data->mlx = 0;
	data->mlx_win = 0;
	data->img_player = 0;
	data->img_player_width = 0;
	data->img_player_height = 0;
	data->player_posx = 0;
	data->player_posy = 0;
	data->img_exit = 0;
	data->img_exit_width = 0;
	data->img_exit_height = 0;
	data->img_wall = 0;
	data->img_wall_width = 0;
	data->img_wall_height = 0;
	data->img_ground = 0;
	data->img_ground_width = 0;
	data->img_ground_height = 0;
}

void	data_init_two(t_list *data)
{
	data->img_sprites = 0;
	data->img_sprites_width = 0;
	data->img_sprites_height = 0;
	data->check_item = 0;
	data->check_exit = 0;
	data->check_start = 0;
	data->check_composition = 1;
	data->check_surround = 1;
	data->check_shape = 1;
	data->check_name = 1;
	data->height_map = 0;
	data->length_map = 0;
	data->counter = 0;
	data->on_exit = 0;
	data->exiting = 0;
	count_height_and_length(data);
}

int	init_xpm_one(t_list *data)
{
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"./textures/Valerie.xpm", &data->img_player_width,
			&data->img_player_height);
	if (data->img_player == NULL)
	{
		freeing(data);
		return (0);
	}
	data->img_sprites = mlx_xpm_file_to_image(data->mlx,
			"./textures/Euro.xpm", &data->img_sprites_width,
			&data->img_sprites_height);
	if (data->img_sprites == NULL)
	{
		freeing(data);
		return (0);
	}
	data->img_ground = mlx_xpm_file_to_image(data->mlx,
			"./textures/Ground.xpm", &data->img_ground_width,
			&data->img_ground_height);
	return (1);
}

int	init_xpm_two(t_list *data)
{
	if (data->img_ground == NULL)
	{
		freeing(data);
		return (0);
	}
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			"./textures/Nicolas.xpm", &data->img_exit_width,
			&data->img_exit_height);
	if (data->img_exit == NULL)
	{
		freeing(data);
		return (0);
	}
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/Red.xpm", &data->img_wall_width,
			&data->img_wall_height);
	if (data->img_wall == NULL)
	{
		freeing(data);
		return (0);
	}
	return (1);
}
