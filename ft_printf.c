/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:12:35 by amartino          #+#    #+#             */
/*   Updated: 2019/09/01 20:08:28 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *input, ...)
{
	t_state_machine	machine;
	va_list			args_printf;

	init_state_machine(&machine, input);
	va_start(args_printf, input);
	parser(&machine, (char *)input, &args_printf);
	va_end(args_printf);
	return (SUCCESS);
}
