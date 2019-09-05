/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:51:01 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 09:44:41 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_di(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		*nb_itoa;
	int64_t		nbr;
	uint8_t		base;

	base = 10;
	nbr = va_arg(*args_printf, int64_t);
	nbr = apply_modifier_di(nbr, flag);
	vector = vct_new(0);
	if((nb_itoa = ft_itoa_base(nbr, base)) != NULL)
		if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
