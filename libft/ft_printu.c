/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:43:25 by huidris           #+#    #+#             */
/*   Updated: 2024/09/02 23:44:10 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printu(unsigned int unint)
{
	int	len;

	len = 0;
	if (unint >= 10)
	{
		len += ft_printu(unint / 10);
		len += ft_printu(unint % 10);
	}
	else
	{
		ft_putchar_fd((unint + '0'), 1);
		len++;
	}
	return (len);
}

/*
int main()
{
    unsigned int    a;
    
    a = 1005;
    ft_printu(a);
    ft_prints("\n");
    printf("%u", a);
    return (0);
}
*/
