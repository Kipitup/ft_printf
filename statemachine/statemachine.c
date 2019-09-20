/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statemachine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:37:23 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 02:14:32 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		debug(t_state_machine *ptf, char *input, int8_t scale,
					enum e_main_states state)
{
	static const char  *state_str[] = {"\033[31mSTR", "\033[32mFLAG",
							"\033[33mCONV", "\033[36mOUT", "\033[35mERROR"};

	if (state == ST_BUFFER)
		printf("|------------>\tstate:%s\033[0m\n\n",
					state_str[state]);
	else if (*input != '\0')
		printf("input: %.*s\tstate:%s\033[0m\toption: 0x%8x\t width: %llu\t precision: %llu\n",
				scale == 0 ? 1 : scale, input, state_str[state], ptf->option, ptf->width, ptf->precision);
}

ssize_t		parser(t_state_machine *ptf, char *input, va_list *arg_pf)
{
	static t_statefunc	parser[5] = {string, flags, conversion, buffer, color};
	enum e_main_states	cur_state;
	int8_t				scale;

	while (ptf->state != ST_END && ptf->state != ST_ERROR)
	{
		cur_state = ptf->state;
		if ((scale = parser[ptf->state](ptf, input, arg_pf)) != FAILURE)
		{
			// debug(ptf, input, scale, cur_state); //  DEBUG
			input += scale;
		}
	}
	return (ptf->state == ST_ERROR ? FAILURE : vct_len(ptf->output));
}
