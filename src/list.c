/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:12:04 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 14:54:50 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

t_list		*singleton(void)
{
	static t_list	*lst = NULL;

	if (!lst)
		lst = (t_list *)ft_memalloc(sizeof(t_list));
	return (lst);
}

t_list		*newnode(int match)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	new->nb_match = match;
	new->init = match;
	new->next = NULL;
	return (new);
}

void		add_link(int match)
{
	t_list	*lst;

	lst = singleton();
	while (lst->next)
		lst = lst->next;
	lst->next = newnode(match);
}

void		disp_list(int picked)
{
	t_list	*lst;

	lst = singleton();
	lst = lst->next;
	ft_putendl("");
	while (lst && lst->nb_match)
	{
		if (lst->next && lst->next->nb_match)
			disp_match(lst->nb_match, 0);
		else if (lst->next && !lst->next->nb_match
				&& lst->nb_match == lst->init && picked)
		{
			disp_match(lst->nb_match, 0);
			ft_putendl("");
			disp_match(0, picked);
		}
		else
			disp_match(lst->nb_match, picked);
		ft_putendl("");
		lst = lst->next;
	}
}

int			remaining_matches(void)
{
	t_list	*lst;

	lst = singleton();
	lst = lst->next;
	while (lst->next && lst->next->nb_match)
		lst = lst->next;
	return (lst->nb_match);
}
