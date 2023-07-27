/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:12:33 by slombard          #+#    #+#             */
/*   Updated: 2023/07/27 20:13:47 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: Maybe a small animation for when the player dies?
void	check_kill(t_game *game)
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
			ft_putendl_fd("Oooops, you have been killed!", 1);
			ft_putendl_fd("Start the game again, \
			if you don't have anything better to do!", 1);
		}
		count++;
	}
}

void	move_enemies(t_game *game, int count)
{
	t_enemy_move	enemy_move;

	enemy_move.pos_x = &game->img->enemy->instances[count].x;
	enemy_move.pos_y = &game->img->enemy->instances[count].y;
	enemy_move.x_increment = (rand() % 3 - 1) * 64;
	enemy_move.y_increment = (rand() % 3 - 1) * 64;
	enemy_move.next_x = *enemy_move.pos_x + enemy_move.x_increment;
	enemy_move.next_y = *enemy_move.pos_y + enemy_move.y_increment;
	if (enemy_move.next_x != 0)
		enemy_move.next_x /= PIXELS;
	if (enemy_move.next_y != 0)
		enemy_move.next_y /= PIXELS;
	if (game->map_grid[enemy_move.next_y][enemy_move.next_x] != '1'
		&& game->map_grid[enemy_move.next_y][enemy_move.next_x] != 'E')
	{
		*enemy_move.pos_x += enemy_move.x_increment;
		*enemy_move.pos_y += enemy_move.y_increment;
	}
}

void	enemy_hook(t_game *game)
{
	size_t			count;
	static double	initial_time;
	double			current_time;

	current_time = mlx_get_time();
	if (initial_time == 0)
		initial_time = current_time;
	count = 0;
	check_kill(game);
	if (current_time - initial_time < 1.0)
		return ;
	while (count < game->img->enemy->count)
	{
		move_enemies (game, count);
		count++;
	}
	initial_time = current_time;
}
