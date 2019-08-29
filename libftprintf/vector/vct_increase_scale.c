/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_increase_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:44:22 by amartino          #+#    #+#             */
/*   Updated: 2019/08/29 19:26:18 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* ***************************************************************************
	Increase the size of allocated bloc by a certain scale.

	The size et the scale are both define in vector.h
**************************************************************************** */

int8_t			vct_increase_scale(t_vector *vector)
{
	char	*old;

	old = vector->str;
	vector->size += vector->scale;
	vector->str = ft_memalloc(vector->size);
	if (vector->str == NULL)
		return (FAILURE);
	ft_memcpy(vector->str, old, vector->len);
	ft_strdel(&old);
	return (SUCCESS);
}
