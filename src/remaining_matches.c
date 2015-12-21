/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remaining_matches.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:50:54 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 15:51:05 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	remaining_matches(void)
{
	t_list	*lst;

	lst = singleton();
	lst = lst->next;
	while (lst->next && lst->next->nb_match)
		lst = lst->next;
	return (lst->nb_match);
}
