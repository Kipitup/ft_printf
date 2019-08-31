/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:13 by fkante            #+#    #+#             */
/*   Updated: 2019/08/30 16:51:31 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_state_machine init_state_machine(char *argv)
{
	t_state_machine machine;

	ft_bzero(&machine, sizeof(t_state_machine));
	machine.state = ST_STRING;
	machine.p_cursor = argv;
	return (machine);
}

t_main init_main_struct(char *input)
{
	t_main struc_main;

	ft_bzero(&struc_main;, sizeof(t_main));
	struc_main.option = 0x0000000000000000;
	va_start(struc_main->arg_printf, input); 
	return (struc_main);
}
