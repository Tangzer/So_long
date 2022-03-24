#include "so_long.h"

void boucle_init_map(t_personnage *pers, char *line, int x, int y)
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
			collectible(pers, x, y);
		if (line[x] == 'E')
			exit_position(pers, x, y);
		x++;
	}
}