/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 09:39:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/13 14:09:03 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int8_t			conv(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	if ((apply_padding_flag(vector, flag, nb_itoa)) == FAILURE)
		vct_del(&vector);
	if (flag->option & FLAG_HASH)
	{
		if (flag->option & CONV_X)
		{
			if (apply_hashtag_hexa(vector, flag) == FAILURE)
				vct_del(&vector);
		}
		else
			if (apply_hashtag_octal(vector, flag) == FAILURE)
				vct_del(&vector);
	}

	return (vector == NULL ? FAILURE : SUCCESS);
}

t_vector		*conv_to_ox(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	int64_t		nbr;
	uint8_t		base;

	base = (flag->option & CONV_O ? 8 : 16);
	nbr = va_arg(*args_printf, int64_t);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	cancel_flag_for_numeric_conv(flag);
	nbr = apply_modifier_oxX(nbr, flag->option);
	if (nb_itoa != NULL)
		if ((vct_strjoin(nb_itoa,
		ft_ox_itoa_base(nbr, base, flag->option))) == FAILURE)
			vct_del(&nb_itoa);
	if (nb_itoa != NULL)
		if ((conv(vector, flag, nb_itoa)) == FAILURE)
			vct_del(&vector);
	vct_del(&nb_itoa);
	// printf("vector is : |%s|\t and len is : %zu\n", vector->str, vector->len);
	return (vector);
}
