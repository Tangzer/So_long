
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_mms_20200219/mlx.h"
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct	s_maps
{
	void 	*img_wall;
	void 	*img_floor;
	void 	*img_collect;
	void 	*img_exit;
	char 	**map_mem;
	int 	map_size_x;
	int 	map_size_y;
}				t_maps;

typedef struct	s_personnage
{
	t_coord coord;
	t_maps 	map;
	void 	*mlx;
	void 	*windows;
	void 	*img;
	int 	moves;
	int 	click;
}				t_personnage;

char	*get_next_line(int fd);
int		map_size_x(void);
int 	map_size_y(void);
int		destroy_window(int key);
int 	valid_move(t_personnage *pers, int key);
void	init_coord(t_personnage *pers);

#endif