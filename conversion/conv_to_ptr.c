/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:54:54 by fkante            #+#    #+#             */
/*   Updated: 2019/09/04 16:18:26 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_pointer(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	void		*ptr;
	uint64_t	*address;
	char		*nb_itoa;

	ptr = va_arg(*args_printf, void *);
	address = ptr;
	address = (uint64_t*)apply_modifier_p((uint64_t)address, flag);
	vector = vct_new(0);
	if ((vct_strjoin(vector, "0x")) == FAILURE)
		vct_del(&vector);
	if((nb_itoa = ft_u_itoa_base((uint64_t)address, 16)) != NULL)
		if((vct_strjoin(vector, nb_itoa)) == FAILURE)
			vct_del(&vector);
	return (vector);
}
