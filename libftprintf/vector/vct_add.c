/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:17:56 by amartino          #+#    #+#             */
/*   Updated: 2019/08/27 18:09:09 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* ***************************************************************************
	Add a char to the end of the vector string.

	As for all vectors functions, if the LENGHT of the new string is bigger
	than the string SIZE, an equivalent reallocation occurs.
**************************************************************************** */

ssize_t			vct_add(t_vector *vector, char c)
{
	if (vector->len + 1 >= vector->size)
		if (vct_increase_scale(vector, size_t scale))
	return (0);
}
