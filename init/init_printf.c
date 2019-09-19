/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:29:13 by fkante            #+#    #+#             */
/*   Updated: 2019/09/19 16:04:55 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t	init_state_machine(t_state_machine *ptf, int fd)
{
	ft_bzero(ptf, sizeof(t_state_machine));
	ptf->state = ST_STRING;
	if (fd >= 0)
		ptf->fd = fd;
	else
		return (FAILURE);
	ptf->output = vct_new(0);
	if (ptf->output == NULL)
		return (FAILURE);
	return (SUCCESS);
}

void	init_flags(t_state_machine *ptf, t_flag *flag)
{
	ft_bzero(flag, sizeof(t_flag));
	flag->width = 		ptf->width;
	flag->precision = 	ptf->precision;
	flag->option =		ptf->option;
}
