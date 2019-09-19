/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:42:12 by amartino          #+#    #+#             */
/*   Updated: 2019/09/19 11:16:18 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t	convert(t_state_machine *machine, t_flag *flag, char *input, va_list *args_printf)
{
	static t_convfunc	func_ptr[NB_OF_CONVS] = {conv_to_char, conv_to_str,
							conv_to_pointer, conv_to_di, conv_to_di, conv_to_ox,
							conv_to_u_decimal, conv_to_ox, conv_to_hexa_maj,
							conv_to_float};
	t_vector			*local;
	uint8_t				i;

	i = 0;
	local = NULL;
	while (i < NB_OF_CONVS)
	{
		if (machine->option & ((1 << i) << SHIFT_TO_CONVS))
		{
			if ((local = func_ptr[i](args_printf, flag)) == NULL)
					return (FAILURE);
			break ;
		}
		i++;
	}
	if (i == NB_OF_CONVS && (machine->option & ((1 << i) << SHIFT_TO_CONVS)))
		if ((local = conv_to_none(*input, flag)) == NULL)
			return (FAILURE);
	if (local == NULL || (vct_cat(machine->p_output, local) == FAILURE))
		return (FAILURE);
	vct_del(&local);
	return (SUCCESS);
}
