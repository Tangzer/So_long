
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
	int 	C;
	int		E;
	int 	P;
	int 	map_size_x;
	int 	map_size_y;
}				t_maps;

typedef struct	s_personnage
{
	t_coord coord;
	t_maps 	map;
	void 	*mlx;
	void 	*win;
	void 	*perso_r;
	void 	*perso_l;
	int 	moves;
	int 	right;
}				t_personnage;

char	*get_next_line(int fd);
int		map_size_x(char *map);
int 	map_size_y(char *map);
int		destroy_window(int key);
int 	valid_move(t_personnage *pers, int key);
void	check_collectible_or_exit(t_personnage *pers);
int		ft_map_update(t_maps *maps, t_personnage *pers);
int		protect_map(t_personnage *pers);
void	ft_parsing(char **argv);

void	horizontal_mvt(t_personnage *pers, int key);
void	vertical_mvt(t_personnage *pers, int key);

void	ft_load_images(t_personnage *max);
void	ft_initialize_struct_var(t_personnage *max);

void	update_map_collectible(t_personnage *pers, int x, int y);
void	update_map_exit(t_personnage *pers, int x, int y);
void 	orientation_perso(t_personnage *pers);

void	start_position(t_personnage *pers, int x, int y);
void	collectible(t_personnage *pers, int x, int y);
void	exit_position(t_personnage *pers, int x, int y);
void	wall_position(t_personnage *pers, int x, int y);
void	floor_position(t_personnage *pers, int x, int y);
void	boucle_init_map(t_personnage *pers, char *line, int x, int y);

#endif