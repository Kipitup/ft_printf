/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:06:10 by fkante            #+#    #+#             */
/*   Updated: 2019/09/05 16:20:11 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include <stdio.h>

char	*ft_u_itoa_base(uint64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	base_str = "0123456789abcdef";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (len > 0)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}

char	*ft_itoa_base(int64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	int64_t		nb;
	size_t		len;

	base_str = "0123456789abcdef";
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
		if (value == LLONG_MIN)
			ptr = "-9223372036854775808";
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}

char	*ft_itoa_base_maj(uint64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	base_str = "0123456789ABCDEF";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if (len > 8)
		len = 8;
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (len > 0)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}

char	*ft_ox_itoa_base(uint64_t value, uint8_t base, uint64_t flag)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	base_str = "0123456789abcdef";
	ptr = NULL;
	nb = value;
	len = ft_uint64_t_len(nb, base);
	if (len > 8 && flag & CONV_X)
		len = 8;
	if (len > 11 && flag & CONV_O)
		len = 11;
	if ((ptr = (char*)ft_memalloc(len + 1)) != NULL)
	{
		while (len > 0)
		{
			ptr[--len] = base_str[nb % base];
			nb = nb / base;
		}
		if (value == 0)
			ptr[0] = '0';
	}
	return (ptr);
}
