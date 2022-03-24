#include "so_long.h"

int valid_move(t_personnage *pers, int key)
{
	if ((key == 2 || key == 124) && pers->map.map_mem[pers->coord.y / 28][(pers->coord.x + 28) / 28] != '1')
		return (1);
	if ((key == 0 || key == 123) && pers->map.map_mem[pers->coord.y / 28][(pers->coord.x - 28) / 28] != '1')
		return (1);
	if ((key == 1 || key == 125) && pers->map.map_mem[(pers->coord.y + 28) / 28][pers->coord.x / 28] != '1')
		return (1);
	if ((key == 13 || key == 126) && pers->map.map_mem[(pers->coord.y - 28) / 28][pers->coord.x / 28] != '1')
		return (1);
	return (0);
}

void check_collectible_or_exit(t_personnage *pers)
{
	if (pers->map.map_mem[pers->coord.y / 28][pers->coord.x / 28] == 'C')
	{
		pers->map.map_mem[pers->coord.y / 28][pers->coord.x / 28] = '0';
		pers->map.C--;
		ft_map_update(&pers->map, pers);
	}
	if (pers->map.map_mem[pers->coord.y / 28][pers->coord.x / 28] == 'E' && pers->map.C == 0)
		exit(EXIT_SUCCESS);
}

void horizontal_mvt(t_personnage *pers, int key)
{
	if ((key == 2 || key == 124) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.x += 28;
		pers->right = 1;
		check_collectible_or_exit(pers);
	}
	if ((key == 0 || key == 123) && valid_move(pers, key))
	{
		pers->moves++;
		pers->coord.x -= 28;
		pers->right = 0;
		check_collectible_or_exit(pers);
	}
}

void vertical_mvt(t_personnage *pers, int key)
{
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
}