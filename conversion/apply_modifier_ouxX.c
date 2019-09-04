/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifier_ouxX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:00:08 by fkante            #+#    #+#             */
/*   Updated: 2019/09/03 20:03:19 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	apply_modifier_oxX(int64_t nbr_conv, uint64_t flag)
{
		if (flag & FLAG_HH)
			nbr_conv = (uint8_t)nbr_conv;
		if (flag & FLAG_H)
			nbr_conv = (uint16_t)nbr_conv;
		if (flag & FLAG_L)
			nbr_conv = (uint32_t)nbr_conv;
		if (flag & FLAG_LL)
			nbr_conv = (uint64_t)nbr_conv;
	return(nbr_conv);
}
