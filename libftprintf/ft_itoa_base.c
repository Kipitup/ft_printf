/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:06:10 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 09:18:42 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_u_itoa_base(uint64_t value, uint8_t base)
{
	const char	*base_str;
	char		*ptr;
	uint64_t	nb;
	size_t		len;

	if (value == 0)
		return (0);
	base_str = "0123456789abcdef";
	len = 0;
	nb = value;
	while (nb)
	{
		nb = nb / base;
		len++;
	}
	nb = value;
	if ((ptr = (char*)malloc(sizeof(char) *len + 1)) == NULL)
		return (NULL);
	ptr[len] = '\0';
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

	if (value == 0)
		return (0);
	base_str = "0123456789abcdef";
	len = 0;
	nb = value;
	while (nb)
	{
		nb = nb / base;
		len++;
	}
	nb = value;
	if (nb < 0)
	{
		if (base == 10)
			len++;
		nb = -nb;
	}
	if ((ptr = (char*)malloc(sizeof(char) *len + 1)) == NULL)
		return (NULL);
	ptr[len] = '\0';
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

	if (value == 0)
		return (0);
	base_str = "0123456789ABCDEF";
	len = 0;
	nb = value;
	while (nb)
	{
		nb = nb / base;
		len++;
	}
	nb = value;
	if (nb < 0)
	{
		if (base == 10)
			len++;
		nb = -nb;
	}
	if ((ptr = (char*)malloc(sizeof(char) *len + 1)) == NULL)
		return (NULL);
	ptr[len] = '\0';
	while (nb)
	{
		ptr[--len] = base_str[nb % base];
		nb = nb / base;
	}
	if (value < 0 && base == 10)
		ptr[0] = '-';
	return (ptr);
}
