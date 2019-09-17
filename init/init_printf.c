/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:13 by fkante            #+#    #+#             */
/*   Updated: 2019/09/17 16:18:43 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_state_machine(t_state_machine *machine)
{
	ft_bzero(machine, sizeof(t_state_machine));
	machine->state = ST_STRING;
	machine->p_output = vct_new(0);
}

void	init_flags(t_state_machine *machine, t_flag *flag)
{
	ft_bzero(flag, sizeof(t_flag));
	flag->width = 		machine->width;
	flag->precision = 	machine->precision;
	flag->option =		machine->option;
}
