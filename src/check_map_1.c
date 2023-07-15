/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:24:01 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/10 20:37:56 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/so_long.h"

void	check_file_extension(char *map_file)
{
	char	*extension;

	extension = ft_strrchr(map_file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 5) != 0)
		exit_with_error("The map file should be .ber file", false);
}

void	check_map(char *map_str)
{
	check_if_map_is_empty(map_str);
	check_for_empty_lines(map_str);
	wrong_content(map_str);
	wrong_shape(map_str);
	wrong_wall(map_str);
}



