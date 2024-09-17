/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:56:13 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 17:08:13 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <X11/X.h>
# include <X11/Xlib.h>

# define KEY_UP     119
# define KEY_DOWN   115
# define KEY_LEFT   97
# define KEY_RIGHT  100
# define ESC_KEY    65307

typedef struct s_map_check
{
	char	*line_to_check;
	char	**full_map;
	int		error_code;
	size_t	line_nb;
	size_t	valid_len;
	int		map_fd;
	int		nb_c;
}			t_map_check;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	char	**map;
	void	*player;
	void	*red_player;
	void	*exit;
	void	*collectible;
	void	*wall;
	void	*bg;
	int		nb_c;
	int		nb_move;
	int		p_col;
	int		p_line;
	int		e_col;
	int		e_line;
	int		bool_e;
}			t_game;

//ft_check_arg.c
void	ft_error_format(void);
void	ft_check_argc(int argc);
void	ft_check_argv(char **argv);
void	ft_check_arg(int argc, char **argv);
// ft_secure.c
int		ft_open(char *file_name);
int		ft_secure_file_to_img(t_game *game, void **img, char *path);
void	ft_img_to_win(t_game *game, void *img, int col, int line);
// ft_set.c
void	ft_set_map_check(t_map_check *map);
void	ft_set_game(t_game *game, t_map_check *map);
void	ft_set_window(t_game *game);
void	ft_set_sprites(t_game *game);
void	ft_set_el_index(t_game *game, char c, int mode);
//ft_get_map.c
int		ft_get_map(char *map_file, t_map_check *map);
int		ft_print_map(t_map_check *map);
//ft_basic_check.c
int		ft_is_rectangle(t_map_check *map);
int		ft_check_only_walls(char *str, char c, t_map_check *map);
int		ft_check_border_walls(char *str, t_map_check *map);
int		ft_check_walls(t_map_check *map);
int		ft_basic_check(t_map_check *map);
//ft_basic_check2.c
int		ft_check_chars(t_map_check *map);
int		ft_check_char_nb(t_map_check *map);
int		ft_possible_map(t_map_check *map);
//ft_error_msg.c
void	ft_error_walls(t_map_check *map);
void	ft_error_chars(t_map_check *map);
void	ft_error_char_missing(t_map_check *map, char c);
void	ft_error_toomuch_char(t_map_check *map, char c);
void	ft_error_impossible(t_map_check *map, char **map_copy);
// ft_clear.c
void	ft_clear_img(t_game *game);
void	ft_clear_game(t_game *game);
int		ft_handle_cross(t_game *game);
//ft_img_to_window
void	ft_render_map(t_game *game);
void	ft_render_player_error(t_game *game);
void	ft_render_exit(t_game *game);
void	ft_player_move(t_game *game, int line, int col);
//ft_movement.c
int		ft_is_valid_move(t_game *game, int line, int col);
int		ft_handle_keypress(int keycode, t_game *game);
void	ft_setup_hooks(t_game *game);
int		ft_check_move(t_game *game, int keycode);
int		ft_move(t_game *game, int line, int col);
// ft_put.c
void	ft_put_move_count(t_game *game);
int		ft_put_map(t_game *game);
// ft_check_small
void	ft_error_small_map(t_map_check *map);
int		ft_check_small(t_map_check *map);
void	ft_error_empty(void);
//ft_check_big.c
void	ft_error_toobig(t_game *game);
int		ft_check_big(t_game *game);
#endif