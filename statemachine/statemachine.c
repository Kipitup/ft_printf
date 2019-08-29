/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/08/29 18:50:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "ft_printf.h"

int8_t	string(t_state_machine *machine, char *input)
{
	machine->p_cursor = input;
	if (*input == CONVERSION_SIGN)
		machine->state = ST_FLAG;
	else
	{
//		vct_add(machine->p_out, *input);
	}
	return (1);
}

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
			printf("|flag: %s|\n", grammar[i]);
			return ((int8_t)len);
		}
		i++;
	}
	machine->state = ST_CONVERSION;
	return (FAILURE);
}

int8_t	conversion(t_state_machine *machine, char *input)
{
	static const char	*grammar[10] = {"c", "s", "p", "d", "i", "o", "u", "x",
									"X", "f"};
	int					i;
	size_t				len;
//	static t_convfunc	conversion_func[10] = {conv_char, conv_string, conv_ptr,
//		conv_dec, conv_int, conv_oct, conv_udec, conv_hex, conv_hex_M, conv_flo}

	i = 0;
	machine->p_cursor = input;
	while (i < 10)
	{
		len = ft_strlen(grammar[i]);
		if (ft_strnequ(grammar[i], input, len) == TRUE)
		{
			//machine->option |= pow(2, (i + 1)) << 8;
			//conversion_func[i](machine->option, machine.);
			printf("|conv: %s|\n", grammar[i]);
			return ((int8_t)len);
		}
		i++;
	}
	machine->state = ST_ERROR;
	return (FAILURE);
}

int8_t	error(t_state_machine *machine, char *input)
{
	int		scale;
//	char	*tmp;
	
	scale = input - machine->p_cursor; //error check with
//	if ((tmp = ft_strndup(machine->p_cursor, scale)) == FAILURE)
//		return (ERROR_DUP);
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
		printf("input: %c\tscale: %d\tstate:%u\n", *input, scale, machine->state);
		if ((scale = parser[machine->state](machine, input)) != FAILURE)
			input += scale;
	}
	//write(1, machine->p.out, vct_len(machine->p.out);
	return (-5);
}

//on revient pas en état de conversion
