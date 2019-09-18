/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/18 11:16:33 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;

	//number
	// ft_printf(av[1], atoll(av[2]));
	// printf("|\n");
	// printf(av[1], atoll(av[2]));
	// printf("|\n");

	//float
	ft_printf("notre printf :|%15.2f|\n", 3.9999999999);
	printf("   LE printf :|%15.2f|\n", 3.9999999999);
	printf("------------------------------\n");
	ft_printf("notre printf :|%15.1f|\n", 2.25);
	printf("   LE printf :|%15.1f|\n", 2.25);
	printf("------------------------------\n");
	ft_printf("notre printf :%5.4f\n", 0.001);
	printf("   LE printf :%5.4f\n", 0.001);
	printf("------------------------------\n");
	ft_printf("notre printf : |%f|\n", -42.123456789);
	printf("   LE printf : |%f|\n", -42.123456789);
	printf("------------------------------\n");
	ft_printf("notre printf :%f\n", 0.000005000);
	printf("   LE printf :%f\n", 0.000005000);
	printf("------------------------------\n");
	ft_printf("notre printf :%f\n", 5.0123456789112345678921234567893123456798);
	printf("   LE printf :%f\n", 5.0123456789112345678921234567893123456798);
	printf("------------------------------\n");
	ft_printf("notre printf :%.15f\n", 3.1415926535);
	printf("   LE printf :%.15f\n", 3.1415926535);
	printf("------------------------------\n");
	ft_printf("notre printf :%.f\n", (float)0);
	printf("   LE printf :%.f\n", (float)0);
	printf("------------------------------\n");
	ft_printf("notre printf :%.f\n", 42);
	printf("   LE printf :%.f\n", 42);
	printf("------------------------------\n");
	ft_printf("notre printf :%.f\n", 3.14);
	printf("   LE printf :%.f\n", 3.14);
	printf("------------------------------\n");
	ft_printf("notre printf : |%.4f|\n", 3.139);
	printf("   LE printf : |%.4f|\n", 3.139);
	printf("------------------------------\n");
	ft_printf("notre printf :|%15.1f|\n", 2.26);
	printf("   LE printf :|%15.1f|\n", 2.26);
	printf("------------------------------\n");
	ft_printf("notre printf :|%.100f|\n", 45.28);
	printf("   LE printf :|%.100f|\n", 45.28);
	printf("------------------------------\n");
	ft_printf("notre printf :|%.100f|\n", 45.28);
	printf("   LE printf :|%.100f|\n", 45.28);
	printf("------------------------------\n");
	ft_printf("notre printf :|%.100f|\n", 4445.28);
	printf("   LE printf :|%.100f|\n", 4445.28);
	printf("------------------------------\n");
	ft_printf("notre printf :|%.100f|\n", 1.000000000000000000121);
	printf("   LE printf :|%.100f|\n", 1.000000000000000000121);
	printf("------------------------------\n");

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
	// ft_printf("notre printf :%.2s\n", NULL);
	// printf("   LE printf :%.2s\n", NULL);
	// printf("------------------------------\n");
	//
	// ft_printf("notre printf :%.2s\n", "salut");
	// printf("   LE printf :%.2s\n", "salut");
	// printf("------------------------------\n");

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
