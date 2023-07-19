#include "../include/so_long.h"

void 	check_escape(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

void	enemy_hook(void *tmp)
{
	const t_game	*game;
	size_t			count;
	static int		i;

	game = tmp;
	count = 0;
	kill_check(game);
	if (i++ < 60)
		return ;
	while (count < game->img->enemy->count)
	{
		move_enemies (game, count);
		count++;
	}
	i = 0;
}

void	main_loop_hook(void *tmp)
{
	t_game	*game;
	
	game = (t_game *)tmp;
	check_escape(game);
	mlx_loop_hook(game->mlx, enemy_hook, game);
	mlx_loop(game->mlx);
}