/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_hexa_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:12:10 by fkante            #+#    #+#             */
/*   Updated: 2019/09/09 16:08:02 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_hexa_maj(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	uint8_t		base;
	int64_t		nbr;

	base = 16;
	nbr = va_arg(*args_printf, int64_t);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	cancel_flag_for_numeric_conv(flag);
	nbr = apply_modifier_oxX(nbr, flag->option);
	if (nb_itoa != NULL)
		if ((vct_strjoin(nb_itoa, ft_itoa_base_maj(nbr, base))) == FAILURE)
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
