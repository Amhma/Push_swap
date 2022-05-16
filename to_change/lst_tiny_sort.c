#include"push_swap.h"

void ft_exit_sort(t_list **lst_a, t_list **lst_b)
{
	if (*lst_b)
		ft_lstclear(lst_a);
	ft_lstclear(lst_a);
	exit(EXIT_SUCCESS);
}

void	ft_lst_three(t_list **lst_a, t_list **lst_b)
{
	t_list	*elem;
	t_list	*min;
	t_list	*max;

	max = find_elem(*lst_a, max_list(*lst_a));
	min = find_elem(*lst_a, min_list(*lst_a));
	elem = ft_lstlast(*lst_a);
	if ((*lst_a == max && elem == min) || *lst_a == min || elem == max)
		swap(lst_a, 'a');
	if (ft_is_sort(*lst_a) > 0)
		ft_exit_sort(lst_a, lst_b);
	if (*lst_a == max) 
		rotate(lst_a, 'a');
	if (ft_is_sort(*lst_a) > 0)
		ft_exit_sort(lst_a, lst_b);
	if (elem == min) 
		rev_rotate(lst_a, 'a');
	if (ft_is_sort(*lst_a) > 0)
		ft_exit_sort(lst_a, lst_b);
}

void	tiny_sort(t_list **lst_a, t_list **lst_b)
{
	if (ft_is_sort(*lst_a) > 0)
		 ft_exit_sort(lst_a, lst_b);
	if (ft_lstsize(*lst_a) == 2)
		swap(lst_a, 'a');
	else if (ft_lstsize(*lst_a) == 3)
		ft_lst_three(lst_a, lst_b);
	else if (ft_lstsize(*lst_a) > 3 && ft_lstsize(*lst_a) <= 6)
	{
		if (*lst_a > (*lst_a)->next)
			swap(lst_a, 'a');
		while (ft_lstsize(*lst_a) > 3)
			push(lst_a, lst_b, 'b');
		ft_lst_three(lst_a, lst_b);
	}
	if (ft_is_sort(*lst_a) > 0 && !*lst_b)
		ft_exit_sort(lst_a, lst_b);
}		
