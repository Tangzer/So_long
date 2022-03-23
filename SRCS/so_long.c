#include "so_long.h"

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
			if (pers->right == 1)
				mlx_put_image_to_window(pers->mlx, pers->windows, pers->perso_r, pers->coord.x, pers->coord.y);
			else
				mlx_put_image_to_window(pers->mlx, pers->windows, pers->perso_l, pers->coord.x, pers->coord.y);
			if (maps->map_mem[y][x] == '1')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_wall, x * 28, y * 28);
			if (maps->map_mem[y][x] == '0' || maps->map_mem[y][x] == 'P')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
			if (maps->map_mem[y][x] == 'C')
			{
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_collect, x * 28, y * 28);
			}
			if (maps->map_mem[y][x] == 'E')
			{
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				if (pers->map.C == 0)
					mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_exit, x * 28, y * 28);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map(t_maps *maps, t_personnage *pers, char **map)
{
	int x;
	int y;
	int fd;
	char *line;
	char *res;

	res = malloc(1);
	res[0] = 0;
	fd = open(*map, O_RDONLY);
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
				pers->map.P++;
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, pers->perso_r, x * 28, y * 28);
			}
			if (line[x] == '1')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_wall, x * 28, y * 28);
			if (line[x] == '0')
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
			if (line[x] == 'C')
			{
				pers->map.C++;
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_collect, x * 28, y * 28);
			}
			if (line[x] == 'E')
			{
				pers->map.E++;
				mlx_put_image_to_window(pers->mlx, pers->windows, maps->img_floor, x * 28, y * 28);
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
	horizontal_mvt(pers, key);
	vertical_mvt(pers, key);
	ft_map_update(maps, pers);
	ft_printf("Total moves : %d\n", pers->moves);
	return (0);
}

int main(int argc, char **argv)
{
	int		height;
	int 	width;

	if (argc == 2)
	{
		t_personnage andrew;
		andrew.moves = 0;
		andrew.map.C = 0;
		andrew.map.E = 0;
		andrew.map.P = 0;
		andrew.mlx = mlx_init();
		andrew.map.map_size_x = map_size_x();
		andrew.map.map_size_y = map_size_y();

		andrew.windows = mlx_new_window(andrew.mlx, map_size_x() * 28, map_size_y() * 28, "Adventure");
		andrew.map.img_floor = mlx_xpm_file_to_image(andrew.mlx,"Textures/floor.xpm", &width, &height);
		andrew.map.img_wall = mlx_xpm_file_to_image(andrew.mlx,"Textures/wall.xpm", &width, &height);
		andrew.map.img_collect = mlx_xpm_file_to_image(andrew.mlx,"Textures/collectible.xpm", &width, &height);
		andrew.map.img_exit = mlx_xpm_file_to_image(andrew.mlx,"Textures/exit.xpm", &width, &height);
		andrew.perso_r = mlx_xpm_file_to_image(andrew.mlx, "Textures/andrew_right.xpm", &width, &height);
		andrew.perso_l = mlx_xpm_file_to_image(andrew.mlx, "Textures/andrew_left.xpm", &width, &height);

		ft_map(&andrew.map, &andrew, argv);
		protect_map(&andrew);

		mlx_key_hook(andrew.windows, deal_key, &andrew);
		mlx_hook(andrew.windows, 17, 0L, destroy_window, andrew.windows);
		mlx_loop(andrew.mlx);
	}
	return (0);
}