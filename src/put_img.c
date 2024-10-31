/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 05:53:18 by huidris           #+#    #+#             */
/*   Updated: 2024/10/30 20:23:24 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
wal = wall;		ext = exit;
flw = flower;	fld = field;
up 	= up;		dwn = down;
lef = left;		rit = right;
*/
void	load_images(t_data *map)
{
	int	x;
	int	y;

	map->img.wal = mlx_xpm_file_to_image(map->mlx, "img/wal.xpm", &x, &y);
	map->img.ext = mlx_xpm_file_to_image(map->mlx, "img/ext.xpm", &x, &y);
	map->img.flw = mlx_xpm_file_to_image(map->mlx, "img/flw.xpm", &x, &y);
	map->img.fld = mlx_xpm_file_to_image(map->mlx, "img/fld.xpm", &x, &y);
	map->img.up = mlx_xpm_file_to_image(map->mlx, "img/up.xpm", &x, &y);
	map->img.dwn = mlx_xpm_file_to_image(map->mlx, "img/dwn.xpm", &x, &y);
	map->img.lef = mlx_xpm_file_to_image(map->mlx, "img/lef.xpm", &x, &y);
	map->img.rit = mlx_xpm_file_to_image(map->mlx, "img/rit.xpm", &x, &y);
}

void	load_map(t_data *map, int keysym)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->win,
					map->img.wal, j * 64, i * 64);
			if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->win,
					map->img.fld, j * 64, i * 64);
			if (map->map[i][j] == 'P')
				put_player(map, keysym, i, j);
			if (map->map[i][j] == 'C')
				put_collectible(map, i, j);
			if (map->map[i][j] == 'E')
				put_exit(map, i, j);
		}
	}
}

void	put_player(t_data *mp, int keysym, int i, int j)
{
	if (keysym == 13 || keysym == 126)
		mlx_put_image_to_window(mp->mlx, mp->win, mp->img.up, j * 64, i * 64);
	if (keysym == 0 || keysym == 123)
		mlx_put_image_to_window(mp->mlx, mp->win, mp->img.lef, j * 64, i * 64);
	if (keysym == 1 || keysym == 125)
		mlx_put_image_to_window(mp->mlx, mp->win, mp->img.dwn, j * 64, i * 64);
	if (keysym == 2 || keysym == 124)
		mlx_put_image_to_window(mp->mlx, mp->win, mp->img.rit, j * 64, i * 64);
}

void	put_collectible(t_data *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img.flw, j * 64, i * 64);
}

void	put_exit(t_data *mp, int i, int j)
{
	mlx_put_image_to_window(mp->mlx, mp->win, mp->img.ext, j * 64, i * 64);
}
