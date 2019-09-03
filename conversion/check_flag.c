/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:22:33 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 09:19:30 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_and_cancel_flag(t_state_machine *machine)
{
	if (machine->option & FLAG_PLUS && machine->option & FLAG_SPACE)
		machine->option &= ~FLAG_SPACE;
	if (machine->option & FLAG_MINUS && machine->option & FLAG_ZERO)
		machine->option &= ~FLAG_ZERO;
}

int8_t	convert(t_state_machine *machine, char *input, va_list *args_printf)
{
	static		t_convfunc	func_ptr[NB_OF_CONVS] = {conv_to_char, 
							conv_to_string, conv_to_pointer, conv_to_nbr,
							conv_to_nbr, conv_to_nbr, conv_to_u_decimal,
							conv_to_nbr, conv_to_hexa_maj, conv_to_float};
	t_vector				*local;
	uint8_t					i;

	(void)input;
	i = 0;
	while (i < NB_OF_CONVS)
	{
		if (machine->option & ((1 << i) << SHIFT_TO_CONVS))
		{
			if ((local = func_ptr[i](args_printf, machine->option)) == NULL)
					return (FAILURE);
			if (vct_strjoin(machine->p_output, local->str) == FAILURE)
				return (FAILURE);
			vct_del(&local);
			break ;
		}
		i++;
	}
	return (SUCCESS);
}
