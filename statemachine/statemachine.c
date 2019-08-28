/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/08/28 18:57:20 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/define.h"
#include "../header/ft_printf.h"


int8_t	flag(t_state_machine *machine, char *input)
{
	static const char	*grammar[11] = {"hh", "ll", "h", "l", "L", "+", "-",
						"#", "0", " ", "."};
	int					i;
	size_t				len;

	i = 0;
	machine->p_cursor = input;
	while (i < 11)
	{
		len = ft_strlen(grammar[i]);
		if (ft_strnequ(grammar[i], input, len) == TRUE)
		{
			//machine->option |= pow(2, (i + 1));
			printf("|flag%s|\n", grammar[i]);
			return ((int8_t)len);
		}
		i++;
	}
	machine->state = ST_CONVERSION;
	return (FAILURE);
}

int8_t	conversion(t_state_machine *machine, char *input)
{
	static const char *grammar[10] = {"c", "s", "p", "d", "i", "o", "u", "x", 
									"X", "f"};
	int		i;
	size_t	len;

	i = 0;
	machine->p_cursor = input;		
	while (i < 10)
	{
		len = ft_strlen(grammar[i]);
		if (ft_strnequ(grammar[i], input, len) == TRUE)
		{
			//machine->option |= pow(2, (i + 1)) << 8;
			printf("|conv%s|\n", grammar[i]);
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
	char	*tmp;
	
	scale = 1;
//	scale = input - machine->p_cursor;//error
//	tmp = ft_strndup(machine->p_cursor, scale); 
	/// ADD STRING (output, tmp);
//	ft_strdel(&tmp);
	machine->state = ST_STRING;
	return (scale);
}

int8_t		parser(t_state_machine *machine, char *input)
{
	static t_statefunc parser[4] = {string, flag, conversion, error};
	int8_t				scale;

	while (*input)
	{
		if ((scale = parser[machine->state](machine, input)) != FAILURE)
			input += scale;
	}
	printf("end\n");
	//write(1, machine->output->buffer, vct_len(machine->output);
	return (-2);
}

/*option &= ~SPACE enleve
option |= SPACE ajoute
option & SPACE test*/

on revient pas en état de conversion
