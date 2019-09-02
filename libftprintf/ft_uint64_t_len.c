/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint64_t_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:09:52 by amartino          #+#    #+#             */
/*   Updated: 2019/09/02 19:02:22 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint64_t		ft_uint64_t_len(uint64_t num)
{
	uint64_t		size;

	if (num == 0)
		return (1);
	size = 1;
	while (num > 9)
	{
		num /= 10;
		size++;
	}
	return (size);
}
