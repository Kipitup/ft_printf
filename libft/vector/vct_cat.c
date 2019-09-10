/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_cat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:57:15 by amartino          #+#    #+#             */
/*   Updated: 2019/09/03 17:23:36 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Concat 2 vector string.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t	vct_cat(t_vector *dest, t_vector *src)
{
	if (dest != NULL && dest->str != NULL
		&& src != NULL && src->str != NULL)
	{
		if (src->len + dest->len + 1 >= dest->size)
		{
			if (vct_increase_scale(dest, src->size) == FAILURE)
				vct_del(&dest);
		}
		if (dest != NULL)
		{
			ft_memmove(dest->str + dest->len, src->str, src->len);
			dest->len += src->len;
			dest->str[dest->len] = '\0';
		}
	}
	return (dest == NULL ? FAILURE : SUCCESS);
}
