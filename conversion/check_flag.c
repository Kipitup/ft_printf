/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:22:33 by fkante            #+#    #+#             */
/*   Updated: 2019/08/29 18:54:08 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf"

void	cancel_flag()
{

}

void	check_flag_on(uint64_t option)
{
	if (option & FLAG_HH)
		flag hh is on
	if (option & FLAG_LL)
		flag ll is on
	if (option & FLAG_H)
		flag h is on
	if (option & FLAG_L)
		flag l is on
	if (option & FLAG_L_MAJ)
		flag L is on
	if (option & FLAG_PLUS)
		flag + is on
	if (option & FLAG_MINUS)
		flag - is on
	if (option & FLAG_HASH)
		flag # is on
	if (option & FLAG_ZERO)
		flag 0 is on
	if (option & FLAG_SPACE)
		flag ' '  is on
	if (option & FLAG_POINT)
		flag '.' is on
}

