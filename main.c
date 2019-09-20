/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 09:44:44 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

int		main(int ac, char **av)
{
	(void)ac;


	char *exemple;
	char *monexemple;
	// t_vector *vector;
	//
	// vector = vct_newstr(" saltu sdkcfls dl dl dskjd \033[0m \
	// 					kdf kdf");

	// ft_dprintf(1, "salut \n");
	// dprintf(1, "salut \n");

	// asprintf(&exemple, "salut mon gars\n");
	// ft_asprintf(&monexemple, "salut mon gars\n");

	// printf("|%s|\033[0m\n", vector->str);
	// ft_printf("|{{c_cyan}salut|%r|{c_eoc}} fin\n", "bon\10");
	ft_printf("base: %d\tnbr: %d\n--- %b ---\n", atol(av[1]), atol(av[2]), atol(av[1]), atol(av[2]));




	//number
	// ft_printf(av[1], atoll(av[2]));
	// printf("|\n");
	// printf(av[1], atoll(av[2]));
	// printf("|\n");
//	ft_printf("notre printf : |%jd|\n", 123456789123);
//	printf("   LE printf : |%jd|\n",  123456789123);
//	printf("------------------------------\n");
/*

	//wild WILDCARD_SIGN
	ft_printf("notre printf : |%d|\n", 42);
	printf("   LE printf : |%d|\n", 42);
	printf("------------------------------\n");
	// ft_printf("notre printf : |%8.*d|\n", 5, 42);
	// printf("   LE printf : |%8.*d|\n", 5, 42);
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%*d|\n", -5, -42);
	// printf("   LE printf : |%*d|\n", -5, -42);
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%.*d|\n", -5, 42);
	// printf("   LE printf : |%.*d|\n", -5, 42);
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%.*s|\n", -5, "42");
	// printf("   LE printf : |%.*s|\n", -5, "42");
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%.*s|\n", 0, "42");
	// printf("   LE printf : |%.*s|\n", 0, "42");
	// printf("------------------------------\n");
*/
	//
	// ft_printf("notre printf : |%###-#0000 33...12..#0+0d|\n", 256);
	// printf("   LE printf : |%###-#0000 33...12..#0+0d|\n", 256);
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%.12.2.8.d|\n", 256);
	// printf("   LE printf : |%.12.2.8.d|\n", 256);
	// printf("------------------------------\n");

	// octal
	// ft_printf("notre printf :|%#o|\n", 0);
	// printf("   LE printf :|%#o|\n", 0);
	// printf("------------------------------\n");
	// ft_printf("notre printf :|%#.o|\n", 0);
	// printf("   LE printf :|%#.o|\n", 0);
	// printf("------------------------------\n");
	// ft_printf("notre printf :|%#0o|\n", 0);
	// printf("   LE printf :|%#0o|\n", 0);
	// printf("------------------------------\n");
	// ft_printf("notre printf :|%#o|\n", 1);
	// printf("   LE printf :|%#o|\n", 1);
	// printf("------------------------------\n");
	// ft_printf("notre printf :|%o|\n", 1);
	// printf("   LE printf :|%o|\n", 1);
	// printf("------------------------------\n");
	// ft_printf("notre printf :|%#.3o|\n", 1);
	// printf("   LE printf :|%#.3o|\n", 1);
	// printf("------------------------------\n");
	// ft_printf("notre printf :|%#.2o|\n", 1);
	// printf("   LE printf :|%#.2o|\n", 1);
	// printf("------------------------------\n");

	//
	// // hexa
	// ft_printf("notre printf :|%#.2x|\n", 1);
	// printf("   LE printf :|%#.2x|\n", 1);
	// printf("------------------------------\n");
	//
	// pointeur
	// ft_printf("notre printf : |%p|\n", NULL);
	// printf("   LE printf : |%p|\n", NULL);
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%5p|\n", NULL);
	// printf("   LE printf : |%5p|\n", NULL);
	// printf("------------------------------\n");

	// char
	// ft_printf("\033[31m notre printf \033[0m: |%.c|\n", 0);
	// printf("\033[31m   LE printf \033[0m: |%.c|\n", 0);
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%.c|\n", 'a');
	// printf("   LE printf : |%.c|\n", 'a');
	// printf("------------------------------\n");
	// ft_printf("notre printf : |%.5c|\n", 0);
	// printf("   LE printf : |%.5c|\n", 0);
	// printf("------------------------------\n");

	// float
	// ft_printf("|%f|\n|%lf|\n|%Lf|\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	// printf("\n------------------------------\n");
	// printf("|%f|\n|%lf|\n|%Lf|\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
//	ft_printf("|%f|\n|%lf|\n|%Lf|\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
//	printf("\n------------------------------\n");
//	printf("|%f|\n|%lf|\n|%Lf|\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
/*	printf("------------------------------\n");
//	ft_printf("notre printf :|%15.2Lf|\n",123456789123.9999999999L);
//	printf("   LE printf :|%15.2Lf|\n", 123456789123.9999999999L);
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
*/
	// string
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

	// none        WARNING functions are inversed
	// printf(av[1]);
	// printf("|\n");
	// ft_printf(av[1]);
	// printf("|\n");


	return (0);
}

/*option &= ~SPACE enleve
  option |= SPACE ajoute
  option & SPACE test*/
