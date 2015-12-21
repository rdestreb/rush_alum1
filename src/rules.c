/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:27:05 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 19:27:12 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	pick_up(int pick)
{
	t_list	*lst;

	lst = singleton();
	lst = lst->next;
	while (lst->next && lst->next->nb_match)
		lst = lst->next;
	lst->nb_match -= pick;
	disp_list(pick);
	return (CPU);
}
