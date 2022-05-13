/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:31:10 by amahla            #+#    #+#             */
/*   Updated: 2022/05/13 18:36:24 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_fd(lst->nb, 1);
		if (lst->next)
			write(1, " ", 1);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

void	print_lst_list(t_list *lst)
{
	while (lst)
	{
		write(1, &(lst->stack), 1);
		if (lst->next)
			write(1, " ", 1);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

void	print_lst_value(t_list *lst)
{
	while (lst)
	{
		ft_putnbr_fd(lst->value, 1);
		if (lst->next)
			write(1, " ", 1);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (ac > 1)
	{
		parse(av, ac, &lst_a);
		print_lst(lst_a);
		print_lst(lst_b);
		lst_patch(&lst_a);
		print_lst(lst_a);
		print_lst_list(lst_a);
		print_lst_value(lst_b);
	}
	exit(EXIT_SUCCESS);
}

