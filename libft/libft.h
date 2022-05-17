/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amahla <amahla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:37:51 by amahla            #+#    #+#             */
/*   Updated: 2022/05/17 17:43:02 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
//# include "../push_swap.h"

typedef struct s_list
{
	int				nb;
	int				value;
	char			stack;
	struct s_list	*next;
}				t_list;

int			ft_strlen(const char *s);
int			ft_isdigit(int c);
void		*ft_calloc(size_t nmemb, size_t size);
long long	ft_atoi(const char *nptr);
void		ft_putendl_fd(char *str, int fd);
char		**ft_split(char const *s, char c);
void		ft_free_split(char **split);

//		list_ft
t_list		*ft_lstnew(int nb, int value, char c);
int			ft_lstsize(t_list *lst);
int			ft_index_lst_at(int data_ref, t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);
t_list		*ft_list_at(t_list *begin_list, unsigned int nbr);
int			ft_is_sort(t_list *lst);
int			ft_is_sort_rotate(t_list *lst);

#endif
