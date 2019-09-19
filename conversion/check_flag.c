/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:22:33 by fkante            #+#    #+#             */
/*   Updated: 2019/09/13 17:27:30 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cancel_flag_for_numeric_conv(t_flag *flag)
{
	if (flag->option & FLAG_ZERO && flag->option & FLAG_POINT)
		flag->option &= ~FLAG_ZERO;
}

void	cancel_flag_for_u_conv(t_flag *flag)
{
	if (flag->option & FLAG_ZERO && flag->option & FLAG_POINT)
		flag->option &= ~FLAG_ZERO;
	if (flag->option & FLAG_SPACE)
		flag->option &= ~FLAG_SPACE;
	if (flag->option & FLAG_PLUS)
		flag->option &= ~FLAG_PLUS;
}


void	cancel_flag_for_other_conv(t_flag *flag)
{
	if (flag->option & FLAG_ZERO && flag->option & FLAG_POINT)
		flag->option &= ~FLAG_ZERO;
	if (flag->option & FLAG_SPACE)
		flag->option &= ~FLAG_SPACE;
}

void	check_and_cancel_flag(t_state_machine *ptf)
{
	if (ptf->option & FLAG_PLUS && ptf->option & FLAG_SPACE)
		ptf->option &= ~FLAG_SPACE;
	if (ptf->option & FLAG_MINUS && ptf->option & FLAG_ZERO)
		ptf->option &= ~FLAG_ZERO;
}
