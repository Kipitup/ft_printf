/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_pop_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:28:28 by amartino          #+#    #+#             */
/*   Updated: 2019/09/12 13:44:49 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Remove a certain number of characters from the index of the string
*/

void	vct_pop_from(t_vector *vector, size_t len, size_t index)
{
	t_vector	*tmp;
	size_t		i;

	i = 0;
	if (vector != NULL && vector->str != NULL)
	{
		if (index > vector->len)
			vct_pop(vector, 1);
		else
		{
			if (len > vector->len - index)
				len = vector->len - index;
			if ((tmp = vct_dup(vector)) != NULL)
			{
				ft_memset(vector->str + index, '\0', vector->len - index);
				ft_memmove(vector->str + index, tmp->str + index + len,
					tmp->len - index - len);
				vector->len -= len;
				vector->str[vector->len] = '\0';
			}
		}
	}
}
