/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_add_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:34:15 by amartino          #+#    #+#             */
/*   Updated: 2019/08/29 19:23:30 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* ***************************************************************************
	Add a char to the end of the string
**************************************************************************** */

int8_t			vct_add_char(t_vector *vector, char c)
{
	if (vector->len + 1 >= vector->size)
		if (vct_increase_scale(vector) == FAILURE)
			return (FAILURE);
	vector->str[vector->len] = c;
	vector->str[vector->len + 1] = '\0';
	vector->len += 1;
	return (SUCCESS);
}
