/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:38:25 by amartino          #+#    #+#             */
/*   Updated: 2019/09/13 16:56:45 by amartino         ###   ########.fr       */
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




// int8_t          apply_hashtag_hexa(t_vector *vector, t_flag *flag,
// 	t_vector *nb_itoa)
// {
// 	size_t	len;
//
// 	if (flag->width > flag->precision && flag->width > vct_len(nb_itoa)
// 	&& (vct_apply(vector, IS_BLANK) == FALSE))
// 	{
// 		if (*(vct_get_str(vector) + 1) == ' ')
// 			vct_pop_from(vector, 2, START);
// 		else
// 			vct_pop_from(vector, 1, START);
// 		len = flag->precision > vct_len(nb_itoa) ?
// 									flag->precision : vct_len(nb_itoa);
// 		len = vct_len(vector) - len;
// 		if ((vct_add_str_at(vector, "0x", len)) == FAILURE)
// 			vct_del(&vector);
// 	}
// 	else if (vct_apply(vector, IS_BLANK) == FALSE)
// 		if ((vct_push_str(vector, "0x")) == FAILURE)
// 			vct_del(&vector);
// 	return (vector == NULL ? FAILURE : SUCCESS);
// }
//
// int8_t          apply_hashtag_octal(t_vector *vector, t_flag *flag)
// {
// 	(void)flag;
// 	if ((vct_add_char_at(vector, '0', START)) == FAILURE)
// 		vct_del(&vector);
// 	return (vector == NULL ? FAILURE : SUCCESS);
// }
