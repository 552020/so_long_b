/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:44:50 by bsengeze          #+#    #+#             */
/*   Updated: 2023/07/11 22:45:32 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player;

	// player = mlx_load_png("./sprites/Player.png");
	player = mlx_load_png("./sprites/Player.png");
	if (!player)
		exit_with_error("Error while loading png", false);
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(player);
}

void	load_player_right_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player_right;

	player_right = mlx_load_png("./sprites/Player_Right.png");
	if (!player_right)
		exit_with_error("Error while loading png", false);
	img->player_right = mlx_texture_to_image(mlx, player_right);
	if (!img->player_right)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(player_right);
}

void	load_player_left_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player_left;

	player_left = mlx_load_png("./sprites/Player_Left.png");
	if (!player_left)
		exit_with_error("Error while loading png", false);
	img->player_left = mlx_texture_to_image(mlx, player_left);
	if (!img->player_left)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(player_left);
}

void	load_player_up_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player_up;

	player_up = mlx_load_png("./sprites/Player_Up.png");
	if (!player_up)
		exit_with_error("Error while loading png", false);
	img->player_up = mlx_texture_to_image(mlx, player_up);
	if (!img->player_up)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(player_up);
}

void	load_player_down_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player_down;

	player_down = mlx_load_png("./sprites/Player_Down.png");
	if (!player_down)
		exit_with_error("Error while loading png", false);
	img->player_down = mlx_texture_to_image(mlx, player_down);
	if (!img->player_down)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(player_down);
}
