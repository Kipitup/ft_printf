/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:54:54 by fkante            #+#    #+#             */
/*   Updated: 2019/09/17 17:29:44 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (flag->option & FLAG_Z || flag->option & FLAG_J)
		address = (uint64_t*)apply_modifier_zj((int64_t)address, flag->option);
	if (nb_itoa != NULL)
		if ((vct_strjoin(nb_itoa,
						ft_u_itoa_base((uint64_t)address, 16))) == FAILURE)
			vct_del(&nb_itoa);
	if (nb_itoa != NULL)
	{
		if ((vct_push_str(nb_itoa, "0x")) == FAILURE)
			vct_del(&vector);
		if ((apply_padding_flag(vector, flag, nb_itoa)) == FAILURE)
			vct_del(&vector);
		vct_del(&nb_itoa);
	}
	return (vector);
}
