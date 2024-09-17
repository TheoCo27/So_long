/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:36:20 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:06:19 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_map_check(t_map_check *map)
{
	char	c;

	c = '\0';
	map->error_code = 0;
	map->line_nb = 0;
	map->valid_len = 0;
	map->map_fd = 0;
	map->line_to_check = &c;
	map->full_map = NULL;
}

void	ft_set_el_index(t_game *game, char c, int mode)
{
	t_point	index;

	if (mode == 1)
	{
		index = ft_tab_findchar(game->map, c);
		game->p_line = index.x;
		game->p_col = index.y;
		return ;
	}
	index = ft_tab_findchar(game->map, c);
	game->e_line = index.x;
	game->e_col = index.y;
}

void	ft_set_game(t_game *game, t_map_check *map)
{
	game->bg = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->red_player = NULL;
	game->wall = NULL;
	game->mlx = NULL;
	game->window = NULL;
	game->map = map->full_map;
	game->height = (int)map->line_nb;
	game->width = (int)map->valid_len - 1;
	game->nb_c = map->nb_c;
	game->nb_move = 0;
	ft_set_el_index(game, 'P', 1);
	ft_set_el_index(game, 'E', 0);
	game->bool_e = 0;
}

void	ft_set_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("mlx_init failed\n", 2);
		ft_free_all(game->map);
		exit (3);
	}
	ft_check_big(game);
	game->window = mlx_new_window(game->mlx, game->width * 50,
			game->height * 50, "game");
	if (!game->window)
	{
		ft_putstr_fd("mlx_new_window failed\n", 2);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_free_all(game->map);
		exit (4);
	}
}

void	ft_set_sprites(t_game *game)
{
	ft_secure_file_to_img(game, (void **)&game->player, "img/p.xpm");
	ft_secure_file_to_img(game, (void **)&game->red_player, "img/red_p.xpm");
	ft_secure_file_to_img(game, (void **)&game->bg, "img/bg.xpm");
	ft_secure_file_to_img(game, (void **)&game->wall, "img/wall.xpm");
	ft_secure_file_to_img(game, (void **)&game->collectible, "img/c.xpm");
	ft_secure_file_to_img(game, (void **)&game->exit, "img/e.xpm");
}
