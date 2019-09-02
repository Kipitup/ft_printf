/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:13:45 by amartino          #+#    #+#             */
/*   Updated: 2019/09/02 13:11:27 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdio.h> //warning
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <math.h>
# include <inttypes.h>
# include "libft.h"
# include "ft_printf.h"

# define FALSE				0
# define TRUE				1
# define FAILURE			-1
# define SUCCESS			0
# define ON					1
# define OFF				0

# define NB_OF_FLAGS		11
# define NB_OF_CONVS		10

# define SHIFT_TO_CONVS		16

# define CONVERSION_SIGN	'%'

# define HH 				"hh"
# define LL 				"ll"
# define H 					"h"
# define L 					"l"
# define L_MAJ				"L"
# define PLUS 				"+"
# define MOINS				"-"
# define HASH				"#"
# define ZERO				"0"
# define SPACE				" "
# define POINT				"."
# define C					"c"
# define S					"s"
# define P					"p"
# define D					"d"
# define I					"i"
# define O					"o"
# define U					"u"
# define X					"x"
# define X_MAJ				"X"
# define F					"f"

# define FLAG_HH			0x00000001
# define FLAG_LL			0x00000002
# define FLAG_H				0x00000004
# define FLAG_L				0x00000008
# define FLAG_L_MAJ			0x00000010
# define FLAG_PLUS			0x00000020
# define FLAG_MINUS			0x00000040
# define FLAG_HASH			0x00000080
# define FLAG_ZERO			0x00000100
# define FLAG_SPACE			0x00000200
# define FLAG_POINT			0x00000400

# define CONV_C				0x00010000
# define CONV_S				0x00020000
# define CONV_P				0x00040000
# define CONV_D				0x00080000
# define CONV_I				0x00100000
# define CONV_O				0x00200000
# define CONV_U				0x00400000
# define CONV_X				0x00800000
# define CONV_X_MAJ			0x01000000
# define CONV_F				0x02000000
# define CONV_NONE			0x04000000

#endif
