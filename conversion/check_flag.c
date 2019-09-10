/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:22:33 by fkante            #+#    #+#             */
/*   Updated: 2019/09/10 11:15:36 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cancel_flag_for_numeric_conv(t_flag *flag)
{
	if (flag->option & FLAG_ZERO && flag->option & FLAG_POINT)
		flag->option &= ~FLAG_ZERO;
}

void	cancel_flag_for_other_conv(t_flag *flag)
{
	if (flag->option & FLAG_ZERO && flag->option & FLAG_POINT)
		flag->option &= ~FLAG_ZERO;
	if (flag->option & FLAG_SPACE)
		flag->option &= ~FLAG_SPACE;
}

void	check_and_cancel_flag(t_state_machine *machine)
{
	if (machine->option & FLAG_PLUS && machine->option & FLAG_SPACE)
		machine->option &= ~FLAG_SPACE;
	if (machine->option & FLAG_MINUS && machine->option & FLAG_ZERO)
		machine->option &= ~FLAG_ZERO;
}
