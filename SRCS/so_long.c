#include "so_long.h"
/////////////////////
#include <stdio.h>

int protect_map(t_personnage *pers)
{
	int x;
	int y;
	int sample;

	y = 0;
	sample = map_size_x();
	while (pers->map.map_mem[y])
	{
		x = 0;
		while (pers->map.map_mem[y][x])
		{
			if (pers->map.map_mem[0][x] != '1')
			{
				ft_printf("Il y manque un ou plusieurs murs en haut de la map\n");
				exit(EXIT_SUCCESS);
			}
			if (pers->map.map_mem[map_size_y() - 1][x] != '1')
			{
				ft_printf("Il y manque un ou plusieurs murs en bas de la map\n");
				exit(EXIT_SUCCESS);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map_update(t_maps *maps, t_personnage *pers)
{
	int y;
	int x;

	y = 0;
	while (y < pers->map.map_size_y)
	{
		x = 0;
		while (x < pers->map.map_size_x)
		{
			mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, pers->coord.x, pers->coord.y);
			if (maps->map_mem[y][x] == '1')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_wall, x * 28, y * 28);
			if (maps->map_mem[y][x] == '0')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
			if (maps->map_mem[y][x] == 'P')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
			if (maps->map_mem[y][x] == 'C')
			{
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_collect, x * 28, y * 28);
			}
			if (maps->map_mem[y][x] == 'E')
			{
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_exit, x * 28, y * 28);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map(t_maps *maps, t_personnage *pers)
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
				pers->coord.x = x * 28;
				pers->coord.y = y * 28;
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, pers->img, x * 28, y * 28);
			}
			if (line[x] == '1')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_wall, x * 28, y * 28);
			if (line[x] == '0')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
			if (line[x] == 'C')
			{
				pers->map.collectible++;
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_collect, x * 28, y * 28);
			}
			if (line[x] == 'E')
			{
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_exit, x * 28, y * 28);
			}
			x++;
		}
		res = ft_strjoin(res, line);
		line = get_next_line(fd);
		y++;
	}
	maps->map_mem = ft_split(res, '\n');
	free(line);
	free(res);
	return (0);
}

int deal_key(int key, t_personnage *pers)
{
	t_maps *maps;
	maps = &pers->map;
	mlx_clear_window(pers->mlx, pers->windows);
	if (key == 53)
		exit(EXIT_SUCCESS);
	if ((key == 2 || key == 124) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.x += 28;
//		pers.img = mlx_xpm_file_to_image(pers.mlx, "Textures/andrew_right.xpm", &width, &height);
		check_collectible_or_exit(pers);
	}
	if ((key == 0 || key == 123) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.x -= 28;
//		pers->img = mlx_xpm_file_to_image(pers->mlx, "Textures/andrew_left.xpm", &width, &height);
		check_collectible_or_exit(pers);
	}
	if ((key == 1 || key == 125) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.y += 28;
		check_collectible_or_exit(pers);
	}
	if ((key == 13 || key == 126) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.y -= 28;
		check_collectible_or_exit(pers);
	}
	ft_map_update(maps, pers);
	ft_printf("Total moves : %d\n", pers->moves);
	return (0);
}

int main()
{
	int		height;
	int 	width;

	t_personnage andrew;
	andrew.moves = 0;
	andrew.map.collectible = 0;
	andrew.mlx = mlx_init();
	andrew.windows = mlx_new_window(andrew.mlx, map_size_x() * 28, map_size_y() * 28, "Andrew's adventure");

	andrew.map.map_size_x = map_size_x();
	andrew.map.map_size_y = map_size_y();
	andrew.map.img_floor = mlx_xpm_file_to_image(andrew.mlx,"Textures/floor.xpm", &width, &height);
	andrew.map.img_wall = mlx_xpm_file_to_image(andrew.mlx,"Textures/wall.xpm", &width, &height);
	andrew.map.img_collect = mlx_xpm_file_to_image(andrew.mlx,"Textures/collectible.xpm", &width, &height);
	andrew.map.img_exit = mlx_xpm_file_to_image(andrew.mlx,"Textures/exit.xpm", &width, &height);
	andrew.img = mlx_xpm_file_to_image(andrew.mlx, "Textures/andrew_right.xpm", &width, &height);

	ft_map(&andrew.map, &andrew);
	protect_map(&andrew);

	mlx_key_hook(andrew.windows, deal_key, &andrew);
	mlx_hook(andrew.windows, 17, 0L, destroy_window, andrew.windows);
	mlx_loop(andrew.mlx);
}