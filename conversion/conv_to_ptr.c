/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:54:54 by fkante            #+#    #+#             */
/*   Updated: 2019/09/18 12:11:33 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_prefix(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	size_t itoa_len;

	itoa_len = ft_strlen(nb_itoa->str);
	if ((flag->option & FLAG_POINT) && flag->width >= itoa_len)
	{
		if ((vct_push_str(nb_itoa, "0x")) == FAILURE)
			vct_del(&nb_itoa);
		if (nb_itoa != NULL)
		{
			if ((apply_padding_flag(vector, flag, nb_itoa)) == FAILURE)
				vct_del(&vector);
		}
	}
	else
	{
		if (nb_itoa != NULL)
		{
			if ((apply_padding_flag(vector, flag, nb_itoa)) == FAILURE)
				vct_del(&vector);
			vct_del(&nb_itoa);
		if ((vct_push_str(vector, "0x")) == FAILURE)
			vct_del(&nb_itoa);
		}
	}
}

t_vector	*conv_to_pointer(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	uint64_t	*address;
	void		*ptr;

	ptr = va_arg(*args_printf, void *);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	address = ptr;
	address = (uint64_t*)apply_modifier_p((uint64_t)address, flag->option);
	if (nb_itoa != NULL)
		if ((vct_strjoin(nb_itoa,
						ft_u_itoa_base((uint64_t)address, 16))) == FAILURE)
			vct_del(&nb_itoa);
	apply_prefix(vector, flag, nb_itoa);
	return (vector);
}
