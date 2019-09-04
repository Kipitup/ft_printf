/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifier_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:33:08 by fkante            #+#    #+#             */
/*   Updated: 2019/09/04 14:31:29 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		apply_modifier_di(int64_t nbr_conv, uint32_t flag)
{
	if (flag & FLAG_HH)
		nbr_conv = (int8_t)nbr_conv;
	if (flag & FLAG_H)
		nbr_conv = (int16_t)nbr_conv;
	if (flag & FLAG_L)
		nbr_conv = (long)nbr_conv;
	if (flag & FLAG_LL)
		nbr_conv = (int64_t)nbr_conv;
	return (nbr_conv);
}

uint64_t	apply_modifier_oxX(int64_t nbr_conv, uint32_t flag)
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

uint64_t	apply_modifier_u(uint64_t nbr_conv, uint32_t flag)
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
