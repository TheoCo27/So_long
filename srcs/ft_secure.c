/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:20:59 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:01:02 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(file_name);
		exit (2);
	}
	return (fd);
}

static void	ft_error_img(t_game *game)
{
	ft_putstr_fd("Error\nCouldn't convert xpm to img\n", 2);
	ft_clear_game(game);
}

int	ft_secure_file_to_img(t_game *game, void **img, char *path)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	*img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (*img == NULL || w != 50 || h != 50)
		return (ft_error_img(game), 1);
	return (0);
}

void	ft_img_to_win(t_game *game, void *img, int col, int line)
{
	mlx_put_image_to_window(game->mlx, game->window, img, col * 50, line * 50);
}
