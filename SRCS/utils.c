#include "so_long.h"

int	map_size_x(void)
{
	int		x;
	int 	fd;
	char	*line;

	fd = open("./Maps/map1.ber",O_RDONLY);
	line = get_next_line(fd);
	x = 0;
	while (line && line[x])
		x++;
	close(fd);
	free(line);
	return (--x);
}

int map_size_y(void)
{
	int 	y;
	int 	fd;
	char	*collumn;

	fd = open("./Maps/map1.ber",O_RDONLY);
	collumn = get_next_line(fd);
	y = 0;
	while (collumn && collumn[y])
	{
		collumn = get_next_line(fd);
		y++;
	}
	free(collumn);
	return (y);
}

int destroy_window(int key)
{
	if(key)
		exit(EXIT_SUCCESS);
	return (0);
}

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

void init_coord(t_personnage *pers)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (y < map_size_y())
	{
		while (x < map_size_x())
		{
			if (pers->map.map_mem[x][y] == 'P')
			{
				pers->coord.x = x * 28;
				pers->coord.y = y * 28;
			}
			x++;
		}
		y++;
	}
}