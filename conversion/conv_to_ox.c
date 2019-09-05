/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:39:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 15:57:05 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_ox(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		*nb_itoa;
	int64_t		nbr;
	uint8_t		base;
	
	base = 16;
	if (flag & CONV_O)
	{
		nbr = va_arg(*args_printf, int64_t);
		base = 8;
	}
	else
		nbr = va_arg(*args_printf, int64_t);
	nbr = apply_modifier_oxX(nbr, flag);
	vector = vct_new(0);
	if((nb_itoa = ft_ox_itoa_base(nbr, base, flag)) != NULL)
		if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
