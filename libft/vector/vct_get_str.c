/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_get_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:06:11 by amartino          #+#    #+#             */
/*   Updated: 2019/09/13 10:47:37 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Return a pointer on the vector string
*/

char	*vct_get_str(t_vector *vector)
{
	char	*str;

	str = NULL;
	if (vector != NULL && vector->str != NULL)
		str = vector->str;
	return (str);
}
