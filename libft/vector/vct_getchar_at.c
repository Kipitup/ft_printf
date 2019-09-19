/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_get_char_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:11:18 by amartino          #+#    #+#             */
/*   Updated: 2019/09/19 14:14:22 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char	vct_getchar_at(t_vector *vector, size_t index)
{
	char c;

	c = 0;
	if (vector != NULL && vector->str != NULL)
		c = vector->str[index];
	return (c);
}
