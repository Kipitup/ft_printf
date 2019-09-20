/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:22:12 by amartino          #+#    #+#             */
/*   Updated: 2019/09/20 10:18:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_asprintf(char **str, const char *input, ...)
{
	t_state_machine		ptf;
	va_list				arg_pf;
	ssize_t				ret;

	ret = init_state_machine(&ptf, 0);
	if (ret == SUCCESS)
	{
		va_start(arg_pf, input);
		ret = parser(&ptf, (char *)input, &arg_pf);
		*str = (char*)malloc(sizeof(char) * (vct_len(ptf.output) + 1));
		if (str == NULL)
			return (FAILURE);
		ft_memcpy(*str, vct_getstr(ptf.output), vct_len(ptf.output));
		*(str[vct_len(ptf.output)]) = '\0';
		vct_del(&(ptf.output));
		va_end(arg_pf);
	}
	return (ret);
}