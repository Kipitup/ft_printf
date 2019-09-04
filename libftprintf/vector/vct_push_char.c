/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_push_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:34:15 by amartino          #+#    #+#             */
/*   Updated: 2019/09/04 17:21:22 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char to the end of the string
*/

int8_t			vct_add_char(t_vector *vector, char c)
{
	if (vector != NULL && vector->str != NULL)
	{
		if (vector->len + 1 >= vector->size)
			if (vct_increase_scale(vector, 0) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			vector->str[vector->len] = c;
			vector->str[vector->len + 1] = '\0';
			vector->len += 1;
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
