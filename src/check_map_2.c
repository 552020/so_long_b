/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:43:09 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/08 17:13:49 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO change to absolute path
#include "../include/so_long.h"

void	check_if_map_is_empty(char *map)
{
	if (!*map)
		exit_with_error("The map is a string, which is good. But the string is empty! No good. Load a valid map!", false);
}

void	check_for_empty_lines(char *map)
{
	char *map_tmp;

	map_tmp = map;
	if (*map_tmp == '\n')
		exit_with_error("Empty line in map!", false);
	while (*map_tmp)
	{
		if ((*map_tmp == '\n' && *(map_tmp + 1) == '\n'))
			exit_with_error("Empty line in map!", false);
		map_tmp++;
	}
}

void	wrong_content(char *map)
{
	int	player;
	int	collectibles;
	int	exit;
	int	i;

	player = 0;
	exit = 0;
	collectibles = 0;
	i = 0;
	while (map[i])
	{
		if (!(ft_strchr("PECX01\n", map[i])))
			exit_with_error("Invalid characters in the map file!", false);
		if (map[i] == 'P')
			player++;
		if (map[i] == 'C')
			collectibles++;
		if (map[i] == 'E')
			exit++;
		i++;
	}
	if (player != 1 || exit != 1 || collectibles < 1)
		exit_with_error("Invalid map! The map contains more than 1 player or more than 1 exit or no collectibles at all!", false);
}

void	wrong_shape(char *map)
{
	size_t	curr_line_len;
	size_t	i;
	size_t	len;

	curr_line_len = 0;
	i = 0;
	len = 0;
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			i++;
			curr_line_len++;
		}
		if (len == 0)
			len = curr_line_len;
		else if (curr_line_len != len)
			exit_with_error("Invalid map! The map is not rectangular!", false);
		curr_line_len = 0;
		if (map[i] == '\n')
			i++;
	}
}

void	wrong_wall(char *map)
{
	wall_check_horizontal(map);
	wall_check_vertical(map);
}
