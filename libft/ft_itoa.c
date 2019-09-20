/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:24:25 by fkante            #+#    #+#             */
/*   Updated: 2019/09/20 10:57:57 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_u_itoa(uint64_t value)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;
	uint8_t		base;

	base = 10;
	base_str = "0123456789";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (nb)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}

char	*ft_itoa(int64_t value)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;
	uint8_t		base;

	base = 10;
	base_str = "0123456789";
	ptr = NULL;
	nb = value;
	len = ft_int64_t_len(nb, base);
	nb = ft_absolute(nb);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (nb)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value < 0 && base == 10)
			ptr[0] = '-';
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}
