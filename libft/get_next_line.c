/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:13:39 by huidris           #+#    #+#             */
/*   Updated: 2024/09/19 01:45:24 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)--s);
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*buffer_add(char *buffer_all, char *buffer)
{
	char	*temp;

	temp = ft_strjoingnl(buffer_all, buffer);
	if (!temp)
		return (free(buffer_all), NULL);
	free(buffer_all);
	return (temp);
}

char	*read_file(char *buffer_all, int fd)
{
	int		rd;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0)
		{
			if (buffer_all && *buffer_all == '\0')
				return (free(buffer_all), free(buffer), NULL);
			return (free(buffer), buffer_all);
		}
		buffer[rd] = '\0';
		buffer_all = buffer_add(buffer_all, buffer);
		if (!buffer_all)
			return (free(buffer_all), free(buffer), NULL);
		if (ft_strchr(buffer_all, '\n'))
			break ;
	}
	free(buffer);
	return (buffer_all);
}

char	*extract_line(char *buffer_all, int check)
{
	char	*buffer;
	char	*line;
	size_t	line_len;

	if (check == 0)
	{
		line = ft_strchr(buffer_all, '\n');
		line_len = (size_t)(line - buffer_all) + 1;
		buffer = ft_substr(buffer_all, 0, line_len);
		if (!buffer)
			return (NULL);
	}
	if (check == 1)
	{
		line = ft_strchr(buffer_all, '\n');
		if (!line)
			return (free(buffer_all), NULL);
		line_len = ft_strlen(line + 1);
		buffer = ft_calloc(line_len + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		ft_strlcpy(buffer, line + 1, line_len + 1);
		free(buffer_all);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer_all[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buffer_all[fd] || !ft_strchr(buffer_all[fd], '\n'))
		buffer_all[fd] = read_file(buffer_all[fd], fd);
	if (!buffer_all[fd])
		return (NULL);
	line = extract_line(buffer_all[fd], 0);
	if (!line)
		return (free(buffer_all[fd]), NULL);
	buffer_all[fd] = extract_line(buffer_all[fd], 1);
	if (buffer_all[fd] && *buffer_all[fd] == 0)
	{
		free(buffer_all[fd]);
		buffer_all[fd] = NULL;
	}
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*next_line;
	int		countline;

	//int     sz;
	//char    isi[] = "\0";
	countline = 0;
	fd = open("null.txt", O_RDONLY ); //| O_CREAT);
	//sz = write(fd, isi, ft_strlen(isi));
	if (fd == -1)
	{
		printf("Error Opening File");
		return (0);
	}
	while (1)
	{
	next_line = get_next_line(fd);
	if (next_line == NULL)
		break ;
	countline++;
	printf("[%d]:%s\n", countline, next_line);
	free(next_line);
	next_line = NULL;
	}
	close(fd);
	return (0);
	// size_t read (int fd, void *buf, size_t buf_len);
}
*/

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("bic.txt", O_RDONLY | O_CREAT);
// 	if (fd == -1)
// 	{
// 		printf("error opening file\n");
// 		return (0);
// 	}
// 	line = get_next_line(fd);
// 	printf("\nthis is line1: %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("\nthis is line2: %s\n", line);
//     // line = get_next_line(fd);
// 	// printf("\nthis is line3: %s\n", line);
//     // line = get_next_line(fd);
// 	// printf("\nthis is line4: %s\n", line);
// 	close(fd);
//     system("leaks a.out");
// }