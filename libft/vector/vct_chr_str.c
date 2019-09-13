/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_chr_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:23:12 by amartino          #+#    #+#             */
/*   Updated: 2019/09/13 13:27:38 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char	*vct_chr_str(t_vector *vector, char *find)
{
	size_t		index;
	size_t		j;

	index = 0;
	while (index <= vector->len)
	{
		j = 0;
		if (vector->str[index] == find[j])
		{
			while (find[j] != '\0')
			{
				if (vector->str[index] != find[j])
					break ;
				index++;
				j++;
			}
			if (find[j] == '\0')
				return (vector->str + index - j);
		}
		index++;
	}
	return (NULL);
}
