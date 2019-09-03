/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 10:21:00 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac <= 2)
		return (0);
	//char *str;

	//str = NULL;
	/*	
	ft_printf(av[1], av[2], ac <= 3 ? NULL : av[3],
						ac <= 4 ? NULL : av[4], ac <= 5 ? NULL : av[5]);
	printf("------------\n");
	printf(av[1], av[2], ac <= 3 ? NULL : av[3],
						ac <= 4 ? NULL : av[4], ac <= 5 ? NULL : av[5]);
	*/
	printf("Leur Printf:\t");
	printf(av[1], atoi(av[2]));
	printf("------------\n");
	ft_printf(av[1], atoi(av[2]));
	
	return (0);
}

/*option &= ~SPACE enleve
  option |= SPACE ajoute
  option & SPACE test*/
