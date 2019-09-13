/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hash_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:38:25 by amartino          #+#    #+#             */
/*   Updated: 2019/09/13 14:29:44 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t          apply_hashtag_hexa(t_vector *vector, t_flag *flag)
{
	if ((vct_len(vector) == 1 && *(vct_get_str(vector)) == '0') == FALSE)
	{
		if (vct_len(vector) > 0)
		{
			printf("len : %zu\n", vct_len(vector));
			if (flag->width > flag->precision && flag->width > vct_len(vector))
			{
				if (flag->width + 1 == vct_len(vector))
					vct_pop_from(vector, 1, START);
				else
					vct_pop_from(vector, 2, START);
				if ((vct_push_str(vector, "0x")) == FAILURE)
					vct_del(&vector);
			}
			else if (vct_apply(vector, IS_BLANK) == FALSE)
			{
				if ((vct_push_str(vector, "0x")) == FAILURE)
				vct_del(&vector);
			}
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}

int8_t          apply_hashtag_octal(t_vector *vector, t_flag *flag)
{
	(void)flag;
	if ((vct_add_char_at(vector, '0', START)) == FAILURE)
		vct_del(&vector);
	return (vector == NULL ? FAILURE : SUCCESS);
}
