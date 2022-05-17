/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:54:02 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:10:03 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	check_is_digit(char *str)
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
	if ((*str && (nb > INT_MAX || nb < INT_MIN)) || ft_strlen(str) > 12)
		return (0);
	else if (ft_strlen(str) >= 2 && str[0] == '-' && check_is_digit(str + 1))
		return (1);
	else if (check_is_digit(str))
		return (1);
	return (0);
}

void	ft_error(t_list **lst, char **split, int i)
{
	if (i)
		ft_putendl_fd("Error", 2);
	if (split)
		ft_free_split(split);
	ft_lstclear(lst);
	exit(EXIT_FAILURE);
}

void	parse(char **av, int ac, t_list **lst)
{
	int			i;
	int			y;
	long long	nb;
	t_list		*elem;
	char		**arg;

	y = 0;
	while (++y < ac)
	{
		i = -1;
		arg = ft_split(av[y], ' ');
		if (!arg)
			ft_error(lst, arg, 0);
		while (arg[++i])
		{
			nb = ft_atoi(arg[i]);
			if (!*arg[i] || !check_arg(arg[i], nb) || !check_list(lst, (int)nb))
				ft_error(lst, arg, 1);
			elem = ft_lstnew((int)nb, 0, 'a');
			if (!elem)
				ft_error(lst, arg, 0);
			ft_lstadd_back(lst, elem);
		}
		ft_free_split(arg);
	}
}	
