/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/10 17:07:19 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;

	// ft_printf("%x", 4294967296);
	// printf("\n");
	// printf("%x", 4294967296);
	// printf("\n------------------------------------\n");
	// ft_printf("%X", 4294967296);
	// printf("\n");
	// printf("%X", 4294967296);
	// printf("\n------------------------------------\n");
	// ft_printf("%lx", 4294967296);
	// printf("\n");
	// printf("%lx", 4294967296);
	// printf("\n------------------------------------\n");
	// ft_printf("%llX", 4294967296);
	// printf("\n");
	// printf("%llX", 4294967296);
	// printf("\n------------------------------------\n");
	// ft_printf("%llx", 9223372036854775807);
	// printf("\n");
	// printf("%llx", 9223372036854775807);
	// printf("\n------------------------------------\n");
	// ft_printf("%llx", 9223372036854775808);
	// printf("\n");
	// printf("%llx", 9223372036854775808);
	// printf("\n------------------------------------\n");
	// ft_printf("%#llx", 9223372036854775807);
	// printf("\n");
	// printf("%#llx", 9223372036854775807);
	// printf("\n------------------------------------\n");
	ft_printf("%#08x", 42);
	printf("\n");
	printf("%#08x", 42);
	printf("\n------------------------------------\n");
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	printf("\n");
	printf("@moulitest: %#.x %#.0x", 0, 0);
	printf("\n------------------------------------\n");
	ft_printf("@moulitest: %.x %.0x", 0, 0);
	printf("\n");
	printf("@moulitest: %.x %.0x", 0, 0);
	printf("\n------------------------------------\n");
	ft_printf("@moulitest: %5.x %5.0x", 0, 0);
	printf("\n");
	printf("@moulitest: %5.x %5.0x", 0, 0);
	printf("\n------------------------------------\n");
	// ft_printf("@moulitest: %.o %.0o", 0, 0);
	// printf("\n");
	// printf("@moulitest: %.o %.0o", 0, 0);
	// printf("\n------------------------------------\n");
	// ft_printf("@moulitest: %5.o %5.0o", 0, 0);
	// printf("\n");
	// printf("@moulitest: %5.o %5.0o", 0, 0);
	// printf("\n------------------------------------\n");
	// ft_printf("@moulitest: %#.o %#.0o", 0, 0);
	// printf("\n");
	// printf("@moulitest: %#.o %#.0o", 0, 0);
	// printf("\n------------------------------------\n");
	// ft_printf("%lld", -9223372036854775808);
	// printf("\n");
	// printf("%lld", -9223372036854775808);
	// printf("\n------------------------------------\n");
	// ft_printf("@moulitest: %.d %.0d", 0, 0);
	// printf("\n");
	// printf("@moulitest: %.d %.0d", 0, 0);
	// printf("\n------------------------------------\n");
	// ft_printf("@moulitest: %5.d %5.0d", 0, 0);
	// printf("\n");
	// printf("@moulitest: %5.d %5.0d", 0, 0);
	// printf("\n------------------------------------\n");
	// ft_printf("%15u", 4294967295);
	// printf("\n");
	// printf("%15u", 4294967295);
	// printf("\n------------------------------------\n");
	// ft_printf("%-15u", 4294967295);
	// printf("\n");
	// printf("%-15u", 4294967295);
	// printf("\n------------------------------------\n");
	// ft_printf("%015u", 4294967295);
	// printf("\n");
	// printf("%015u", 4294967295);
	// printf("\n------------------------------------\n");
	// ft_printf("%U", 4294967295);
	// printf("\n");
	// printf("%U", 4294967295);
	// printf("\n------------------------------------\n");
	// ft_printf("%hU", 4294967296);
	// printf("\n");
	// printf("%hU", 4294967296);
	// printf("\n------------------------------------\n");
	// ft_printf("%U", 4294967296);
	// printf("\n");
	// printf("%U", 4294967296);
	// printf("\n------------------------------------\n");
	// ft_printf("@moulitest: %.5u", 42);
	// printf("\n");
	// printf("@moulitest: %.5u", 42);
	// printf("\n------------------------------------\n");

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
