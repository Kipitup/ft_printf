/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_add_char_at_replace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:28:46 by amartino          #+#    #+#             */
/*   Updated: 2019/09/16 15:17:16 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Add a char at a given index of the string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

void			vct_add_char_at_replace(t_vector *vector, char c, size_t index)
{
	if (vector != NULL && vector->str != NULL && index < vector->len)
		vector->str[index] = c;
}
