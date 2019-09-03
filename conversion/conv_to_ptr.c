/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:54:54 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 09:46:29 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_pointer(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	void		*ptr;
	uint64_t	*address;
	char		*nb_itoa;

	(void)flag;
	ptr = va_arg(*args_printf, void *);
	address = ptr;
	if ((vector = vct_new(0)) == NULL)
		return (NULL);
	if ((vct_strjoin(vector, "0x")) == FAILURE)
	{
		vct_del(&vector);
		return (NULL);
	}
	if((nb_itoa = ft_u_itoa_base((uint64_t)address, 16)) == NULL)
	{
		vct_del(&vector);
		return (NULL);
	}
	if((vct_strjoin(vector, nb_itoa)) == FAILURE)
	{
		vct_del(&vector);
		return (NULL);
	}
	return (vector);
}
