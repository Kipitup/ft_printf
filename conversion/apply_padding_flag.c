/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:05:02 by amartino          #+#    #+#             */
/*   Updated: 2019/09/18 15:12:34 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		apply_padding_flag(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	t_vector	*sign;

	sign = handle_sign(nb_itoa, flag);
	if (sign == NULL)
		vct_del(&vector);
	vct_cat(vector, nb_itoa);
	if (vector == NULL)
		vct_del(&vector);
	if ((apply_precision(vector, flag)) == FAILURE)
		vct_del(&vector);
	if (apply_hash(vector, flag) == FAILURE)
 		vct_del(&vector);
	if (vct_len(sign) > 0 && ((flag->option & FLAG_ZERO) == FALSE))
		vct_add_char_at(vector, sign->str[0], START);
	if ((apply_width(vector, flag)) == FAILURE)
		vct_del(&vector);
	if (vct_len(sign) > 0 && flag->option & FLAG_ZERO)
	{
		if (vector->str[0] == '0')
			vct_pop_from(vector, 1, 0);
		vct_add_char_at(vector, sign->str[0], START);
	}
	vct_del(&sign);
	return (vector == NULL ? FAILURE : SUCCESS);
}

t_vector	*handle_sign(t_vector *nb_itoa, t_flag *flag)
{
	t_vector	*sign;

	sign = vct_new(0);
	if (nb_itoa->str[0] == '-')
	{
		vct_add_char(sign, '-');
		vct_pop_from(nb_itoa, 1, 0);
	}
	else if (flag->option & FLAG_PLUS)
		vct_add_char(sign, '+');
	else if (flag->option & FLAG_SPACE)
		vct_add_char(sign, ' ');
	return (sign);
}

int8_t 		apply_precision(t_vector *vector, t_flag *flag)
{
	uint64_t	len;
	int8_t		ret;

	ret = SUCCESS;
	if ((flag->option & CONV_S || flag->option & CONV_C)
			&& (flag->option & FLAG_POINT))
	{
		if (flag->precision < vct_len(vector))
			vct_pop(vector, (vct_len(vector) - (size_t)flag->precision));
	}
	else
	{
		len = 0;
		if (flag->precision >= vct_len(vector))
		{
			len = flag->precision - vct_len(vector);
			if (flag->option & FLAG_POINT)
				ret = vct_fill_before(vector, '0', len);
		}
		else
			apply_hash_special_case(vector, flag);
	}
	if (ret == FAILURE)
		vct_del(&vector);
	return (vector == NULL ? FAILURE : SUCCESS);
}

int8_t 		apply_width(t_vector *vector, t_flag *flag)
{
	uint64_t	len;

	len = flag->width < vct_len(vector) ? 0 : flag->width - vct_len(vector);
	if (len > 0)
	{
		if (flag->option & FLAG_MINUS)
		{
			if ((vct_fill_after(vector, ' ', len)) == FAILURE)
				vct_del(&vector);
		}
		else if (flag->option & FLAG_ZERO)
		{
			if ((vct_fill_before(vector, '0', len)) == FAILURE)
				vct_del(&vector);
			if (flag->option & CONV_X || flag->option & CONV_X_MAJ)
				if (apply_hash_flag_zero(vector, flag) == FAILURE)
			 		vct_del(&vector);
		}
		else
			if ((vct_fill_before(vector, ' ', len)) == FAILURE)
				vct_del(&vector);
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
