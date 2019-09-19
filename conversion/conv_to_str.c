/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:31:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/10 12:12:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vector	*conv_to_str(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*to_be_joined;
	char		*str;

	vector = vct_new(flag->width);
	cancel_flag_for_other_conv(flag);
	str = va_arg(*arg_pf, char *);
	str = (char*)apply_modifier_s((uint64_t)str, flag->option);
	if (str == NULL)
		to_be_joined = vct_newstr("(null)");
	else
		to_be_joined = vct_newstr(str);
	if (to_be_joined != NULL)
	{
		if ((apply_padding_flag(vector, flag, to_be_joined)) == FAILURE)
			vct_del(&vector);
	}
	else
		vct_del(&vector);
	vct_del(&to_be_joined);
	return (vector);
}
