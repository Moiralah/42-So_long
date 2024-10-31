/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:28:32 by huidris           #+#    #+#             */
/*   Updated: 2024/03/12 22:19:33 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
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
