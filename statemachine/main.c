/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/08/28 18:53:56 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		main(int ac, char **av)
{
	int fd;
	t_state_machine machine;

	if (ac <= 1)
		return (0);
	ft_bzero(&machine, sizeof(t_state_machine));
	machine.state = ST_STRING;
	machine.p_cursor = av[1];
	printf("%d\n", (parser(&machine, av[1])));
	return (0);
}
