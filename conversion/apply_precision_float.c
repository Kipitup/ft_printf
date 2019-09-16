/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:56:19 by amartino          #+#    #+#             */
/*   Updated: 2019/09/16 16:48:32 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t 		apply_precision_float(t_vector *vector, t_flag *flag)
{
	uint64_t	len;

	len = 0;
	len = (flag->option & FLAG_POINT) ? flag->precision : 6;
	if (len < vct_len(vector))
		vct_pop(vector, (vct_len(vector) - (size_t)flag->precision));
	return (vector == NULL ? FAILURE : SUCCESS);
}
