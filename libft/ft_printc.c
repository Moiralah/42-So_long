/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:44:32 by huidris           #+#    #+#             */
/*   Updated: 2024/09/02 23:43:43 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printc(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
/*
int main ()
{
	ft_printc('%');
}
*/
