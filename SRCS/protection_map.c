#include "so_long.h"

void walls_protect(t_personnage *pers)
{
	int x;
	int y;

	y = 0;
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
}

void check_taille_map(t_personnage *pers)
{
	int x;
	int y;

	y = 0;
	x = pers->map.map_size_x;
	if (x == 0)
	{
		ft_printf("La première ligne dans le fichier de la map est vide.\n");
		exit(EXIT_SUCCESS);
	}
	while (y < pers->map.map_size_y)
	{
		if ((int)ft_strlen(pers->map.map_mem[y]) != x)
		{
			ft_printf("La map n'est pas homologuée.\n");
			exit(EXIT_SUCCESS);
		}
		y++;
	}
}

void check_contenu(t_personnage *pers)
{
	if (pers->map.E != 1)
	{
		ft_printf("Il peut seulement y avoir 1 EXIT dans la map.\n");
		exit(EXIT_SUCCESS);
	}
	if (pers->map.P != 1)
	{
		ft_printf("Il peut seulement y avoir 1 point de départ dans la map.\n");
		exit(EXIT_SUCCESS);
	}
}

int protect_map(t_personnage *pers)
{
	check_taille_map(pers);
	walls_protect(pers);
	check_contenu(pers);
	return (0);
}