/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:27:33 by huidris           #+#    #+#             */
/*   Updated: 2024/03/07 16:27:35 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_len(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	len;
	long	num;
	char	*result;

	len = digit_len(n);
	num = n;
	if (n < 0)
		num *= -1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = 0;
	if (num == 0)
		result[0] = '0';
	else
	{
		while (len--, num != 0)
		{
			result[len] = (num % 10) + '0';
			num = (num - (num % 10)) / 10;
		}
		if (n < 0)
			result[len] = '-';
	}
	return (result);
}
