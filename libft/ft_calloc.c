/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:50:22 by huidris           #+#    #+#             */
/*   Updated: 2024/03/16 17:36:31 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*m;
	size_t	i;

	if (count && size && count > (UINT_MAX / size))
		return (NULL);
	m = malloc(count * size);
	if (!m)
		return (0);
	i = -1;
	while (++i < size * count)
		m[i] = 0;
	return (m);
}
