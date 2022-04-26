/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:13:17 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 15:38:59 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_position(t_personnage *pers, int x, int y)
{
	pers->map.exit++;
	mlx_put_image_to_window(pers->mlx, pers->win,
		pers->map.img_floor, x * 28, y * 28);
}

void	enemy_position(t_personnage *pers, int x, int y)
{
	mlx_put_image_to_window(pers->mlx, pers->win,
		pers->map.img_floor, x * 28, y * 28);
	mlx_put_image_to_window(pers->mlx, pers->win,
		pers->map.img_enemy, x * 28, y * 28);
}

void	orientation_perso(t_personnage *pers)
{
	if (pers->right == 1)
		mlx_put_image_to_window(pers->mlx, pers->win, pers->perso_r,
			pers->coord.x, pers->coord.y);
	else
		mlx_put_image_to_window(pers->mlx, pers->win, pers->perso_l,
			pers->coord.x, pers->coord.y);
}
