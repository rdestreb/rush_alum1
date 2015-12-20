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
		read_board(0);
	else if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			print_error();
		else
			read_board(fd);
	}
	else
		ft_putendl_fd("Error : too many arguments", 2);
	return (0);
}
