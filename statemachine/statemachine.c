/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/08/30 13:46:45 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "ft_printf.h"

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
		len = ft_strlen(flags[i]);
		if (ft_strnequ(flags[i], input, len) == TRUE)
		{
			//machine->option |= ft_pow(2, (i + 1));
			printf("|flag%s|\n", flags[i]);
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
	size_t	len;

	i = 0;
	machine->p_cursor = input;
	while (i < NB_OF_CONVS)
	{
		len = ft_strlen(convs[i]);
		if (ft_strnequ(convs[i], input, len) == TRUE)
		{
			//machine->option |= ft_pow(2, (i + 1)) << 16;
			printf("|conv%s|\n", convs[i]);
			return ((int8_t)len);
		}
		i++;
	}
	machine->state = ST_ERROR;
	return (FAILURE);
}

int8_t	string(t_state_machine *machine, char *input)
{
	machine->p_cursor = input;
	if (*input == CONVERSION_SIGN)
		machine->state = ST_FLAG;
	else
	{
		///////// ADD BUFFER (input)
	}
	return (1);
}

int8_t	error(t_state_machine *machine, char *input)
{
	int		scale;
	// char	*tmp;

	scale = input - machine->p_cursor; //error check with
//	tmp = ft_strndup(machine->p_cursor, scale);
	/// ADD STRING (output, tmp);
//	ft_strdel(&tmp);
	machine->state = ST_STRING;
	return (scale);
}

int8_t		parser(t_state_machine *machine, char *input)
{
	static t_statefunc	parser[4] = {string, flag, conversion, error};
	int8_t				scale;

	while (*input)
	{
		if ((scale = parser[machine->state](machine, input)) != FAILURE)
			input += scale;
	}
	//write(1, machine->output->buffer, vct_len(machine->output);
	return (-2);
}
