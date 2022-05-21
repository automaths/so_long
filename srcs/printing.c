/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:00:35 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 20:42:26 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_list *data)
{
	data->img_player_width += keycode - keycode;
	if (keycode == 65307)
		freeing(data);
	if (keycode == 97 || keycode == 65361)
		going_left(data);
	if (keycode == 119 || keycode == 65362)
		going_up(data);
	if (keycode == 100 || keycode == 65363)
		going_right(data);
	if (keycode == 115 || keycode == 65364)
		going_down(data);
	return (0);
}

void	is_game_complete(t_list *data)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	t = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'C')
				t++;
			j++;
		}
		i++;
	}
	if (t == 0)
		freeing(data);
}

void	print_game_one(t_list *data)
{
	int	i;
	int	j;

	is_game_complete(data);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_ground, 50 * j, 50 * i);
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_wall, 50 * j, 50 * i);
			j++;
		}
		i++;
	}
}

void	print_game_two(t_list *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_player, 50 * j, 50 * i);
			if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_exit, 50 * j, 50 * i);
			if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_sprites, 50 * j, 50 * i);
			j++;
		}
		i++;
	}
}
