/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:54:02 by amahla            #+#    #+#             */
/*   Updated: 2022/05/12 14:58:07 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int check_is_digit(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (!ft_isdigit(*(str + i++)))
			return (0);
	}
	return (1);
}

int	check_list(t_list **lst, int nb)
{
	t_list	*elem;

	elem = *lst;
	while (elem)
	{
		if (elem->nb == nb)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int	check_arg(char *str, long long nb)
{
	if (*str && (nb > INT_MAX || nb < INT_MIN))
		return (0);
	else if (ft_strlen(str) >= 2 && str[0] == '-' && check_is_digit(str + 1))
		return (1);
	else if (check_is_digit(str))
		return (1);
	return (0);
}

void	parse(char **av, int ac, t_list **lst)
{
	int			i;
	long long	nb;
	t_list		*elem;

	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (!*av[i] || !check_arg(av[i], nb) || !check_list(lst, (int)nb))
		{
			ft_putendl_fd("Error", 2);
			ft_lstclear(lst);
			exit(EXIT_SUCCESS);
		}
		elem = ft_lstnew((int)nb, 0, 'a');
		if (!elem)
		{
			ft_lstclear(lst);
			exit(EXIT_SUCCESS);
		}
		ft_lstadd_front(lst, elem);
		i++;
	}
}

