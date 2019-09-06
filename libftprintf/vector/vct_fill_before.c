/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_fill_before.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:29:07 by fkante            #+#    #+#             */
/*   Updated: 2019/09/06 12:02:12 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int8_t		vct_fill_before(t_vector *vector, char c, size_t size)
{
	size_t	start;

	start = 0;
	if (vector != NULL && vector->str != NULL)
	{
		if (vector->len + size >= vector->size)
			if (vct_increase_scale(vector, size) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			while (size > 0)
			{
				if ((vct_add_char_at(vector, c, start)) == FAILURE)
				{
					vct_del(&vector);
					break ;
				}
				size--;
			}
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
