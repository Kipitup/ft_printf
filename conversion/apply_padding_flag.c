/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:05:02 by amartino          #+#    #+#             */
/*   Updated: 2019/09/04 18:08:42 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** vector functions to do
** width ok
precision
*/



int8_t		apply_padding_flag(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	t_vector	*sign;

	sign = handle_sign(nb_itoa, flag);
	if (sign == NULL)
		vct_del(&vector);
	vector = vct_join_free(vector, nb_itoa, BOTH);
	if (vector == NULL)
		vct_del(&vector);
	if ((apply_width(vector, flag)) == FAILURE)
		vct_del(&vector);
	if ((apply_precision(vector, flag)) == FAILURE)
		vct_del(&vector);
	return (vector == NULL ? FAILURE : SUCCESS);
}

t_vector	*handle_sign(t_vector *nb_itoa, t_flag *flag)
{
	t_vector	*sign;

	sign = vct_new(0);
	if (nb_itoa->str[0] == '-')
	{
		vct_push_char(sign, '-');
		// vct_pop_from(nb_itoa, 0);
	}
	else
		if (flag->option & FLAG_PLUS)
			vct_push_char(sign, '+');
	return (sign);
}

int8_t 		apply_width(t_vector *vector, t_flag *flag)
{
	if (flag->option & FLAG_MINUS)
	{
		while (flag->width > vector->len)
		{
			if ((vct_push_char(vector, ' ')) == FAILURE)
				break ;
		}
	}
	else
	{
		while (flag->width > vector->len)
		{
			// if ((vct_add_char_at(vector, ' ', 0)) == FAILURE)
				break ;
		}
	}
	return (flag->width > vector->len ? FAILURE : SUCCESS);
}


int8_t 		apply_precision(t_vector *vector, t_flag *flag)
{
	if (flag->option & FLAG_ZERO)
	{
		while (flag->precision > vector->len)
		{
			if ((vct_push_char(vector, ' ')) == FAILURE)
				break ;
		}
	}
	else
	{
		while (flag->precision > vector->len)
		{
			// if ((vct_add_char_at(vector, ' ', 0)) == FAILURE)
				break ;
		}
	}
	return (flag->precision > vector->len ? FAILURE : SUCCESS);
}
