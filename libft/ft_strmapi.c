/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:28:08 by huidris           #+#    #+#             */
/*   Updated: 2024/03/12 21:56:47 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}

// char	uppercase(unsigned int i, char c)
// {
// 	if (ft_toupper(c) != c)
// 		return (ft_toupper(c));
// 	else if (ft_tolower(c) != c)
// 		return (ft_tolower(c));
// 	else
// 		return (c);
// }

// #include <stdio.h>
// int main()
// {
// 	char *result = ft_strmapi("Hello, World!", uppercase);
// 	printf("%s\n", result);
// }
