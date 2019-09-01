/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:57:15 by amartino          #+#    #+#             */
/*   Updated: 2019/09/01 15:04:39 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* ***************************************************************************
	Join 2 vector string together.

	As for all vectors functions, if the LENGHT of the new string is bigger
	than the string SIZE, an equivalent reallocation occurs.
**************************************************************************** */

int8_t	vct_join(t_vector *dest, t_vector *src)
{
	while (src->len + dest->len >= dest->size)
	{
		if (vct_increase_scale(dest) == FAILURE)
			return (FAILURE);
	}
	ft_strcpy(dest->str + dest->len, src->str);
	dest->len += src->len;
	return (SUCCESS);
}
