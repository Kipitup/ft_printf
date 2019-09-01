/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:27:50 by amartino          #+#    #+#             */
/*   Updated: 2019/09/01 19:02:26 by fkante           ###   ########.fr       */
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
		machine->state = ST_OUTPUT;
		return (0);
	}
	else if (vct_add_char(machine->p_output, *input) == FAILURE)
		machine->state = ST_ERROR;
	return (1);
}

int8_t	flag(t_state_machine *machine, char *input, va_list *args_printf)
{
	(void)args_printf;
	static const char	*flags[NB_OF_FLAGS] = {HH, LL, H, L, L_MAJ, PLUS,
											   MINUS, HASH, ZERO, SPACE, POINT};
	size_t				len;
	uint8_t				i;

	i = 0;
	machine->p_cursor = input;
	while (i < NB_OF_FLAGS)
	{
		len = i < 2 ? 2 : 1;
		if (ft_strnequ(flags[i], input, len) == TRUE)
		{
			machine->option |= ft_pow_positive(2, i);
			return ((int8_t)len);
		}
		i++;
	}
	machine->state = ST_CONVERSION;
	return (FAILURE);
}

int8_t	conversion(t_state_machine *machine, char *input, va_list *args_printf)
{
	(void)args_printf;
	static char *convs[NB_OF_CONVS] = {C, S, P, D, I, O, U, X, X_MAJ, F};
	int		i;

	i = 0;
	machine->p_cursor = input;
	while (i < NB_OF_CONVS)
	{
		if (ft_strnequ(convs[i], input, 1) == TRUE)
			break ;
		i++;
	}
	machine->option |= ft_pow_positive(2, i) << 16;
	machine->state = ST_OUTPUT;
	return (0);
}

int8_t			output(t_state_machine *machine, char *input, va_list *args_printf)
{
	check_and_cancel_flag(machine);
	if (*input == '\0')
	{
		// EXTRACT
		machine->state = ST_END;
		return (0);
	}
	else if (convert(machine, input, args_printf) == FAILURE)
		machine->state = ST_ERROR;
	else
		machine->state = ST_STRING;
	machine->option = 0;
	return (1);
}

int8_t	error(t_state_machine *machine, char *input, va_list *args_printf)
{
	(void)machine;
	(void)input;
	(void)args_printf;
	return (FAILURE);
}