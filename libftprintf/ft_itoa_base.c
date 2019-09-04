/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:06:10 by fkante            #+#    #+#             */
/*   Updated: 2019/09/04 17:45:55 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_u_itoa_base(uint64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	base_str = "0123456789abcdef";
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if ((ptr = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	while (nb)
	{
		ptr[--len] = base_str[nb % base];
		nb = nb / base;
	}
	return (ptr);
}

char	*ft_itoa_base(int64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	int64_t		nb;
	size_t		len;

	printf("value before itoa: %lld\n", value);
	base_str = "0123456789abcdef";
	nb = value;
	len = ft_int64_t_len(nb, base);
	nb = ft_absolute(nb);
	if ((ptr = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	while (nb)
	{
		ptr[--len] = base_str[nb % base];
		nb = nb / base;
	}
	if (value < 0 && base == 10)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa_base_maj(int64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	int64_t		nb;
	size_t		len;

	base_str = "0123456789ABCDEF";
	nb = value;
	len = ft_int64_t_len(nb, base);
	nb = ft_absolute(nb);
	if ((ptr = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	while (nb)
	{
		ptr[--len] = base_str[nb % base];
		nb = nb / base;
	}
	if (value < 0 && base == 10)
		ptr[0] = '-';
	return (ptr);
}
