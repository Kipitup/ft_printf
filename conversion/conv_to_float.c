/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:11:36 by fkante            #+#    #+#             */
/*   Updated: 2019/09/06 12:19:24 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_float(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	float		nbr;
	
	nbr = va_arg(*args_printf, float);
	cancel_flag_for_numeric_conv(flag);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	nbr = apply_modifier_f(nbr, flag->option);
	printf("nbr float: %f\n", nbr);	
	return (vector);
}
