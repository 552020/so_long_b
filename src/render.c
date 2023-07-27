/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:41:35 by slombard          #+#    #+#             */
/*   Updated: 2023/07/27 19:41:46 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_background(t_game *game)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->img->ground,
					x * PIXELS, y * PIXELS) < 0)
				exit_with_error("Error while loading an image", false);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game, size_t y, size_t x)
{
	if (mlx_image_to_window(game->mlx, game->img->player,
			x * PIXELS, y * PIXELS) < 0)
		exit_with_error("Error while loading an image", false);
	game->img->player->instances[0].enabled = true;
	if (mlx_image_to_window(game->mlx, game->img->player_right,
			x * PIXELS, y * PIXELS) < 0)
		exit_with_error("Error while loading an image", false);
	game->img->player_right->instances[0].enabled = false;
	if (mlx_image_to_window(game->mlx, game->img->player_left,
			x * PIXELS, y * PIXELS) < 0)
		exit_with_error("Error while loading an image", false);
	game->img->player_left->instances[0].enabled = false;
	if (mlx_image_to_window(game->mlx, game->img->player_up,
			x * PIXELS, y * PIXELS) < 0)
		exit_with_error("Error while loading an image", false);
	game->img->player_up->instances[0].enabled = false;
	if (mlx_image_to_window(game->mlx, game->img->player_down,
			x * PIXELS, y * PIXELS) < 0)
		exit_with_error("Error while loading an image", false);
	game->img->player_down->instances[0].enabled = false;
}

void	render_image(t_game *game, size_t y, size_t x)
{
	size_t	img_size;

	img_size = 32;
	if (game->map_grid[y][x] == '1')
		if (mlx_image_to_window(game->mlx, game->img->wall,
				x * PIXELS, y * PIXELS) < 0)
			exit_with_error("Error while loading an image", false); 
	if (game->map_grid[y][x] == 'C')
		if (mlx_image_to_window(game->mlx, game->img->collectible,
				x * PIXELS + img_size / 2, y * PIXELS + img_size / 2) < 0)
			exit_with_error("Error while loading an image", false);
	if (game->map_grid[y][x] == 'E')
		if (mlx_image_to_window(game->mlx, game->img->exit_closed,
				x * PIXELS, y * PIXELS) < 0)
			exit_with_error("Error while loading an image", false);
	if (game->map_grid[y][x] == 'X')
		if (mlx_image_to_window(game->mlx, game->img->enemy,
				x * PIXELS, y * PIXELS) < 0)
			exit_with_error("Error while loading an image", false);
	if (game->map_grid[y][x] == 'P')
		render_player(game, y, x);
}

void	render_map(t_game *game)
{
	size_t		x;
	size_t		y;

	render_background(game);
	x = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_image(game, y, x);
			x++;
		}
		y++;
	}
}
