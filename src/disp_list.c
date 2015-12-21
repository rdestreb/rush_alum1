/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:51:29 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 15:51:30 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	disp_list(int picked)
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
