/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:17:56 by amartino          #+#    #+#             */
/*   Updated: 2019/08/29 18:38:55 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* ***************************************************************************
	Add a char to the end of the vector string.

	As for all vectors functions, if the LENGHT of the new string is bigger
	than the string SIZE, an equivalent reallocation occurs.
**************************************************************************** */


int8_t	vct_strjoin(t_vector *vector, char *str)
{
	size_t len;

	len = ft_strlen(str);
	while (len + vector->len >= vector->size)
	{
		if (vct_increase_scale(vector) == FAILURE)
			return (FAILURE);
	}
	ft_strcat(vector->str, str);
	vector->len += len;
	return (SUCCESS);
}
