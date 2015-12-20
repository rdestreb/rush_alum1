/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:47:14 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 09:47:25 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	main(int ac, char **av)
{
	int	fd;

	if (ac == 1)
	{
		fd = 0;
		read_board(fd);
	}
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		read_board(fd);
	}
	return (0);
}
