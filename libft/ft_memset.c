/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:49:40 by huidris           #+#    #+#             */
/*   Updated: 2024/02/29 19:34:09 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str_ptr;

	i = 0;
	str_ptr = (char *)b;
	while (i < len)
	{
		str_ptr[i] = c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
int main ()
{
	char str[10];
	ft_memset(str, 'a', sizeof(str));
	printf("%s\n", str);
}
*/