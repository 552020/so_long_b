/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:11:28 by slombard          #+#    #+#             */
/*   Updated: 2023/07/15 11:45:11 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

# define PIXELS 64

# define WALL_PATH "./sprites/swimming_pool.png"
# define GROUND_PATH "./sprites/beach.png"
# define COLLECTIBLE_PATH "./sprites/umbrella.png"
# define EXIT_CLOSED_PATH "./sprites/golden_gate_closed.png"
# define EXIT_OPEN_PATH "./sprites/golden_gate_open.png"
# define ENEMY_PATH "./sprites/pamela.png"
# define PLAYER_PATH "./sprites/mitch.png"
# define PLAYER_RIGHT_PATH "./sprites/mitch_right.png"
# define PLAYER_LEFT_PATH "./sprites/mitch_left.png"
# define PLAYER_UP_PATH "./sprites/mitch_up.png"
# define PLAYER_DOWN_PATH "./sprites/mitch_down.png"

typedef struct s_img {
	mlx_image_t			*wall;
	mlx_image_t			*ground;
	mlx_image_t			*collectible;
	mlx_image_t			*player;
	mlx_image_t			*player_right;
	mlx_image_t			*player_left;
	mlx_image_t			*player_up;
	mlx_image_t			*player_down;
	mlx_image_t			*exit_closed;
	mlx_image_t			*exit_open;
	mlx_image_t			*enemy;
	mlx_image_t			*count_moves;
	mlx_image_t			*collectibles_count;
}	t_img;

typedef struct s_game {
	char			**map_grid;
	size_t			width;
	size_t			height;
	size_t			moves;
	size_t			collectibles;
	size_t			collected;
	size_t			player_x;
	size_t			player_y;
	size_t			exit_x;
	size_t			exit_y;
	t_img			*img;
	mlx_t			*mlx;
}	t_game;

typedef struct s_enemy_move {
	int				x_increment;
	int				y_increment;
	int				*pos_x;
	int				*pos_y;
	int				next_x;
	int				next_y;
}	t_enemy_move;

void	exit_with_error(const char *msg, bool is_system_error);

void	check_file_extension(char *file_name_str);

void	check_map(char *map_str);
void	check_if_map_is_empty(char *map);
void	check_for_empty_lines(char *map);
void	check_map_values(char *map);
void	check_map_shape(char *map);
void	check_wall(char *map);

void	free_game(t_game *game);

t_game	*init_game(char *map);
t_game	*init_game_struct(char **map_grid);
t_img	*init_img_struct(mlx_t *mlx);


char	*read_map(char *map);
size_t	count_y(char **map_grid);
size_t	count_collectibles(t_game *game);
size_t	get_pos(t_game *game, char axis, char element);
void	check_path(t_game *game);
int		flood_fill(t_game *tmp, size_t y, size_t x);
void	free_grid(char **grid, size_t grid_height);

void	load_ground_texture(mlx_t *mlx, t_img *img);
void	load_wall_texture(mlx_t *mlx, t_img *img);
void	load_collectible_texture(mlx_t *mlx, t_img *img);
void	load_exit_closed(mlx_t *mlx, t_img	*img);
void	load_exit_open(mlx_t *mlx, t_img *img);
void	load_enemy_texture(mlx_t *mlx, t_img *img);
void	load_player_texture(mlx_t *mlx, t_img *img);
void	load_player_right_texture(mlx_t *mlx, t_img *img);
void	load_player_left_texture(mlx_t *mlx, t_img *img);
void	load_player_up_texture(mlx_t *mlx, t_img *img);
void	load_player_down_texture(mlx_t *mlx, t_img *img);

void	render_background(t_game *game);
void	render_image(t_game *game, size_t y, size_t x);
void	render_map(t_game *game);
void	render_info(t_game *game);
void	render_moves(t_game *game);
void	render_collected(t_game *game);


void	main_loop_hook(void *tmp);
void	move_hook(mlx_key_data_t keydata, void *tmp);
t_game	*move_up(t_game *game);
t_game	*move_down(t_game *game);
t_game	*move_left(t_game *game);
t_game	*move_right(t_game *game);
void	move_up_core(t_game *game);
void	move_down_core(t_game *game);
void	move_left_core(t_game *game);
void	move_right_core(t_game *game);
void	pick_collectibles(t_game *game, int y, int x);
void	check_win(t_game *game);
void	enemy_hook(t_game *game);
void	move_enemies(t_game *game, int count);

#endif
