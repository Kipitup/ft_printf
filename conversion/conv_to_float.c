/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:11:36 by fkante            #+#    #+#             */
/*   Updated: 2019/09/16 16:12:49 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_float(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	double		nbr;

	nbr = va_arg(*args_printf, double);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	// nbr = apply_modifier_f(nbr, flag->option);
	if (nb_itoa != NULL)
		if ((vct_strjoin(nb_itoa, ft_ftoa(nbr, flag->precision, flag->option))) == FAILURE)
			vct_del(&nb_itoa);
	if (nb_itoa != NULL)
	{
		if ((apply_padding_flag(vector, flag, nb_itoa)) == FAILURE)
			vct_del(&vector);
		vct_del(&nb_itoa);
	}
	else
		vct_del(&vector);
	return (vector);
}
