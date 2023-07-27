/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:33:29 by slombard          #+#    #+#             */
/*   Updated: 2023/07/27 20:33:54 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(const char *msg, bool is_system_error)
{
	if (is_system_error)
		perror(msg);
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd((char *)msg, 2);
	}
	exit(1);
}

void	free_game(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map_grid[i]);
		i++;
	}
	free(game->map_grid);
	free(game->img);
	free(game);
}

void	pick_collectibles(t_game *game, int y, int x)
{
	size_t	collectible_i;

	collectible_i = 0;
	x = x * PIXELS + 16;
	y = y * PIXELS + 16;
	while (collectible_i < game->img->collectible->count)
	{
		if (game->img->collectible->instances[collectible_i].x == x
			&& game->img->collectible->instances[collectible_i].y == y)
		{
			game->img->collectible->instances[collectible_i].enabled = false;
		}
		collectible_i++;
	}
}
