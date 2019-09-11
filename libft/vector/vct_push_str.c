/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_push_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:32:56 by amartino          #+#    #+#             */
/*   Updated: 2019/09/11 11:42:04 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int8_t			vct_push_str(t_vector *vector, char *str)
{
	size_t	len;

	if (vector != NULL && vector->str != NULL)
	{
		len = ft_strlen(str);
		if (vector->len + len >= vector->size)
			if (vct_increase_scale(vector, len) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
		{
			ft_memmove(vector->str + len, vector->str, vector->len);
			ft_memcpy(vector->str, str, len);
			vector->len += len;
			vector->str[vector->len] = '\0';
		}
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}
