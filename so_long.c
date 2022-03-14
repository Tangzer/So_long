#include "so_long.h"
#include <unistd.h>
#include <stdio.h>

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_personnage
{
	t_coord coord;
	void *mlx;
	void *windows;
	void *img;
}				t_personnage;

int deal_key(int key, t_personnage *pers)
{
	printf("Coord %d --- %d\n", pers->coord.x, pers->coord.y);
	if (key == 2)
	{
		mlx_clear_window(pers->mlx, pers->windows);
		mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x + 28, 10);
		pers->coord.x = pers->coord.x + 28;
	}
	return (0);
}

int main()
{
	int		height;
	int 	width;

	t_personnage tanguy;
	if (!tanguy.coord.x && !tanguy.coord.y)
	{
		tanguy.coord.x = 10;
		tanguy.coord.y = 10;
	}
	tanguy.mlx = mlx_init();
	tanguy.windows = mlx_new_window(tanguy.mlx, 600, 500, "Tanguy's so_long");
//	while ()
//	{
//		mlx_pixel_put(mlx_ptr, window_ptr, 10, 10, 0xFFFF3F);
//	}

	tanguy.img = mlx_xpm_file_to_image(tanguy.mlx, "Textures/andrew-front.xpm", &width, &height);
	mlx_put_image_to_window(tanguy.mlx, tanguy.windows, tanguy.img, 10, 10);
	mlx_key_hook(tanguy.windows, deal_key, &tanguy);
	mlx_loop(tanguy.mlx);
}