/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:56:41 by huidris           #+#    #+#             */
/*   Updated: 2024/09/19 01:51:28 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	std_process(const char *str, va_list *ap)
{
	int	len;

	len = 0;
	if (str[0] == 'c')
		len += ft_printc(va_arg(*ap, int));
	else if (str[0] == 's')
		len += ft_prints(va_arg(*ap, char *));
	else if (str[0] == 'p')
		len += ft_printp(va_arg(*ap, void *));
	else if (str[0] == 'd' || str[0] == 'i')
		len += ft_printdni(va_arg(*ap, int));
	else if (str[0] == 'u')
		len += ft_printu(va_arg(*ap, unsigned int));
	else if (str[0] == 'x')
		len += ft_printx(va_arg(*ap, unsigned int));
	else if (str[0] == 'X')
		len += ft_print_x(va_arg(*ap, unsigned int));
	else if (str[0] == '%')
		len += ft_printc('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += std_process(&str[i + 1], &ap);
			i++;
		}
		else
			len += ft_printc(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

// int main ()
// {
// 	char	c;
// 	char	d;
// 	char	e;
// 	int total;

// 	c = '0';
// 	d = '1';
// 	e = '2';
// 	total = ft_printf("cp%sduixX");
// 	//ft_printf("%c", 'c');
// 	printf("\ncp%sduixX");
// 	//printf("this is correct ans:[%c %c %c]\n",c,d,e);
// }
