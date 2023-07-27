/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:20:05 by slombard          #+#    #+#             */
/*   Updated: 2023/07/27 20:32:01 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hook(mlx_key_data_t keydata, void *tmp)
{
	t_game	*game;

	game = (t_game *) tmp;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_right(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_left(game);
}

t_game	*move_up(t_game *game)
{
	if (game->map_grid[game->player_y - 1][game->player_x] != '1'
		&& game->map_grid[game->player_y - 1][game->player_x] != 'E')
	{
		if (game->map_grid[game->player_y - 1][game->player_x] == 'C')
		{
			pick_collectibles(game, game->player_y - 1, game->player_x);
			game->collected += 1;
			render_collected(game);
			game->map_grid[game->player_y - 1][game->player_x] = '0';
		}
		move_up_core(game);
	}
	render_moves(game);
	check_win(game);
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (game->map_grid[game->player_y + 1][game->player_x] != '1'
		&& game->map_grid[game->player_y + 1][game->player_x] != 'E')
	{
		if (game->map_grid[game->player_y + 1][game->player_x] == 'C')
		{
			pick_collectibles(game, game->player_y + 1, game->player_x);
			game->collected += 1;
			render_collected(game);
			game->map_grid[game->player_y + 1][game->player_x] = '0';
		}
		move_down_core(game);
	}
	render_moves(game);
	check_win(game);
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (game->map_grid[game->player_y][game->player_x + 1] != '1'
		&& game->map_grid[game->player_y][game->player_x + 1] != 'E')
	{
		if (game->map_grid[game->player_y][game->player_x + 1] == 'C')
		{
			pick_collectibles(game, game->player_y, game->player_x + 1);
			game->collected += 1;
			render_collected(game);
			game->map_grid[game->player_y][game->player_x + 1] = '0';
		}
		move_right_core(game);
	}
	render_moves(game);
	check_win(game);
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (game->map_grid[game->player_y][game->player_x - 1] != '1'
		&& game->map_grid[game->player_y][game->player_x - 1] != 'E')
	{
		if (game->map_grid[game->player_y][game->player_x - 1] == 'C')
		{
			pick_collectibles(game, game->player_y, game->player_x - 1);
			game->collected += 1;
			render_collected(game);
			game->map_grid[game->player_y][game->player_x - 1] = '0';
		}
		move_left_core(game);
	}
	render_moves(game);
	check_win(game);
	return (game);
}
