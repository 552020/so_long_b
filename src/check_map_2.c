// TODO change to absolute path
#include "../include/so_long.h"

void	throw_errors_for_check_map_values(int player, int exit, int collectables)
{
	if (player == 0)
		exit_with_error("Invalid map! There is no player! This might by zen, but it will not work!", false);
	else if (player > 1)
		exit_with_error("Invalid map! There is more than one player! Multi-player mode still in prgress...", false);
	if (exit == 0)
		exit_with_error("Invalid map! There is no exit! Without an exit, you will not be able to exit the game. Are you sure this is what you want? You could be late for dinner.", false);
	else if (exit > 1)
		exit_with_error("Invalid map! There is more than one exit! Only one exit is allowed.", false);
	if (collectables < 1)
		exit_with_error("Invalid map! There are no collectibles! Without any collectibles to collect, you will not be able to collect any of them any, the exit will never open, and you will be stuck in the game for the rest of your life. Are you sure this is what you want?", false);
}
void	check_map_values(char *map)
{
	int	player;
	int	collectables;
	int	exit;
	int	i;

	player = 0;
	exit = 0;
	collectables = 0;
	i = 0;
	while (map[i])
	{
		if (!(ft_strchr("PECX01\n", map[i])))
			exit_with_error("Invalid values in the map file! The allowed character are P, E, C, X, 0 and 1.", false);
		if (map[i] == 'P')
			player++;
		else if (map[i] == 'C')
			collectables++;
		else if (map[i] == 'E')
			exit++;
		i++;
	}
	if (player != 1 || exit != 1 || collectables < 1)
		throw_errors_for_check_map_values(player, exit, collectables);
}


void	wall_check_horizontal(char *map)
{
	size_t	i;
	size_t	width;
	size_t	map_len;

	i = 0;
	width = 0;
	map_len = ft_strlen(map);
	while (map[i] != '\0')
	{
		while (map[i] != '\n' && map[i] != '\0')
		{
			if (map[i] != '1')
				exit_with_error("The wall should delimitate the gaming area. This is not the case.", false);
			i++;
			width++;
		}
		i = map_len - width;
		while (map[i] != '\0')
		{
			if (map[i] != '1')
				exit_with_error("The wall should delimitate the gaming area. This is not the case.", false);
			i++;
		}
	}
}

void	wall_check_vertical(char *map)
{
	size_t	i;
	size_t	width;
	size_t	map_len;

	i = 0;
	width = 0;
	map_len = ft_strlen(map);
	while (map[i] != '\0')
	{
		while (map[i] != '\n')
		{
			i++;
			width++;
		}
		i++;
		while (i < map_len - width -1)
		{
			if (map[i] != '1' || map[i + width -1] != '1')
				exit_with_error("The wall should delimitate the gaming area. This is not the case.", false);
			i = i + width + 1;
		}
		i = i + width;
	}
}


void	wrong_wall(char *map)
{
	wall_check_horizontal(map);
	wall_check_vertical(map);
}
