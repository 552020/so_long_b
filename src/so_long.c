/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:29:24 by slombard          #+#    #+#             */
/*   Updated: 2023/07/15 12:42:00 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	//TODO: create a macro for the error message
	if (argc != 2)
		exit_with_error("To play the game run ./so_long with some .ber map file!", false);
	check_file_extension(argv[1]);
	game = init_game(argv[1]);
	game->mlx = mlx_init(game->width * PIXELS,
			game->height * PIXELS, "so_long", true);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->img = init_img_struct(game->mlx);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	render_map(game);
	render_info(game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop_hook(game->mlx, main_loop_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	return (0);
}
