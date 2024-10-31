/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:44:46 by huidris           #+#    #+#             */
/*   Updated: 2024/09/02 23:43:47 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printdni(int deci)
{
	int		len;
	char	*total;

	len = 0;
	total = ft_itoa(deci);
	len = ft_prints(total);
	free (total);
	return (len);
}

/*
int main()
{
    int a;
    
    a = 1005;
    ft_printdni(a);
    ft_prints("\n");
    printf("%d", a);
    return (0);
}
*/
