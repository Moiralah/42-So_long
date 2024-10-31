/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:42:11 by huidris           #+#    #+#             */
/*   Updated: 2024/03/14 22:16:44 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	char	*src_ptr;

	if (!src && !dst)
		return (NULL);
	if (src > dst)
	{
		dst = ft_memcpy(dst, src, len);
	}
	else
	{
		dst_ptr = (char *)dst;
		src_ptr = (char *)src;
		while (len--)
			dst_ptr[len] = src_ptr[len];
	}
	return (dst);
}

/*
#include <stdio.h>
int main()
{
	char src[] = "Holy";
	char dst[] = "Holla World";
	printf("%s\n", src);
	printf("%s\n", dst);
	ft_memmove(dst, src, sizeof(src));
	printf("%s\n", dst);
}
*/
