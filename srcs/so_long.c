/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:42:08 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 21:59:29 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_list *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error\nCan't init MLX window\n");
		freeing(data);
		return (0);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->length_map * 50,
			data->height_map * 50, "SOOO_LOOOOOONG");
	if (data->mlx == NULL)
	{
		ft_printf("Error\nCan't init MLX window\n");
		freeing(data);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	data;

	if (!parsing(argc, argv, &data))
		return (0);
	init_mlx(&data);
	if (init_xpm_one(&data) == 0 || init_xpm_two(&data) == 0)
	{
		ft_printf("Error\nCan't init textures");
		freeing(&data);
		return (0);
	}
	print_game_one(&data);
	print_game_two(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, &key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, &freeing, &data);
	mlx_loop(data.mlx);
	return (0);
}
