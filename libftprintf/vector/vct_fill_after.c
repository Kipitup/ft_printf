/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_fill_after.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:11:00 by fkante            #+#    #+#             */
/*   Updated: 2019/09/06 09:42:53 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_fill_after(t_vector *vector, char c, size_t size)
{
	if (size < 0)
		size = 0;
	if (vector != NULL && vector->str != NULL)
	{
		if (vector->len + 1 >= vector->size)
			if (vct_increase_scale(vector, size) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			while (size > 0)
			{
				vector->str[vector->len++] = c;
				size--;
			}
			vector->str[vector->len] = '\0';
		}
	}
	return (vector);
}
