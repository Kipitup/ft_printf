/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:12:35 by amartino          #+#    #+#             */
/*   Updated: 2019/09/17 16:22:30 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *input, ...)
{
	t_state_machine		machine;
	va_list				args_printf;
	size_t				len;

	init_state_machine(&machine);
	va_start(args_printf, input);
	len = parser(&machine, (char *)input, &args_printf);
	vct_del(&(machine.p_output));
	va_end(args_printf);
	return (len);
}
