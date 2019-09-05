/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int64_t_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:09:52 by amartino          #+#    #+#             */
/*   Updated: 2019/09/05 11:13:36 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_int64_t_len(int64_t num, uint8_t base)
{
	size_t		size;

	if (num == 0)
		return (1);
	size = 1;
	if (num < 0 && base == 10)
		size++;
	num = ft_absolute(num);
	while (num > base)
	{
		num /= base;
		size++;
	}
	return (size);
}
