/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifier_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:33:08 by fkante            #+#    #+#             */
/*   Updated: 2019/09/04 17:44:47 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		apply_modifier_di(int64_t nbr_conv, uint64_t flag)
{
	if (flag & FLAG_HH)
		nbr_conv = (int8_t)nbr_conv;
	else if (flag & FLAG_H)
		nbr_conv = (int16_t)nbr_conv;
	else if (flag & FLAG_L)
		nbr_conv = (long)nbr_conv;
	else if (flag & FLAG_LL)
		nbr_conv = (int64_t)nbr_conv;
	else
	{
		nbr_conv = (int32_t)nbr_conv;
		if (nbr_conv == LLONG_MAX)
			nbr_conv = -1;
	}
	return (nbr_conv);
}

uint64_t	apply_modifier_oxX(int64_t nbr_conv, uint64_t flag)
{
	if (flag & FLAG_HH)
		nbr_conv = (uint8_t)nbr_conv;
	if (flag & FLAG_H)
		nbr_conv = (uint16_t)nbr_conv;
	if (flag & FLAG_L)
		nbr_conv = (unsigned long)nbr_conv;
	if (flag & FLAG_LL)
		nbr_conv = (uint64_t)nbr_conv;
	return (nbr_conv);
}

uint64_t	apply_modifier_u(uint64_t nbr_conv, uint64_t flag)
{
	if (flag & FLAG_HH)
		nbr_conv = (uint8_t)nbr_conv;
	if (flag & FLAG_H)
		nbr_conv = (uint16_t)nbr_conv;
	if (flag & FLAG_L)
		nbr_conv = (unsigned long)nbr_conv;
	if (flag & FLAG_LL)
		nbr_conv = (uint64_t)nbr_conv;
	return (nbr_conv);
}

uint64_t	apply_modifier_p(uint64_t address, uint64_t flag)
{
	if (flag & FLAG_HH)
		address = (uint64_t)address; 
	if (flag & FLAG_H)
		address = (uint64_t)address; 
	if (flag & FLAG_L)
		address = (unsigned long)address;
	if (flag & FLAG_LL)
		address = (uint64_t)address;
	return (address);
}

uint64_t	apply_modifier_s(uint64_t str, uint64_t flag)
{
	if (flag & FLAG_HH)
		str = (uint64_t)str;
	if (flag & FLAG_H)
		str = (uint64_t)str;
	if (flag & FLAG_L)
		str = 0;
	if (flag & FLAG_LL)
		str = (uint64_t)str;
	return (str);
}
