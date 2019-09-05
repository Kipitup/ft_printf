/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_hexa_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:12:10 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 18:24:48 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_hexa_maj(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	uint8_t		base;
	int64_t		nbr;
	char		*nb_itoa;

	base = 16;
	nbr = va_arg(*args_printf, long);
	nbr = apply_modifier_oxX(nbr, flag->option);
	vector = vct_new(0);
	if((nb_itoa = ft_itoa_base_maj(nbr, base)) != NULL)
		if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
