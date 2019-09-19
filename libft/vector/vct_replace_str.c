/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_replace_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:58:09 by amartino          #+#    #+#             */
/*   Updated: 2019/09/18 19:36:22 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/*
**	Search the vector to find if a given 'str' string exist in the vector. If yes
**	it wll replace it with the given 'replace' string
**
**	As for all vectors functions, if the LENGHT of the new string is bigger
**	than the string SIZE, an equivalent reallocation occurs.
*/

int8_t			replace_func(t_vector *vector, char *str, char *replace,
								size_t len_str, size_t len_replace)
{
	size_t		index;
	ssize_t		tmp;
	int8_t		state;

	index = 0;
	state = FALSE;
	while (index < vector->len)
	{
		tmp = vct_chr_str(vector + index, str);
		if (tmp >= 0)
		{
			index = (size_t)tmp;
			state = vct_add_str_at(vector, replace, index);
			if (state == SUCCESS)
			{
				vct_pop_from(vector, len_str, index + len_replace);
				index += len_replace;
				state = TRUE;
			}
		}
		else
			break ;
	}
	return (state);
}

int8_t			vct_replace_str(t_vector *vector, char *str, char *replace)
{
	size_t		len_str;
	size_t		len_replace;
	int8_t		state;

	len_str = ft_strlen(str);
	len_replace = ft_strlen(replace);
	state = FAILURE;
	if (vector != NULL && vector->str != NULL && str != NULL && replace != NULL)
		state = replace_func(vector, str, replace, len_str, len_replace);
	return (state);
}
