/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:37:26 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 21:52:11 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->height_map)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	freeing_map(t_list *data)
{
	int				i;

	if (data != 0)
	{
		if (data->map != 0)
		{
			i = 0;
			while (data->map[i])
			{
				free(data->map[i]);
				i++;
			}
			free(data->map);
		}
	}
}

int	freeing(t_list *data)
{
	if (data->map != 0)
		freeing_map(data);
	if (data != 0)
	{
		if (data->img_ground != 0)
			mlx_destroy_image(data->mlx, data->img_ground);
		if (data->img_wall != 0)
			mlx_destroy_image(data->mlx, data->img_wall);
		if (data->img_sprites != 0)
			mlx_destroy_image(data->mlx, data->img_sprites);
		if (data->img_exit != 0)
			mlx_destroy_image(data->mlx, data->img_exit);
		if (data->img_player != 0)
			mlx_destroy_image(data->mlx, data->img_player);
		if (data->mlx_win != 0)
			mlx_destroy_window(data->mlx, data->mlx_win);
		if (data->mlx != 0)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
	}
	exit(0);
	return (0);
}
