/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:20:22 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 16:22:53 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_size_x(char *map)
{
	int		x;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	while (line && line[x])
		x++;
	close(fd);
	free(line);
	return (--x);
}

int	map_size_y(char *map)
{
	int		y;
	int		fd;
	char	*collumn;

	fd = open(map, O_RDONLY);
	collumn = get_next_line(fd);
	y = 0;
	while (collumn && collumn[y])
	{
		free(collumn);
		collumn = get_next_line(fd);
		y++;
	}
	close(fd);
	free(collumn);
	return (y);
}

int	destroy_window(int key)
{
	if (key)
		exit(EXIT_SUCCESS);
	return (0);
}

void	ft_initialize_struct_var(t_personnage *max)
{
	max->moves = 0;
	max->map.collectible = 0;
	max->map.exit = 0;
	max->map.position = 0;
}

void	ft_load_images(t_personnage *max)
{
	int	width;
	int	heigth;

	max->map.img_floor = mlx_xpm_file_to_image(max->mlx, "Textures/floor.xpm",
			&width, &heigth);
	max->map.img_wall = mlx_xpm_file_to_image(max->mlx, "Textures/wall.xpm",
			&width, &heigth);
	max->map.img_collect = mlx_xpm_file_to_image(max->mlx, "Textures/item.xpm",
			&width, &heigth);
	max->map.img_exit = mlx_xpm_file_to_image(max->mlx, "Textures/exit.xpm",
			&width, &heigth);
	max->perso_r = mlx_xpm_file_to_image(max->mlx, "Textures/max_right.xpm",
			&width, &heigth);
	max->perso_l = mlx_xpm_file_to_image(max->mlx, "Textures/max_left.xpm",
			&width, &heigth);
	max->map.img_enemy = mlx_xpm_file_to_image(max->mlx, "Textures/enemy.xpm",
			&width, &heigth);
	return ;
}
