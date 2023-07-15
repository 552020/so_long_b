/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:32:25 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/08 17:33:15 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	write_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
	exit (1);
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
