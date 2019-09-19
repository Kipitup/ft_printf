/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:05:11 by amartino          #+#    #+#             */
/*   Updated: 2019/09/18 20:10:58 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t	is_width(t_state_machine *machine, char *input, va_list *arg_pf)
{
	int32_t	neg_prot;
	size_t	nb;

	neg_prot = 0;
	nb = 0;
	if (ft_isdigit((int)input[0]) == TRUE)
		machine->width = get_numbers(machine, input, &nb);
	else if (input[0] == WILDCARD_SIGN)
	{
		if ((neg_prot = va_arg(*arg_pf, int64_t)) < 0)
		{
			neg_prot = ft_absolute(neg_prot);
			machine->option |= FLAG_MINUS;
		}
		machine->width = neg_prot;
		nb++;
	}
	return (nb);
}

uint8_t	is_precision(t_state_machine *machine, char *input, va_list *arg_pf)
{
	int32_t	neg_prot;
	size_t	nb;

	neg_prot = 0;
	nb = 0;
	if (ft_isdigit((int)input[0]) == TRUE)
		machine->precision = get_numbers(machine, input, &nb);
	else if (input[0] == WILDCARD_SIGN)
	{
		if ((neg_prot = va_arg(*arg_pf, int64_t)) < 0)
		{
			neg_prot = 0;
			machine->option &= ~FLAG_POINT;
		}
		machine->precision = neg_prot;
		nb++;
	}
	return (nb + 1);
}

uint64_t	get_numbers(t_state_machine *machine, char *input, size_t *count)
{
	uint64_t	nb;
	t_vector	*vector;

	nb = 0;
	vector = vct_new(0);
	if (vector == NULL)
		machine->state = ST_ERROR;
	else
	{
		while (ft_isdigit((int)input[*count]) == TRUE)
		{
			if ((vct_addchar(vector, input[*count])) == FAILURE)
			{
				machine->state = ST_ERROR;
				break ;
			}
			(*count)++;
		}
		nb = (uint64_t)ft_atoi(vector->str);
		vct_del(&vector);
	}
	return (nb);
}
