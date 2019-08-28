/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/08/28 15:35:55 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/define.h"
#include "../header/ft_printf.h"


int8_t	flag_machine (*machine, char *input)
{
	static const char *grammar[8] = {"ll", "hh", "h", "l", "+", "-", "#", "0"};
	int		i;
	size_t	len;

	i = 0;
	while (i < 8)
	{
		len = ft_strlen(grammar[i]);
		if (ft_strnequ(grammar, input, len) == TRUE)
		{
			if (i == E_TYPE_POINT)
			{

			}
			machine->option |= pow(2, (i + 1));
			return ((int8_t)len);
		}
		i++;
	}
	machine->state = ST_CONVERSION;
	return (FAILURE);
}

int8_t	conversion(t_state machine *machine, char *input)
{
	static const char *grammar[8] = {"d", "o"};
	int		i;
	size_t	len;

	while (i < 8)
	{
		len = ft_strlen(grammar[i]);
		if (ft_strnequ(grammar, input, len) == TRUE)
		{
			machine->option |= pow(2, (i + 1)) << 8;
			return ((int8_t)len);
		}
		i++;
	}
	machine->state = ST_ERROR;
	return (FAILURE);
}

int		parser(char *cursor, t_state_machine)
{
	static tab_statefunc *parser[5];
	parser[] = {string, flag, conversion, print, error};
	int		scale;

	while (*cursor)
	{
		if ((scale = parser[machine->state](machine, input) != FAILURE)
			input += scale
		else
	}
}











option &= ~SPACE enleve
option |= SPACE ajoute
option & SPACE test
