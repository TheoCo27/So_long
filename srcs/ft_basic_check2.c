/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_check2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:00:35 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:03:50 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_chars(t_map_check *map)
{
	char	**temp_map;

	temp_map = map->full_map;
	while (*temp_map)
	{
		if (ft_str_setonly(*temp_map, "01ECP\n") == 1)
			return (ft_error_chars(map), 1);
		temp_map++;
	}
	return (0);
}

int	ft_check_char_nb(t_map_check *map)
{
	if (ft_tabcount_char(map->full_map, 'P') > 1)
		return (ft_error_toomuch_char(map, 'P'), 1);
	if (ft_tabcount_char(map->full_map, 'P') < 1)
		return (ft_error_char_missing(map, 'P'), 1);
	if (ft_tabcount_char(map->full_map, 'E') > 1)
		return (ft_error_toomuch_char(map, 'E'), 1);
	if (ft_tabcount_char(map->full_map, 'E') < 1)
		return (ft_error_char_missing(map, 'E'), 1);
	map->nb_c = ft_tabcount_char(map->full_map, 'C');
	if (map->nb_c < 1)
		return (ft_error_char_missing(map, 'C'), 1);
	return (0);
}

static void	ft_flood(char **map, t_point i, char c)
{
	if (map[i.x][i.y] == '1' || map[i.x][i.y] == c)
		return ;
	map[i.x][i.y] = c;
	ft_flood(map, (t_point){i.x - 1, i.y}, c);
	ft_flood(map, (t_point){i.x + 1, i.y}, c);
	ft_flood(map, (t_point){i.x, i.y - 1}, c);
	ft_flood(map, (t_point){i.x, i.y + 1}, c);
}

int	ft_possible_map(t_map_check *map)
{
	t_point	i;
	char	**map_copy;

	ft_init_t_point(&i);
	i = ft_tab_findchar(map->full_map, 'P');
	map_copy = ft_tabstr_copy(map->full_map);
	if (!map_copy)
		return (ft_free_all(map->full_map), 1);
	ft_flood(map_copy, i, '.');
	if (ft_tabcount_char(map_copy, 'C') != 0)
		return (ft_error_impossible(map, map_copy), 1);
	if (ft_tabcount_char(map_copy, 'E') != 0)
		return (ft_error_impossible(map, map_copy), 1);
	ft_free_all(map_copy);
	return (0);
}
