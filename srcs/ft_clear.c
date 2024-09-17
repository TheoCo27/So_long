/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:03:47 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:08:39 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_img(t_game *game)
{
	if (game->collectible)
		mlx_destroy_image(game->mlx, game->collectible);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->red_player)
		mlx_destroy_image(game->mlx, game->red_player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->bg)
		mlx_destroy_image(game->mlx, game->bg);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
}

void	ft_clear_game(t_game *game)
{
	ft_clear_img(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_all(game->map);
	exit(0);
}

int	ft_handle_cross(t_game *game)
{
	ft_clear_game(game);
	return (0);
}
