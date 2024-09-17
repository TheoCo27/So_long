/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:59:29 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:54:25 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map_check	map;
	t_game		game;

	ft_bzero(&map, sizeof(t_map_check));
	ft_bzero(&game, sizeof(t_game));
	ft_set_map_check(&map);
	ft_check_arg(argc, argv);
	if (ft_get_map(argv[1], &map) == 1)
		return (1);
	if (ft_basic_check(&map) != 0)
		return (2);
	ft_set_game(&game, &map);
	ft_set_window(&game);
	ft_set_sprites(&game);
	ft_render_map(&game);
	ft_setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
