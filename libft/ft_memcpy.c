/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:56 by huidris           #+#    #+#             */
/*   Updated: 2024/03/14 22:10:27 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_ptr;
	char	*src_ptr;

	if (!src && !dst)
		return (NULL);
	i = 0;
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst_ptr);
}

/*
#include <stdio.h>
int	main()
{
	char str[] = "holla";
	char dst[10];
	ft_memcpy(dst, str, 2);
	printf("%s\n", str);
	printf("%s\n", dst);
}
*/
