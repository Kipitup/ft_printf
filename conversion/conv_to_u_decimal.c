/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_u_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:47:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 17:54:56 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_u_decimal(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		*nb_itoa;
	uint64_t	nbr;

	nbr = (uint64_t)va_arg(*args_printf, uint64_t);
	nbr = apply_modifier_u(nbr, flag);
	vector = vct_new(0);
	if((nb_itoa = ft_u_itoa(nbr)) != NULL)
		if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
