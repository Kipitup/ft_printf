/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:31:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 09:25:53 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_string(va_list *args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		*str;

	(void)flag;
	str = va_arg(*args_printf, char *);
	//apply_flag(c, flag);
	if ((vector = vct_new(0)) == NULL)
		return (NULL);
	if ((vct_strjoin(vector, str)) == FAILURE)
	{
		vct_del(&vector);
		return (NULL);
	}
	return (vector);
}
