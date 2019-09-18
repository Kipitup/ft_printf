/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:38:25 by amartino          #+#    #+#             */
/*   Updated: 2019/09/18 16:28:19 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t	apply_hash(t_vector *vector, t_flag *flag)
{
	if (flag->option & FLAG_HASH)
	{
		if ((flag->option & CONV_X || flag->option & CONV_X_MAJ)
				&& (flag->option & FLAG_ZERO) == 0
				&& (vct_get_char_at(vector, vct_len(vector) - 1) != '0')
				&& (vct_apply(vector, IS_BLANK) == FALSE))
		{
			if ((vct_push_str(vector, "0x")) == SUCCESS)
				if (flag->option & CONV_X_MAJ)
					ft_strupcase(vector->str);
		}
		else if (flag->option & CONV_O)
		{
			if (vct_get_char_at(vector, START) != '0')
				vct_add_char_at(vector, '0', START);
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}

int8_t	apply_hash_flag_zero(t_vector *vector, t_flag *flag)
{
	if (flag->option & FLAG_HASH)
	{
		vct_pop_from(vector, 2, START);
		if ((vct_push_str(vector, "0x")) == SUCCESS)
			if (flag->option & CONV_X_MAJ)
				ft_strupcase(vector->str);
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}

void	apply_hash_special_case(t_vector *vector, t_flag *flag)
{
	char	c;

	c = vct_get_char_at(vector, START);
	if (vct_len(vector) == 1 && flag->option & FLAG_POINT && c == '0')
	{
		if (flag->option & CONV_D
				|| flag->option & CONV_I
				|| flag->option & CONV_O
				|| flag->option & CONV_X
				|| flag->option & CONV_U
				|| flag->option & CONV_P
				|| flag->option & CONV_X_MAJ)
			vct_pop(vector, 1);
	}
}
