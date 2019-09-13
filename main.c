/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/13 17:14:33 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;

	// ft_printf("%jx", 4294967296);
	// printf("\n");
	// printf("%jx", 4294967296);
	// printf("\n------------------------------\n");
	// ft_printf("%jx", -4294967296);
	// printf("\n");
	// printf("%jx", -4294967296);
	// printf("\n------------------------------\n");
	// ft_printf("%jx", -4294967297);
	// printf("\n");
	// printf("%jx", -4294967297);
	// printf("\n------------------------------\n");
	// ft_printf("%jd", 9223372036854775807);
	// printf("\n");
	// printf("%jd", 9223372036854775807);
	// printf("\n------------------------------\n");
	// ft_printf("%jd", -9223372036854775808);
	// printf("\n");
	// printf("%jd", -9223372036854775808);
	// printf("\n------------------------------\n");
	// ft_printf("%zd", 4294967295);
	// printf("\n");
	// printf("%zd", 4294967295);
	// printf("\n------------------------------\n");
	// ft_printf("%zd", 4294967296);
	// printf("\n");
	// printf("%zd", 4294967296);
	// printf("\n------------------------------\n");
	ft_printf("%-15u", 4294967295);
	printf("\n");
	printf("%-15u", 4294967295);
	printf("\n------------------------------\n");
	ft_printf("%015u", 4294967295);
	printf("\n");
	printf("%015u", 4294967295);
	// printf("\n------------------------------\n");
	// ft_printf("%ju", 4999999999);
	// printf("\n");
	// printf("%ju", 4999999999);
	// printf("\n------------------------------\n");
	// ft_printf("%ju", 4294967296);
	// printf("\n");
	// printf("%ju", 4294967296);
	// printf("\n------------------------------\n");
	ft_printf("@moulitest: %.5u", 42);
	printf("\n");
	printf("@moulitest: %.5u", 42);
	printf("\n------------------------------\n");

	//number
	// ft_printf(av[1], atoll(av[2]));
	// printf("|\n");
	// printf(av[1], atoll(av[2]));
	// printf("|\n");

	//char
	// ft_printf(av[1], av[2][0]);
	// printf("|\n");
	// printf(av[1], av[2][0]);
	// printf("|\n");

	//string
	// ft_printf(av[1], av[2]);
	// printf("|\n");
	// printf(av[1], av[2]);
	// printf("|\n");

	//none        WARNING functions are inversed
	// printf(av[1]);
	// printf("|\n");
	// ft_printf(av[1]);
	// printf("|\n");

	return (0);
}

/*option &= ~SPACE enleve
  option |= SPACE ajoute
  option & SPACE test*/
