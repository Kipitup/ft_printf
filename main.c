/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 11:48:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

int		main(int ac, char **av)
{
	int		ret1;
	int		ret2;

	(void)ac;
	ret1 = ft_printf("|%#04hX|\n", (unsigned short)0);
	ret2 = printf("|%#04hX|\n", (unsigned short)0);
	printf("ret ft_printf: %d, ret printf: %d\n", ret1, ret2);
	return (0);
}
