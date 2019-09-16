/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/16 20:42:21 by amartinod        ###   ########.fr       */
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
	// ft_printf("%ju", 4999999999);
	// printf("\n");
	// printf("%ju", 4999999999);
	// printf("\n------------------------------\n");
	// ft_printf("%ju", 4294967296);
	// printf("\n");
	// printf("%ju", 4294967296);
	// printf("\n------------------------------\n");
	// ft_printf("%U", 4294967295);
	// printf("\n");
	// printf("%U", 4294967295);
	// printf("\n------------------------------\n");
	// ft_printf("%hU", 4294967296);
	// printf("\n");
	// printf("%hU", 4294967296);
	// printf("\n------------------------------\n");
	// ft_printf("%U", 4294967296);
	// printf("\n");
	// printf("%U", 4294967296);
	// printf("\n------------------------------\n");
	// printf("\n------------------------------\n");

	//number
	// ft_printf(av[1], atoll(av[2]));
	// printf("|\n");
	// printf(av[1], atoll(av[2]));
	// printf("|\n");

	//float
	ft_printf("notre printf :|%15.2f|\n", 3.9999999999);
	printf("   LE printf :|%15.2f|\n", 3.9999999999);
	printf("------------------------------\n");
	// ft_printf("notre printf :%5.4f\n", 0.001);
	// printf("   LE printf :%5.4f\n", 0.001);
	// printf("------------------------------\n");
	// ft_printf("notre printf :%f\n", -42.123456789);
	// printf("   LE printf :%f\n", -42.123456789);
	// printf("------------------------------\n");
	// ft_printf("notre printf :%f\n", 0.000005000);
	// printf("   LE printf :%f\n", 0.000005000);
	// printf("------------------------------\n");
	// ft_printf("notre printf :%f\n", 5.0123456789112345678921234567893123456798);
	// printf("   LE printf :%f\n", 5.0123456789112345678921234567893123456798);
	// printf("------------------------------\n");
	// ft_printf("notre printf :%.15f\n", 3.1415926535);
	// printf("   LE printf :%.15f\n", 3.1415926535);
	// printf("------------------------------\n");
	// ft_printf("notre printf :%.f\n", 0);
	// printf("   LE printf :%.f\n", 0);
	// printf("------------------------------\n");
	// ft_printf("notre printf :%.f\n", 3.14);
	// printf("   LE printf :%.f\n", 3.14);
	// printf("------------------------------\n");
	// ft_printf("notre printf :%.8f\n", 3.0000139);
	// printf("   LE printf :%.8f\n", 3.0000139);
	// printf("------------------------------\n");

	// ft_printf("notre printf :%.2s\n", NULL);
	// printf("   LE printf :%.2s\n", NULL);
	// printf("------------------------------\n");
	//
	// ft_printf("notre printf :%.2s\n", "salut");
	// printf("   LE printf :%.2s\n", "salut");
	// printf("------------------------------\n");
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
