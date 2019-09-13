/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_add_char_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:43:28 by amartino          #+#    #+#             */
/*   Updated: 2019/09/12 17:11:53 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char at a given index of the vector string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t			vct_add_char_at(t_vector *vector, char c, size_t index)
{
	if (vector != NULL && vector->str != NULL)
	{
		if (vector->len + 1 >= vector->size)
			if (vct_increase_scale(vector, 0) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			if (index > vector->len)
				vct_add_char(vector, c);
			else
			{
				ft_memmove(vector->str + index + 1, vector->str + index,
					vector->len - index);
				vector->str[index] = c;
				vector->len++;
				vector->str[vector->len] = '\0';
			}
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
