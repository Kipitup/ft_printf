/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:38:25 by amartino          #+#    #+#             */
/*   Updated: 2019/09/16 15:53:41 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t          apply_hashtag(t_vector *vector, t_flag *flag)
{
	if (flag->option & FLAG_HASH)
	{
		if ((flag->option & CONV_X || flag->option & CONV_X_MAJ)
		&& (flag->option & FLAG_ZERO) == 0
		&& (vct_get_str(vector))[vct_len(vector) - 1] != '0'
		&& (vct_apply(vector, IS_BLANK) == FALSE))
		{
			if ((vct_push_str(vector, "0x")) == SUCCESS)
				if (flag->option & CONV_X_MAJ)
					ft_strupcase(vector->str);
		}
		else if (flag->option & CONV_O)
			vct_add_char_at(vector, '0', START);
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}

int8_t          apply_special_hashtag(t_vector *vector, t_flag *flag)
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
