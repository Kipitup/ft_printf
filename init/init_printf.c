/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:13 by fkante            #+#    #+#             */
/*   Updated: 2019/08/31 19:58:44 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_state_machine(t_state_machine *machine, const char *input)
{
	ft_bzero(machine, sizeof(t_state_machine));
	machine->state = ST_STRING;
	machine->p_cursor = (char *)input;
	machine->p_output = vct_new(0);
}
