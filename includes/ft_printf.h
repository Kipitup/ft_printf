/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:14:27 by amartino          #+#    #+#             */
/*   Updated: 2019/09/18 18:59:10 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "define.h"

enum	e_main_states
{
	ST_STRING,
	ST_FLAGS,
	ST_CONVERSION,
	ST_BUFFER,
	ST_END
};

typedef struct	s_state_machine
{
	t_vector			*p_output;
	uint64_t			width;
	uint64_t			precision;
	uint32_t			option;
	enum e_main_states	state;
}				t_state_machine;

typedef struct	s_flag
{
	uint64_t			width;
	uint64_t			precision;
	uint32_t			option;
}				t_flag;

typedef int8_t		(*t_statefunc)(t_state_machine *self, char *input, va_list *args_printf);
typedef t_vector	*(*t_convfunc)(va_list *args_printf, t_flag *flag);

/*
**********************
**     FT_PRINTF    **
**********************
*/
int				ft_printf(const char *input, ...);// __attribute__
//					((format(printf, 1, 2)));

/*
**********************
**  STATE MACHINE	**
**********************
*/
size_t			parser(t_state_machine *machine, char *input, va_list *args_printf);
int8_t			string(t_state_machine *machine, char *input, va_list *args_printf);
int8_t			conversion(t_state_machine *machine, char *input, va_list *args_printf);
int8_t			flags(t_state_machine *machine, char *input, va_list *args_printf);
int8_t			buffer(t_state_machine *mahcine, char *input, va_list *args_printf);
int8_t			error(t_state_machine *machine, char *input, va_list *args_printf);
int8_t			end(t_state_machine *machine, char *input, va_list *args_printf);
uint8_t			is_width(t_state_machine *machine, char *input, va_list *arg_pf);
uint8_t			is_precision(t_state_machine *machine, char *input, va_list *arg_pf);
uint64_t		get_numbers(t_state_machine *machine, char *input, size_t *count);


/*
**********************
**  	 INIT	    **
**********************
*/
void  			init_state_machine(t_state_machine *machine);
void			init_flags(t_state_machine *machine, t_flag *flags);

/*
**********************
**    CONVERSION	**
**********************
*/
t_vector		*conv_to_char(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_str(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_pointer(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_ox(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_di(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_u_decimal(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_hexa_maj(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_float(va_list *args_printf, t_flag *flag);
t_vector		*conv_to_none(char input, t_flag *flag);


int64_t			apply_modifier_di(int64_t nbr_conv, uint32_t flag);
uint64_t		apply_modifier_oxX(int64_t nbr_conv, uint32_t flag);
uint64_t		apply_modifier_u(uint64_t nbr_conv, uint32_t flag);
uint64_t		apply_modifier_s(uint64_t str, uint64_t flag);
uint64_t		apply_modifier_p(uint64_t str, uint64_t flag);
int64_t			apply_modifier_zj(int64_t nbr_conv, uint32_t flag);
long double		apply_modifier_f(long double nbr, int32_t flag);
int8_t 			apply_precision(t_vector *vector, t_flag *flag);
int8_t 			apply_width(t_vector *vector, t_flag *flag);
int8_t			apply_padding_flag(t_vector *vector, t_flag *flag, t_vector *nb_itoa);
t_vector		*handle_sign(t_vector *nb_itoa, t_flag *flag);
// int8_t          apply_hashtag_hexa(t_vector *vector, t_flag *flag, t_vector *nb_itoa);
// int8_t          apply_hashtag_octal(t_vector *vector, t_flag *flag);
int8_t          apply_hash(t_vector *vector, t_flag *flag);
int8_t          apply_hash_flag_zero(t_vector *vector, t_flag *flag);
void			apply_hash_special_case(t_vector *vector, t_flag *flag);
int8_t			apply_precision_float(t_vector *vector, t_flag *flag, size_t is_sign);

t_vector		*get_converted_number(t_vector	*vector, t_flag *flag, uint8_t base, int64_t nbr);


int8_t			convert(t_state_machine *machine, t_flag *flag, char *input, va_list *args_printf);
void			check_and_cancel_flag(t_state_machine *machine);
void			cancel_flag_for_numeric_conv(t_flag *flag);
void			cancel_flag_for_other_conv(t_flag *flag);
void			cancel_flag_for_u_conv(t_flag *flag);

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
	E_TYPE_CONV_F,
	E_TYPE_CONV_NONE
};

#endif
