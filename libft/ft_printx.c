/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:43:25 by huidris           #+#    #+#             */
/*   Updated: 2024/09/02 23:44:13 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printx(unsigned int hex)
{
	char	c;
	int		len;

	len = 0;
	if (hex >= 16)
	{
		len += ft_printx(hex / 16);
		len += ft_printx(hex % 16);
	}
	else
	{
		c = hex + '0';
		if (hex > 9)
			c = (hex + 'a' - 10);
		ft_putchar_fd(c, 1);
		len++;
	}
	return (len);
}

/*
int main()
{
    int *a;

    a = NULL;
    ft_printx((unsigned int)&a);
    ft_prints("\n");
    printf("%x\n", (unsigned int)&a);
    return (0);
}
*/
