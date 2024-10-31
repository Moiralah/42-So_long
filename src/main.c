/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:50:29 by huidris           #+#    #+#             */
/*   Updated: 2024/11/01 01:58:47 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_exit(char *str)
{
	ft_putstr_fd ("Error", 2);
	ft_printf (": %s", str);
	ft_printf ("\n");
	exit (1);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window (data->mlx, data->win);
	free (data->mlx);
	exit (0);
	return (0);
}

int	key__hook(int keysym, t_data *map)
{
	t_pmove	playermove;

	map->player = 0;
	char_pos (map->map, &playermove, map, 'P');
	movement (map, &playermove, keysym);
	load_map (map, keysym);
	return (1);
}

void	movement(t_data *map, t_pmove *player, int keysym)
{
	if (keysym == 0 || keysym == 123)
		move_left (map, player);
	else if (keysym == 1 || keysym == 125)
		move_down (map, player);
	else if (keysym == 2 || keysym == 124)
		move_right (map, player);
	else if (keysym == 13 || keysym == 126)
		move_up (map, player);
	else if (keysym == 53)
	{
		ft_printf ("LAZY BEE\n");
		mlx_destroy_window (map->mlx, map->win);
		free(map->mlx);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	data = (t_data){0};
	check_map (&data, av);
	data.mlx = mlx_init ();
	data.win = mlx_new_window (data.mlx, 64 * data.width, 64 * data.row, "BEE");
	load_images (&data);
	load_map (&data, 2);
	mlx_hook (data.win, 2, 1L << 0, key__hook, &data);
	mlx_hook (data.win, 17, 1L << 0, &on_destroy, &data);
	mlx_loop (data.mlx);
	return (0);
}
