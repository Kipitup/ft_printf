/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:11:36 by fkante            #+#    #+#             */
/*   Updated: 2019/09/17 18:55:03 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_float(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_ftoa;
	double		nbr;

	nbr = va_arg(*args_printf, double);
	vector = vct_new(flag->width);
	nb_ftoa = NULL;
	// nbr = apply_modifier_f(nbr, flag->option);
	nb_ftoa = ft_ftoa(nbr, flag->precision, flag->option);
	if (nb_ftoa != NULL)
	{
		if ((apply_padding_flag(vector, flag, nb_ftoa)) == FAILURE)
			vct_del(&vector);
	}
	else
		vct_del(&vector);
	vct_del(&nb_ftoa);
	return (vector);
}
