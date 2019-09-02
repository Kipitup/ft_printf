/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/09/02 19:04:36 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		debug(t_state_machine *machine, char *input, int8_t scale,
					enum e_main_states state)
{
	static const char  *state_str[] = {"\033[31mSTR", "\033[32mFLAG",
							"\033[33mCONV", "\033[36mOUT", "\033[35mERROR"};

	if (state == ST_BUFFER)
		printf("|------------>\tstate:%s\033[0m\n\n",
					state_str[state]);
	else if (*input != '\0')
		printf("input: %.*s\tstate:%s\033[0m\toption: 0x%8x\t width: %llu\t precision: %llu\n",
				scale == 0 ? 1 : scale, input, state_str[state], machine->option, machine->width, machine->precision);
}

int8_t		parser(t_state_machine *machine, char *input, va_list args_printf)
{
	static t_statefunc	parser[5] = {string, flag, conversion, buffer, end};
	enum e_main_states	cur_state;
	int8_t				scale;

	while (machine->state != ST_END)
	{
		cur_state = machine->state;
		if ((scale = parser[machine->state](machine, input, args_printf)) != FAILURE)
		{
			debug(machine, input, scale, cur_state); //  DEBUG
			input += scale;
		}
	}
	return (-5);
}

uint8_t	is_width(t_state_machine *machine, char *input)
{
	size_t	nb;

	nb = 0;
	machine->width = get_numbers(machine, input, &nb);
	return (nb);
}

uint8_t	is_precision(t_state_machine *machine, char *input)
{
	size_t	nb;

	nb = 0;
	machine->precision = get_numbers(machine, input, &nb);
	return (nb + 1);
}

uint64_t	get_numbers(t_state_machine *machine, char *input, size_t *count)
{
	uint64_t	nb;
	t_vector	*vector;

	nb = 0;
	vector = vct_new(0);
	if (vector == NULL)
		machine->state = ST_END;
	else
	{
		while (ft_isdigit((int)input[*count]) == TRUE)
		{
			if ((vct_add_char(vector, input[*count])) == FAILURE)
			{
				machine->state = ST_END;
				break ;
			}
			(*count)++;
		}
	}
	if (machine->state != ST_END)
		nb = (uint64_t)ft_atoi(vector->str);
	vct_del(&vector);
	return (nb);
}
