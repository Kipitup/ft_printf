/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/08/29 19:30:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char **av)
{
	t_vector		*output_string;
	t_state_machine	machine;

	if (ac <= 1)
		return (0);
	ft_bzero(&machine, sizeof(t_state_machine));
	machine.state = ST_STRING;
	machine.p_cursor = av[1];
//	if (machine->state == ST_STRING && *output_string == NULL)
//		output_string = vct_new(0);
//	machine.p_out = *output_string;
	(void)output_string;
	printf("%d\n", (parser(&machine, av[1])));
	return (0);
}


/*option &= ~SPACE enleve
option |= SPACE ajoute
option & SPACE test*/
