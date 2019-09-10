/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_padding_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:05:02 by amartino          #+#    #+#             */
/*   Updated: 2019/09/10 17:00:26 by amartino         ###   ########.fr       */
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
	if (apply_hashtag(vector, flag) == FAILURE)
 		vct_del(&vector);
	if (sign->len > 0 && ((flag->option & FLAG_ZERO) == FALSE))
		vct_add_char_at(vector, sign->str[0], START);
	if ((apply_width(vector, flag)) == FAILURE)
		vct_del(&vector);
	if (sign->len > 0 && flag->option & FLAG_ZERO)
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
		vct_push_char(sign, '-');
		vct_pop_from(nb_itoa, 1, 0);
	}
	else if (flag->option & FLAG_PLUS)
		vct_push_char(sign, '+');
	else if (flag->option & FLAG_SPACE)
		vct_push_char(sign, ' ');
	return (sign);
}

int8_t 		apply_precision(t_vector *vector, t_flag *flag)
{
	uint64_t	len;

	if (flag->option & CONV_S || flag->option & CONV_C || flag->option & CONV_F)
	{
		if (flag->precision < vct_len(vector))
			vct_pop(vector, (size_t)flag->precision);
	}
	else
	{
		len = 0;
		if (flag->precision >= vct_len(vector))
			len = flag->precision - vct_len(vector);
		if (flag->option & FLAG_POINT)
			if ((vct_fill_before(vector, '0', len)) == FAILURE)
				vct_del(&vector);
	}
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
				if (apply_hashtag(vector, flag) == FAILURE)
			 		vct_del(&vector);
		}
		else
			if ((vct_fill_before(vector, ' ', len)) == FAILURE)
				vct_del(&vector);
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}

int8_t          apply_hashtag(t_vector *vector, t_flag *flag)
{
	if (flag->option & FLAG_HASH)
	{
		if ((flag->option & CONV_X || flag->option & CONV_X_MAJ) && vector->str[vct_len(vector) - 1] != '0')
		{
			if (ft_strchr(vector->str, 'x') != 0 || ft_strchr(vector->str, 'X') != 0) // la suite est un brouillon/ wait and don't judge
			{
				vct_add_char_at(vector, 'x', START);
				vct_add_char_at(vector, '0', START);
				if (flag->option & CONV_X_MAJ)
					ft_strcapitalize(vector->str);
			}
		}
		else if (flag->option & CONV_O)
			vct_add_char_at(vector, '0', START);
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
