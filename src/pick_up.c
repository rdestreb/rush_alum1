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
	ft_putendl("\033[4;35m");
	ft_putnbr(lst->nb_match);
	ft_putendl(" match(es) remaining on last row\033[00m");
	return (CPU);
}
