/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:21:58 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 14:52:44 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	disp_match(int match, int picked)
{
	int	i;

	i = -1;
	while (++i < match)
		ft_putstr("|");
	while (picked--)
		ft_putstr("\033[2;31m|\033[00m");
}
