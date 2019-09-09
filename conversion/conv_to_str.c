/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:31:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/09 14:33:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_str(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	char		*str;

	str = va_arg(*args_printf, char *);
	str = (char*)apply_modifier_s((uint64_t)str, flag->option);
	vector = vct_new(0);
	if ((vct_strjoin(vector, str)) == FAILURE)
		vct_del(&vector);
	return (vector);
}
