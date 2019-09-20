/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:31:42 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 08:54:42 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int8_t		conv_to_r(t_vector *vector)
// {
// 	char		*str;
// 	size_t		index;
// 	size_t		len;
// 	int8_t		ret;
// 	int			nb;
//
// 	index = 0;
// 	len = vct_len(vector);
// 	ret = SUCCESS;
// 	while (index < len)
// 	{
// 		if ((ft_isprint(vct_getchar_at(vector, index))) == FALSE)
// 		{
// 			ret = vct_addchar_at(vector, '\\', index);
// 			index++;
// 			nb = (int)vct_getchar_at(vector, index);
// 			printf("%d\n", nb);
// 			str = ft_itoa(nb);
// 			printf("str : %s\n", str);
// 			ret = vct_addstr_at(vector, str, index);
// 			printf("str : %s\n", vector->str);
// 			if (ret == FAILURE)
// 				break ;
// 			index++;
// 		}
// 		index++;
// 	}
// 	return (ret);
// }

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
	{
		to_be_joined = vct_newstr(str);
		// if (flag->option & CONV_R)
		// {
		// 	if ((conv_to_r(to_be_joined)) == FAILURE)
		// 		vct_del(&to_be_joined);
		// }
	}
	if (to_be_joined != NULL)
	{
		if ((apply_padding_flag(vector, flag, to_be_joined)) == FAILURE)
			vct_del(&vector);
	}
	else
		vct_del(&vector);
	vct_del(&to_be_joined);
	printf("be join : %s\nlen: %zu\n", vector->str, vector->len);
	return (vector);
}
