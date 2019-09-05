/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:51:01 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 17:58:11 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_nbr(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	int64_t		nbr;
	uint8_t		base;

	base = 10;
	if (flag->option & CONV_O)
		base = 8;
	if (flag->option & CONV_X)
		base = 16;
	nbr = va_arg(*args_printf, int64_t);
	cancel_flag_for_numeric_conv(flag);
	if (flag->option & CONV_D || flag->option & CONV_I)
		nbr = apply_modifier_di(nbr, flag->option);
	else
		nbr = apply_modifier_oxX(nbr, flag->option);
	vector = vct_new(flag->width);
	vector = get_converted_number(vector, flag, base, nbr);
	return (vector);
}

t_vector		*get_converted_number(t_vector *vector, t_flag *flag,
										uint8_t base, int64_t nbr)
{
	t_vector	*nb_itoa;

	nb_itoa = vct_new(0);
	if (nb_itoa != NULL)
	{
		if ((nb_itoa->str = ft_itoa_base(nbr, base)) != NULL)
		{
			if ((apply_padding_flag(vector, flag, nb_itoa)) == FAILURE)
				vct_del(&vector);
			vct_del(&nb_itoa);
		}
	}
	else
		vct_del(&vector);
	return (vector);
}
