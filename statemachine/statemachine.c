/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/09/02 18:59:58 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		debug(t_state_machine *machine, char *input, int8_t scale,
					enum e_main_states state)
{
	static const char  *state_str[] = {"\033[31mSTR", "\033[32mFLAG",
							"\033[33mCONV", "\033[36mOUT", "\033[35mERROR"};

	if (state == ST_OUTPUT)
		printf("|------------>\tstate:%s\033[0m\n\n",
					state_str[state]);
	else if (*input != '\0')
		printf("input: %.*s\tstate:%s\033[0m\toption: 0x%016llx\n",
				scale == 0 ? 1 : scale, input, state_str[state], machine->option);
}

int8_t		parser(t_state_machine *machine, char *input, va_list *args_printf)
{
	static t_statefunc	parser[5] = {string, flag, conversion, output, error};
	int8_t				scale;
	enum e_main_states	cur_state;

	while (machine->state != ST_END)
	{
		cur_state = machine->state;
		if ((scale = parser[machine->state](machine, input, args_printf)) != FAILURE)
		{
			debug(machine, input, scale, cur_state); //  DEBUG
			input += scale;
		}
	}
	printf("\nlen is : %lu \nNotre Printf:\t%s\n", machine->p_output->len, machine->p_output->str);
	return (-5);
}
