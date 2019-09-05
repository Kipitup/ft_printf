/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 11:13:26 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	//if (ac <= 2)
	//	return (0);
	//char *str;
	(void)ac;

	//str = NULL;
	/*
	ft_printf(av[1], av[2], ac <= 3 ? NULL : av[3],
						ac <= 4 ? NULL : av[4], ac <= 5 ? NULL : av[5]);
	printf("\n------------\n");
	printf("printf:\t\t");
	printf(av[1], av[2], ac <= 3 ? NULL : av[3],
						ac <= 4 ? NULL : av[4], ac <= 5 ? NULL : av[5]);
*/
	
	ft_printf(av[1], atoll(av[2]));
	printf("------------\n");
	printf("Printf:\t\t");
	printf(av[1], atoll(av[2]));
	/*
	ft_printf("ft_printf: |%c|\n", 'Q');
	printf("printf: |%c|\n", 'Q');
	printf("------------\n");
	ft_printf("ft_printf: |%hhc|\n", 'Q');
	printf("printf: |%hhc|\n", 'Q');
	printf("------------\n");
	ft_printf("ft_printf: |%llc|\n", 'Q');
	printf("printf: |%llc|\n", 'Q');
	printf("------------\n");
	ft_printf("ft_printf: |%hc|\n", 'Q');
	printf("printf: |%hc|\n", 'Q');
	printf("------------\n");
	ft_printf("ft_printf: |%hhp|\n", 'Q');
	printf("printf: |%hhp|\n", 'Q');
*/
	return (0);
}

/*option &= ~SPACE enleve
  option |= SPACE ajoute
  option & SPACE test*/
