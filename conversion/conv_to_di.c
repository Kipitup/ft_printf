/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:51:01 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 18:23:52 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_di(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	int64_t		nbr;

	nbr = va_arg(*args_printf, int64_t);
	cancel_flag_for_numeric_conv(flag);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	nbr = apply_modifier_di(nbr, flag->option);
	if (nb_itoa != NULL)
	{
		if ((nb_itoa->str = ft_itoa_base(nbr, 10)) != NULL)
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