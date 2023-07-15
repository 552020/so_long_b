/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:41:29 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/11 22:50:41 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*load_enemy_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./sprites/Enemy.png");
	if (!enemy)
		write_error("Error while loading png");
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy)
		write_error("Error during texture to image");
	mlx_delete_texture(enemy);
	return (img);
}
