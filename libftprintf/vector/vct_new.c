/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:35:59 by amartino          #+#    #+#             */
/*   Updated: 2019/08/27 18:10:37 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* ***************************************************************************
	Return a new vector.

	The size parameter is the lenght of the string with the '\0'.
**************************************************************************** */

t_vector		*vct_new(size_t size)
{
	t_vector	*new_vector;

	new_vector = NULL;
	if (!(new_vector = (t_vector*)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(new_vector->str = (char*)malloc(sizeof(char) * size)))
	{
		free(new_vector);
		return (NULL);
	}
	new_vector->str[size - 1] = '\0';
	new_vector->size = size;
	new_vector->len = 0;
	new_vector->scale = DEFAULT_VECTOR_SCALE;
	return (new_vector);
}

#define DEFAULT_VCT_SIZE 64 

t_vector		*vct_new(size_t size)
{
	t_vector	*new_vector;

	new_vector = (t_vector *)malloc(sizeof(t_vector));
	if (new_vector == NULL)
		return (NULL);
	new_vector->size = size == 0 ? DEFAULT_VCT_SIZE : size;
	new_vector->len = 0;
	new_vector->scale = DEFAULT_VECTOR_SCALE;
	new_vector->str = ft_memalloc(size);
	if (new_vector->str == NULL)
	{
		free(new_vector);
		new_vector = NULL;
	}
	return (new_vector);
}

int8_t	vct_add_string(t_vector *vct)
{
	char	*old;

	old = vct->str;
	vct->size += vct->scale;
	vct->str = ft_memalloc(vct->size);
	if (vct->str == NULL)
		return (FAILURE);
	ft_strcpy(vct->str, old);
	ft_strdel(old);
	return (SUCCESS);
}

int8_t	vct_add_string(t_vector *vct, char *s)
{
	size_t len;

	len = ft_strlen(s);
	while (len + vct->len >= vct->size)
	{
		if (vct_resize(vct) == FAILURE)
			return (FAILURE);
	}
	ft_strcat(vct->str, s);
	return (SUCCESS);
}
