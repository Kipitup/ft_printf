/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:31:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/04 14:34:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_string(va_list *args_printf, t_flag *flag)
{
	t_vector	*vector;
	char		*str;

	(void)flag;
	str = va_arg(*args_printf, char *);
		str = (char*)apply_modifier_di((int64_t)str, flag->option);
	if ((vector = vct_new(0)) == NULL)
		return (NULL);
	if ((vct_strjoin(vector, str)) == FAILURE)
	{
		vct_del(&vector);
		return (NULL);
	}
	return (vector);
}
