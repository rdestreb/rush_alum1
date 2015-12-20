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

int	read_board(int fd)
{
	char	*line;

	while (get_next_line(fd, &line) > 0 && ft_strcmp(line, ""))
	{
		ft_putendl(line);
		free (line);
	}
	close (fd);
	return (0);
}
