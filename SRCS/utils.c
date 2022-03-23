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
	close(fd);
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