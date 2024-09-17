/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:04:45 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:06:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_move_count(t_game *game)
{
	game->nb_move++;
	ft_putstr_fd("Nomber of moves is: ", 1);
	ft_putnbr_fd(game->nb_move, 1);
	ft_putchar_fd('\n', 1);
}

int	ft_put_map(t_game *game)
{
	size_t	i;

	i = 0;
	while (game->map[i])
	{
		ft_putstr_fd(game->map[i], 1);
		i++;
	}
	ft_putstr_fd("\nMap have been printed\n", 1);
	return (0);
}
