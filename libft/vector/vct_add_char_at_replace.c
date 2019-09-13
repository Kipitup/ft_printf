/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_add_char_at_replace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:28:46 by amartino          #+#    #+#             */
/*   Updated: 2019/09/12 17:12:10 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char at a given index of the string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t			vct_add_char_at_replace(t_vector *vector, char c, size_t index)
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
				vector->str[index] = c;
				vector->len++;
				vector->str[vector->len] = '\0';
			}
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
