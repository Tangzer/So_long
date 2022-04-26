/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:19:09 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 16:59:05 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:18:33 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 15:18:34 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_taille_map(t_personnage *pers)
{
	int	x;
	int	y;

	y = 0;
	x = pers->map.map_size_x;
	if (x == 0)
	{
		ft_printf("Error : La première ligne du fichier de la map est vide.\n");
		exit(EXIT_SUCCESS);
	}
	while (y < pers->map.map_size_y)
	{
		if ((int)ft_strlen(pers->map.map_mem[y]) != x)
		{
			ft_printf("Error : La map n'est pas homologuée.\n");
			exit(EXIT_SUCCESS);
		}
		y++;
	}
}

void	walls_protect_line(t_personnage *pers)
{
	int	x;
	int	y;

	y = 0;
	while (pers->map.map_mem[y])
	{
		x = 0;
		while (pers->map.map_mem[y][x])
		{
			if (pers->map.map_mem[0][x] != '1')
			{
				ft_printf("Error : Il manque un/plusieurs murs dans la map.\n");
				exit(EXIT_SUCCESS);
			}
			if (pers->map.map_mem[pers->map.map_size_y - 1][x] != '1')
			{
				ft_printf("Error : Il manque un/plusieurs murs dans la map.\n");
				exit(EXIT_SUCCESS);
			}
			x++;
		}
		y++;
	}
}

void	walls_protect_columns(t_personnage *pers)
{
	int	i;

	i = 0;
	while (i < pers->map.map_size_y)
	{
		if (pers->map.map_mem[i][0] != '1')
		{
			ft_printf("Error : Il manque un/plusieurs murs dans la map.\n");
			exit(EXIT_SUCCESS);
		}
		if (pers->map.map_mem[i][pers->map.map_size_x - 1] != '1')
		{
			ft_printf("Error : Il manque un/plusieurs murs dans la map.\n");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	check_contenu_indispensable(t_personnage *pers)
{
	if (pers->map.collectible < 1)
	{
		ft_printf("Error : Il faut au moins 1 item dans la map.\n");
		exit(EXIT_SUCCESS);
	}
	if (pers->map.exit < 1)
	{
		ft_printf("Error : Il manque un EXIT dans la map.\n");
		exit(EXIT_SUCCESS);
	}
	if (pers->map.position < 1)
	{
		ft_printf("Error : Il doit y avoir au moins 1 point de départ.\n");
		exit(EXIT_SUCCESS);
	}
	if (pers->map.position > 1)
	{
		ft_printf("Error : Il peut y avoir maximum 1 point de départ.\n");
		exit(EXIT_SUCCESS);
	}
}

int	protect_map(t_personnage *pers)
{
	check_taille_map(pers);
	walls_protect_line(pers);
	walls_protect_columns(pers);
	check_contenu_indispensable(pers);
	return (0);
}
