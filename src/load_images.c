/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:23:40 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/11 18:25:30 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	*load_grass_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("./sprites/Grass.png");
	if (!grass)
		exit_with_error("Error while loading png", false);
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(grass);
	return (img);
}

t_img	*load_brick_wall_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*brick_wall;

	brick_wall = mlx_load_png("./sprites/Brick_Wall.png");
	if (!brick_wall)
		exit_with_error("Error while loading png", false);
	img->brick_wall = mlx_texture_to_image(mlx, brick_wall);
	if (!img->brick_wall)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture (brick_wall);
	return (img);
}

t_img	*load_collectible_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*collectible;

	collectible = mlx_load_png("./sprites/Collectible.png");
	if (!collectible)
		exit_with_error("Error while loading png", false);
	img->collectible = mlx_texture_to_image(mlx, collectible);
	if (!img->collectible)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(collectible);
	return (img);
}

t_img	*load_exit_closed(mlx_t *mlx, t_img	*img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./sprites/Exit_Closed.png");
	if (!exit)
		exit_with_error("Error while loading png", false);
	img->exit_closed = mlx_texture_to_image(mlx, exit);
	if (!img->exit_closed)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(exit);
	return (img);
}

t_img	*load_exit_open(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("./sprites/Exit_Open.png");
	if (!exit)
		exit_with_error("Error while loading png", false);
	img->exit_open = mlx_texture_to_image(mlx, exit);
	if (!img->exit_open)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(exit);
	return (img);
}
