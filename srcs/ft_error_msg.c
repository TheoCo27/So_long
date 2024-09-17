/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:25:11 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:07:36 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_walls(t_map_check *map)
{
	ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
	ft_free_all(map->full_map);
}

void	ft_error_chars(t_map_check *map)
{
	ft_putstr_fd("Error\nIncorrect char detected, use only <01ECP>\n", 2);
	ft_free_all(map->full_map);
}

void	ft_error_char_missing(t_map_check *map, char c)
{
	ft_putstr_fd("Error\nChar missing: ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_free_all(map->full_map);
}

void	ft_error_toomuch_char(t_map_check *map, char c)
{
	ft_putstr_fd("Error\nToo much char: ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_free_all(map->full_map);
}

void	ft_error_impossible(t_map_check *map, char **map_copy)
{
	ft_putstr_fd("Error\nImpossible map uploaded\n", 2);
	ft_free_all(map->full_map);
	ft_free_all(map_copy);
}
