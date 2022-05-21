/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:33:20 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/19 23:17:25 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_shape(t_list *data)
{
	int	i;

	i = 0;
	while (i < data->height_map)
	{
		if (ft_strlen(data->map[i]) != ft_strlen(data->map[0]))
			return (0);
		i++;
	}
	if ((int)ft_strlen(data->map[0]) <= data->height_map)
		return (0);
	return (1);
}

int	check_surround(t_list *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
	{
		if (data->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (data->map[data->height_map - 1][i])
	{
		if (data->map[data->height_map - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->height_map)
	{
		if (data->map[i][0] != '1'
			|| data->map[i][ft_strlen(data->map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_map_one(t_list *data)
{
	if (check_shape(data) == 0)
		data->check_shape = 0;
	if (check_surround(data) == 0)
		data->check_surround = 0;
}

void	check_map_two(t_list *data)
{
	int	i;
	int	n;

	n = -1;
	while (++n < data->height_map)
	{
		i = -1;
		while (data->map[n][++i])
		{
			if (data->map[n][i] != 'C' && data->map[n][i] != 'E'
				&& data->map[n][i] != 'P' && data->map[n][i] != '1'
				&& data->map[n][i] != '0')
				data->check_composition = 0;
			if (data->map[n][i] == 'C')
				data->check_item = 1;
			if (data->map[n][i] == 'E')
				data->check_exit = 1;
			if (data->map[n][i] == 'P')
			{
				data->check_start = 1;
				data->player_posx = i;
				data->player_posy = n;
			}
		}
	}
}

int	check_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	if (i < 5)
		return (0);
	i--;
	if (name[i--] != 'r')
		return (0);
	if (name[i--] != 'e')
		return (0);
	if (name[i--] != 'b')
		return (0);
	if (name[i--] != '.')
		return (0);
	return (1);
}
