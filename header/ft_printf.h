/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:14:27 by amartino          #+#    #+#             */
/*   Updated: 2019/08/28 15:31:55 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "define.h"

typedef enum	main_states
{
	ST_STRING,
	ST_FLAG,
	ST_CONVERSION,
	ST_PRINT,
	ST_ERROR
}				e_main_states;

typedef struct	s_state_machine
{
	void				*p_cursor;
	unsigned long long	option;
	e_main_states		state;
}				t_state_machine;

typedef void (*tab_statefunc)(t_state_machine *self, void *p_cursor);

int		parser (char *cursor);
void	st_string (char *string);
void	st_conversion();
int		is_conversion();
int		is_width();
int		is_precision();
int		is_cast();
int		is_conversion_specifier();
int		is_flag();

typedef enum	type_flag
{
	E_TYPE_FLAG_FLAG_HH,
	E_TYPE_FLAG_LL,
	E_TYPE_FLAG_H,
	E_TYPE_FLAG_L,
	E_TYPE_FLAG_L_MAJ,
	E_TYPE_FLAG_PLUS,
	E_TYPE_FLAG_MINUS,
	E_TYPE_FLAG_HASH,
	E_TYPE_FLAG_ZERO,
	E_TYPE_FLAG_SPACE,
	E_TYPE_FLAG_POINT
}				e_type_flag;

typedef enum	type_conv
{
	E_TYPE_CONV_C,
	E_TYPE_CONV_S,
	E_TYPE_CONV_P,
	E_TYPE_CONV_D,
	E_TYPE_CONV_I,
	E_TYPE_CONV_O,
	E_TYPE_CONV_U,
	E_TYPE_CONV_X,
	E_TYPE_CONV_X_MAJ,
	E_TYPE_CONV_F

}				e_type_conv;

#endif

/*
typedef unsigned long t_option

t_option option;

option = 0;

if (input[i] == 'h')
	option |= FLAG_H;

	option |= (unsigned long)field << 32;

	if ((option & FLAG_H) == FALSE)
		nb = (char)nb;

{
00000000
		01000000

		01000000
		
		00010000
		01010000

		00000000
		}

typedef struct
{
	char *output_str;
}stdout_to_be_print;


** State machine EVENT functions
EVENT_DECLARE(ST_print, end_of_input)
EVENT_DECLARE(ST_conversion, found_conversion_sign)

** State machine STATE functions
STATE_DECLARE(ST_STRING, */
