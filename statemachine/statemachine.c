/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/09/17 17:56:34 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



size_t		parser(t_state_machine *machine, char *input, va_list *args_printf)
{
	static t_statefunc	parser[5] = {string, flags, conversion, buffer, end};
	int8_t				scale;

	while (machine->state != ST_END)
	{
		if ((scale = parser[machine->state](machine, input, args_printf)) != FAILURE)
			input += scale;
	}
	return (machine->p_output->len);
}
