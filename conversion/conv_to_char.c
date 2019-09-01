/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:55:03 by fkante            #+#    #+#             */
/*   Updated: 2019/09/01 20:12:46 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_char(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		c;

	(void)flag;
	c = (char)va_arg(*args_printf, int);
	//apply_flag(c, flag);
	vector = vct_new(0);
	vct_add_char(vector, c);
	return (vector);
}
