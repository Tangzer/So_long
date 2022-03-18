#include "so_long.h"
/////////////////////
#include <stdio.h>

int	ft_map_update(t_maps *maps, t_personnage *perso_map)
{
	int y;
	int x;

	y = 0;
	while (y < perso_map->pers_map.map_size_y)
	{
		x = 0;
		while (x < perso_map->pers_map.map_size_x)
		{
			mlx_put_image_to_window(perso_map->mlx, perso_map->windows, perso_map->img, perso_map->coord.x, perso_map->coord.y);
			if (maps->map[y][x] == '1')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_wall, x * 28, y * 28);
			if (maps->map[y][x] == '0')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
			if (maps->map[y][x] == 'P')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
			if (maps->map[y][x] == 'C')
			{
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_collect, x * 28, y * 28);
			}
			if (maps->map[y][x] == 'E')
			{
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_exit, x * 28, y * 28);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map(t_maps *maps, t_personnage *perso_map)
{
	int x;
	int y;
	int fd;
	char *line;
	char *res;

	res = malloc(1);
	res[0] = 0;
	fd = open("./Maps/map1.ber",O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = 0;
		while (line[x])
		{
			if (line[x] == 'P')
			{
				perso_map->coord.x = x * 28;
				perso_map->coord.y = y * 28;
				printf("x = %d --- y = %d\n", perso_map->coord.x, perso_map->coord.y);
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, perso_map->img, x * 28, y * 28);
			}
			if (line[x] == '1')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_wall, x * 28, y * 28);
			if (line[x] == '0')
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
			if (line[x] == 'C')
			{
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_collect, x * 28, y * 28);
			}
			if (line[x] == 'E')
			{
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(perso_map->mlx, perso_map->windows, maps->img_exit, x * 28, y * 28);
			}
			x++;
		}
		res = ft_strjoin(res, line);
		line = get_next_line(fd);
		y++;
	}
	maps->map = ft_split(res, '\n');
	return (0);
}

int deal_key(int key, t_personnage *pers)
{
	pers->click++;
	t_maps *maps;
	maps = &pers->pers_map;
	printf("Coord %d --- %d\nkey = %d\n", pers->coord.x, pers->coord.y, key);
	mlx_clear_window(pers->mlx, pers->windows);
	if (key == 53)
		exit(0);
	if ((key == 2 || key == 124) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.x += 28;
	}
	if ((key == 0 || key == 123) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.x -= 28;
	}
	if ((key == 1 || key == 125) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.y += 28;
	}
	if ((key == 13 || key == 126) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.y -= 28;
	}
	ft_map_update(maps, pers);
	ft_printf("Total moves : %d\n", pers->moves);
	ft_printf("Total clicks : %d\n", pers->click);
	return (0);
}

int main()
{
	int		height;
	int 	width;

	t_personnage andrew;
	andrew.moves = 0;
	andrew.click = 0;
	printf("Coord %d --- %d\n", andrew.coord.x, andrew.coord.y);
	andrew.mlx = mlx_init();
	andrew.windows = mlx_new_window(andrew.mlx, map_size_x() * 28, map_size_y() * 28, "Andrew's adventure");
	andrew.pers_map.map_size_x = map_size_x();
	andrew.pers_map.map_size_y = map_size_y();
	andrew.pers_map.img_floor = mlx_xpm_file_to_image(andrew.mlx,"Textures/floor.xpm", &width, &height);
	andrew.pers_map.img_wall = mlx_xpm_file_to_image(andrew.mlx,"Textures/wall.xpm", &width, &height);
	andrew.pers_map.img_collect = mlx_xpm_file_to_image(andrew.mlx,"Textures/collectible.xpm", &width, &height);
	andrew.pers_map.img_exit = mlx_xpm_file_to_image(andrew.mlx,"Textures/exit.xpm", &width, &height);
	andrew.img = mlx_xpm_file_to_image(andrew.mlx, "Textures/andrew1.xpm", &width, &height);

	ft_map(&andrew.pers_map, &andrew);
	mlx_key_hook(andrew.windows, deal_key, &andrew);
	mlx_hook(andrew.windows, 17, 0L, destroy_window, andrew.windows);
	mlx_loop(andrew.mlx);
}