/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:41:45 by huidris           #+#    #+#             */
/*   Updated: 2024/10/31 00:31:35 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <mlx.h>

typedef struct s_img
{
	void	*wal;
	void	*ext;
	void	*flw;
	void	*fld;
	void	*up;
	void	*dwn;
	void	*lef;
	void	*rit;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		img;
	int			col;
	int			ext;
	int			player;
	int			row;
	int			width;
	int			moves;
	int			fill;
}	t_data;

typedef struct player_move
{
	int	x;
	int	y;
}	t_pmove;

// main function
// main.c
void	error_exit(char *str);
int		on_destroy(t_data *data);
int		key__hook(int keysym, t_data *map);
void	movement(t_data *map, t_pmove *player, int keysym);

// initialize struct and map
// init.c
void	initialize(t_data *map);
void	check_map(t_data *map, char **argv);
void	map_parsing(char *file, t_data *map);
void	map_valid(char **map, t_data *data);

// map checking function
// check_map.c
void	check_name(char *av);
void	check_rect(char **map, t_data *data);
void	check_wall(char **map, t_data *data);
void	check_char(char **map, t_data *data);

// map path check
// flood_fill.c
void	flood_fill(char **map, int i, int j, t_data *data);
void	char_pos(char **map, t_pmove *player, t_data *data, char c);
void	check_element(t_data *data, char c);
void	elementxfound(t_data *data, char c);

// rendering all image
// put_image.c
void	load_images(t_data *map);
void	load_map(t_data *map, int keysym);
void	put_player(t_data *map, int keysym, int i, int j);
void	put_collectible(t_data *map, int i, int j);
void	put_exit(t_data *map, int i, int j);

// movement function
// key_hook.c
void	move_left(t_data *map, t_pmove *p);
void	move_up(t_data *map, t_pmove *p);
void	move_right(t_data *map, t_pmove *p);
void	move_down(t_data *map, t_pmove *p);
void	win_exit(t_data *map);

void	free_map(char **map);

#endif
