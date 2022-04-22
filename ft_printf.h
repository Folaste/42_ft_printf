/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:31 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/21 18:06:28 by fleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_BASE_MIN "0123456789abcdef"
# define HEX_BASE_MAJ "0123456789ABCDEF"
# define CASTS "cspduixX%"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_printf	t_printf;
struct	s_printf
{
	va_list	args;
	int		dot;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		hash;
	int		tot_len;
	int		width;
	int		count_flags;
};

/*--- Fonctions principales  ---*/
int			ft_printf(const char *format, ...);
int			ft_read_format(t_printf *tab, const char *format, int i);

/*--- Fonctions de gestion de la structure ---*/
t_printf	*ft_init_tab(t_printf *tab);
t_printf	*ft_reset_tab(t_printf *tab);
t_printf	*ft_count_flags(t_printf *tab);

/*--- Fonctions de lecture des flags et des casts ---*/
int			ft_check_flags(t_printf *tab, const char *format, int i);
int			ft_check_cast(t_printf *tab, const char *format, int i);

/*--- Fonctions d'écriture ---*/
int			ft_printf_char(t_printf *tab, int i);
int			ft_printf_string(t_printf *tab, int i);
t_printf	*ft_printf_string_dot(t_printf *tab, char *str, int index);
t_printf	*ft_printf_string_width(t_printf *tab, char *str, int index);
t_printf	*ft_printf_string_minus(t_printf *tab, char *str, int index);

/*--- Fonctions de retour de valeur ---*/
t_printf	*ft_return_value_s(t_printf *tab);

#endif
