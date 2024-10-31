/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:49:39 by huidris           #+#    #+#             */
/*   Updated: 2024/03/16 16:33:11 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	if (!haystack && !len)
		return (NULL);
	needle_len = ft_strlen(needle);
	while (haystack[i] && (i + needle_len -1) < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
		{
			if (j == needle_len - 1)
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char	*s1 = "";
// 	char	*s2 = "oh no not the empty string !";
// 	size_t	max = strlen(s2);

// 	char	*i1 = strnstr(s1, s2, max);
// 	char	*i2 = ft_strnstr(s1, s2, max);
// 	printf("%s\n%s\n", i1, i2);
//     // char haystack[] = "Hello World";
//     // char needle[] = "Wor";
//     // printf("%s\n", ft_strnstr(haystack, needle, 10));
// }
