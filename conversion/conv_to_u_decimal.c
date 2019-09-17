/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_u_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:47:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/17 09:05:53 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_u_decimal(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	uint64_t	nbr;

	nbr = (uint64_t)va_arg(*args_printf, uint64_t);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	cancel_flag_for_u_conv(flag);
	nbr = apply_modifier_u(nbr, flag->option);
	if (flag->option & FLAG_Z || flag->option & FLAG_J)
		nbr = apply_modifier_zj(nbr, flag->option);
	if (nb_itoa != NULL)
			if ((vct_strjoin(nb_itoa, ft_u_itoa(nbr))) == FAILURE)
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
