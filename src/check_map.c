/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:38:42 by huidris           #+#    #+#             */
/*   Updated: 2024/10/27 07:21:00 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_name(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (av[i - 4] == '.')
		if (av[i - 3] == 'b')
			if (av[i - 2] == 'e')
				if (av[i - 1] == 'r')
					return ;
	error_exit ("Invalid file format. Please input '.ber' format.");
}

void	check_rect(char **map, t_data *data)
{
	int	temp;
	int	i;

	data->width = ft_strlen (map[0]);
	i = -1;
	while (map[++i])
	{
		temp = ft_strlen (map[i]);
		if (temp != data->width)
			error_exit ("Invalid map. Map shape not uniform");
	}
	data->row = i;
	if (data->row == data->width)
		error_exit ("Invalid map. Only rectangle map accepted.");
}

void	check_wall(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->width)
	{
		if (map[0][i] != '1' || map[data->row - 1][i] != '1')
			error_exit ("Invalid wall. Only '1' accepted for map outer layer.");
		i++;
	}
	while (j < data->row)
	{
		if (map[j][0] != '1' || map[j][data->width - 1] != '1')
			error_exit ("Invalid wall. Only '1' accepted for map outer layer.");
		j++;
	}
	return ;
}

void	check_char(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->width)
		{
			if (map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'P' &&
					map[i][j] != 'E' && map[i][j] != '0')
				error_exit ("Invalid character found in map.");
			else
				j++;
		}
		i++;
	}
}
