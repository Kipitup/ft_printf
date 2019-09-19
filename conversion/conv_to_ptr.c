/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:54:54 by fkante            #+#    #+#             */
/*   Updated: 2019/09/18 18:39:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		apply_prefix(t_vector *vector, t_flag *flag, t_vector *nb_itoa)
{
	if (flag->width >= vct_len(nb_itoa))
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
		if ((vct_push_str(vector, "0x")) == FAILURE)
			vct_del(&nb_itoa);
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}

t_vector	*conv_to_pointer(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_itoa;
	uint64_t	*address;
	void		*ptr;
	char		*str_itoa;

	ptr = va_arg(*args_printf, void *);
	vector = vct_new(flag->width);
	nb_itoa = vct_new(0);
	address = ptr;
	str_itoa = NULL;
	address = (uint64_t*)apply_modifier_p((uint64_t)address, flag->option);
	if ((str_itoa = ft_u_itoa_base((uint64_t)address, 16)) == NULL)
		vct_del(&nb_itoa);
	if (nb_itoa != NULL)
		if ((vct_strjoin(nb_itoa, str_itoa)) == FAILURE)
			vct_del(&nb_itoa);
	ft_strdel(&str_itoa);
	if ((apply_prefix(vector, flag, nb_itoa)) == FAILURE)
		vct_del(&vector);
	vct_del(&nb_itoa);
	return (vector);
}
