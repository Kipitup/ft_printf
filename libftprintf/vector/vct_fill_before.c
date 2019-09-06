/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_fill_before.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:29:07 by fkante            #+#    #+#             */
/*   Updated: 2019/09/06 09:57:16 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vct_fill_before(t_vector *vector, char c, size_t size)
{
	size_t	start;

	start = 0;
	if (vector != NULL && vector->str != NULL)
	{
		if (vector->len + 1 >= vector->size)
			if (vct_increase_scale(vector, size) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			while (size > 0)
			{
				vct_add_char_at(vector, c, start);
				size--;
			}
		}
	}
	return (vector);
}
