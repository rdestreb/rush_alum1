/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:53:44 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 09:53:53 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"
#include <stdio.h>
int	read_board(int fd)
{
	char	*line;
	int		nb_match;

	while ((fd == 0 && get_next_line(fd, &line) > 0 && ft_strcmp(line, ""))
			|| (fd > 0 && get_next_line(fd, &line) > 0))
	{
		if ((nb_match = verif_board(line)))
		{
			add_link(nb_match);
		}
		else
			return (0);
		free (line);
	}
	close (fd);
	disp_list();
	return (0);
}
