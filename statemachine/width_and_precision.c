/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:05:11 by amartino          #+#    #+#             */
/*   Updated: 2019/09/06 14:59:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t	is_width(t_state_machine *machine, char *input)
{
	size_t	nb;

	nb = 0;
	if (ft_isdigit((int)input[0]) == TRUE)
		machine->width = get_numbers(machine, input, &nb);
	return (nb);
}

uint8_t	is_precision(t_state_machine *machine, char *input)
{
	size_t	nb;

	nb = 0;
	if (ft_isdigit((int)input[0]) == TRUE)
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
			if ((vct_push_char(vector, input[*count])) == FAILURE)
			{
				machine->state = ST_END;
				break ;
			}
			(*count)++;
		}
		nb = (uint64_t)ft_atoi(vector->str);
		vct_del(&vector);
	}
	return (nb);
}
