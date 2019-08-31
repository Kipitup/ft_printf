/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/08/31 16:39:16 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int ac, char **av)
{
	//	t_vector		*output_string;
	t_state_machine	machine;// initialize in newfile
	t_main			t_argv;

	if (ac <= 1)
		return (0);
	init_state_machine(av[1]);
	init_main_struct(*input);
	//	if (machine->state == ST_STRING && *output_string == NULL)
	//		output_string = vct_new(0);
	//	machine.p_out = *output_string;
		printf("%d\n", (parser(&machine, av[1])));
	//ft_printf("%s%d%x", av[1], av[2]);
//	printf("%s%d%x");

	return (0);
}

/*option &= ~SPACE enleve
  option |= SPACE ajoute
  option & SPACE test*/
