#include "../include/so_long.h"

void	load_enemy_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("./sprites/Enemy.png");
	if (!enemy)
		exit_with_error("Error while loading png", false);
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy)
		exit_with_error("Error while loading the image", false);
	mlx_delete_texture(enemy);
}