

#include "../include/so_long.h"

t_game	*init_game(char *map)
{
	char	*map_str;
	char	**map_arr;
	t_game	*game;

	map_str = read_map(map);
	check_map(map_str);
	map_arr = ft_split(map_str, '\n');
	game = init_game_struct(map_arr);
	check_path(game);
	free(map_str);
	return (game);
}

t_game	*init_game_struct(char **map_arr)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		exit_with_error("Memory allocation error!", true);
	game->width = ft_strlen(map_arr[0]);
	game->height = count_y(map_arr);
	game->map_grid = map_arr;
	game->moves = 0;
	game->collectibles = count_collectibles(game);
	game->player_x = get_pos(game, 'x', 'P');
	game->player_y = get_pos(game, 'y', 'P');
	game->exit_x = get_pos(game, 'x', 'E');
	game->exit_y = get_pos(game, 'y', 'E');
	return (game);
}

// TODO; change var names- bric_wall and grass

t_img	*init_img_struct(mlx_t *mlx)
{
	t_img	*images;

	images = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!images)
		return (NULL);
	load_grass_texture(mlx, images);
	load_brick_wall_texture(mlx, images);
	load_collectible_texture(mlx, images);
	load_player_texture(mlx, images);
	load_player_right_texture(mlx, images);
	load_player_left_texture(mlx, images);
	load_player_down_texture(mlx, images);
	load_player_up_texture(mlx, images);
	load_exit_closed(mlx, images);
	load_exit_open(mlx, images);
	load_enemy_texture(mlx, images);
	return (images);
}
