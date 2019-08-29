/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:25:09 by amartino          #+#    #+#             */
/*   Updated: 2019/08/29 15:59:33 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define DEFAULT_VECTOR_SIZE 64
# define DEFAULT_VECTOR_SCALE 16

/* ***************************************************************************
	size  is the total lenght of str (including the '\0')
	len	  is the number of characters of the string
	scale is the number by which the string will be increase for each memory
	      allocation
**************************************************************************** */

typedef struct 	s_vector
{
	char		*str;
	size_t		size;
	size_t		len;
	size_t		scale;
}				t_vector;

void			vct_del(t_vector **vector);
t_vector		*vct_new(size_t size);
ssize_t			vct_add(t_vector *vector, char c);
ssize_t			vct_remove(t_vector *vector, size_t len);
ssize_t			vct_concat(t_vector *vector, char *str);
ssize_t			vct_insert_char_index(t_vector *vector, char c, size_t index);
ssize_t			vct_reset(t_vector *vector);
ssize_t			vct_increase_scale(t_vector *vector, size_t scale);


#endif
