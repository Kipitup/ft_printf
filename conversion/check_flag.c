/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkante <fkante@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:22:33 by fkante            #+#    #+#             */
/*   Updated: 2019/08/31 19:37:20 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	check_cancel_flag(uint64_t option)
{
	t_main	t_argv;

	if (option & FLAG_PLUS && option & FLAG_SPACE)
		option &= ~FLAG_SPACE;
	if (option & FLAG_MINUS && option & FLAG_ZER0)
		option &= ~FLAG_ZERO;
	t_argv.option = option;
}

int		ft_printf(const char *input, ...)
{
}

void	after_check_of_option()
{
	va_list		arg_pf;
	t_main 		t_argv;
	int			valid_conv_count;
	static		t_convfunc func_ptr[NB_CONV_FUNC];

	func_ptr = {conv_to_char, conv_to_string, conv_to_pointer, conv_to_decimal,
				conv_to_int, conv_to_octal, conv_to_u_decimal, conv_to_hexa,
				conv_to_hexa_maj, conv_to_float};

	//initialize valist for the valid number of conv
	va_start(arg_pf, input);

	//we access the arguments assigned to valist
	t_argv.p_arg = va_arg(arg_pf, char*);
	printf("print argv : |%s|\n", argv);
}
// clean n free memory for valist

va_end(arg_pf);
return (0);
}*/
