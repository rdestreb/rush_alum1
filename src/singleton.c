/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:51:15 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 15:51:18 by rdestreb         ###   ########.fr       */
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
