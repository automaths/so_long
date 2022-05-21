/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 02:33:11 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/19 22:18:25 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_list *data)
{
	int	t;

	t = 0;
	if (data->check_item == 0 || data->check_composition == 0
		|| data->check_exit == 0 || data->check_start == 0
		|| data->check_surround == 0 || data->check_shape == 0)
	{
		ft_printf("Error\n");
		t = 1;
	}
	if (data->check_item == 0)
		ft_printf("-> there is no item\n");
	if (data->check_composition == 0)
		ft_printf("-> wrong map composition\n");
	if (data->check_exit == 0)
		ft_printf("-> there is no way out\n");
	if (data->check_start == 0)
		ft_printf("-> there is no start\n");
	if (data->check_surround == 0)
		ft_printf("-> there is no surround\n");
	if (data->check_shape == 0)
		ft_printf("-> map isn't correctly shaped\n");
	if (t == 1)
		return (0);
	return (1);
}
