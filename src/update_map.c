/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:18:10 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 16:18:12 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_map_collectible(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_floor,
		x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_collect,
		x * 28, y * 28);
}

void	update_map_exit(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_floor,
		x * 28, y * 28);
	if (pers->map.collectible == 0)
		mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_exit,
			x * 28, y * 28);
}

void	update_map_enemy(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_floor,
		x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_enemy,
		x * 28, y * 28);
}

void	update_map_floor(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_floor,
		x * 28, y * 28);
}

void	update_map_wall(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win, pers->map.img_wall,
		x * 28, y * 28);
}
