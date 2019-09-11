/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:33:22 by amartino          #+#    #+#             */
/*   Updated: 2019/09/11 14:49:15 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdio.h>

int 	main(int ac, char **av)
{
	t_vector	*vector1;
	t_vector	*vector2;
	t_vector	*vector3;
	int			ret;
	(void)ac;
	ret = -1;
	vector1 = vct_new_str("hellO cA va ?");
	ret = vct_apply(vector1, LOWCASE);
	printf("str : |%s|\t ret : %d\n", vector1->str, ret);
	printf("len : %zu\tsize : %zu\n\n", vector1->len, vector1->size);
	// 	vector2 = vct_dup(vector1);
	// printf("str : |%s|\n", vector1->str);
	// printf("len : %zu\tsize : %zu\n\n", vector1->len, vector1->size);
	// vct_fill_before(vector1, av[2][0], atoi(av[3]));
	// printf("%s\n", vector1->str);
	// printf("%zu\n", vector1->len);
	// vct_add_char_at(vector1, 'A', 0);
	// printf("str : |%s|\n", vector1->str);
	// printf("len : %zu\tsize : %zu\n\n", vector1->len, vector1->size);
	// vct_del(&vector1);
	// vector1 = vct_new_str(" allez c'est parti avec ou sans e ? ");
	// vector3 = vct_join(vector2, vector1);
	// printf("str : |%s|\n", vector3->str);
	// printf("len : %zu\tsize : %zu\n\n", vector3->len, vector3->size);
	// vector2 = vct_join_free(vector3, vector2, BOTH);
	// printf("str : |%s|\n", vector2->str);
	// printf("len : %zu\tsize : %zu\n\n", vector2->len, vector2->size);
	// vct_pop(vector2, 3);
	// printf("str : |%s|\n", vector2->str);
	// printf("len : %zu\tsize : %zu\n\n", vector2->len, vector2->size);
	// vct_pop_from(vector2, 80, 85);
	// printf("str : |%s|\n", vector2->str);
	// printf("len : %zu\tsize : %zu\n\n", vector2->len, vector2->size);
	// vct_del(&vector2);
	// vct_del(&vector1);

}
