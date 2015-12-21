/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:51:50 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 15:51:51 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static t_list	*newnode(int match)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	new->nb_match = match;
	new->init = match;
	new->next = NULL;
	return (new);
}

void			add_link(int match)
{
	t_list	*lst;

	lst = singleton();
	while (lst->next)
		lst = lst->next;
	lst->next = newnode(match);
}
