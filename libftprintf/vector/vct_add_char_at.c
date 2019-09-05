/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_add_char_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:43:28 by amartino          #+#    #+#             */
/*   Updated: 2019/09/05 14:43:49 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char at a given index of the string
*/

int8_t			vct_add_char_at(t_vector *vector, char c, size_t index)
{
	t_vector	*tmp;

	if (vector != NULL && vector->str != NULL)
	{
		if (vector->len + 1 >= vector->size)
			if (vct_increase_scale(vector, 0) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			if (index > vector->len)
				vct_push_char(vector, c);
			else
			{
				if ((tmp = vct_dup(vector)) != NULL)
				{
					vector->str[index] = c;
					ft_memmove(vector->str + index + 1, tmp->str + index,
						tmp->len - index);
					vector->len++;
					vector->str[vector->len] = '\0';
				}
			}
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
