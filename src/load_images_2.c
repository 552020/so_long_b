/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slombard <slombard@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:19:44 by slombard          #+#    #+#             */
/*   Updated: 2023/07/27 20:19:46 by slombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemy_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png(ENEMY_PATH);
	if (!enemy)
		exit_with_error("Error while loading png - enemy", false);
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy)
		exit_with_error("Error while loading the image - enemy", false);
	mlx_delete_texture(enemy);
}
