/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:47:04 by huidris           #+#    #+#             */
/*   Updated: 2024/03/16 22:54:56 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			a = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		a = (char *)(s + i);
	return (a);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "Hollaloly";
	printf("%s\n", ft_strrchr(str, 'y'));
	return (0);
}
*/
