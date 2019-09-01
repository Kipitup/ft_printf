/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:31:42 by fkante            #+#    #+#             */
/*   Updated: 2019/08/31 21:56:24 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int8_t	*conv_to_string(t_state_machine *machine, char *args)
{
	while (*args != *p_cursor)
	{
		vct_strjoin(machine->p_out, args);
		args++;
	}
	return (SUCCESS);
}
