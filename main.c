/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/02 12:01:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac <= 1)
		return (0);

	ft_printf(av[1], ac <= 2 ? NULL : av[2], ac <= 3 ? NULL : av[3],
						ac <= 4 ? NULL : av[4], ac <= 5 ? NULL : av[5]);
	return (0);
}

/*option &= ~SPACE enleve
  option |= SPACE ajoute
  option & SPACE test*/
