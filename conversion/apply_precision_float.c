/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:56:19 by amartino          #+#    #+#             */
/*   Updated: 2019/09/16 20:42:05 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t 		apply_precision_float(t_vector *vector, t_flag *flag)
{
	uint64_t	len;

	len = (flag->option & FLAG_POINT) ? flag->precision : 6;
	printf("len is :%llu\n", len);
	if (len < vct_len(vector))
	{
		len = vct_len(vector) - vct_chr(vector, '.') + 1;
		vct_pop(vector, (vct_len(vector) - len));
	}
	else
	{
		len = flag->precision - (uint64_t)vct_len(vector);
		printf("len is :%llu\n", len);
		if ((vct_fill_after(vector, '0', len)) == FAILURE)
			vct_del(&vector);
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
