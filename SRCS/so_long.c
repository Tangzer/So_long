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

typedef struct	s_maps
{
	void *img_wall;
	void *img_floor;
	void *img_collectible;
	char **map;
}				t_maps;

int	ft_map_update(t_maps *maps, t_personnage *perso_map)
{
	int y;
	int x;

	y = 0;
	while (maps->map[y])
	{
		x = 0;
		while (maps->map[y][x])
		{
			if (maps->map[y][x] == '1')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_wall, x * 28, y * 28);
			if (maps->map[y][x] == '0')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
//			if (line[x] == 'C')
//			{
//
//			}
//			if (line[x] == 'E')
//			{
//
//			}
			x++;
		}
		y++;
	}
	return (0);
}

int ft_map(t_maps *maps, t_personnage *perso_map)
{
	int x;
	int y;
	int fd;
	char *line;
	char *res;
//	res = malloc(1);
//	res[0] = 0;
	fd = open("./Maps/map1.ber",O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == '1')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_wall, x * 28, y * 28);
			if (line[x] == '0')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
//			if (line[x] == 'C')
//			{
//
//			}
//			if (line[x] == 'E')
//			{
//
//			}
			x++;
		}
		res = ft_strjoin(res, line);
		line = get_next_line(fd);
		y++;
	}
	maps->map = ft_split(res, '\n');
	return (0);
}

int deal_key(int key, t_personnage *pers, t_maps *maps)
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
		mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x, pers->coord.y + 28);
		pers->coord.y = pers->coord.y + 28;
	}
	if (key == 13 || key == 126)
	{
		mlx_clear_window(pers->mlx, pers->windows);
		mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x, pers->coord.y - 28);
		pers->coord.y = pers->coord.y - 28;
	}
	ft_map_update(maps, pers);
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
	andrew.windows = mlx_new_window(andrew.mlx, 500, 500, "Andrew's adventure");

	t_maps maps;
	maps.img_floor = mlx_xpm_file_to_image(andrew.mlx,"Textures/floor.xpm", &width, &height);
	maps.img_wall = mlx_xpm_file_to_image(andrew.mlx,"Textures/wall.xpm", &width, &height);
	maps.img_collectible = mlx_xpm_file_to_image(andrew.mlx,"Textures/collectible.xpm", &width, &height);
	andrew.img = mlx_xpm_file_to_image(andrew.mlx, "Textures/andrew1.xpm", &width, &height);

	ft_map(&maps, &andrew);

	mlx_put_image_to_window(andrew.mlx, andrew.windows, andrew.img, 0, 0);
	mlx_key_hook(andrew.windows, deal_key, &andrew);
	mlx_loop(andrew.mlx);

}