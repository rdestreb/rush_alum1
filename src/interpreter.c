/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:21:58 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 16:22:12 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void disp_match(int match)
{
	int	i;

	i = -1;
	while (++i < match)
		ft_putstr("|");
}
