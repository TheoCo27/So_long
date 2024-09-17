/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:31:25 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:02:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangle(t_map_check *map)
{
	char	**temp_map;

	map->valid_len = ft_strlen(map->full_map[0]);
	temp_map = map->full_map;
	while (*temp_map)
	{
		if (ft_strlen(*temp_map) != map->valid_len)
		{
			ft_putstr_fd("Error\nMap is not a rectangle\n", 2);
			return (ft_free_all(map->full_map), 1);
		}
		temp_map++;
		if (*(temp_map + 1) == NULL)
			break ;
	}
	if (ft_strlen(*temp_map) != (map->valid_len - 1))
	{
		ft_putstr_fd("Error\nMap is not a rectangle\n", 2);
		return (ft_free_all(map->full_map), 1);
	}
	return (0);
}

int	ft_check_only_walls(char *str, char c, t_map_check *map)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (c == 'f' && i == (map->valid_len - 1))
			break ;
		if (ft_charcmp(str[i], '1') != 1)
			return (1);
		i++;
	}
	if (c == 'f' && str[i] != '\n')
		return (1);
	return (0);
}

int	ft_check_border_walls(char *str, t_map_check *map)
{
	if (str[0] != '1')
		return (1);
	if (str[map->valid_len - 2] != '1')
		return (1);
	if (str[map->valid_len - 1] != '\n')
		return (1);
	return (0);
}

int	ft_check_walls(t_map_check *map)
{
	char	**temp_map;
	size_t	i;

	i = 1;
	temp_map = map->full_map;
	if (ft_check_only_walls(map->full_map[0], 'f', map) == 1)
		return (ft_error_walls(map), 1);
	if (ft_check_only_walls(map->full_map[map->line_nb - 1], 'l', map) == 1)
		return (ft_error_walls(map), 1);
	while (i < (map->line_nb - 1))
	{
		if (ft_check_border_walls(map->full_map[i], map) == 1)
			return (ft_error_walls(map), 1);
		i++;
	}
	return (0);
}

int	ft_basic_check(t_map_check *map)
{
	if (ft_check_small(map) == 1)
		return (6);
	if (ft_is_rectangle(map) == 1)
		return (1);
	if (ft_check_walls(map) == 1)
		return (2);
	if (ft_check_chars(map) == 1)
		return (3);
	if (ft_check_char_nb(map) == 1)
		return (4);
	if (ft_possible_map(map) == 1)
		return (5);
	return (0);
}
