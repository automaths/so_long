/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 23:15:48 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 17:02:57 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	going_down(t_list *data)
{
	if (data->map[data->player_posy + 1][data->player_posx] != '1')
	{
		if (data->on_exit == 1)
		{
			data->map[data->player_posy][data->player_posx] = 'E';
			data->on_exit = 0;
		}
		else
			data->map[data->player_posy][data->player_posx] = '0';
		if (data->map[data->player_posy + 1][data->player_posx] == 'E')
			data->on_exit = 1;
		data->map[data->player_posy + 1][data->player_posx] = 'P';
		data->player_posy++;
		ft_printf("Moves: %d\n", data->counter++);
	}
	print_game_one(data);
	print_game_two(data);
}

void	going_up(t_list *data)
{
	if (data->map[data->player_posy - 1][data->player_posx] != '1')
	{
		if (data->on_exit == 1)
		{
			data->map[data->player_posy][data->player_posx] = 'E';
			data->on_exit = 0;
		}
		else
			data->map[data->player_posy][data->player_posx] = '0';
		if (data->map[data->player_posy - 1][data->player_posx] == 'E')
			data->on_exit = 1;
		data->map[data->player_posy - 1][data->player_posx] = 'P';
		data->player_posy--;
		ft_printf("Moves: %d\n", data->counter++);
	}
	print_game_one(data);
	print_game_two(data);
}

void	going_left(t_list *data)
{
	if (data->map[data->player_posy][data->player_posx - 1] != '1')
	{
		if (data->on_exit == 1)
		{
			data->map[data->player_posy][data->player_posx] = 'E';
			data->on_exit = 0;
		}
		else
			data->map[data->player_posy][data->player_posx] = '0';
		if (data->map[data->player_posy][data->player_posx - 1] == 'E')
			data->on_exit = 1;
		data->map[data->player_posy][data->player_posx - 1] = 'P';
		data->player_posx--;
		ft_printf("Moves: %d\n", data->counter++);
	}
	print_game_one(data);
	print_game_two(data);
}

void	going_right(t_list *data)
{
	if (data->map[data->player_posy][data->player_posx + 1] != '1')
	{
		if (data->on_exit == 1)
		{
			data->map[data->player_posy][data->player_posx] = 'E';
			data->on_exit = 0;
		}
		else
			data->map[data->player_posy][data->player_posx] = '0';
		if (data->map[data->player_posy][data->player_posx + 1] == 'E')
			data->on_exit = 1;
		data->map[data->player_posy][data->player_posx + 1] = 'P';
		data->player_posx++;
		ft_printf("Moves: %d\n", data->counter++);
	}
	print_game_one(data);
	print_game_two(data);
}
