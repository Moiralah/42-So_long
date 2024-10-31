/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:45:37 by huidris           #+#    #+#             */
/*   Updated: 2024/09/02 23:44:06 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prints(char *str)
{
	if (str == NULL)
		return (ft_prints("(null)"));
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

/*
int main()
{
    ft_prints(NULL);
	printf();
    return (0);
}
*/
