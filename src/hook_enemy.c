#include "../include/so_long.h"

void	kill_check(t_game *game)
{
	size_t	count;

	count = 0;
	while (count < game->img->enemy->count)
	{
		if (game->player_x * PIXELS
			== (size_t)game->img->enemy->instances[count].x
			&& game->player_y * PIXELS
			== (size_t)game->img->enemy->instances[count].y)
		{
			mlx_close_window(game->mlx);
			ft_putendl_fd("Oooops, you lost!", 1);
			ft_putendl_fd("Try again!", 1);
		}
		count++;
	}
}

void	move_enemies(t_game *game, int count)
{
	t_tmp			tmp;

	tmp.x = &game->img->enemy->instances[count].x;
	tmp.y = &game->img->enemy->instances[count].y;
	tmp.ran_x = (rand() % 3 - 1) * 64;
	tmp.ran_y = (rand() % 3 - 1) * 64;
	tmp.index_x = *tmp.x + tmp.ran_x;
	tmp.index_y = *tmp.y + tmp.ran_y;
	if (tmp.index_x != 0)
		tmp.index_x /= PIXELS;
	if (tmp.index_y != 0)
		tmp.index_y /= PIXELS;
	if (game->map_grid[tmp.index_y][tmp.index_x] != '1'
		&& game->map_grid[tmp.index_y][tmp.index_x] != 'E')
	{
		*tmp.x += tmp.ran_x;
		*tmp.y += tmp.ran_y;
	}
}

void	enemy_hook(t_game *game)
{
	size_t			count;
	static int		i;

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