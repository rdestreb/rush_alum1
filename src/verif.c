/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 11:57:12 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 11:57:25 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	verif_board(char *line)
{
	if (ft_atoi(line) > 0 && ft_atoi(line) < 10001)
	{
	//	ft_putendl("OK");
		return (1);
	}
	else
	{
		print_error();
		return (0);
	}
}
