/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 15:19:55 by fkante            #+#    #+#             */
/*   Updated: 2019/10/03 11:26:48 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

int		main(int ac, char **av)
{
	(void)ac;
	ft_printf("%f\n", 3513515616516516515616516515.75);
	return (0);
}
