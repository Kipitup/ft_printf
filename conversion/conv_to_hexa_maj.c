/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_hexa_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:12:10 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 12:00:01 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_hexa_maj(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	uint8_t		base;
	int64_t		nbr;
	char		*nb_itoa;

	base = 16;
	nbr = va_arg(*args_printf, long);
	nbr = apply_modifier_oxX(nbr, flag);
	vector = vct_new(0);
	if((nb_itoa = ft_itoa_base_maj(nbr, base)) != NULL)
		if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
