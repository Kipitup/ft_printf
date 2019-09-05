/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:39:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 18:23:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_ox(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	char		*nb_itoa;
	int64_t		nbr;
	uint8_t		base;

	base = 16;
	if (flag->option & CONV_O)
	{
		nbr = va_arg(*args_printf, int64_t);
		base = 8;
	}
	else
		nbr = va_arg(*args_printf, int64_t);
	nbr = apply_modifier_oxX(nbr, flag->option);
	vector = vct_new(0);
	if((nb_itoa = ft_ox_itoa_base(nbr, base, flag->option)) != NULL)
		if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
