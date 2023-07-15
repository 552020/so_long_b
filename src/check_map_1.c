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

void	map_check(char *map_str)
{
	empty_map(map_str);
	empty_lines(map_str);
	wrong_content(map_str);
	wrong_shape(map_str);
	wrong_wall(map_str);
}


void	check_file_extension(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(file_name + len - 4, ".ber", 4))
		exit_with_error("The map file should be .ber file", false);
}
