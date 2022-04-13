/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:12:29 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 15:12:48 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_position(t_personnage *pers, int x, int y)
{
	pers->coord.x = x * 28;
	pers->coord.y = y * 28;
	pers->map.position++;
	mlx_put_image_to_window(pers->mlx, pers->win,
		pers->map.img_floor, x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win,
		pers->perso_r, x * 28, y * 28);
}

void	collectible_position(t_personnage *pers, int x, int y)
{
	pers->map.collectible++;
	mlx_put_image_to_window(pers->mlx, pers->win,
		pers->map.img_floor, x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win,
		pers->map.img_collect, x * 28, y * 28);
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

void	boucle_init_map(t_personnage *pers, char *line, int x, int y)
{
	while (line[x])
	{
		if (line[x] == 'P')
			start_position(pers, x, y);
		if (line[x] == '1')
			wall_position(pers, x, y);
		if (line[x] == '0')
			floor_position(pers, x, y);
		if (line[x] == 'C')
			collectible_position(pers, x, y);
		if (line[x] == 'E')
			exit_position(pers, x, y);
		if (line[x] == 'Z')
			enemy_position(pers, x, y);
		x++;
	}
}
