/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:00:27 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:13:17 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_small_map(t_map_check *map)
{
	ft_putstr_fd("Error\nMinimum for map is 3x5 or 5x3\n", 2);
	ft_free_all(map->full_map);
}

void	ft_error_empty(void)
{
	ft_putstr_fd("Error\nEmpty map\n", 2);
}

int	ft_check_small(t_map_check *map)
{
	if (map->line_nb < 3)
		return (ft_error_small_map(map), 1);
	map->valid_len = ft_strlen(map->full_map[0]);
	if (map->valid_len < 4)
		return (ft_error_small_map(map), 1);
	if (map->valid_len < 4 && map->line_nb <= 5)
		return (ft_error_small_map(map), 1);
	if (map->valid_len < 6 && map->line_nb <= 3)
		return (ft_error_small_map(map), 1);
	return (0);
}
