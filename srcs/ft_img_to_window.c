/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_to_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:29:22 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:10:15 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_map(t_game *game)
{
	int	col;
	int	line;

	line = 0;
	while (line < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[line][col] == '1')
				ft_img_to_win(game, game->wall, col, line);
			else if (game->map[line][col] == '0')
				ft_img_to_win(game, game->bg, col, line);
			else if (game->map[line][col] == 'C')
				ft_img_to_win(game, game->collectible, col, line);
			else if (game->map[line][col] == 'P')
				ft_img_to_win(game, game->player, col, line);
			else if (game->map[line][col] == 'E')
				ft_img_to_win(game, game->bg, col, line);
			col++;
		}
		line++;
	}
}

void	ft_render_player_error(t_game *game)
{
	ft_img_to_win(game, game->red_player, game->p_col, game->p_line);
}

void	ft_render_exit(t_game *game)
{
	game->map[game->e_line][game->e_col] = 'E';
	ft_img_to_win(game, game->exit, game->e_col, game->e_line);
}

void	ft_player_move(t_game *game, int line, int col)
{
	ft_img_to_win(game, game->bg, game->p_col, game->p_line);
	ft_img_to_win(game, game->player, col, line);
	game->p_line = line;
	game->p_col = col;
}
