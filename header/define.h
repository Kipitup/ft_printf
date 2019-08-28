/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <a.martino@sutdent.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:13:45 by amartino          #+#    #+#             */
/*   Updated: 2019/08/28 16:58:23 by fkante           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //warning
# include <stdint.h>
# include <stdarg.h>
# include <math.h>
# include "../libftprintf/libft.h"
# include "ft_printf.h"

# define FALSE		0
# define TRUE		1
# define FAILURE	-1
# define SUCCESS	0
# define ON			1
# define OFF		0

# define CONVERSION_SIGN	'%'


# define FLAG_HH		0x0000000000000001
# define FLAG_LL		0x0000000000000002
# define FLAG_H			0x0000000000000004
# define FLAG_L			0x0000000000000008
# define FLAG_L_MAJ		0x0000000000000010
# define FLAG_PLUS		0x0000000000000020
# define FLAG_MINUS		0x0000000000000040
# define FLAG_HASH		0x0000000000000080
# define FLAG_ZERO		0x0000000000000100
# define FLAG_SPACE		0x0000000000000200
# define FLAG_POINT		0x0000000000000400

# define CONV_C			0x0000000000001000
# define CONV_S			0x0000000000002000
# define CONV_P			0x0000000000004000
# define CONV_D			0x0000000000008000
# define CONV_I			0x0000000000010000
# define CONV_O			0x0000000000020000
# define CONV_U			0x0000000000040000
# define CONV_X			0x0000000000080000
# define CONV_X_MAJ		0x0000000000100000
# define CONV_F			0x0000000000200000

/*
# define STATE_DECLARE(state_function, event_data) \
	static void ST_STATE_FUNCT(t_state_machine *self, event_data *pEventData)
	*/
#endif
