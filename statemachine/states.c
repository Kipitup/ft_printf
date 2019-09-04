/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:27:50 by amartino          #+#    #+#             */
/*   Updated: 2019/09/04 09:20:36 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t	string(t_state_machine *machine, char *input, va_list *args_printf)
{
	(void)args_printf;
	machine->p_cursor = input;
	if (*input == CONVERSION_SIGN)
		machine->state = ST_FLAG;
	else if (*input == '\0')
	{
		machine->state = ST_BUFFER;
		return (0);
	}
	else if (vct_add_char(machine->p_output, *input) == FAILURE)
		machine->state = ST_END;
	return (1);
}

int8_t	flag(t_state_machine *machine, char *input, va_list *args_printf)
{
	static const char	*flags[NB_OF_FLAGS] = {HH, LL, H, L, L_MAJ, PLUS,
											   MINUS, HASH, ZERO, SPACE, POINT};
	size_t				len;
	uint8_t				i;

	(void)args_printf;
	i = 0;
	machine->p_cursor = input;
	while (i < NB_OF_FLAGS)
	{
		len = i < 2 ? 2 : 1;
		if (ft_strnequ(flags[i], input, len) == TRUE)
		{
			if (i < NB_OF_MODIFIER)//to be DEFINED
				machine->option &= ~ALL_MOD;
			machine->option |= ft_pow_positive(2, i);
			return (flags[i] == POINT ? is_precision(machine, input + 1) : len);
		}
		i++;
	}
	if ((len = is_width(machine, input)) > 0)
		return ((int8_t)len);
	machine->state = ST_CONVERSION;
	return (FAILURE);
}

int8_t	conversion(t_state_machine *machine, char *input, va_list *args_printf)
{
	(void)args_printf;
	static char *convs[NB_OF_CONVS] = {C, S, P, D, I, O, U, X, X_MAJ, F};
	uint8_t		i;

	i = 0;
	machine->p_cursor = input;
	while (i < NB_OF_CONVS)
	{
		if (ft_strnequ(convs[i], input, 1) == TRUE)
			break ;
		i++;
	}
	machine->option |= ft_pow_positive(2, i) << 16;
	machine->state = ST_BUFFER;
	return (0);
}

int8_t			buffer(t_state_machine *machine, char *input, va_list *args_printf)
{
	if (*input == '\0')
	{
		printf("\nlen is : %lu\n", machine->p_output->len);
		write(1, machine->p_output->str, machine->p_output->len);
		write(1, "\n", 1);
		machine->state = ST_END;
		return (0);
	}
	check_and_cancel_flag(machine);
	if (convert(machine, input, args_printf) == FAILURE)
		machine->state = ST_END;
	else
		machine->state = ST_STRING;
	machine->option = 0;
	return (1);
}

int8_t	end(t_state_machine *machine, char *input, va_list *args_printf)
{
	(void)input;
	(void)args_printf;

	vct_del(&machine->p_output);
	return (SUCCESS);
}
