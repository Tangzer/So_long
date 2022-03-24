#include "so_long.h"

void	start_position(t_personnage *pers, int x, int y)
{
	pers->coord.x = x * 28;
	pers->coord.y = y * 28;
	pers->map.P++;
	mlx_put_image_to_window(pers->mlx, pers->win,
							pers->map.img_floor, x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win,
							pers->perso_r, x * 28, y * 28);
}

void	collectible(t_personnage *pers, int x, int y)
{
	pers->map.C++;
	mlx_put_image_to_window(pers->mlx, pers->win,
							pers->map.img_floor, x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win,
							pers->map.img_collect, x * 28, y * 28);
}

void	exit_position(t_personnage *pers, int x, int y)
{
	pers->map.E++;
	mlx_put_image_to_window(pers->mlx, pers->win,
							pers->map.img_floor, x * 28, y * 28);
}

void	floor_position(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win,
							pers->map.img_floor, x * 28, y * 28);
}

void	wall_position(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win,
							pers->map.img_wall, x * 28, y * 28);
}