#include "so_long.h"
/////////////////////
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

int map()
{
	int x;
	int y;
	int fd;
	char *line;
	char **res;

	fd = open("./Maps/map1.ber",O_RDONLY);
	line = get_next_line(fd);

	return (0);
}

int deal_key(int key, t_personnage *pers)
{
	printf("Coord %d --- %d\nkey = %d\n", pers->coord.x, pers->coord.y, key);
	if (key == 2 || key == 124)
	{
		mlx_clear_window(pers->mlx, pers->windows);
		mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x + 28, pers->coord.y);
		pers->coord.x = pers->coord.x + 28;
	}
	if (key == 0 || key == 123)
	{
		mlx_clear_window(pers->mlx, pers->windows);
		mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x - 28, pers->coord.y);
		pers->coord.x = pers->coord.x - 28;
	}
	if (key == 1 || key == 125)
	{
		mlx_clear_window(pers->mlx, pers->windows);
		mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x, pers->coord.y + 53);
		pers->coord.y = pers->coord.y + 53;
	}
	if (key == 13 || key == 126)
	{
		mlx_clear_window(pers->mlx, pers->windows);
		mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x, pers->coord.y - 53);
		pers->coord.y = pers->coord.y - 53;
	}
	return (0);
}

int main()
{
	int		height;
	int 	width;

	t_personnage andrew;
	if (!andrew.coord.x && !andrew.coord.y)
	{
		andrew.coord.x = 0;
		andrew.coord.y = 0;
	}
	andrew.mlx = mlx_init();
	andrew.windows = mlx_new_window(andrew.mlx, 600, 500, "Andrew's adventure");
	andrew.img = mlx_xpm_file_to_image(andrew.mlx, "Textures/andrew-front.xpm", &width, &height);
	mlx_put_image_to_window(andrew.mlx, andrew.windows, andrew.img, 0, 0);
	mlx_key_hook(andrew.windows, deal_key, &andrew);
	mlx_loop(andrew.mlx);
}