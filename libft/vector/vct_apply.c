/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:43:23 by amartino          #+#    #+#             */
/*   Updated: 2019/09/11 14:38:58 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_char_ptr_func		apply_func(enum e_apply type)
{
	static	t_char_ptr_func	func[] = 	{ft_strupcase, ft_strlowcase,
										ft_strcapitalize};

	return (func[type]);
}

t_int_func			test_func(enum e_apply type)
{
	static	t_int_func	func[] = 	{ft_strisupcase, ft_strislowcase};

	return (func[type]);
}

int				vct_apply(t_vector *vector, enum e_apply type)
{
	int		ret;

	ret = 0;
	if (vector != NULL && vector->str != NULL)
	{
		if (type < 3)
			apply_func(type)(vector->str);
		else if (type < NB_TOTAL_OF_FUNC)
			ret = test_func(type - NB_OF_APPLY_FUNC)(vector->str);
	}
	return (ret);
}
