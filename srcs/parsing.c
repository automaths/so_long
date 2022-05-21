/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:59:51 by nsartral          #+#    #+#             */
/*   Updated: 2022/05/20 22:03:56 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parsing(t_list *data)
{
	data_init_one(data);
	data_init_two(data);
	data->map = gnl_split(data);
	if (data->map == NULL)
	{
		ft_printf("Error\n-> map invalid\n");
		return (0);
	}
	if (data->height_map < 3)
	{
		ft_printf("Error\n-> map invalid\n");
		return (0);
	}
	if (data->length_map < 3)
	{
		ft_printf("Error\n-> map_invalid\n");
		return (0);
	}
	check_map_one(data);
	check_map_two(data);
	if (check_errors(data) == 0)
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_list *data)
{
	if (argc != 2)
	{
		ft_printf("Error\n-> wrong input\n");
		return (0);
	}
	if (check_name(argv[1]) == 0)
	{
		ft_printf("Error\n-> wrong map name\n");
		return (0);
	}
	data->name = argv[1];
	if (!map_parsing(data))
	{
		free_map(data);
		return (0);
	}
	return (1);
}

char	**gnl_split(t_list *data)
{
	int	fd;
	int	i;

	fd = open(data->name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	data->map = (char **)malloc(sizeof(char *) * (data->height_map + 1));
	i = 0;
	while (i < data->height_map)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	close (fd);
	return (data->map);
}
