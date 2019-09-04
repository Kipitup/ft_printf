/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:51:01 by fkante            #+#    #+#             */
/*   Updated: 2019/09/04 17:42:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_nbr(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		*nb_itoa;
	int64_t		nbr;
	uint8_t		base;

	base = 10;
	if (flag & CONV_O)
			base = 8;
	if (flag & CONV_X)
			base = 16;
	nbr = va_arg(*args_printf, int64_t);
	if (flag & CONV_D || flag & CONV_I)
		nbr = apply_modifier_di(nbr, flag);
	else
		nbr = apply_modifier_oxX(nbr, flag);
	vector = vct_new(0);
	if((nb_itoa = ft_itoa_base(nbr, base)) != NULL)
		if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
