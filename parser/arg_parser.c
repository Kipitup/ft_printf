#include "ft_printf.h"

char	*arg_parser(t_vector arg, char *input)
{
	int count;

	count = 0;
	if (ft_strcmp (*input, '"') == SUCCESS)
	{
		*input++;
		vct_add(arg->str, *input);
	}
	while (ft_strcmp(*input, '"') != SUCCESS)
	{
		vct_add(arg->str, *input);
		*input++;
	}
	if (*input + 1 == ' ')
	{
		while (*input == ' ')
		{
			*input++;
			count++;
		}
	}
	if (ft_strcmp (*input, ',') == SUCCESS)
	{
		
	}
}
