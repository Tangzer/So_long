#include "so_long.h"

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
