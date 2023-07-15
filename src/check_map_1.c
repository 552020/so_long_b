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
	check_map_values(map_str);
	check_map_shape(map_str);
	wrong_wall(map_str);
}

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

void	check_map_shape(char *map)
{
	size_t	map_width;
	size_t	i;
	size_t	line_len;

	map_width = 1;
	i = 0;
	line_len = 1;
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			line_len++;
			i++;
		}
		if (map_width == 1)	
			map_width = line_len;
		else if (map_width != line_len)
			exit_with_error("Invalid map! The map should be a rectangular! Or a square at least!", false);
		line_len = 1;
		if (map[i] == '\n')
			i++;
	}
}



