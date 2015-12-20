/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:40:19 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 16:40:30 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int game_turn(int player)
{
	char	*line;

	while (42)
	{
		get_next_line(0, &line);
		if (!ft_strcmp(line, "stop"))
			return (-1);
		else if (player == 0)
		{
			ft_putendl("CPU playing");
			player = 1;
		}
		else if (player == 1)
		{
			ft_putendl("Pick 1, 2 or 3 match(es) :");
			player = 0;
		}
	}
	return (1);
}

static int	start_game(char *line)
{

	if (!ft_strcmp(line, "stop"))
		return (-1);
	else if (!ft_strcmp(line, "1"))
	{
		ft_putendl("You play first !");
		return (game_turn(1));
	}
	else if (!ft_strcmp(line, "2"))
	{
		ft_putendl("CPU plays first !");
		return (game_turn(0));
	}
	else
	{
		ft_putendl("wrong entry, please retry !");
		return (0);
	}
}

void game()
{
	int		status;
	char	*line;

	status = 0;
	ft_putendl("\nChoose first player (1 : you ; 2 : CPU) :");
	while (status != -1 && status != 1)
	{
		if (get_next_line(0, &line) == -1)
			status = -1;
		else
			status = start_game(line);
		free(line);
	}
	if (status == -1)
		return(ft_putendl("exit !"));
}
