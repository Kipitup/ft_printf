/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:55:03 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 18:04:37 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_char(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	char		c;

	c = (char)va_arg(*args_printf, int);
	c = apply_modifier_u((int64_t)c, flag->option);
	if ((vector = vct_new(0)) == NULL)
		return (NULL);
	if ((vct_add_char(vector, c)) == FAILURE)
		vct_del(&vector);
	return (vector);
}
