/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:03:05 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 16:03:35 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_update(t_maps *map, t_personnage *pers)
{
	int	y;
	int	x;

	y = 0;
	while (y < pers->map.map_size_y)
	{
		x = 0;
		while (x < pers->map.map_size_x)
		{
			orientation_perso(pers);
			if (map->map_mem[y][x] == '1')
				update_map_wall(pers, x, y);
			if (map->map_mem[y][x] == '0' || map->map_mem[y][x] == 'P')
				update_map_floor(pers, x, y);
			if (map->map_mem[y][x] == 'C')
				update_map_collectible(pers, x, y);
			if (map->map_mem[y][x] == 'E')
				update_map_exit(pers, x, y);
			if (map->map_mem[y][x] == 'Z')
				update_map_enemy(pers, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_map(t_maps *maps, t_personnage *pers, char *map, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	*res;
	char	*temp;

	res = ft_calloc(1, 1);
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		x = 0;
		boucle_init_map(pers, line, x, y);
		temp = res;
		res = ft_strjoin(res, line);
		if (!res)
			exit(EXIT_SUCCESS);
		ft_free(temp, line);
		y++;
		check_if_empty_first_line(line);
		line = get_next_line(fd);
	}
	maps->map_mem = ft_split(res, '\n');
	ft_free(line, res);
	return (0);
}

int	deal_key(int key, t_personnage *pers)
{
	t_maps	*maps;
	char	*str;

	maps = &pers->map;
	mlx_clear_window(pers->mlx, pers->win);
	if (key == 53)
		exit(EXIT_SUCCESS);
	horizontal_mvt(pers, key);
	vertical_mvt(pers, key);
	ft_map_update(maps, pers);
	ft_printf("Total moves : %d\n", pers->moves);
	str = ft_itoa(pers->moves);
	if (!str)
		exit(EXIT_FAILURE);
	mlx_string_put(pers->mlx, pers->win, 10, 3, 0xFFFFFF, "Moves : ");
	mlx_string_put(pers->mlx, pers->win, 90, 3, 0xFFFFFF, str);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_personnage	max;
	int				fd;

	fd = 0;
	ft_parsing(argv);
	if (argc == 2)
	{
		ft_initialize_struct_var(&max);
		max.mlx = mlx_init();
		if (!max.mlx)
			exit(EXIT_FAILURE);
		max.map.map_size_x = map_size_x(argv[1]);
		max.map.map_size_y = map_size_y(argv[1]);
		max.win = mlx_new_window(max.mlx, map_size_x(argv[1]) * 28,
				map_size_y(argv[1]) * 28, "So_long");
		if (!max.win)
			exit(EXIT_FAILURE);
		ft_load_images(&max);
		ft_map(&max.map, &max, argv[1], fd);
		protect_map(&max);
		mlx_key_hook(max.win, deal_key, &max);
		mlx_hook(max.win, 17, 0L, destroy_window, max.win);
		mlx_loop(max.mlx);
	}
	return (0);
}
