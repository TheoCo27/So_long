/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:17:50 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:15:33 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_add_first_line(t_map_check *map, char *line)
{
	map->full_map = (char **)malloc((map->line_nb + 1) * sizeof(char *));
	if (!map->full_map)
	{
		ft_putstr_fd("Malloc failed\n", 2);
		close(map->map_fd);
		free(line);
		exit (1);
	}
	map->full_map[0] = line;
	map->full_map[1] = NULL;
	return (0);
}

static int	ft_tempmap_tofullmap(char **temp_map, t_map_check *map)
{
	size_t	i;

	i = 0;
	while (temp_map[i])
	{
		map->full_map[i] = temp_map[i];
		i++;
	}
	return (0);
}

static int	ft_addline_tomap(t_map_check *map, char *line)
{
	char	**temp_map;

	if (map->line_nb == 1)
		return (ft_add_first_line(map, line));
	temp_map = map->full_map;
	map->full_map = (char **)malloc((map->line_nb + 1) * sizeof(char *));
	if (!map->full_map)
		return (ft_free_all(temp_map), ft_putstr_fd("Malloc failed\n", 2), 1);
	map->full_map[map->line_nb] = NULL;
	map->full_map[map->line_nb - 1] = line;
	ft_tempmap_tofullmap(temp_map, map);
	free(temp_map);
	return (0);
}

int	ft_get_map(char *map_file, t_map_check *map)
{
	char	buffer[10];

	map->map_fd = ft_open(map_file);
	while (map->line_to_check)
	{
		map->line_to_check = get_next_line(map->map_fd);
		if (!map->line_to_check)
			break ;
		map->line_nb++;
		if (ft_addline_tomap(map, map->line_to_check) == 1)
			return (close(map->map_fd), 1);
	}
	if (map->line_nb == 0)
		return (close(map->map_fd), ft_error_empty(), 1);
	if (read(map->map_fd, buffer, 11) != 0)
		return (ft_free_all(map->full_map), close(map->map_fd), 1);
	close(map->map_fd);
	return (0);
}

int	ft_print_map(t_map_check *map)
{
	size_t	i;

	i = 0;
	while (map->full_map[i])
	{
		ft_putstr_fd(map->full_map[i], 1);
		free(map->full_map[i]);
		i++;
	}
	free(map->full_map);
	return (0);
}
