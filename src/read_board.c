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
	int		nb_match;
	t_list	*lst;

	while ((fd == 0 && get_next_line(fd, &line) > 0 && ft_strcmp(line, ""))
			|| (fd > 0 && get_next_line(fd, &line) > 0))
	{
		if ((nb_match = verif_board(line)))
			add_link(nb_match);
		else
			return (0);
		free (line);
	}
	lst = singleton();
	if (line && !lst->next)
		return (print_error());
	if (fd)
		close (fd);
	disp_list();
	game();
	return (0);
}
