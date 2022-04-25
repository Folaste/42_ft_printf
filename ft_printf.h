/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:20:31 by fleblanc          #+#    #+#             */
/*   Updated: 2022/04/25 16:33:24 by fleblanc         ###   ########.fr       */
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
int		ft_printf(const char *format, ...);
int		ft_read_format(t_printf *tab, const char *format, int i);

/*--- Fonctions de gestion de la structure ---*/
void	ft_init_tab(t_printf *tab);
void	ft_reset_tab(t_printf *tab);
void	ft_count_flags(t_printf *tab);

/*--- Fonctions de lecture des flags et des casts ---*/
int		ft_check_flags(t_printf *tab, const char *format, int i);
int		ft_check_cast(t_printf *tab, const char *format, int i);

/*--- Fonctions d'écriture ---*/
int		ft_printf_char(t_printf *tab, int i);

int		ft_printf_string(t_printf *tab, int i);
void	ft_printf_string_dot(t_printf *tab, char *str, int index);
void	ft_printf_string_width(t_printf *tab, char *str, int index);
void	ft_printf_string_minus(t_printf *tab, char *str, int index);

int		ft_printf_pointer(t_printf *tab, int i);
void	ft_putptr_fd(unsigned long p, t_printf *tab, int fd, char *base);
int		ft_hexalen(unsigned long p);
void	ft_printf_pointer_minus(t_printf *tab, unsigned long p, int index);
void	ft_printf_pointer_width(t_printf *tab, unsigned long p, int index);

int		ft_printf_hexa(t_printf *tab, int i, char x_case);
void	ft_printf_hexa_minus(t_printf *tab, unsigned int x,
			char *base, int index);
void	ft_printf_hexa_zero(t_printf *tab, unsigned int x,
			char *base, int index);
void	ft_printf_hexa_hash(t_printf *tab, unsigned int x, char *base);
void	ft_printf_hexa_width(t_printf *tab, unsigned int x,
			char *base, int index);

int		ft_printf_unsigned(t_printf *tab, int i);
void	ft_putnbr_u_fd(unsigned int u, t_printf *tab, int fd);
void	ft_printf_unsigned_minus(t_printf *tab, unsigned int u, int index);
void	ft_printf_unsigned_zero(t_printf *tab, unsigned int u, int index);
void	ft_printf_unsigned_width(t_printf *tab, unsigned int u, int index);

int		ft_printf_number(t_printf *tab, int i);
void	ft_choice_write(t_printf *tab, int nbr, int size, int index);
void	ft_printf_number_minus(t_printf *tab, int nbr, int index, int size);
void	ft_printf_number_zero(t_printf *tab, int nbr, int index, int size);
void	ft_printf_number_width(t_printf *tab, int nbr, int index, int size);
void	ft_printf_number_dot(t_printf *tab, int nbr, int index, int size);

/*--- Fonctions de retour de valeur ---*/
void	ft_return_value_s(t_printf *tab);
void	ft_return_value_p(t_printf *tab);
void	ft_return_value_x(t_printf *tab);
void	ft_return_value_u(t_printf *tab);
void	ft_return_value_nbr(t_printf *tab);

#endif
