/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:27:50 by amartino          #+#    #+#             */
/*   Updated: 2019/08/31 21:58:03 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t	string(t_state_machine *machine, char *input)
{

	machine->p_cursor = input;
	if (*input == CONVERSION_SIGN)
		machine->state = ST_FLAG;
	else
		vct_add_char(machine->p_output, *input);
	return (1);
}

int8_t	flag(t_state_machine *machine, char *input)
{

	static const char	*flags[NB_OF_FLAGS] = {HH, LL, H, L, L_MAJ, PLUS,
											   MOINS, HASH, ZERO, SPACE, POINT};
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

int8_t	conversion(t_state_machine *machine, char *input)
{

	static char *convs[NB_OF_CONVS] = {C, S, P, D, I, O, U, X, X_MAJ, F};
	int		i;

	i = 0;
	machine->p_cursor = input;
	while (i < NB_OF_CONVS)
	{
		if (ft_strnequ(convs[i], input, 1) == TRUE)
		{
			machine->option |= ft_pow_positive(2, i) << 16;
			machine->state = ST_OUTPUT;
			return (1);
		}
		i++;
	}
	machine->state = ST_ERROR;
	return (FAILURE);
}

int8_t			output(t_state_machine *machine, char *input, va_list args_printf)
{
	(void)args_printf;
	(void)input;

	//appeler la bonne conversion

	machine->state = ST_STRING;
	return (0);
}

int8_t	error(t_state_machine *machine, char *input, va_list args_printf)
{
	(void)args_printf;
	(void)input;
	(void)machine;
	printf("error : appliquer les flags a *input\n");
	return (FAILURE);
}
