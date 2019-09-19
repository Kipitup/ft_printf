/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:11:36 by fkante            #+#    #+#             */
/*   Updated: 2019/09/19 08:18:43 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_float(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_ftoa;
	long double	nbr;
	
	if (flag->option & FLAG_L_MAJ)
		nbr = va_arg(*arg_pf, long double);
	else
		nbr = va_arg(*arg_pf, double);
	vector = vct_new(flag->width);
	nb_ftoa = NULL;
	//nbr = apply_modifier_f(nbr, flag->option);
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
