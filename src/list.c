/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:12:04 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 15:12:15 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

t_list	*singleton(void)
{
	static t_list	*lst = NULL;

	if (!lst)
		lst = (t_list *)ft_memalloc(sizeof(t_list));
	return (lst);
}

t_list	*newnode(int match)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	new->nb_match = match;
	new->next = NULL;
	return (new);
}

void add_link(int match)
{
	t_list	*lst;

	lst = singleton();
	while (lst->next)
		lst = lst->next;
	lst->next = newnode(match);
}

void disp_list(void)
{
	t_list	*lst;

	lst = singleton();
	lst = lst->next;
	while (lst)
	{
		disp_match(lst->nb_match);
		ft_putendl("");
		lst = lst->next;
	}
}
