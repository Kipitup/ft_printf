/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_u_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:47:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 09:52:44 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_u_decimal(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		*nb_itoa;
	uint64_t	nbr;

	(void)flag;
	nbr = va_arg(*args_printf, uint64_t);
	if ((vector = vct_new(0)) == NULL)
		return (NULL);
	if((nb_itoa = ft_u_itoa_base(nbr, 10)) == NULL)
		return (NULL);
	if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
	{
		vct_del(&vector);
		return (NULL);
	}	
	return (vector);
}
