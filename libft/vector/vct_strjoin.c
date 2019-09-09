/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:17:56 by amartino          #+#    #+#             */
/*   Updated: 2019/09/05 16:17:01 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char to the end of the vector string.
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t	vct_strjoin(t_vector *vector, char *str)
{
	size_t len;

	if (vector != NULL && vector->str != NULL && str != NULL)
	{
		len = ft_strlen(str);
		if (len + vector->len >= vector->size)
		{
			if (vct_increase_scale(vector, len + DEFAULT_VCT_SCALE) == FAILURE)
				vct_del(&vector);
		}
		if (vector != NULL)
		{
			ft_memcpy(vector->str + vector->len, str, len);
			vector->len += len;
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
