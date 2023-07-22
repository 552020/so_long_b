#include "so_long.h"

void 	check_escape(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}


void	main_loop_hook(void *game_void_ptr)
{
	t_game	*game;
	
	game = (t_game *)game_void_ptr;
	check_escape(game);
	enemy_hook(game);
}