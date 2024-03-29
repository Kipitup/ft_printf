/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:38:25 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 11:54:58 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t	apply_hash(t_vector *vector, t_flag *flag)
{
	int8_t	ret;

	ret = SUCCESS;
	if (flag->option & FLAG_HASH)
	{
		if ((flag->option & CONV_X || flag->option & CONV_X_MAJ)
				&& (flag->option & FLAG_ZERO) == 0
				&& (vct_getchar_at(vector, vct_len(vector) - 1) != '0')
				&& (vct_apply(vector, IS_BLANK) == FALSE))
		{
			ret = vct_pushstr(vector, "0x");
			if (flag->option & CONV_X_MAJ)
				ft_strupcase(vector->str);
		}
		else if (flag->option & CONV_O)
		{
			if (vct_getchar_at(vector, START) != '0')
				ret = vct_addchar_at(vector, '0', START);
		}
	}
	return (ret);
}

void	apply_hash_flag_zero(t_vector *vector, t_flag *flag)
{
	if (flag->option & FLAG_HASH)
	{
		if ((vct_getchar_at(vector, vct_len(vector) - 1) != '0')
				&& (vct_apply(vector, IS_BLANK) == FALSE))
		{
			vct_pop_from(vector, 2, START);
			vct_pushstr(vector, "0x");
			if (flag->option & CONV_X_MAJ)
				ft_strupcase(vector->str);
		}
	}
}

void	apply_hash_special_case(t_vector *vector, t_flag *flag)
{
	char	c;

	c = vct_getchar_at(vector, START);
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
