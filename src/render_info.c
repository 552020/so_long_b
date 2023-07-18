#include "../include/so_long.h"

void	render_info(t_game *game)
{
	mlx_put_string(game->mlx, "MOVES:",
			(game->width - (game->width - 1) ) * PIXELS, (game->height - 0.8) * PIXELS);
	mlx_image_to_window(game->mlx, game->img->collectible,
		(game->width - (game->width - 1)) * PIXELS, (game->height - 0.6) * PIXELS);
	mlx_put_string(game->mlx, ":", (game->width - (game->width - 1.8)) * PIXELS,
		(game->height - 0.5) * PIXELS);
	render_moves(game);
	render_collected(game);
	
}

void	render_moves(t_game *game)
{
	char	*moves_str;

	moves_str = ft_itoa(game->moves);
	mlx_delete_image(game->mlx, game->img->count_moves);
	game->img->count_moves = mlx_put_string(game->mlx, moves_str,
			(game->width - (game->width - 2)) * PIXELS, (game->height - 0.8) * PIXELS);
	free(moves_str);
}

void	render_collected(t_game *game)
{
	char	*collected_str;

	collected_str = ft_itoa(game->collected);
	mlx_delete_image(game->mlx, game->img->collectibles_count);
	game->img->collectibles_count = mlx_put_string(game->mlx, collected_str,
			(game->width - (game->width -2)) * PIXELS, (game->height - 0.5) * PIXELS);
	free(collected_str);
}
