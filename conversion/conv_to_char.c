/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:06:10 by fkante            #+#    #+#             */
/*   Updated: 2019/09/01 17:53:02 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_vector	*conv_to_char(va_list args_printf, uint64_t flag)
{
	t_vector	*vector;
	char		c;

	(void)flag;
	c = va_arg(args_printf, char);
	vector = vct_new(0);
	vct_add_char(vector, c);
	return (vector);
}
