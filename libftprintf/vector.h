/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:25:09 by amartino          #+#    #+#             */
/*   Updated: 2019/08/29 19:04:44 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define FALSE		0
# define TRUE		1
# define FAILURE	-1
# define SUCCESS	0
# define ON			1
# define OFF		0

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
int8_t			vct_strjoin(t_vector *vector, char *str);
void			vct_remove_from_end(t_vector *vector, size_t len);
int8_t			vct_add_char(t_vector *vector, char c);
void			vct_bzero(t_vector *vector);
int8_t			vct_increase_scale(t_vector *vector);


#endif
