/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:48:49 by huidris           #+#    #+#             */
/*   Updated: 2024/03/16 16:13:30 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_ptr;

	i = 0;
	str_ptr = (unsigned char *)s;
	while (i < n)
	{
		if (str_ptr[i] == (unsigned char)c)
			return ((void *)(str_ptr + i));
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
    char str[] = "Holla";
    unsigned char *result = ft_memchr(str, 'l', 3);
    printf("%c\n", *result);
}
*/
