/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint64_t_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:09:52 by amartino          #+#    #+#             */
/*   Updated: 2019/09/04 17:27:33 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_uint64_t_len(uint64_t num, uint8_t base)
{
	size_t		size;

	if (num == 0)
		return (1);
	size = 1;
	while (num > 9)
	{
		num /= base;
		size++;
	}
	return (size);
}
