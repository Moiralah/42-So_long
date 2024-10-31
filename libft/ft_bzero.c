/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:41:36 by huidris           #+#    #+#             */
/*   Updated: 2024/03/14 21:41:39 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	c;
	char	*str_ptr;

	c = 0;
	str_ptr = (char *)s;
	while (c < n)
	{
		str_ptr[c] = 0;
		c++;
	}
}

/*
#include <stdio.h>
int main()
{
    char str [10] = "holla";
    printf("%s\n", str);
    ft_bzero(str, sizeof(str));
    printf("%s\n", str);
}
*/
