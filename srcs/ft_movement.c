/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:46:59 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:53:21 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

int	ft_is_valid_move(t_game *game, int line, int col)
{
	if (game->map[line][col] == '1')
		return (0);
	return (1);
}

int	ft_move(t_game *game, int line, int col)
{
	if (game->map[line][col] == 'C')
	{
		game->nb_c--;
		game->map[line][col] = '0';
	}
	if (line == game->e_line && col == game->e_col && game->nb_c <= 0)
		ft_clear_game(game);
	ft_player_move(game, line, col);
	if (game->nb_c == 0)
		return (ft_render_exit(game), 0);
	return (0);
}

int	ft_check_move(t_game *game, int keycode)
{
	int	line;
	int	col;

	line = game->p_line;
	col = game->p_col;
	if (keycode == XK_a)
		col--;
	else if (keycode == XK_d)
		col++;
	else if (keycode == XK_w)
		line--;
	else if (keycode == XK_s)
		line++;
	if (ft_is_valid_move(game, line, col) == 0)
		return (ft_render_player_error(game), 0);
	ft_put_move_count(game);
	ft_move(game, line, col);
	return (0);
}

int	ft_handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_clear_game(game);
	if (keycode == XK_a)
		ft_check_move(game, keycode);
	else if (keycode == XK_d)
		ft_check_move(game, keycode);
	else if (keycode == XK_w)
		ft_check_move(game, keycode);
	else if (keycode == XK_s)
		ft_check_move(game, keycode);
	return (0);
}

void	ft_setup_hooks(t_game *game)
{
	mlx_key_hook(game->window, ft_handle_keypress, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask,
		ft_handle_cross, game);
}
