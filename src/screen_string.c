#include "../include/so_long.h"

void	screen_str(t_game *game)
{
	mlx_put_string(game->mlx, "MOVES:",
			(game->width - 3) * PIXELS, game->height * PIXELS - 48);
	mlx_image_to_window(game->mlx, game->img->collectible,
		(game->width - 1.6) * PIXELS, game->height * PIXELS - 55);
	mlx_put_string(game->mlx, ":", (game->width - 1.2) * PIXELS,
		game->height * PIXELS - 48);
}

void	print_moves(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->moves);
	mlx_delete_image(game->mlx, game->img->count_moves);
	game->img->count_moves = mlx_put_string(game->mlx, moves_str,
			(game->width - 2) * PIXELS, game->height * PIXELS - 48);
	free(moves_str);
}

void	print_collectibles(t_game *game)
{
	char	*string;

	string = ft_itoa(game->collected + 1);
	mlx_delete_image(game->mlx, game->img->collectibles_count);
	game->img->collectibles_count = mlx_put_string(game->mlx, string,
			(game->width - 1) * PIXELS, game->height * PIXELS - 48);
	free(string);
}
