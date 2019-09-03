/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:51:01 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 09:48:31 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector		*conv_to_nbr(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	uint8_t		base;
	int64_t		nbr;
	char		*nb_itoa;

	(void)flag;
	base = 10;
	if (flag & CONV_O)
			base = 8;
	if (flag & CONV_X)
			base = 16;
	nbr = va_arg(*args_printf, int64_t);
	if ((vector = vct_new(0)) == NULL)
		return (NULL);
	if((nb_itoa = ft_itoa_base(nbr, base)) == NULL)
		return (NULL);
	if ((vct_strjoin(vector, nb_itoa)) == FAILURE)
	{
		vct_del(&vector);
		return (NULL);
	}	
	return (vector);
}
