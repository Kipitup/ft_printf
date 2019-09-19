/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:11:36 by fkante            #+#    #+#             */
/*   Updated: 2019/09/19 16:37:23 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int8_t			conv_f(t_vector *vector, t_flag *flag, t_vector *nb_ftoa)
{
	int 	ret;

	ret = FAILURE;
	if (vector != NULL && nb_ftoa != NULL)
		ret = apply_padding_flag(vector, flag, nb_ftoa);
	return (ret);
}

t_vector		*conv_to_f(va_list *arg_pf, t_flag *flag)
{
	t_vector	*vector;
	t_vector	*nb_ftoa;
	long double	ldb;
	double		nbr;

	nb_ftoa = NULL;
	if (flag->option & FLAG_L_MAJ)
	{
		ldb = va_arg(*arg_pf, long double);
		nb_ftoa = ft_fldtoa(ldb, flag->precision, flag->option);
	}
	else
	{
		nbr = va_arg(*arg_pf, double);
		nb_ftoa = ft_ftoa(nbr, flag->precision, flag->option);
	}
	vector = vct_new(flag->width);
	if ((conv_f(vector, flag, nb_ftoa)) == FAILURE)
		vct_del(&vector);
	vct_del(&nb_ftoa);
	return (vector);
}
