/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:31:10 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:10:59 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (ac > 1)
	{
		parse(av, ac, &lst_a);
		if (ft_lstsize(lst_a) <= 6)
			tiny_sort(&lst_a, &lst_b);
		else
		{
			lst_patch(&lst_a);
			lst_split(&lst_a, &lst_b);
		}
		sort_list(&lst_a, &lst_b);
		ft_lstclear(&lst_a);
		ft_lstclear(&lst_b);
	}
	exit(EXIT_SUCCESS);
}
