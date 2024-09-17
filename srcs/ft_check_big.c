/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:29:15 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:13:54 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_toobig(t_game *game)
{
	ft_putstr_fd("Error\nMap too big for screen size\n", 2);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_all(game->map);
	exit (5);
}

int	ft_check_big(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(game->mlx, &width, &height);
	if (width < game->width * 50)
		ft_error_toobig(game);
	if (height < game->height * 50)
		ft_error_toobig(game);
	return (0);
}
