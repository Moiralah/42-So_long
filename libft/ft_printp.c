/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:45:09 by huidris           #+#    #+#             */
/*   Updated: 2024/09/02 23:44:02 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(long unsigned address)
{
	char	c;
	int		len;

	len = 0;
	if (address >= 16)
	{
		len += ft_putptr(address / 16);
		len += ft_putptr(address % 16);
	}
	else
	{
		c = address + '0';
		if (address > 9)
			c = address + 'a' - 10;
		ft_putchar_fd(c, 1);
		len++;
	}
	return (len);
}

int	ft_printp(void *ptr)
{
	int		len;
	long	address;

	address = (unsigned long long)ptr;
	len = ft_prints("0x") + ft_putptr(address);
	return (len);
}

/*
int main()
{
    int *a;

    //a = 17;
    ft_printp(&a);
    ft_prints("\n");
    printf("%p\n", &a);
    return (0);
}
*/
