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
	int	nb_match;

	nb_match = ft_atoi(line);
	if (nb_match > 0 && nb_match < 10001)
		return (nb_match);
	else
		return (print_error());
}
