/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:14:27 by amartino          #+#    #+#             */
/*   Updated: 2019/08/30 16:51:47 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "define.h"

enum	e_main_states
{
	ST_STRING,
	ST_FLAG,
	ST_CONVERSION,
	ST_ERROR
};

typedef struct	s_state_machine
{
	char				*p_cursor;
//	t_vector			*p_out;
	uint64_t			option;
	enum e_main_states	state;
}				t_state_machine;

typedef struct	s_main
{
	char				*output;
	uint64_t			option;
	va_list				arg_printf;
}				t_main;

typedef int8_t	(*t_statefunc)(t_state_machine *self, char *input);
typedef int8_t	(*t_convfunc)(uint64_t option, char *argv);

int8_t			parser(t_state_machine *machine, char *input);
int8_t			string(t_state_machine *machine, char *input);
int8_t			conversion(t_state_machine *machine, char *input);
int8_t			flag(t_state_machine *machine, char *input);
int8_t			error(t_state_machine *machine, char *input);

t_state_machine init_state_machine(char *argv);
int				ft_printf(const char *input, ...)
					__attribute__((format(printf, 1, 2)));

enum	e_type_flag
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
};

enum	e_type_conv
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

};

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
