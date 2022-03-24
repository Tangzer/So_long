#include "so_long.h"

void	update_map_collectible(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_floor,
							x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_collect,
							x * 28, y * 28);
}

void	update_map_exit(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_floor,
						 x * 28, y * 28);
	if (pers->map.C == 0)
		mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_exit,
						  x * 28, y * 28);
}

void 	orientation_perso(t_personnage *pers)
{
	if (pers->right == 1)
		mlx_put_image_to_window(pers->mlx, pers->win, pers->perso_r,
								pers->coord.x, pers->coord.y);
	else
		mlx_put_image_to_window(pers->mlx, pers->win, pers->perso_l,
								pers->coord.x, pers->coord.y);
}