/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:19:38 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/25 11:04:23 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_read_format(t_printf *tab, const char *format, int i)
{
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = ft_check_flags(tab, format, i);
			ft_reset_tab(tab);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*tab;
	int			i;

	i = 0;
	tab = (t_printf *)malloc(sizeof(*tab));
	if (!tab)
		return (0);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = ft_read_format(tab, format, i);
	i += tab->tot_len;
	va_end(tab->args);
	free(tab);
	return (i);
}
