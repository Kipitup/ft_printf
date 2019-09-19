/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fldtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:50:31 by fkante            #+#    #+#             */
/*   Updated: 2019/09/19 17:00:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "define.h"

int8_t		round_up_ld(t_vector *vector, uint64_t accuracy)
{
	char 		c;

	c = vct_getchar_at(vector, accuracy);
	if (c >= '0' && c <= '9')
		vct_replace_char_at(vector, c + 1, accuracy);
	if (c == '9' || c == '.')
	{
		if ((round_up_ld(vector, accuracy - 1)) == SUCCESS)
		{
			if (c == '.')
				return (SUCCESS);
			else
				vct_replace_char_at(vector, '0', accuracy);
		}
	}
	return (SUCCESS);
}

int8_t		check_for_rounding_up_ld(t_vector *vector, long double value, int64_t cast)
{
	uint64_t 	accuracy;
	int64_t		tmp;

	value *= 10;
	cast = (int64_t)value;
	value -= (long double)cast;
	tmp = (int64_t)(value * 10);
	if (tmp > 0)
		cast++;
	accuracy = (uint64_t)vct_len(vector) - 1;
	if ((cast == 5 && (vct_getchar_at(vector, accuracy) % 2 == 0)) == FALSE)
	{
		if (cast > 4)
			if ((round_up_ld(vector, accuracy)) == FAILURE)
				vct_del(&vector);
	}
	return (vector == NULL ? FAILURE : SUCCESS);
}

int8_t		nb_to_string_ld(t_vector *vector, long double value, int64_t cast,
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
		value -= (long double)cast;
		if ((vct_addchar(vector, base_str[cast % 10])) == FAILURE)
			vct_del(&vector);
		i--;
	}
	if ((check_for_rounding_up_ld(vector, value, cast)) == FAILURE)
		vct_del(&vector);
	return (vector == NULL ? FAILURE : SUCCESS);
}

t_vector	*ft_fldtoa(long double value, uint64_t precision, uint32_t option)
{
	t_vector	*vector;
	char		*str;
	int64_t		cast;
	uint64_t	accuracy;

	vector = vct_new(0);
	if (value < (long double)LLONG_MIN || value > (long double)LLONG_MAX)
		return (NULL);
	if (vector != NULL)
	{
		cast = (int64_t)value;
		value -= (long double)cast;
		if ((str = ft_itoa(cast)) != NULL)
			if ((vct_strjoin(vector, str)) == FAILURE)
				vct_del(&vector);
		ft_strdel(&str);
		value = value < 0 ? -value : value;
		accuracy = (option & FLAG_POINT) ? precision : 6;
		if (accuracy > 0)
			if ((vct_addchar(vector, '.')) == FAILURE)
				vct_del(&vector);
		if (vector != NULL)
			if ((nb_to_string_ld(vector, value, cast, accuracy)) == FAILURE)
				vct_del(&vector);
	}
	return (vector);
}
