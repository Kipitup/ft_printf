/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:42:35 by amartino          #+#    #+#             */
/*   Updated: 2019/09/17 18:25:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"
#include <stdio.h>

int8_t		round_up(t_vector *vector, uint64_t accuracy)
{
	char c;

	c = vct_get_char_at(vector, accuracy);
	if (c % 2 == 0)
		vct_add_char_at_replace(vector, c, accuracy);
	if (c % 2 == 1)
		vct_add_char_at_replace(vector, c + 1, accuracy);
	if (c == '9' || c == '.')
	{
		if ((round_up(vector, accuracy - 1)) == SUCCESS)
		{
			if (c == '.')
				return (SUCCESS);
			else
				vct_add_char_at_replace(vector, '0', accuracy);
		}
	}
	return (SUCCESS);
}

int8_t		nb_to_string(t_vector *vector, double value, int64_t cast,
	uint64_t accuracy)
{
	const char	*base_str;
	uint64_t	i;

	base_str = "0123456789";
	i = accuracy;
	while (i > 0 && vector != NULL)
	{
		value *= 10;
		cast = (int64_t)value;
		value -= (double)cast;
		if ((vct_add_char(vector, base_str[cast % 10])) == FAILURE)
			vct_del(&vector);
		i--;
	}
	cast = (int64_t)(value * 10);
	accuracy = (uint64_t)vct_len(vector) - 1;
	if (cast > 4)
		if ((round_up(vector, accuracy)) == FAILURE)
			vct_del(&vector);
	return (vector == NULL ? FAILURE : SUCCESS);
}

t_vector	*ft_ftoa(double value, uint64_t precision, uint32_t option)
{
	t_vector	*vector;
	char		*str;
	int64_t		cast;
	uint64_t	accuracy;

	vector = vct_new(0);
	if (vector != NULL)
	{
		cast = (int64_t)value;
		value -= (double)cast;
		if ((str = ft_itoa(cast)) != NULL)
			if ((vct_strjoin(vector, str)) == FAILURE)
				vct_del(&vector);
		ft_strdel(&str);
		value = value < 0 ? -value : value;
		accuracy = (option & FLAG_POINT) ? precision : 6;
		if (accuracy > 0)
			if ((vct_add_char(vector, '.')) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
			if ((nb_to_string(vector, value, cast, accuracy)) == FAILURE)
				vct_del(&vector);
	}
	return (vector);
}

// int8_t	handle_decimal(double value, int64_t cast, t_vector *vector,
// 	uint64_t accuracy)
// {
// 	if (accuracy > 0)
// 		if ((vct_add_char(vector, '.')) == FAILURE)
// 			vct_del(&vector);
// 	if (vector != NULL)
// 		if ((nb_to_string(vector, value, cast, accuracy)) == FAILURE)
// 			vct_del(&vector);
// 	return (vector == NULL ? FAILURE : SUCCESS);
// }
//
// char	*ft_ftoa(double value, uint64_t precision, uint32_t option)
// {
// 	t_vector	*vector;
// 	char		*str;
// 	int64_t		cast;
// 	uint64_t	accuracy;
//
// 	str = NULL;
// 	if ((vector = vct_new(0)) != NULL)
// 	{
// 		cast = (int64_t)value;
// 		value -= (double)cast;
// 		if ((str = ft_itoa(cast)) == NULL)
// 			vct_del(&vector);
// 		if ((vct_strjoin(vector, str)) == FAILURE)
// 			vct_del(&vector);
// 		value = value < 0 ? -value : value;
// 		accuracy = (option & FLAG_POINT) ? precision : 6;
// 		if ((handle_decimal(value, cast, vector, accuracy)) == FAILURE)
// 			vct_del(&vector);
// 		if (vector != NULL)
// 		{
// 			ft_strdel(&str);
// 			str = vct_get_str(vector);
// 		}
// 		vct_del(&vector);
// 	}
// 	return (str);
// }
