/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 05:03:28 by huidris           #+#    #+#             */
/*   Updated: 2024/11/01 01:59:18 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int i, int j, t_data *data)
{
	if (map[i][j] == '1' || map[i][j] == 'X' || map[i][j] == 'Y')
		return ;
	if (map[i][j] == 'E')
	{
		map[i][j] = 'Y';
		return ;
	}
	else
		map[i][j] = 'X';
	flood_fill (map, i - 1, j, data);
	flood_fill (map, i + 1, j, data);
	flood_fill (map, i, j - 1, data);
	flood_fill (map, i, j + 1, data);
}

	// for (int i = 0; map[i] != NULL; i++)
	// {
	//		printf("Map Line %d: %s\n", i, map[i]);
	// }
	// flood fill print map.

void	char_pos(char **map, t_pmove *player, t_data *data, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->width)
		{
			if (map[i][j] == c)
			{
				player->x = i;
				player->y = j;
				check_element (data, c);
			}
			j++;
		}
		i++;
	}
	elementxfound (data, c);
}

void	check_element(t_data *data, char c)
{
	if (c == 'E')
	{
		if (data->fill != 0)
			error_exit ("HIVE cannot be access.");
		data->ext += 1;
	}
	if (c == 'X')
		data->fill++;
	else if (c == 'P')
		data->player += 1;
	else if (c == 'C')
	{
		if (data->fill != 0)
			error_exit ("There is HONEY stashed somewhere.");
		data->col += 1;
	}
}

void	elementxfound(t_data *data, char c)
{
	if (c == 'E' && data->ext == 0)
		error_exit ("The BEE need a home, homie.");
	else if (c == 'E' && data->ext > 1)
		error_exit ("One BEE one HIVE policy.");
	else if (c == 'P' && data->player == 0)
		error_exit ("Where is the BEE, BABEE.");
	else if (c == 'P' && data->player > 1)
		error_exit ("To BEE, not TWO BEE.");
	else if (c == 'C' && data->col == 0)
		error_exit ("No HONEY no talk.");
}
