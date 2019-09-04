/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:55:03 by fkante            #+#    #+#             */
/*   Updated: 2019/09/04 09:31:44 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_char(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		c;

	(void)flag;
	c = (char)va_arg(*args_printf, int);
	c = apply_modifier_di((int64_t)c, flag);
	if ((vector = vct_new(0)) == NULL)
		return (NULL);
	if ((vct_add_char(vector, c)) == FAILURE)
	{
		vct_del(&vector);
		return (NULL);
	}
	return (vector);
}
