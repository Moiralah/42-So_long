/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:14:45 by huidris           #+#    #+#             */
/*   Updated: 2024/11/01 01:55:31 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map(t_data *map, char **argv)
{
	char	*file;

	check_name (argv[1]);
	file = argv[1];
	map_parsing (file, map);
}

void	map_parsing(char *file, t_data *map)
{
	char	*content;
	char	*temp;
	int		fd;
	char	**mapcopy;

	fd = open (file, O_RDONLY);
	if (fd == -1)
		error_exit ("Open file failed");
	file = get_next_line (fd);
	while (file)
	{
		content = get_next_line (fd);
		if (!content)
			break ;
		temp = file;
		file = ft_strjoin (temp, content);
		free (temp);
		free (content);
	}
	close (fd);
	mapcopy = ft_split (file, '\n');
	map_valid (mapcopy, map);
	free_map(mapcopy);
	map->map = ft_split (file, '\n');
	free (file);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	map_valid(char **map, t_data *data)
{
	t_pmove	p;

	check_rect (map, data);
	check_wall (map, data);
	check_char(map, data);
	char_pos (map, &p, data, 'E');
	char_pos (map, &p, data, 'C');
	char_pos (map, &p, data, 'P');
	flood_fill (map, p.x, p.y, data);
	char_pos (map, &p, data, 'X');
	char_pos (map, &p, data, 'C');
	char_pos (map, &p, data, 'E');
}
