/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 05:36:39 by huidris           #+#    #+#             */
/*   Updated: 2024/10/27 02:31:49 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(t_data *map, t_pmove *p)
{
	if (map->map[p->x][p->y -1] == 'E' && map->col == 0)
		win_exit (map);
	else if (map->map[p->x][p->y -1] != '1' && map->map[p->x][p->y -1] != 'E')
	{
		if (map->map[p->x][p->y -1] == 'C')
			map->col--;
		map->map[p->x][p->y -1] = 'P';
		map->map[p->x][p->y] = '0';
		map->moves++;
		ft_printf ("MOVES: %d\n", map->moves);
	}
}

void	move_up(t_data *map, t_pmove *p)
{
	if (map->map[p->x -1][p->y] == 'E' && map->col == 0)
		win_exit (map);
	else if (map->map[p->x -1][p->y] != '1' && map->map[p->x -1][p->y] != 'E')
	{
		if (map->map[p->x -1][p->y] == 'C')
			map->col--;
		map->map[p->x -1][p->y] = 'P';
		map->map[p->x][p->y] = '0';
		map->moves++;
		ft_printf ("MOVES: %d\n", map->moves);
	}
}

void	move_right(t_data *map, t_pmove *p)
{
	if (map->map[p->x][p->y +1] == 'E' && map->col == 0)
		win_exit (map);
	else if (map->map[p->x][p->y +1] != '1' && map->map[p->x][p->y +1] != 'E')
	{
		if (map->map[p->x][p->y +1] == 'C')
			map->col--;
		map->map[p->x][p->y +1] = 'P';
		map->map[p->x][p->y] = '0';
		map->moves++;
		ft_printf ("MOVES: %d\n", map->moves);
	}
}

void	move_down(t_data *map, t_pmove *p)
{
	if (map->map[p->x + 1][p->y] == 'E' && map->col == 0)
		win_exit (map);
	else if (map->map[p->x + 1][p->y] != '1' && map->map[p->x + 1][p->y] != 'E')
	{
		if (map->map[p->x +1][p->y] == 'C')
			map->col--;
		map->map[p->x + 1][p->y] = 'P';
		map->map[p->x][p->y] = '0';
		map->moves++;
		ft_printf("MOVES: %d\n", map->moves);
	}
}

void	win_exit(t_data *map)
{
	map->moves++;
	ft_printf ("MOVES: %d\n", map->moves);
	ft_printf ("CONGRATULATION!!! OUR BEE OF THE DAY\n");
	mlx_destroy_window (map->mlx, map->win);
	exit (0);
}
