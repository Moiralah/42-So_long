/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:49:06 by huidris           #+#    #+#             */
/*   Updated: 2024/03/16 17:27:42 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_ptr;
	char	*s2_ptr;

	if (n == 0)
		return (0);
	i = 0;
	s1_ptr = (char *)s1;
	s2_ptr = (char *)s2;
	while (n--)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return ((unsigned char)s1_ptr[i] - (unsigned char)s2_ptr[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char str1[] = "Hello";
    char str2[] = "Hella";
    int result = ft_memcmp(str1, str2, 5);
	printf("%d\n", result);
}
*/
