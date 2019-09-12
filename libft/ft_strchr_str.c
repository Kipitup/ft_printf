/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:05:40 by amartino          #+#    #+#             */
/*   Updated: 2019/09/12 17:05:56 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_str(const char *str, char *find)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == find[j])
		{
			while (find[j] != '\0')
			{
				if (str[i] != find[j])
					break ;
				i++;
				j++;
			}
			if (find[j] == '\0')
				return ((char*)str + i - j);
		}
		i++;
	}
	return (NULL);
}
