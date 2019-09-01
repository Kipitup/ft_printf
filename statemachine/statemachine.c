/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/09/01 12:26:52 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t		parser(t_state_machine *machine, char *input, va_list args_printf)
{
	static t_statefunc	parser[5] = {string, flag, conversion, output, error};
	int8_t				scale;

	while (*input)
	{
		if ((scale = parser[machine->state](machine, input, args_printf)) != FAILURE)
		{
			printf("input: %c\tscale: %u\tstate:%u\toption : %llx\n", *input, scale, machine->state, machine->option);
			input += scale;
		}
//		if (ft_error(scale, machine) == SUCCESS)
//			return (FAILURE);
	}
	printf("\nlen is : %lu \t%s\n", machine->p_output->len, machine->p_output->str);
	// write(1, machine->p_output->str, machine->p_output->len);
	return (-5);
}
